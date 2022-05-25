/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:13:50 by lide              #+#    #+#             */
/*   Updated: 2022/05/25 17:00:30 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line_ci_i(t_box *box, t_dr_map *m, int event)
{
	long	tmp_x;
	long	tmp_y;
	long	tmp_z;

	box->ci->color = init_color(box, m->y, m->x, event);
	box->ci->y = (m->y + m->iso_y) * box->len;
	box->ci->x = (m->x + m->i - m->iso_x) * box->len;
	box->ci->y -= ((m->len_y / 2) * box->len);
	box->ci->x -= ((m->len_x / 2) * box->len);
	tmp_y = box->ci->y;
	tmp_x = box->ci->x;
	tmp_z = box->he->z[m->y][m->x] * (m->height * box->len);
	rotate_ci(tmp_y, tmp_x, tmp_z, box);
	box->ci->y += box->move_y * box->len;
	box->ci->x += box->move_x * box->len;
	box->ci->y -= box->var_zi;
	box->ci->y += 540 - ((m->len_y / 2) * box->len);
	box->ci->x += 960 - ((m->len_x / 2) * box->len);
}

void	line_xe_i(t_box *box, t_dr_map *m, int event)
{
	long	tmp_x;
	long	tmp_y;
	long	tmp_z;

	box->ce->color = init_color(box, m->y, m->x + 1, event);
	box->ce->y = (m->y + m->iso_y + 1) * box->len;
	box->ce->x = (m->x + m->i + 2 - m->iso_x) * box->len;
	box->ce->y -= ((m->len_y / 2) * box->len);
	box->ce->x -= ((m->len_x / 2) * box->len);
	tmp_y = box->ce->y;
	tmp_x = box->ce->x;
	tmp_z = box->he->z[m->y][m->x + 1] * (m->height2 * box->len);
	rotate_ce(tmp_y, tmp_x, tmp_z, box);
	box->ce->y += box->move_y * box->len;
	box->ce->x += box->move_x * box->len;
	box->ce->y -= box->var_ze;
	box->ce->y += 540 - ((m->len_y / 2) * box->len);
	box->ce->x += 960 - ((m->len_x / 2) * box->len);
}

void	line_ye_i(t_box *box, t_dr_map *m, int event)
{
	long	tmp_x;
	long	tmp_y;
	long	tmp_z;

	box->ce->color = init_color(box, m->y + 1, m->x, event);
	box->ce->y = (m->y + m->iso_y + 1) * box->len;
	box->ce->x = (m->x + m->i - 2 - m->iso_x) * box->len;
	box->ce->y -= ((m->len_y / 2) * box->len);
	box->ce->x -= ((m->len_x / 2) * box->len);
	tmp_y = box->ce->y;
	tmp_x = box->ce->x;
	tmp_z = box->he->z[m->y + 1][m->x] * (m->height2 * box->len);
	rotate_ce(tmp_y, tmp_x, tmp_z, box);
	box->ce->y += box->move_y * box->len;
	box->ce->x += box->move_x * box->len;
	box->ce->y -= box->var_ze;
	box->ce->y += 540 - ((m->len_y / 2) * box->len);
	box->ce->x += 960 - ((m->len_x / 2) * box->len);
}

void	line_x_i(t_box *box, t_dr_map *m, int event)
{
	line_ci_i(box, m, event);
	line_xe_i(box, m, event);
	dr_line(box, event);
}

void	line_y_i(t_box *box, t_dr_map *m, int event)
{
	line_ci_i(box, m, event);
	line_ye_i(box, m, event);
	dr_line(box, event);
}
