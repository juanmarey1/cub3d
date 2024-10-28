#include "../include/cub3d.h"

int	check_if_map_info(t_cub *cub)
{
	if (!cub->north_sprite || !cub->south_sprite
		|| !cub->east_sprite || !cub->west_sprite
		|| cub->ceiling_colour == NULL || cub->floor_colour == NULL)
		return (1);
	return (0);
}

int	save_map_info(char *line, t_cub *cub)
{
	char	*line_cpy;

	if (ft_strncmp(line, "NO ", 3) == 0)
		cub->north_sprite = ft_strtrim(line, "NO \t\n");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cub->south_sprite = ft_strtrim(line, "SO \t\n");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cub->west_sprite = ft_strtrim(line, "WE \t\n");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cub->east_sprite = ft_strtrim(line, "EA \t\n");
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		line_cpy = ft_strtrim(line, "F \t\n");
		cub->floor_colour = ft_split(line_cpy, ',');
		free(line_cpy);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		line_cpy = ft_strtrim(line, "C \t\n");
		cub->ceiling_colour = ft_split(line_cpy, ',');
		free(line_cpy);
	}
	else
		return (1);
	return (0);
}

int	get_map_file_info(int fd, t_cub *cub)
{
	char	*line;
	char	*line_trim;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line_trim = ft_strtrim(line, " \t\n");
		if (line_trim == NULL)
			free(line);
		else
		{
			cub->error = save_map_info(line_trim, cub);
			free(line_trim);
			free(line);
			if (cub->error)
				return (1);
		}
		if (check_if_map_info(cub) == 0)
			break ;
		line = get_next_line(fd);
	}
	if (check_if_map_info(cub))
		return (1);
	return (0);
}

void	get_map(int fd, t_cub *cub)
{
	int		i;
	char	*line;

	i = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		cub->map_line = ft_strjoin(cub->map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	while (cub->map_line[++i])
	{
		if (cub->map_line[i] != ' ' && cub->map_line[i] != '\n' && cub->map_line[i] != '\t'
			&& cub->map_line[i] != '1' && cub->map_line[i] != '0' && cub->map_line[i] != 'N'
			&& cub->map_line[i] != 'S' && cub->map_line[i] != 'E' && cub->map_line[i] != 'W')
			cub->error++;
		if (cub->map_line[i] == 'N' || cub->map_line[i] == 'S'
			|| cub->map_line[i] == 'W' || cub->map_line[i] == 'E')
			cub->initial_position++;
	}
	cub->map = ft_split(cub->map_line, '\n');
	free(cub->map_line);
	cub->map_line = NULL;
}

int	check_map(char *map_file, t_cub *cub)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (get_map_file_info(fd, cub))
		return (1);
	cub->map_line = ft_strdup("");
	get_map(fd, cub);
	if (cub->error || cub->initial_position != 1)
		return (1);
	if (is_map_valid(cub))
		return (1);
	get_init_pos_angle(cub->map, cub);
	return (0);
}