#include "../include/cub3d.h"

void	calculate_distance_to_wall(t_cub *cub)
{
	if (cub->angle >= 0 && cub->angle <= PI / 2)
		raycast_case_1(cub);
	else if (cub->angle >= PI / 2 && cub->angle <= PI)
		raycast_case_2(cub);
	else if (cub->angle >= PI && cub->angle <= (3 * PI) / 2)
		raycast_case_3(cub);
	else if (cub->angle >= (3 * PI) / 2 && cub->angle <= (2 * PI))
		raycast_case_4(cub);
}

void	proyect_wall(t_cub *cub, int i)
{
	int		wall_height;
	int		pos;
	int		j;

	j = 0;
	cub->distance = cub->distance * cos(cub->angle - cub->initial_angle);
	if (cub->distance < 0)
		cub->distance *= -1;
	if (cub->distance <= 10)
		wall_height = 8 * HEIGHT;
	else
		wall_height = (int)(HEIGHT * ((WALL_HEIGHT_CTE) / (cub->distance)));
	if (wall_height > (int)HEIGHT)
		get_colour_2(cub, (double)wall_height / (double)HEIGHT, j, i);
	else
	{
		while (j < (HEIGHT - wall_height) / 2)
		{
			pos = (j * WIDTH + i);
			*(unsigned int *)(cub->game.image_data + pos) = cub->colour_c;
			j++;
		}
		get_colour(cub, wall_height, j, i);
		while (j < (wall_height + ((HEIGHT - wall_height) / 2)))
			j++;
		while (j < HEIGHT)
		{
			pos = (j * WIDTH + i);
			*(unsigned int *)(cub->game.image_data + pos) = cub->colour_f;
			j++;
		}
	}
}

void	init_raycasting(t_cub *cub)
{
	int	i;

	i = 0;	
	cub->game.image = mlx_new_image(cub->game.mlx_ptr, WIDTH, HEIGHT);
	cub->game.image_data = (int *)mlx_get_data_addr(cub->game.image, &cub->game.pixel_bits, &cub->game.line_bytes, &cub->game.endian);
	while (i < WIDTH)
	{
		cub->distance = 0;
		cub->grid_raycast_x = cub->grid_x;
		cub->grid_raycast_y = cub->grid_y;
		calculate_distance_to_wall(cub);
		proyect_wall(cub, i);
		cub->angle = cub->angle - cub->in_between_ray_dist;
		if (cub->angle < 0)
			cub->angle = (2 * PI) + cub->angle;
		i++;
	}
	mlx_clear_window(cub->game.mlx_ptr, cub->game.win_ptr);
	mlx_put_image_to_window(cub->game.mlx_ptr, cub->game.win_ptr, cub->game.image, 0, 0);
	if (cub->game.image)
	{
		mlx_destroy_image(cub->game.mlx_ptr, cub->game.image);
		cub->game.image = NULL;
	}
}