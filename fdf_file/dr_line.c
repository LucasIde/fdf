/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/11 00:24:46 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_dif(t_box *box)
{
	int	dif;
	int x;
	int y;

	dif = 0;
	x = box->ce->x - box->ci->x;
	y = box->ce->y - box->ci->y;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	dif = x + y;
	return (dif);
}

void	init_trgb(t_color *c)
{
	c->t = 0;
	c->r = 0;
	c->g = 0;
	c->b = 0;
}

void	set_trgb(t_color *c, unsigned int color, unsigned int exp, int i)
{
	init_trgb(c);
	while (i >= 0)
	{
		if (i == 7 && color >= 268435456)
			c->t += 16;
		else if (i == 6 && color >= 16777216)
			c->t++;
		else if (i == 5 && color >= 1048576)
			c->r += 16;
		else if (i == 4 && color >= 65536)
			c->r++;
		else if (i == 3 && color >= 4096)
			c->g += 16;
		else if (i == 2 && color >= 256)
			c->g++;
		else if (i == 1 && color >= 16)
			c->b += 16;
		else if (i == 0 && color >= 1)
			c->b++;
		exp = pow(16, i);
		if (color >= exp)
			color -= exp;
		else
			i--;
	}
}

void	color_dif(t_box *box, t_color *c)
{
	t_color	c_i;
	set_trgb(&c_i, box->ci->color, 0, 7);
	set_trgb(c, box->ce->color, 0, 7);
	c->t -= c_i.t;
	c->r -= c_i.r;
	c->g -= c_i.g;
	c->b -= c_i.b;
	// printf("ct = %u | cti = %u\n", c->t, c_i.t);
	// printf("cr = %u | cri = %u\n", c->r, c_i.r);
	// printf("cg = %u | ctg = %u\n", c->g, c_i.g);
	// printf("cb = %u | ctb = %u\n", c->b, c_i.b);
}

void	set_color(t_box *box, int event, t_color *c)
{
	static unsigned int	dif;
	static unsigned int	traveled;

	if (c->event == 1 || box->ci->color == box->ce->color)
		box->color = box->ci->color;
	else if (event == 0)
	{
		dif = 0;
		traveled = 0;
		dif = find_dif(box);
		color_dif(box, c);
		// printf("ct == %d\n", c->t);
		c->t_move = (float)c->t / dif;
		c->r_move = (float)c->r / dif;
		c->g_move = (float)c->g / dif;
		c->b_move = (float)c->b / dif;
		// printf("t_move = %f\n", c->t_move);
		// printf("r_move = %f\n", c->r_move);
		// printf("g_move = %f\n", c->g_move);
		// printf("b_move = %f\n", c->b_move);
		// printf("first c_gmove == %f\n", c->g_move);
	}
	else
	{
		traveled = dif - find_dif(box);
		// printf("dif = %u\n", dif);
		// printf("trav = %u\n",((unsigned int)(c->g_move * traveled)) * 256);
		// printf("|%f|\n", c->g_move * traveled);
		box->color = box->ci->color;
		if (c->t_move != 0)
			box->color += ((unsigned int)(c->t_move * (double)traveled)) * 16777216;
		if (c->r_move != 0)
			box->color += ((unsigned int)(c->r_move * (double)traveled)) * 65536;
		if (c->g_move != 0)
			box->color += ((unsigned int)(c->g_move * (double)traveled)) * 256;
		if (c->b_move != 0)
			box->color += (unsigned int)(c->b_move * (double)traveled);
		// if (box->color > box->ce->color)
		// 	box->color = box->ce->color;
	}
}


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
		{
			set_color(box, 1, c);
			dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
		}
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
		{
			set_color(box, 1, c);
			dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
		}
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
		{
			set_color(box, 1, c);
			dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
		}
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
		{
			set_color(box, 1, c);
			dr_pixel(box->img, box->ci->x, box->ci->y, box->color);
		}
	}
}

void	dr_line(t_box *box, int event)
{
	t_color	c;
	int		dx;
	int		dy;

	c.event = event;
	ft_swap(box);
	if (box->ce->x >= box->ci->x)
		dx = box->ce->x - box->ci->x;
	else if (box->ce->x < box->ci->x)
		dx = box->ci->x - box->ce->x;
	dy = box->ce->y - box->ci->y;
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
