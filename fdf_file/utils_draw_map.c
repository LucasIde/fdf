/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:59:05 by lide              #+#    #+#             */
/*   Updated: 2022/05/17 19:24:25 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	add_height(t_box *box, int y, int x)
{
	if (box->he->z[y][x] != 0)
		return (box->height);
	else
		return (1);
}

void	init_dr_map(t_box *box, t_dr_map *m)
{
	m->len_x = 0;
	m->len_y = 0;
	while (box->he->z[0][m->len_x] != 2147483649)
		m->len_x++;
	while (box->he->z[m->len_y])
		m->len_y++;
	m->y = -1;
	m->iso_x = 0;
	m->i = 0;
}

void	color_screen( int screen, t_box *box)
{
	int	y;
	int	x;
	unsigned int color;

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

unsigned int inverted(int event)
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

void	color_and_pixel(t_box *box, t_color *c)
{
	set_color(box, 1, c);
	dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
}
