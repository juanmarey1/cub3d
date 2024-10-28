#include "../include/cub3d.h"

static	double	move_to_y(t_cub *cub, double y_move)
{
	if (cub->grid_y + y_move < 0)
	{
		if (cub->map[cub->y + 1][cub->x] == '1')
			return (0);
		return (cub->y++, cub->grid_y + 100 + y_move);
	}
	else if (cub->grid_y + y_move > 100)
	{
		if (cub->map[cub->y - 1][cub->x] == '1')
			return (100);
		return (cub->y--, cub->grid_y + y_move - 100);
	}
	return (cub->grid_y + y_move);
}

static	double	move_to_x(t_cub *cub, double x_move)
{
	if (cub->grid_x + x_move < 0)
	{
		if (cub->map[cub->y][cub->x - 1] == '1')
			return (0);
		return (cub->x--, cub->grid_x + 100 + x_move);
	}
	else if (cub->grid_x + x_move > 100)
	{
		if (cub->map[cub->y][cub->x + 1] == '1')
			return (100);
		return (cub->x++, cub->grid_x + x_move - 100);
	}
	return (cub->grid_x + x_move);
}

void	ft_move_player(t_cub *cub, int n)
{
	double	movement_angle;
	double	x_move;
	double	y_move;

	// printf("initial_angle: %f\n", cub->initial_angle * 180 / PI);
	if (n == 1)
		movement_angle = cub->initial_angle;
	else if (n == 2)
		movement_angle = cub->initial_angle + PI / 2;
	else if (n == 3)
		movement_angle = cub->initial_angle + PI;
	else
		movement_angle = cub->initial_angle + (3 * PI) / 2;
	if (cub->angle > 2 * PI)
		cub->angle = (cub->angle - (2 * PI));
	x_move = MOVEMENT_SPEED * cos(movement_angle);
	y_move = MOVEMENT_SPEED * sin(movement_angle);
	cub->grid_x = move_to_x(cub, x_move);
	cub->grid_y = move_to_y(cub, y_move);
	cub->angle = cub->initial_angle + PI / 6;
	if (cub->angle < 0)
		cub->angle = (2 * PI) + cub->angle;
	else if (cub->angle > 2 * PI)
		cub->angle = (cub->angle - (2 * PI));
	redo_raycasting(cub);
}