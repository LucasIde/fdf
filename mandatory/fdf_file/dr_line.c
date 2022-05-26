/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/18 20:06:38 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	case1(t_box *box, int dx, int dy, t_color *c)
{
	int	p;

	p = 2 * (dy - dx);
	if (box->ci->y < 1080 && box->ci->x < 1920
		&& box->ci->x > -1 && box->ci->y > -1)
		dr_pixel(box->img, box->ci->x, box->ci->y, box->ci->color);
	while (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y)
	{
		if (p < 0)
		{
			p = p + (2 * dy);
			box->ci->x++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dy - dx));
			box->ci->x++;
			box->ci->y++;
		}
		if (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y
			&& box->ci->y < 1080 && box->ci->x < 1920
			&& box->ci->x > -1 && box->ci->y > -1)
			color_and_pixel(box, c);
	}
}

void	case2(t_box *box, int dx, int dy, t_color *c)
{
	int	p;

	p = 2 * (dx - dy);
	if (box->ci->y < 1080 && box->ci->x < 1920
		&& box->ci->x > -1 && box->ci->y > -1)
		dr_pixel(box->img, box->ci->x, box->ci->y, box->ci->color);
	while (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y)
	{
		if (p <= 0)
		{
			p = p + (2 * dx);
			box->ci->y++;
		}
		else if (p > 0)
		{
			p = p + (2 * (dx - dy));
			box->ci->x++;
			box->ci->y++;
		}
		if (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y
			&& box->ci->y < 1080 && box->ci->x < 1920
			&& box->ci->x > -1 && box->ci->y > -1)
			color_and_pixel(box, c);
	}
}

void	case3(t_box *box, int dx, int dy, t_color *c)
{
	int	p;

	p = 2 * (dy - dx);
	if (box->ci->y < 1080 && box->ci->x < 1920
		&& box->ci->x > -1 && box->ci->y > -1)
		dr_pixel(box->img, box->ci->x, box->ci->y, box->ci->color);
	while (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y)
	{
		if (p <= 0)
		{
			p = p + (2 * dy);
			box->ci->x--;
		}
		else if (p > 0)
		{
			p = p + (2 * (dy - dx));
			box->ci->x--;
			box->ci->y++;
		}
		if (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y
			&& box->ci->y < 1080 && box->ci->x < 1920
			&& box->ci->x > -1 && box->ci->y > -1)
			color_and_pixel(box, c);
	}
}

void	case4(t_box *box, int dx, int dy, t_color *c)
{
	int	p;

	p = 2 * (dx - dy);
	if (box->ci->y < 1080 && box->ci->x < 1920
		&& box->ci->x > -1 && box->ci->y > -1)
		dr_pixel(box->img, box->ci->x, box->ci->y, box->ci->color);
	while (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y)
	{
		if (p < 0)
		{
			p = p + (2 * dx);
			box->ci->y++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dx - dy));
			box->ci->x--;
			box->ci->y++;
		}
		if (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y
			&& box->ci->y < 1080 && box->ci->x < 1920
			&& box->ci->x > -1 && box->ci->y > -1)
			color_and_pixel(box, c);
	}
}

void	dr_line(t_box *box, int event)
{
	t_color	c;
	int		dx;
	int		dy;

	c.event = event;
	ft_swap(box);
	find_delta(box, &dy, &dx);
	set_color(box, 0, &c);
	if (box->ce->x >= box->ci->x)
	{
		if (dx >= dy)
			case1(box, dx, dy, &c);
		else if (dx < dy)
			case2(box, dx, dy, &c);
	}
	else if (box->ce->x < box->ci->x)
	{
		if (dx > dy)
			case3(box, dx, dy, &c);
		else if (dx <= dy)
			case4(box, dx, dy, &c);
	}
}
