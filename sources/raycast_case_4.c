#include "../include/cub3d.h"

static double	get_x_distance(t_cub *cub)
{
	double	x;
	double	h;

	x = 100 - cub->grid_raycast_x;
	if (cub->angle == (3 * PI) / 2)
		return (99999999999);
	h = x / cos((2 * PI) - cub->angle);
	return (h);
}

static double	get_y_distance(t_cub *cub)
{
	double	y;
	double	h;

	y = cub->grid_raycast_y;
	if (cub->angle == (2 * PI))
		return (99999999999);
	h = y / sin((2 * PI) - cub->angle);
	return (h);
}

static int	dist_y(t_cub *cub, int j, double y_distance)
{
	cub->distance = cub->distance + y_distance;
	cub->grid_raycast_y = 100;
	cub->sprite_direction = 'N';
	if (cub->angle == (3 * PI) / 2)
		return (j + 1);
	cub->grid_raycast_x = cub->grid_raycast_x + (y_distance * cos((2 * PI) - cub->angle));
	return (j + 1);
}

static int	dist_x(t_cub *cub, int i, double x_distance)
{
	cub->distance = cub->distance + x_distance;
	cub->grid_raycast_x = 0;
	cub->sprite_direction = 'W';
	if (cub->angle == (2 * PI))
		return (i + 1);
	cub->grid_raycast_y = cub->grid_raycast_y - (x_distance * sin((2 * PI) - cub->angle));
	return (i + 1);
}

void	raycast_case_4(t_cub *cub)
{
	double	x_distance;
	double	y_distance;
	int		i;
	int		j;

	j = 0;
	i = 0;
	// printf("\n\ncub->distance : %f\n", cub->distance);
	// printf("cube->grid_raycast: %f , %f\n", cub->grid_raycast_x, cub->grid_raycast_y);
	// printf("cub->angle : %f\n\n", cub->angle);
	while (cub->map[cub->y + j][cub->x + i] == '0')
	{
		x_distance = get_x_distance(cub);
		y_distance = get_y_distance(cub);
		// printf("%f\n", x_distance);
		// printf("%f\n", y_distance);
		if (x_distance > y_distance)
			j = dist_y(cub, j, y_distance);
		else
			i = dist_x(cub, i, x_distance);
		// printf("cube->grid_raycast: %f , %f\n", cub->grid_raycast_x, cub->grid_raycast_y);
		// printf("cub->distance : %f\n", cub->distance);
		// printf("j, i: %d, %d\n", j, i);
	}
}