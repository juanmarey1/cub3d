#include "../include/cub3d.h"

int	check_first_last_row(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (1);
	}
	j = 0;
	while (map[j + 1])
		j++;
	i = -1;
	while (map[j][++i])
	{
		if (map[j][i] != ' ' && map[j][i] != '1')
			return (1);
	}
	return (0);
}

int	is_spaces_not_surrounded_by_walls(char **map, int i, int j)
{
	while(map[i][j])
	{
		if (map[i][j] == '0')
		{
			if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
				|| map[i - 1][j + 1] == ' ' || map[i][j - 1] == ' '
				|| map[i][j + 1] == ' ' || map[i + 1][j - 1] == ' '
				|| map[i + 1][j] == ' ' || map[i + 1][j + 1] == ' ')
				return (1);
		}
		j++;
	}
	return (0);
}

int	check_row(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i - 1][j] == ' ')
		j++;
	while (map[i][j] == ' ')
		j++;
	if (map[i - 1][j] == '\0' || map[i][j] == '\0')
		return (1);
	if (map[i - 1][j] != '1' || map[i][j] != '1')
		return (1);
	if (is_spaces_not_surrounded_by_walls(map, i, j))
		return (1);
	while (map[i - 1][j + 1])
		j++;
	while (map[i - 1][j] == ' ')
		j--;
	while (map[i][j] == ' ')
		j--;
	if (map[i - 1][j] != '1' || map[i][j] != '1')
		return (1);
	return (0);
}

void	get_init_pos_angle(char **map, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S')
			{
				cub->x = j;
				cub->y = i;
				cub->direction = map[i][j];
				return ;
			}
		}
	}
}