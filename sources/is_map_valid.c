#include "../include/cub3d.h"

char	*get_spaces_array(size_t length)
{
	char	*spaces;
	size_t	i;

	i = 0;
	spaces = (char *)malloc(sizeof(char) * (length + 1));
	while (i < length)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[i] = '\0';
	return (spaces);
}

void	map_to_square_map(char **map, size_t max_len)
{
	int		i;
	char	*spaces;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) < max_len)
		{
			spaces = get_spaces_array(max_len - ft_strlen(map[i]));
			map[i] = ft_strjoin(map[i], spaces);
			free(spaces);
		}
	}	
}

int	get_max_len_in_map(char **map)
{
	int		i;
	size_t	max_len;

	max_len = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	}
	return (max_len);
}

int	is_map_valid(t_cub *cub)
{
	size_t	max_len;
	int		i;

	max_len = get_max_len_in_map(cub->map);
	map_to_square_map(cub->map, max_len);
	i = 1;
	if (check_first_last_row(cub->map))
		return (1);
	while (cub->map[i + 1])
	{
		if (check_row(cub->map, i))
			return (1);
		i++;
	}
	return (0);
}