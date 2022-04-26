/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/04/26 16:33:05 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# define KEY_W 13
# define SPEED 150
# define COLOURS 0x8fE74C3C

typedef struct s_list
{
	int				line;
	void			*content;
	struct s_list	*next;
	struct s_list	*before;
}				t_list;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_box
{
	t_point	*ci;
	t_point	*ct;
	t_point	*ce;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
}				t_box;

void	dr_line(t_box *box);
void	ft_swap(t_box *box);
void	dr_pixel(t_data *img, int x, int y, int color);

#endif
