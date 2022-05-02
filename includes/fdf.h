/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/05/02 18:25:45 by lide             ###   ########.fr       */
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
# define SPEED 150
# define COLOURS 16711680

typedef struct s_list
{
	int				line;
	void			*content;
	struct s_list	*next;
	struct s_list	*before;
}				t_list;

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
	int		verif;
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
}				t_point;

typedef struct s_box
{
	// t_point	*ci;
	// t_point	*ct;
	// t_point	*ce;
	t_height	*he;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		*img;
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
int		ft_key(int keycode, t_box *box);
void	freebox(int error, t_box *box);
void	free_list(t_list *list);
void	free_split(char **splited);
int		p_map(t_box *box, char *argv);
int		ft_copy(t_box *box, char **splited, int y);
int		init_data(t_box *box);

#endif
