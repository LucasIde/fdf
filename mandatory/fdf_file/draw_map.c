/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:33 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 19:26:02 by lide             ###   ########.fr       */
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

void	init_dr_map(t_box *box, t_dr_map *m, int event)
{
	int	y;

	m->len_x = 0;
	m->len_y = 0;
	while (box->he->z[0][m->len_x] != 2147483649)
		m->len_x++;
	while (box->he->z[m->len_y])
		m->len_y++;
	m->y = -1;
	m->iso_x = 0;
	m->i = 0;
	if (m->len_x == 1 && m->len_y == 1)
	{
		y = 540 + (box->he->z[0][0] * box->len);
		box->color = init_color(box, 0, 0, event);
		if (y < 1080 && y > -1)
			dr_pixel(box->img, 960, y, box->color);
	}
}

void	point_finder(t_box *box, t_dr_map *m, int event)
{
	init_dr_map(box, m, event);
	while (++m->y < m->len_y)
	{
		m->x = -1;
		m->iso_y = 0;
		while (++m->x < m->len_x)
		{
			if (m->x < m->len_x && box->he->z[m->y][m->x + 1] != 2147483649)
			{
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y, m->x + 1);
				line_x_i(box, m, event);
			}
			if (m->y < m->len_y && box->he->z[m->y + 1])
			{
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y + 1, m->x);
				line_y_i(box, m, event);
			}
			m->i++;
			m->iso_y++;
		}
		m->i = 0;
		m->iso_x += 2;
	}
}

void	dr_map(t_box *box)
{
	t_dr_map		m;

	point_finder(box, &m, 0);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	point_finder(box, &m, 1);
}
