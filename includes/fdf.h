/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/05/19 19:25:03 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15
# define KEY_Z 6
# define KEY_X 7
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_0_N 82
# define KEY_1_N 83
# define KEY_2_N 84
# define KEY_3_N 85
# define KEY_MINUS 78
# define KEY_PLUS 69
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_TAB 48
# define KEY_ESC 53
# define RED 0xC41E3A
# define ORANGE 0xffa500
# define YELLOW 0xffc000
# define GREEN 0x00D100
# define BLUE 0x0096FF
# define INDIGO 0x6500B0
# define VIOLET 0x8f00ff

typedef struct s_list
{
	int				line;
	void			*content;
	struct s_list	*next;
	struct s_list	*before;
}				t_list;

typedef struct s_key_set
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	q;
	int	e;
	int	r;
	int	z;
	int	x;
	int	zero;
	int	one;
	int	two;
	int	three;
	int	up;
	int	left;
	int	down;
	int	right;
	int	esc;
	int	minus;
	int	plus;
	int	tab;
}				t_key_set;

typedef struct s_parcing
{
	int		verif;
	int		fd;
	int		len;
	int		i;
	int		y;
	char	**splited;
	char	*line;
	t_list	*list;
	t_list	*new;
}				t_parcing;

typedef struct s_copy
{
	int		z;
	int		x;
	int		len;
	int		error;
	char	**str;
	long	tmp;
}				t_copy;

typedef struct s_dr_map
{
	int	y;
	int	x;
	int	len_x;
	int	len_y;
	int	iso_x;
	int	iso_y;
	int	i;
	int	height;
	int	height2;
}				t_dr_map;

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
	float	t_move;
	float	r_move;
	float	g_move;
	float	b_move;
	int		event;
}				t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_height
{
	long	**z;
	char	***color;
}				t_height;

typedef struct s_point
{
	long			x;
	long			y;
	unsigned int	color;
}				t_point;

typedef struct s_mountain
{
	unsigned int	color;
	long			tmp;
	long			mid;
	long			div;
	long			height;
	long			z;
	long			max_z;
	long			min_z;
}				t_mountain;

typedef struct s_box
{
	t_point			*ci;
	t_point			*c_mid;
	t_point			*ce;
	t_height		*he;
	t_key_set		*key;
	t_data			*img;
	unsigned int	*rainbow;
	void			*mlx_ptr;
	void			*win_ptr;
	int				len;
	int				fd;
	int				move_y;
	int				move_x;
	int				height;
	double			rotate_x;
	double			rotate_y;
	double			rotate_z;
	int				speed;
	unsigned int	color;
	int				color_set;
	long			max_z;
	long			min_z;
	long			var_zi;
	long			var_ze;
}				t_box;

void			dr_pixel(t_data *img, int x, int y, int color);
void			dr_line(t_box *box, int end);
void			ft_swap(t_box *box);
void			addback(t_list **list, t_list *new);
void			list_next(t_list **list);
t_list			*lstnew(char *arg);
long			ft_atoi(char *str);
char			*ft_strdup(char *s1);
int				len_w(char **str);
int				len_c(char *str);
int				close(int keycode);
int				check_color(char *str, int len);
int				check_c(char *splited);
int				key_move(t_box *box);
void			freebox(int error, t_box *box);
void			free_list(t_list *list);
void			free_split(char **splited);
int				p_map(t_box *box, char *argv);
int				ft_copy(t_box *box, char **splited, int y);
int				init_data(t_box *box);
int				key_press(int keycode, t_box *box);
int				key_release(int keycode, t_box *box);
int				scroll(int mouse, int x, int y, t_box *box);
void			dr_map(t_box *box);
unsigned int	hd_to_d(char *str);
void			set_color(t_box *box, int event, t_color *c);
int				add_height(t_box *box, int y, int x);
void			init_dr_map(t_box *box, t_dr_map *m);
unsigned int	init_color(t_box *box, int y, int x, int event);
void			find_delta(t_box *box, int *dy, int *dx);
void			color_scene(t_box *box);
void			rainbow_move(t_box *box, unsigned int *template, int size);
int				check_rectangle(int y, t_copy *c, t_box *box);
void			color_and_pixel(t_box *box, t_color *c);
void			init_rainbow(unsigned int *tab);
unsigned int	rainbow_road(unsigned int *template, int size, int y, int x);
unsigned int	mountain(t_box *box, int y, int x);
void			color_screen( int screen, t_box *box);

#endif
