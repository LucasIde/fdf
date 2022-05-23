/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mountain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:02:51 by lide              #+#    #+#             */
/*   Updated: 2022/05/23 15:32:23 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	peak(t_mountain *m)
{
	unsigned int	red;
	unsigned int	green;

	if (m->z == m->max_z)
		return (0xff0000);
	m->div = (m->max_z - m->mid);
	m->height -= m->mid - m->min_z;
	green = (0x00ff00 / (m->div)) * (m->div - m->height);
	if (green > 256)
	green = green - (((0x00ff00 / (m->div)) * (m->div - m->height)) % 256);
	red = ((0xff0000 / (m->div)) * m->height);
	if (red > 65536)
	red = red - (((0xff0000 / (m->div)) * m->height) % 65536);
	m->color = red + green;
	return (m->color);
}

unsigned int	base(t_mountain *m)
{
	unsigned int	green;
	unsigned int	blue;

	if (m->z == m->mid)
		return (0x00ff00);
	else if (m->z == m->min_z)
		return (0x0000ff);
	m->div = (m->mid - m->min_z);
	green = 0x00ff00 / (m->div) * m->height;
	if (green > 256)
		green = green - (((0x00ff00 / (m->div)) * m->height) % 256);
	blue = ((0x0000ff / (double)(m->div)) * (double)(m->div - m->height));
	m->color = green + blue;
	return (m->color);
}

unsigned int	mountain(t_box *box, int y, int x)
{
	t_mountain	m;

	m.z = box->he->z[y][x] * box->height;
	m.max_z = box->max_z * box->height;
	m.min_z = box->min_z * box->height;
	if (m.max_z < m.min_z)
	{
		m.tmp = m.max_z;
		m.max_z = m.min_z;
		m.min_z = m.tmp;
	}
	m.mid = m.max_z - ((m.max_z - m.min_z) / 2);
	m.height = m.z - m.min_z;
	if (m.z >= m.min_z && m.z <= m.mid)
		return (base(&m));
	else
		return (peak(&m));
}
