/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:32:57 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:17:56 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

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
	int	i;
	int	p;
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
	int				view;
	int				help;
}				t_box;

#endif
