/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:59:05 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 19:27:43 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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

int	add_height(t_box *box, int y, int x)
{
	if (box->he->z[y][x] != 0)
		return (box->height);
	else
		return (1);
}

void	init_dr_map(t_box *box, t_dr_map *m, int event)
{
	int	x;
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
		x = 960 + (box->move_x * box->len);
		y = (box->move_y - (box->he->z[0][0] * box->height)) * box->len;
		y = 540 + y;
		box->color = init_color(box, 0, 0, event);
		if (x < 1920 && y < 1080 && x > -1 && y > -1)
			dr_pixel(box->img, x, y, box->color);
	}
}

int	check_empty_line(t_parcing *p)
{
	while (p->list->next != NULL && p->list->line != -1)
		p->list = p->list->next;
	if (p->list->next == NULL && ((char *)p->list->content)[0] == '\0')
		return (-1);
	while (p->list->next != NULL && p->list->next->line != -1)
	{
		if (((char *)p->list->content)[0] == '\0')
			return (-1);
		p->list = p->list->next;
	}
	if (((char *)p->list->content)[0] == '\0')
		return (-1);
	if (p->list->next != NULL)
		p->list = p->list->next;
	return (0);
}
