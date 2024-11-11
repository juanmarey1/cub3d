#include "../include/cub3d.h"

void	ft_free_double(char **double_arr)
{
	int	i;

	i = 0;
	while (double_arr[i])
	{
		free(double_arr[i]);
		i++;
	}
	free(double_arr);
}

void	ft_double_array(char **double_arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (double_arr[j])
			free(double_arr[j]);
		j++;
	}
	free(double_arr);
}

void	ft_clean_all(t_cub *cub)
{
	if (cub->ceiling_colour)
		ft_free_double(cub->ceiling_colour);
	if (cub->floor_colour)
		ft_free_double(cub->floor_colour);
	if (cub->ea_ass)
		mlx_destroy_image(cub->game.mlx_ptr, cub->ea_ass);
	if (cub->east_sprite)
		free(cub->east_sprite);
	if (cub->no_ass)
		mlx_destroy_image(cub->game.mlx_ptr, cub->no_ass);
	if (cub->north_sprite)
		free(cub->north_sprite);
	if (cub->we_ass)
		mlx_destroy_image(cub->game.mlx_ptr, cub->we_ass);
	if (cub->west_sprite)
		free(cub->west_sprite);
	if (cub->so_ass)
		mlx_destroy_image(cub->game.mlx_ptr, cub->so_ass);
	if (cub->south_sprite)
		free(cub->south_sprite);
	if (cub->map_line)
		free(cub->map_line);
	if (cub->map)
		ft_free_double(cub->map);
}

int	ft_error(t_cub *cub)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_clean_all(cub);
	if (cub->game.win_ptr)
		mlx_destroy_window(cub->game.mlx_ptr, cub->game.win_ptr);
	if (cub->game.mlx_ptr)
	{
		mlx_destroy_display(cub->game.mlx_ptr);
		free(cub->game.mlx_ptr);
	}
	return (0);
}

int	ft_end_game(t_cub *cub)
{
	mlx_destroy_window(cub->game.mlx_ptr, cub->game.win_ptr);
	mlx_destroy_display(cub->game.mlx_ptr);
	free(cub->game.mlx_ptr);
	if (cub->game.image)
		free(cub->game.image);
	if (cub->game.image3)
		free(cub->game.image3);
	exit (0);
	return (0);
}

