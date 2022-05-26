/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:32:57 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 16:47:36 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_box
{
	t_point			*ci;
	t_point			*c_mid;
	t_point			*ce;
	t_height		*he;
	t_data			*img;
	void			*mlx_ptr;
	void			*win_ptr;
	int				len;
	int				height;
	unsigned int	color;
}				t_box;

#endif
