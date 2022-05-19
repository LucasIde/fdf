/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:33 by lide              #+#    #+#             */
/*   Updated: 2022/05/19 19:25:24 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_axis(t_box *box, t_dr_map *m)
{
	double	y;
	double	z;

	y = box->ci->y;
	z = box->he->z[m->y][m->x] * (m->height * box->len);
	box->ci->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_zi = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
	y = box->ce->y;
	z = box->he->z[m->y][m->x + 1] * (m->height2 * box->len);
	box->ce->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_ze = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
}

void	y_axis(t_box *box)
{
	double	x;
	double	z;

	x = box->ci->x;
	z = box->var_zi;
	box->ci->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_zi = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
	x = box->ce->x;
	z = box->var_ze;
	box->ce->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_ze = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
}

void	z_axis(t_box *box)
{
	double	x;
	double	y;

	x = box->ci->x;
	y = box->ci->y;
	box->ci->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ci->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
	x = box->ce->x;
	y = box->ce->y;
	box->ce->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ce->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
}

void	x_axis2(t_box *box, t_dr_map *m)
{
	double	y;
	double	z;

	y = box->ci->y;
	z = box->he->z[m->y][m->x] * (m->height * box->len);
	box->ci->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_zi = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
	y = box->ce->y;
	z = box->he->z[m->y + 1][m->x] * (m->height2 * box->len);
	box->ce->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_ze = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
}

void	y_axis2(t_box *box)
{
	double	x;
	double	z;

	x = box->ci->x;
	z = box->var_zi;
	box->ci->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_zi = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
	x = box->ce->x;
	z = box->var_ze;
	box->ce->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_ze = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
}

void	z_axis2(t_box *box)
{
	double	x;
	double	y;

	x = box->ci->x;
	y = box->ci->y;
	box->ci->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ci->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
	x = box->ce->x;
	y = box->ce->y;
	box->ce->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ce->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
}

void	line_x(t_box *box, t_dr_map *m, int event)
{
	box->ci->color = init_color(box, m->y, m->x, event);
	box->ce->color = init_color(box, m->y, m->x + 1, event);
	box->ci->y = m->y + m->iso_y;
	box->ci->y = (box->ci->y * box->len);
	box->ce->y = m->y + m->iso_y + 1;
	box->ce->y = (box->ce->y * box->len);
	box->ci->x = m->x + m->i - m->iso_x;
	box->ci->x = (box->ci->x * box->len);
	box->ce->x = m->x + m->i + 2 - m->iso_x;
	box->ce->x = (box->ce->x * box->len);
	box->ci->y -= ((m->len_y / 2) * box->len);
	box->ce->y -= ((m->len_y / 2) * box->len);
	box->ci->x -= ((m->len_x / 2) * box->len);
	box->ce->x -= ((m->len_x / 2) * box->len);
	x_axis(box, m);
	y_axis(box);
	z_axis(box);
	box->ci->y += box->move_y * box->len;
	box->ce->y += box->move_y * box->len;
	box->ci->x += box->move_x * box->len;
	box->ce->x += box->move_x * box->len;
	box->ci->y -= box->var_zi;
	box->ce->y -= box->var_ze;
	box->ci->y += 540 - ((m->len_y / 2) * box->len);
	box->ce->y += 540 - ((m->len_y / 2) * box->len);
	box->ci->x += 960 - ((m->len_x / 2) * box->len);
	box->ce->x += 960 - ((m->len_x / 2) * box->len);
	dr_line(box, event);
}

void	line_y(t_box *box, t_dr_map *m, int event)
{
	box->ci->color = init_color(box, m->y, m->x, event);
	box->ce->color = init_color(box, m->y + 1, m->x, event);
	box->ci->y = m->y + m->iso_y;
	box->ci->y = (box->ci->y * box->len);
	box->ce->y = m->y + m->iso_y + 1;
	box->ce->y = (box->ce->y * box->len);
	box->ci->x = m->x + m->i - m->iso_x;
	box->ci->x = (box->ci->x * box->len);
	box->ce->x = m->x + m->i - 2 - m->iso_x;
	box->ce->x = (box->ce->x * box->len);
	box->ci->y -= ((m->len_y / 2) * box->len);
	box->ce->y -= ((m->len_y / 2) * box->len);
	box->ci->x -= ((m->len_x / 2) * box->len);
	box->ce->x -= ((m->len_x / 2) * box->len);
	x_axis2(box, m);
	y_axis2(box);
	z_axis2(box);
	box->ci->y += box->move_y * box->len;
	box->ce->y += box->move_y * box->len;
	box->ci->x += box->move_x * box->len;
	box->ce->x += box->move_x * box->len;
	box->ci->y -= box->var_zi;
	box->ce->y -= box->var_ze;
	box->ci->y += 540 - ((m->len_y / 2) * box->len);
	box->ce->y += 540 - ((m->len_y / 2) * box->len);
	box->ci->x += 960 - ((m->len_x / 2) * box->len);
	box->ce->x += 960 - ((m->len_x / 2) * box->len);
	dr_line(box, event);
}

// void	line_x(t_box *box, t_dr_map *m, int event)
// {
// 	box->ci->color = init_color(box, m->y, m->x, event);
// 	box->ce->color = init_color(box, m->y, m->x + 1, event);
// 	box->ci->y = m->y * box->len;
// 	box->ce->y = m->y * box->len;
// 	box->ci->x = m->x * box->len;
// 	box->ce->x = (m->x + 1) * box->len;
// 	box->ci->y -= ((m->len_y / 2) * box->len);
// 	box->ce->y -= ((m->len_y / 2) * box->len);
// 	box->ci->x -= ((m->len_x / 2) * box->len);
// 	box->ce->x -= ((m->len_x / 2) * box->len);
// 	x_axis(box, m);
// 	y_axis(box);
// 	z_axis(box);
// 	box->ci->y -= box->var_zi;
// 	box->ce->y -= box->var_ze;
// 	box->ci->y += box->move_y * box->len;
// 	box->ce->y += box->move_y * box->len;
// 	box->ci->x += box->move_x * box->len;
// 	box->ce->x += box->move_x * box->len;
// 	box->ci->y *= sin(0.785398);
// 	box->ce->y *= sin(0.785398);
// 	box->ci->x *= cos(0.785398);
// 	box->ce->x *= cos(0.785398);
// 	box->ci->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ce->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ci->x += 960 - ((m->len_x / 2) * box->len);
// 	box->ce->x += 960 - ((m->len_x / 2) * box->len);
// 	dr_line(box, event);
// }

// void	line_y(t_box *box, t_dr_map *m, int event)
// {
// 	box->ci->color = init_color(box, m->y, m->x, event);
// 	box->ce->color = init_color(box, m->y + 1, m->x, event);
// 	box->ci->y = m->y * box->len;
// 	box->ce->y = (m->y + 1) * box->len;
// 	box->ci->x = m->x * box->len;
// 	box->ce->x = m->x * box->len;
// 	box->ci->y -= ((m->len_y / 2) * box->len);
// 	box->ce->y -= ((m->len_y / 2) * box->len);
// 	box->ci->x -= ((m->len_x / 2) * box->len);
// 	box->ce->x -= ((m->len_x / 2) * box->len);
// 	x_axis2(box, m);
// 	y_axis2(box);
// 	z_axis2(box);
// 	box->ci->y -= box->var_zi;
// 	box->ce->y -= box->var_ze;
// 	box->ci->y += box->move_y * box->len;
// 	box->ce->y += box->move_y * box->len;
// 	box->ci->x += box->move_x * box->len;
// 	box->ce->x += box->move_x * box->len;
// 	box->ci->y *= sin(0.785398);
// 	box->ce->y *= sin(0.785398);
// 	box->ci->x *= cos(0.785398);
// 	box->ce->x *= cos(0.785398);
// 	box->ci->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ce->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ci->x += 960 - ((m->len_x / 2) * box->len);
// 	box->ce->x += 960 - ((m->len_x / 2) * box->len);
// 	dr_line(box, event);
// }

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
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y, m->x + 1);
				line_x(box, m, event);
			}
			if (m->y < m->len_y && box->he->z[m->y + 1])
			{
				m->height = add_height(box, m->y, m->x);
				m->height2 = add_height(box, m->y + 1, m->x);
				line_y(box, m, event);
			}
			m->i++;
			m->iso_y++;
		}
		m->i = 0;
		m->iso_x += 2;
	}
}

void	need_help(t_box *box, int screen)
{
	if (screen == 1)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0x0, "press tab for help");
	if (screen == 0)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0xffffff, "press tab for help");
}

void	display_help(t_box *box, int screen)
{
	unsigned int color;

	if (screen == 1)
		color = 0x0;
	if (screen == 0)
		color = 0xffffff;
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, color, "color template = 0|1|2|3");
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 30, color, "rotate = w");
}

void	dr_map(t_box *box)
{
	t_dr_map		m;
	static int	screen;

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
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	if (box->key->tab == 0)
		need_help(box, screen);
	else
		display_help(box, screen);
	point_finder(box, &m, 1);
}
