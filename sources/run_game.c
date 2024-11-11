#include "../include/cub3d.h"

// void	ft_move_player_y(t_cub *cub, int direction)
// {
// 	if (cub->grid_y == 100 && direction == -1)
// 	{
// 		if (cub->map[cub->y - 1][cub->x] == '1')
// 			return ;
// 		cub->grid_y = 20;
// 		cub->y += direction;
// 	}
// 	else if (cub->grid_y == 0 && direction == 1)
// 	{
// 		if (cub->map[cub->y + 1][cub->x] == '1')
// 			return ;
// 		cub->grid_y = 80;
// 		cub->y += direction;
// 	}
// 	else
// 		cub->grid_y += 20 * (direction * -1);
// 	printf("%f\n", (cub->initial_angle * 360) / (2 * PI));
// 	cub->angle = cub->initial_angle + PI / 6;
// 	if (cub->angle < 0)
// 		cub->angle = (2 * PI) + cub->angle;
// 	else if (cub->angle > 2 * PI)
// 		cub->angle = (cub->angle - (2 * PI));
// 	printf("cub->x, y: %d, %d\ncub_grid->x, y: %f, %f\n\n", cub->x, cub->y, cub->grid_x, cub->grid_y);
// 	redo_raycasting(cub);
// }

// void	ft_move_player_x(t_cub *cub, int direction)
// {
// 	if (cub->grid_x == 100 && direction == 1)
// 	{
// 		if (cub->map[cub->y][cub->x + 1] == '1')
// 			return ;
// 		cub->grid_x = 20;
// 		cub->x += direction;
// 	}
// 	else if (cub->grid_x == 0 && direction == -1)
// 	{
// 		if (cub->map[cub->y][cub->x - 1] == '1')
// 			return ;
// 		cub->grid_x = 80;
// 		cub->x += direction;
// 	}
// 	else
// 		cub->grid_x += 20 * direction;
// 	printf("%f\n", (cub->initial_angle * 360) / (2 * PI));
// 	cub->angle = cub->initial_angle + PI / 6;
// 	if (cub->angle < 0)
// 		cub->angle = (2 * PI) + cub->angle;
// 	else if (cub->angle > 2 * PI)
// 		cub->angle = (cub->angle - (2 * PI));
// 	redo_raycasting(cub);
// }

void	ft_move_camera(t_cub *cub, int direction)
{
	if (direction > 0)
		cub->angle = cub->initial_angle + ((PI / 18));
	else if (direction < 0)
		cub->angle = cub->initial_angle - ((PI / 18));
	if (cub->angle < 0)
		cub->angle = (2 * PI) + cub->angle;
	else if (cub->angle > 2 * PI)
		cub->angle = (cub->angle - (2 * PI));
	cub->initial_angle = cub->angle;
	// printf("%f\n", (cub->initial_angle * 360) / (2 * PI));
	cub->angle = cub->angle + PI / 6;
	if (cub->angle < 0)
		cub->angle = (2 * PI) + cub->angle;
	else if (cub->angle > 2 * PI)
		cub->angle = (cub->angle - (2 * PI));
	init_raycasting(cub);
}

int	ft_key(int key, t_cub *cub)
{
	if (key == W)
		ft_move_player(cub, 1);
	if (key == S)
		ft_move_player(cub, 3);
	if (key == A)
		ft_move_player(cub, 2);
	if (key == D)
		ft_move_player(cub, 4);
	if (key == LEFT)
		ft_move_camera(cub, 1);
	if (key == RIGHT)
		ft_move_camera(cub, -1);
	if (key == ESC)
		ft_end_game(cub);
	return (0);
}

void	run_game(t_cub *cub)
{
	mlx_hook(cub->game.win_ptr, 2, 1L << 0, ft_key, cub);
	mlx_hook(cub->game.win_ptr, 17, 1L << 17, ft_end_game, cub);
	mlx_loop(cub->game.mlx_ptr);
}