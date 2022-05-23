/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:04:56 by lide              #+#    #+#             */
/*   Updated: 2022/05/23 15:06:08 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_scene(t_box *box)
{
	if (box->key->zero == 1 && box->key->one == 0 && box->key->two == 0
		&& box->key->three == 0)
		box->color_set = 0;
	else if (box->key->zero == 0 && box->key->one == 1 && box->key->two == 0
		&& box->key->three == 0)
		box->color_set = 1;
	else if (box->key->zero == 0 && box->key->one == 0 && box->key->two == 1
		&& box->key->three == 0)
		box->color_set = 2;
	else if (box->key->zero == 0 && box->key->one == 0 && box->key->two == 0
		&& box->key->three == 1)
		box->color_set = 3;
}

void	color_screen( int screen, t_box *box)
{
	int				y;
	int				x;
	unsigned int	color;

	color = 0;
	if (screen == 1)
		color = 0x0;
	else if (screen == 0)
		color = 0x01ffffff;
	y = -1;
	while (++y < 1080)
	{
		x = -1;
		while (++x < 1920)
		{
			dr_pixel(box->img, x, y, color);
		}
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img, 0, 0);
}

unsigned int	inverted(int event)
{
	if (event == 0)
		return (0x0);
	else
		return (0xffffff);
}

unsigned int	init_color(t_box *box, int y, int x, int event)
{
	if (box->color_set == 3)
		return (inverted(event));
	if (event == 0)
	{
		if (box->color_set == 0)
		{
			if (!*box->he->color[y][x])
				return (0xffffff);
			else
				return (hd_to_d(box->he->color[y][x]));
		}
		else if (box->color_set == 1)
			return (rainbow_road(box->rainbow, 7, y, x));
		else
			return (mountain(box, y, x));
	}
	else
		return (0x0);
}
