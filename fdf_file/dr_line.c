/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/03 19:08:51 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	case1(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (box->ci->y < 1081 && box->ci->x < 1921)
		dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	while (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y
		&& box->ce->y < 1081 && box->ce->x < 1921
		&& box->ce->x > -1 && box->ce->y > -1)
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
		if (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y)
			dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case2(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	if (box->ci->y < 1081 && box->ci->x < 1921)
		dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	while (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y
		&& box->ce->y < 1081 && box->ce->x < 1921
		&& box->ce->x > -1 && box->ce->y > -1)
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
		if (box->ci->x <= box->ce->x && box->ci->y <= box->ce->y)
			dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case3(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	if (box->ci->y < 1081 && box->ci->x < 1921)
		dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	while (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y
		&& box->ce->y < 1081 && box->ce->x < 1921
		&& box->ce->x > -1 && box->ce->y > -1)
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
		if (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y)
			dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case4(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	if (box->ci->y < 1081 && box->ci->x < 1921)
		dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	while (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y
		&& box->ce->y < 1081 && box->ce->x < 1921
		&& box->ce->x > -1 && box->ce->y > -1)
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
		if (box->ce->x <= box->ci->x && box->ce->y >= box->ci->y)
			dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	dr_line(t_box *box)
{
	int	dx;
	int	dy;

	ft_swap(box);
	if (box->ce->x >= box->ci->x)
		dx = box->ce->x - box->ci->x;
	else if (box->ce->x < box->ci->x)
		dx = box->ci->x - box->ce->x;
	dy = box->ce->y - box->ci->y;
	// dr_pixel(box->img, box->ci->x, box->ci->y, COLOURS);
	printf(" x = |%d , %d|\n", box->ci->x, box->ci->y);
	if (box->ce->x >= box->ci->x)
	{
		if (dx >= dy)
			case1(box, dx, dy);
		else if (dx < dy)
			case2(box, dx, dy);
	}
	else if (box->ce->x < box->ci->x)
	{
		if (dx > dy)
			case3(box, dx, dy);
		else if (dx <= dy)
			case4(box, dx, dy);
	}
}
