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
	double	wall_height;
	int		j;

	j = 0;
	// printf("%f\n", cub->distance);
	cub->distance = cub->distance * cos(cub->angle - cub->initial_angle);
	if (cub->distance < 0)
		cub->distance *= -1;
	// printf("%f\n", cub->distance);
	if (cub->distance == 0)
		wall_height = HEIGHT;
	else
	{
		// wall_height = ((WIDTH / 2) / (tan(VISION_ANGLE / 2))) * (1 / cub->distance);
		wall_height = HEIGHT * (WALL_HEIGHT_CTE / cub->distance);
	}
	// printf("sexoo->%f\n", wall_height);
	// cub->game.image = mlx_new_image(cub->game.mlx_ptr, WIDTH, HEIGHT);
	// cub->game.image_data = (int *)mlx_get_data_addr(cub->game.image, &cub->game.pixel_bits, &cub->game.line_bytes, &cub->game.endian);
	while (j < (HEIGHT - wall_height) / 2)
		j++;
	while (j < (HEIGHT - ((HEIGHT - wall_height) / 2)))
	{
		mlx_pixel_put(cub->game.mlx_ptr, cub->game.win_ptr, i, j, 0xFFFFFF);
		j++;
	}
	return ;
}

void	init_raycasting(t_cub *cub)
{
	int	i;

	i = 0;	
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
}