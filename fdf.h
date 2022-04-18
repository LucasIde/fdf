/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/04/18 19:22:27 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_box
{
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
}				t_box;

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# define KEY_W 13
# define SPEED 100
# define COLOURS 0x8fE74C3C

#endif
