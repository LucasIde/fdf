/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:52:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/10 04:37:09 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_dif(t_box *box)
{
	int	dif;

	dif = 0;
	if (box->ce->x < 0)
		dif -= box->ce->x;
	else
		dif += box->ce->x;
	if (box->ce->y < 0)
		dif -= box->ce->y;
	else
		dif += box->ce->y;
	if (box->ci->x < 0)
		dif -= box->ci->x;
	else
		dif += box->ci->x;
	if (box->ci->y < 0)
		dif -= box->ci->y;
	else
		dif += box->ci->y;
	return (dif);
}

void	init_trgb(t_color *c)
{
	c->t = 0;
	c->r = 0;
	c->g = 0;
	c->b = 0;
}

void	set_trgb(t_color *c, unsigned int color, int i)
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
		if (color >= pow(16, i))
			color -= pow(16, i);
		else
			i--;
	}
}

void	color_dif(t_box *box, t_color *c)
{
	t_color	c_i;
	set_trgb(&c_i, box->ci->color, 7);
	set_trgb(c, box->ce->color, 7);
	c->t -= c_i.t;
	c->r -= c_i.r;
	c->g -= c_i.g;
	c->b -= c_i.b;
	// printf("ct = %u | cti = %u\n", c->t, c_i.t);
	// printf("cr = %u | cri = %u\n", c->r, c_i.r);
	// printf("cg = %u | ctg = %u\n", c->g, c_i.g);
	// printf("cb = %u | ctb = %u\n", c->b, c_i.b);
	// if (c->t == 0)
	// 	c->t = 1;
	// if (c->r == 0)
	// 	c->r = 1;
	// if (c->g == 0)
	// 	c->g = 1;
	// if (c->b == 0)
	// 	c->b = 1;
}

void	set_color(t_box *box, int event, t_color *c)
{
	static int	dif;
	static unsigned int	traveled;

	if (event == 0)
	{
		dif = 0;
		traveled = 0;
		dif = find_dif(box);
		color_dif(box, c);
		// printf("ct == %d\n", c->t);
		c->t_move = c->t / dif;
		c->r_move = c->r / dif;
		c->g_move = c->g / dif;
		c->b_move = c->b / dif;
		// printf("dif == %d\n", dif);
		// printf("first c_tmove == %u\n", c->t_move);
	}
	else
	{
		traveled = dif - find_dif(box);
		box->color = box->ci->color;
		if (c->t_move != 0)
			box->color += (c->t_move * traveled) * 16777216;
		if (c->r_move != 0)
			box->color += (c->r_move * traveled) * 65536;
		if (c->g_move != 0)
			box->color += (c->g_move * traveled) * 256;
		if (c->g_move != 0)
			box->color += (c->g_move * traveled);
		printf("color %u\n", box->color);
		printf("traveled == %u\n", traveled);
		// if (traveled > c->t_move)
		// {
		// 	box->ci->color += 16777216;
		// 	c->t_move += c->t_move;
		// 	// printf("c_tmove == %u\n", c->t_move);
		// }
		// if (traveled > c->r_move)
		// {
		// 	box->ci->color += 65536;
		// 	c->r_move += c->r_move;
		// }
		// if (traveled > c->g_move)
		// {
		// 	box->ci->color += 256;
		// 	c->g_move += c->g_move;
		// }
		// if (traveled > c->b_move)
		// {
		// 	box->ci->color++;
		// 	c->b_move += c->b_move;
		// }
		// printf("%u\n", box->ci->color);
		// c->t_add = traveled / c->t_move;
		// c->r_add = traveled / c->r_move;
		// c->g_add = traveled / c->g_move;
		// c->b_add = traveled / c->b_move;
		// if (c->t_add != 0)
		// if (c->r_add != 0)
		// box->ci->color += c->r_add * pow(16, 4);
		// if (c->g_add != 0)
		// box->ci->color += c->g_add * pow(16, 2);
		// box->ci->color += c->b_add;
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

void	dr_line(t_box *box)
{
	t_color	c;
	int		dx;
	int		dy;

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
