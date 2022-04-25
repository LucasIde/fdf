/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/04/25 20:58:05 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case1(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	dr_pixel(box->img, box->ci->x, box->ci->y, 0xbaaaaa);
	while (box->ci->x <= box->ct->x && box->ci->y <= box->ct->y
		&& box->ct->y < 1081 && box->ct->x < 1921
		&& box->ct->x > -1 && box->ct->y > -1)
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
		dr_pixel(box->img, box->ci->x, box->ci->y, 0xbaaaaa);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case2(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	dr_pixel(box->img, box->ci->x, box->ci->y, 0xE74C3C);
	while (box->ci->x <= box->ct->x && box->ci->y <= box->ct->y
		&& box->ct->y < 1081 && box->ct->x < 1921
		&& box->ct->x > -1 && box->ct->y > -1)
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
		dr_pixel(box->img, box->ci->x, box->ci->y, 0xE74C3C);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case3(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	dr_pixel(box->img, box->ci->x, box->ci->y, 0xB22222);
	while (box->ct->x <= box->ci->x && box->ct->y >= box->ci->y
		&& box->ct->y < 1081 && box->ct->x < 1921
		&& box->ct->x > -1 && box->ct->y > -1)
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
		dr_pixel(box->img, box->ci->x, box->ci->y, 0xB22222);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case4(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	dr_pixel(box->img, box->ci->x, box->ci->y, 0xB88888);
	while (box->ct->x <= box->ci->x && box->ct->y >= box->ci->y
		&& box->ct->y < 1081 && box->ct->x < 1921
		&& box->ct->x > -1 && box->ct->y > -1)
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
		dr_pixel(box->img, box->ci->x, box->ci->y, 0xB88888);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	dr_line(t_box *box)
{
	int	dx;
	int	dy;

	ft_swap(box);
	if (box->ct->x >= box->ci->x)
		dx = box->ct->x - box->ci->x;
	else if (box->ct->x < box->ci->x)
		dx = box->ci->x - box->ct->x;
	dy = box->ct->y - box->ci->y;
	if (box->ct->x >= box->ci->x)
	{
		if (dx >= dy)
			case1(box, dx, dy);
		else if (dx < dy)
			case2(box, dx, dy);
	}
	else if (box->ct->x < box->ci->x)
	{
		if (dx > dy)
			case3(box, dx, dy);
		else if (dx <= dy)
			case4(box, dx, dy);
	}
}
