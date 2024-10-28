#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <sys/time.h>
# include <math.h>

# define PI 3.14159265358979323846
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define HEIGHT 1440
# define WIDTH 2560
# define VISION_ANGLE (PI / 3)
# define GRID 100
# define WALL_HEIGHT_CTE 83.33333333333333
# define MOVEMENT_SPEED 20

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		*image_data;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_game;

typedef struct s_cub
{
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


int		ft_error(void);
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
void	redo_raycasting(t_cub *cub);
void	ft_move_player(t_cub *cub, int n);

#endif