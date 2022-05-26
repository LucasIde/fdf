/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:33 by lide              #+#    #+#             */
/*   Updated: 2022/05/25 19:12:33 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	point_x(t_box *box, t_dr_map *m, int event)
{
	m->height = add_height(box, m->y, m->x);
	m->height2 = add_height(box, m->y, m->x + 1);
	if (box->view == 0)
		line_x_i(box, m, event);
	else
		line_x_p(box, m, event);
}

void	point_y(t_box *box, t_dr_map *m, int event)
{
	m->height = add_height(box, m->y, m->x);
	m->height2 = add_height(box, m->y + 1, m->x);
	if (box->view == 0)
		line_y_i(box, m, event);
	else
		line_y_p(box, m, event);
}

void	point_finder(t_box *box, t_dr_map *m, int event)
{
	init_dr_map(box, m);
	while (++m->y < m->len_y)
	{
		m->x = -1;
		m->iso_y = 0;
		while (++m->x < m->len_x)
		{
			if (m->x < m->len_x && box->he->z[m->y][m->x + 1] != 2147483649)
				point_x(box, m, event);
			if (m->y < m->len_y && box->he->z[m->y + 1])
				point_y(box, m, event);
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
	static int		screen;

	if (box->color_set == 3)
	{
		if (screen == 0)
		{
			color_screen(screen, box);
			screen = 1;
		}
	}
	else if (screen == 1)
	{
		color_screen(screen, box);
		screen = 0;
	}
	point_finder(box, &m, 0);
	if (box->help == 1)
		color_help(box, screen);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	if (box->help == 0)
		need_help(box, screen);
	else
		help_display(box, screen);
	point_finder(box, &m, 1);
}
