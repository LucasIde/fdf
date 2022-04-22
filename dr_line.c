/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/04/22 08:51:50 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	case1(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	while (box->x <= box->x_e && box->y <= box->y_e && box->y_e < 1081
		&& box->x_e < 1921 && box->x_e > -1 && box->y_e > -1)
	{
		if (p < 0)
		{
			p = p + (2 * dy);
			box->x++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dy - dx));
			box->x++;
			box->y++;
		}
		printf("x init %d | y init %d | x end %d | y end %d\n", box->x, box->y, box->x_e, box->y_e);
		dr_pixel(box->img, box->x, box->y, 0xE74C3C);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case2(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	while (box->x <= box->x_e && box->y <= box->y_e && box->y_e < 1081
		&& box->x_e < 1921 && box->x_e > -1 && box->y_e > -1)
	{
		if (p <= 0)
		{
			p = p + (2 * dx);
			box->y++;
		}
		else if (p > 0)
		{
			p = p + (2 * (dx - dy));
			box->x++;
			box->y++;
		}
		printf("x init %d | y init %d | x end %d | y end %d\n", box->x, box->y, box->x_e, box->y_e);
		dr_pixel(box->img, box->x, box->y, 0xE74C3C);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case3(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dy - dx);
	while (box->x <= box->x_e && box->y <= box->y_e && box->y_e < 1081
		&& box->x_e < 1921 && box->x_e > -1 && box->y_e > -1)
	{
		if (p <= 0)
		{
			p = p + (2 * dy);
			box->x--;
		}
		else if (p > 0)
		{
			p = p + (2 * (dy - dx));
			box->x--;
			box->y++;
		}
		printf("x init %d | y init %d | x end %d | y end %d\n", box->x, box->y, box->x_e, box->y_e);
		dr_pixel(box->img, box->x, box->y, 0xE74C3C);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	case4(t_box *box, int dx, int dy)
{
	int	p;

	p = 2 * (dx - dy);
	while (box->x <= box->x_e && box->y <= box->y_e && box->y_e < 1081
		&& box->x_e < 1921 && box->x_e > -1 && box->y_e > -1)
	{
		if (p < 0)
		{
			p = p + (2 * dx);
			box->y++;
		}
		else if (p >= 0)
		{
			p = p + (2 * (dx - dy));
			box->x-- ;
			box->y++;
		}
		printf("x init %d | y init %d | x end %d | y end %d\n", box->x, box->y, box->x_e, box->y_e);
		dr_pixel(box->img, box->x, box->y, 0xE74C3C);
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

void	dr_line(t_box *box)
{
	int	dx;
	int	dy;

	if (box->y > box->y_e)
		ft_swap(box);
	if (box->x_e >= box->x)
		dx = box->x_e - box->x;
	else if (box->x_e < box->x)
		dx = box->x - box->x_e;
	dy = box->y_e - box->y;
	if (box->x_e >= box->x)
	{
		if (dx >= dy)
			case1(box, dx, dy);
		else if (dx < dy)
			case2(box, dx, dy);
	}
	else if (box->x_e < box->x)
	{
		if (dx > dy)
			case3(box, dx, dy);
		else if (dx <= dy)
			case4(box, dx, dy);
	}
}
