/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/05/05 19:26:39 by lide             ###   ########.fr       */
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
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53
# define COLOURS 0xE91E63

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
	int	up;
	int	left;
	int	down;
	int	right;
	int	esc;
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
	int	x;
	int	y;
	unsigned int	color;
}				t_point;

typedef struct s_box
{
	t_point		*ci;
	t_point		*ce;
	t_height	*he;
	t_key_set	*key;
	t_data		*img;
	void		*mlx_ptr;
	void		*win_ptr;
	int			len;
	int			fd;
	int			move_y;
	int			move_x;
}				t_box;

void	dr_pixel(t_data *img, int x, int y, int color);
void	dr_line(t_box *box);
void	ft_swap(t_box *box);
void	addback(t_list **list, t_list *new);
void	list_next(t_list **list);
t_list	*lstnew(char *arg);
long	ft_atoi(char *str);
char	*ft_strdup(char *s1);
int		len_w(char **str);
int		len_c(char *str);
int		close(int keycode);
void	dr_pixel(t_data *img, int x, int y, int color);
int		check_color(char *str, int len);
int		check_c(char *splited);
int		key_move(t_box *box);
void	freebox(int error, t_box *box);
void	free_list(t_list *list);
void	free_split(char **splited);
int		p_map(t_box *box, char *argv);
int		ft_copy(t_box *box, char **splited, int y);
int		init_data(t_box *box);
int		key_press(int keycode, t_box *box);
int		key_release(int keycode, t_box *box);
int		scroll(int mouse, int x, int y, t_box *box);
void	test_map(t_box *box);

#endif
