/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:33 by lide              #+#    #+#             */
/*   Updated: 2022/05/09 23:15:58 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	angle(t_box *box)
{
	unsigned int	x;
	unsigned int	y;

	x = box->ci->x;
	y = box->ci->y;
	box->ci->x = (x * cos(30)) - (y * sin(30));
	box->ci->y = (x * sin(30)) + (y * cos(30));
	x = box->ce->x;
	y = box->ce->y;
	box->ce->x = (x * cos(30)) - (y * sin(30));
	box->ce->y = (x * sin(30)) + (y * cos(30));
	printf("%d\n", box->ce->y);
}

void	line_x(t_box *box, t_dr_map *m)
{
	box->ci->y = m->y + m->iso_y - (box->he->z[m->y][m->x] * m->height);
	box->ci->y += box->move_y;
	box->ci->y = (box->ci->y * box->len) + (540 - ((m->len_y / 2) * box->len));
	box->ce->y = m->y + m->iso_y + 1 - (box->he->z[m->y][m->x + 1] * m->height2);
	box->ce->y += box->move_y;
	box->ce->y = (box->ce->y * box->len) + (540 - ((m->len_y / 2) * box->len));
	box->ci->x = m->x + m->i - m->iso_x;
	box->ci->x += box->move_x;
	box->ci->x = (box->ci->x * box->len) + (970 - (m->len_x / 2) * box->len);
	box->ce->x = m->x + m->i + 2 - m->iso_x;
	box->ce->x += box->move_x;
	box->ce->x = (box->ce->x * box->len) + (970 - (m->len_x / 2) * box->len);
	// angle(box);
	dr_line(box);
}

void	line_y(t_box *box, t_dr_map *m)
{
	box->ci->y = m->y + m->iso_y - (box->he->z[m->y][m->x] * m->height);
	box->ci->y += box->move_y;
	box->ci->y = (box->ci->y * box->len) + (540 - ((m->len_y / 2) * box->len));
	box->ce->y = m->y + m->iso_y + 1 - (box->he->z[m->y + 1][m->x] * m->height2);
	box->ce->y += box->move_y;
	box->ce->y = (box->ce->y * box->len) + (540 - ((m->len_y / 2) * box->len));
	box->ci->x = m->x + m->i - m->iso_x;
	box->ci->x += box->move_x;
	box->ci->x = (box->ci->x * box->len) + (970 - (m->len_x / 2) * box->len);
	box->ce->x = m->x + m->i - 2 - m->iso_x;
	box->ce->x += box->move_x;
	box->ce->x = (box->ce->x * box->len) + (970 - (m->len_x / 2) * box->len);
	// angle(box);
	dr_line(box);
}

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

unsigned int	init_color(t_box *box, int y, int x, int event)
{
	if (event == 0)
	{
		if (!*box->he->color[y][x])
			return (0xffffff);
		else
			return (hd_to_d(box->he->color[y][x]));
	}
	else
		return (0x0);
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
			{
				box->ci->color = init_color(box, m->y, m->x, event);
				box->ce->color = init_color(box, m->y, m->x + 1, event);
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y, m->x + 1);
				line_x(box, m);
			}
			if (m->y < m->len_y && box->he->z[m->y + 1])
			{
				box->ce->color = init_color(box, m->y + 1, m->x, event);
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y + 1, m->x);
				line_y(box, m);
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

	if (box->he->color)
	point_finder(box, &m, 0);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	point_finder(box, &m, 1);
}
