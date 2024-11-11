#include "../include/cub3d.h"

int	print_repeated_pixel(t_cub *cub, int j, int i, int pixel_count)
{
	int	k;
	unsigned int	colour;

	colour = *(unsigned int *)(cub->game.image_data + (j * WIDTH + i));
	k = 0;
	while (++k < pixel_count)
	{
		*(unsigned int *)(cub->game.image_data + ((j + k) * WIDTH + i)) = colour;
	}
	return (j + k);
}

int	print_repeated_pixel_close(t_cub *cub, int j, int i, int pixel_count)
{
	int	k;
	unsigned int	colour;

	colour = *(unsigned int *)(cub->game.image_data + (j * WIDTH + i));
	k = 0;
	while (++k < pixel_count)
	{
		*(unsigned int *)(cub->game.image_data + ((j + k) * WIDTH + i)) = colour;
	}
	return (j + k);
}