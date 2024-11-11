#include "../include/cub3d.h"

int	check_colours(char **ceiling, char **floor)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(ceiling[0]) > 3 || ft_strlen(ceiling[1]) > 3 || ft_strlen(ceiling[2]) > 3 || ft_strlen(floor[0]) > 3 || ft_strlen(floor[1]) > 3 || ft_strlen(floor[2]) > 3)
		return (1);
	while (++i < 3)
	{
		j = -1;
		while ((size_t)++j < ft_strlen(ceiling[i]))
		{
			if (ft_isdigit(ceiling[i][j]) == 0)
				return (1);
		}
		if (ft_atoi(ceiling[i]) > 255)
			return (1);
	}
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while ((size_t)++j < ft_strlen(floor[i]))
		{
			if (ft_isdigit(floor[i][j]) == 0)
				return (1);
		}
		if (ft_atoi(floor[i]) > 255)
			return (1);
	}
	return (0);
}

int	get_assets(t_cub *cub)
{
	int	ass_size;

	ass_size = ASS_SIZE;
	cub->no_ass = mlx_xpm_file_to_image(cub->game.mlx_ptr, cub->north_sprite, &ass_size, &ass_size);
	cub->we_ass = mlx_xpm_file_to_image(cub->game.mlx_ptr, cub->west_sprite, &ass_size, &ass_size);
	cub->ea_ass = mlx_xpm_file_to_image(cub->game.mlx_ptr, cub->east_sprite, &ass_size, &ass_size);
	cub->so_ass = mlx_xpm_file_to_image(cub->game.mlx_ptr, cub->south_sprite, &ass_size, &ass_size);
	if (!cub->no_ass || !cub->we_ass || !cub->ea_ass || !cub->so_ass)
		return (1);
	if (check_colours(cub->ceiling_colour, cub->floor_colour))
		return (1);
	cub->colour_c = (ft_atoi(cub->ceiling_colour[0]) << 16 | ft_atoi(cub->ceiling_colour[1]) << 8 | ft_atoi(cub->ceiling_colour[2]));
	cub->colour_f = (ft_atoi(cub->floor_colour[0]) << 16 | ft_atoi(cub->floor_colour[1]) << 8 | ft_atoi(cub->floor_colour[2]));
	return (0);
}