#include "../include/cub3d.h"

int	get_pixel(int i, t_cub *cub)
{
	double	j;

	j = 0;
	if (cub->sprite_direction == 'W')
		j = ((100 - cub->grid_raycast_y) * ((double)64/(double)100));
	else if (cub->sprite_direction == 'N')
		j = ((cub->grid_raycast_x) * ((double)64/(double)100));
	else if (cub->sprite_direction == 'E')
		j = ((cub->grid_raycast_y) * ((double)64 / (double)100));
	else if (cub->sprite_direction == 'S')
		j = ((100 - cub->grid_raycast_x) * ((double)64 / (double)100));
	return (i * ASS_SIZE + (int)j);
}

unsigned int	pick_colour(double pixel_count, double j, t_cub *cub)
{
	double	i;
	unsigned int colour;

	if (j < 1)
		i = 0;
	else
		i = ((double)(j - 1) / pixel_count);
	i = get_pixel((int)i, cub);
	// printf("%d\n", i);
	colour = *(unsigned int *)(cub->game.image_data2 + (int)i);
	// printf("Color at (): 0x%X\n", colour);
	return (colour);
}

void	get_colour(t_cub *cub, int wall_height, int j, int i)
{
	void	*sprite;
	double	pixel_count;
	int		image_pos;

	image_pos = 0;
	if (cub->sprite_direction == 'N')
		sprite = cub->no_ass;
	else if (cub->sprite_direction == 'E')
		sprite = cub->ea_ass;
	else if (cub->sprite_direction == 'W')
		sprite = cub->we_ass;
	else if (cub->sprite_direction == 'S')
		sprite = cub->so_ass;
	pixel_count = (double)wall_height / (double)ASS_SIZE;
	cub->game.image_data2 = (int *)mlx_get_data_addr(sprite, &cub->game.pixel_bits2, &cub->game.line_bytes2, &cub->game.endian2);
	// printf("wall_height: %d", wall_height);
	while (j < (wall_height + ((HEIGHT - wall_height) / 2)))
	{
		*(unsigned int *)(cub->game.image_data + (j * WIDTH + i)) = pick_colour(pixel_count, (int)image_pos, cub);
		j = print_repeated_pixel(cub , j, i, pixel_count);
		if (pixel_count < 1)
			image_pos = image_pos + 1 / pixel_count;
		else
			image_pos = image_pos + pixel_count;
	}
}

unsigned int	pick_colour_2(double pixel_count, int j, t_cub *cub, int pos)
{
	int	i;
	unsigned int colour;

	i = (int)((double)(j - 1) / pixel_count) + pos;
	i = get_pixel(i, cub);
	// printf("%d\n", i);
	colour = *(unsigned int *)(cub->game.image_data2 + i);
	// printf("Color at (): 0x%X\n", colour);
	return (colour);
}

void	get_colour_2(t_cub *cub, double zoom, int j, int i)
{
	double	pixel_count;
	int		n;
	void	*sprite;
	int		pos;

	pixel_count = zoom * 16.875;
	n = (int)((double)1080 / (double)pixel_count);
	if (cub->sprite_direction == 'N')
		sprite = cub->no_ass;
	else if (cub->sprite_direction == 'E')
		sprite = cub->ea_ass;
	else if (cub->sprite_direction == 'W')
		sprite = cub->we_ass;
	else if (cub->sprite_direction == 'S')
		sprite = cub->so_ass;
	pos = ((ASS_SIZE - n) / 2);
	cub->game.image_data2 = (int *)mlx_get_data_addr(sprite, &cub->game.pixel_bits2, &cub->game.line_bytes2, &cub->game.endian2);
	while (j < HEIGHT)
	{
		*(unsigned int *)(cub->game.image_data + (j * WIDTH + i)) = pick_colour_2(pixel_count, j, cub, pos);
		j = print_repeated_pixel(cub, j, i, pixel_count);
	}
}