/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:45:33 by lide              #+#    #+#             */
/*   Updated: 2022/05/20 20:32:43 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_ci(double y, double x, double z, t_box *box)
{
	box->ci->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_zi = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
	z = box->var_zi;
	box->ci->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_zi = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
	x = box->ci->x;
	y = box->ci->y;
	box->ci->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ci->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
}

void	rotate_ce(double y, double x, double z, t_box *box)
{
	box->ce->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
	box->var_ze = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
	z = box->var_ze;
	box->ce->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
	box->var_ze = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
	x = box->ce->x;
	y = box->ce->y;
	box->ce->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
	box->ce->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
}

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

void	need_help(t_box *box, int screen)
{
	if (screen == 1)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0x0, HELP);
	if (screen == 0)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0xffffff, HELP);
}

void	color_help(t_box *box, int screen)
{
	int				y;
	int				x;
	unsigned int	color;

	color = 0;
	if (screen == 0)
		color = 0x0;
	else if (screen == 1)
		color = 0x01ffffff;
	y = -1;
	while (++y < 60)
	{
		x = -1;
		while (++x < 1500)
		{
			dr_pixel(box->img, x, y, color);
		}
	}
}

void	display_help(t_box *box, int screen)
{
	unsigned int	color;

	if (screen == 1)
		color = 0x0;
	if (screen == 0)
		color = 0xffffff;
	mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, color, H_COLOR);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 30, color, H_RAINBOW);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 310, 10, color, H_HEIGHT);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 310, 30, color, H_ROTATION);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 670, 10, color, H_SIZE);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 670, 30, color, H_MOVE);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1050, 10, color, H_RESET);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1050, 30, color, H_VIEW);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1350, 10, color, H_QUIT);
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
	if (box->key->tab == 1)
		color_help(box, screen);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	if (box->key->tab == 0)
		need_help(box, screen);
	else
		display_help(box, screen);
	point_finder(box, &m, 1);
}
