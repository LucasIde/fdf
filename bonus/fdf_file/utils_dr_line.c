/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dr_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:11:12 by lide              #+#    #+#             */
/*   Updated: 2022/05/23 15:12:55 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_and_pixel(t_box *box, t_color *c)
{
	set_color(box, 1, c);
	dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
}

void	find_delta(t_box *box, int *dy, int *dx)
{
	if (box->ce->x >= box->ci->x)
		*dx = box->ce->x - box->ci->x;
	else if (box->ce->x < box->ci->x)
		*dx = box->ci->x - box->ce->x;
	*dy = box->ce->y - box->ci->y;
}

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
