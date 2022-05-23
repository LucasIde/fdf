/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:59:05 by lide              #+#    #+#             */
/*   Updated: 2022/05/23 16:30:11 by lide             ###   ########.fr       */
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
