#include "../include/cub3d.h"

void	init_struct(t_cub *cub)
{
	cub->ceiling_colour = NULL;
	cub->floor_colour = NULL;
	cub->map = NULL;
	cub->map_line = NULL;
	cub->north_sprite = NULL;
	cub->south_sprite = NULL;
	cub->east_sprite = NULL;
	cub->west_sprite = NULL;
	cub->error = 0;
	cub->initial_position = 0;
	cub->game.image = NULL;
	cub->game.win_ptr = NULL;
	cub->game.mlx_ptr = NULL;
	cub->game.image_data = 0;
}

int	check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	if (len < 5)
		return (1);
	if (argv[1][len - 1] == 'b' && argv[1][len - 2] == 'u'
		&& argv[1][len - 3] == 'c' && argv[1][len - 4] == '.')
		return (0);
	return (1);	
}

int	ft_init_game(t_cub *cub)
{
	cub->game.mlx_ptr = mlx_init();
	if (!cub->game.mlx_ptr)
		return (1);
	cub->game.win_ptr = mlx_new_window(cub->game.mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!cub->game.win_ptr)
		return (1);
	if (cub->direction == 'N')
		cub->angle = PI / 2;
	else if (cub->direction == 'S')
		cub->angle = (3 * PI) / 2;
	else if (cub->direction == 'E')
		cub->angle = 0;
	else if (cub->direction == 'W')
		cub->angle = PI;
	cub->initial_angle = cub->angle;
	cub->angle = cub->angle + PI / 6;
	cub->in_between_ray_dist = VISION_ANGLE / WIDTH;
	cub->grid_x = 50;
	cub->grid_y = 50;
	cub->map[cub->y][cub->x] = '0';
	init_raycasting(cub);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub	cub;

	init_struct(&cub);
	if (check_args(argc, argv))
		return (ft_error());
	if (check_map(argv[1], &cub))
		return (ft_error());
	if (ft_init_game(&cub))
		return (ft_error());
	run_game(&cub);
	return (0);
}