#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <sys/time.h>
# include <math.h>

# define NO_ASS "../assets/no_ass.xpm"
# define SO_ASS "../assets/so_ass.xpm"
# define EA_ASS "../assets/ea_ass.xpm"
# define WE_ASS "../assets/we_ass.xpm"
# define ASS_SIZE 64

# define PI 3.14159265358979323846
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define HEIGHT 1080
# define WIDTH 1840
# define VISION_ANGLE (PI / 3)
# define GRID 100
# define WALL_HEIGHT_CTE 83.33333333
# define MOVEMENT_SPEED 16

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		*image_data;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*image_data2;
	int		pixel_bits2;
	int		line_bytes2;
	int		endian2;	
	int		*image3;
	int		*image_data3;
	int		pixel_bits3;
	int		line_bytes3;
	int		endian3;	
}	t_game;

typedef struct s_cub
{
	unsigned int	colour_c;
	unsigned int	colour_f;
	void	*no_ass;
	void	*so_ass;
	void	*ea_ass;
	void	*we_ass;
	char	*north_sprite;
	char	*south_sprite;
	char	*west_sprite;
	char	*east_sprite;
	char	**ceiling_colour;
	char	**floor_colour;
	char	**map;
	char	*map_line;
	int		error;
	int		initial_position;
	int		x;
	int		y;
	double	grid_x;
	double	grid_y;
	double	grid_raycast_x;
	double	grid_raycast_y;
	double	angle;
	double	initial_angle;
	char	direction;
	char	sprite_direction;
	double	in_between_ray_dist;
	double	distance;
	t_game	game;
}	t_cub;


int		ft_error(t_cub *cub);
int		check_map(char *map_file, t_cub *cub);
int		is_map_valid(t_cub *cub);
int		check_first_last_row(char **map);
int		check_row(char **map, int i);
void	get_init_pos_angle(char **map, t_cub *cub);
void	init_raycasting(t_cub *cub);
void	raycast_case_1(t_cub *cub);
void	raycast_case_2(t_cub *cub);
void	raycast_case_3(t_cub *cub);
void	raycast_case_4(t_cub *cub);
void	run_game(t_cub *cub);
void	ft_move_player(t_cub *cub, int n);
int		ft_end_game(t_cub *cub);
int		get_assets(t_cub *cub);
void	ft_double_array(char **double_arr, int i);
void	get_colour(t_cub *cub, int wall_height, int j, int i);
void	get_colour_2(t_cub *cub, double zoom, int j, int i);
int		print_repeated_pixel(t_cub *cub, int j, int i, int pixel_count);

#endif