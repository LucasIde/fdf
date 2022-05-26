/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:35:53 by lide              #+#    #+#             */
/*   Updated: 2022/05/20 14:47:09 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_dif(t_box *box)
{
	int	dif;
	int	x;
	int	y;

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

void	set_trgb(t_color *c, unsigned int color, unsigned int exp, int i)
{
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

	c->t = 0;
	c->r = 0;
	c->g = 0;
	c->b = 0;
	c_i.t = 0;
	c_i.r = 0;
	c_i.g = 0;
	c_i.b = 0;
	set_trgb(&c_i, box->ci->color, 0, 7);
	set_trgb(c, box->ce->color, 0, 7);
	c->t -= c_i.t;
	c->r -= c_i.r;
	c->g -= c_i.g;
	c->b -= c_i.b;
}

void	set_color2(t_box *box, t_color *c, double traveled)
{
	box->color = box->ci->color;
	if (c->t_move != 0)
		box->color += ((unsigned int)(c->t_move * traveled)) * 16777216;
	if (c->r_move != 0)
		box->color += ((unsigned int)(c->r_move * traveled)) * 65536;
	if (c->g_move != 0)
		box->color += ((unsigned int)(c->g_move * traveled)) * 256;
	if (c->b_move != 0)
		box->color += (unsigned int)(c->b_move * traveled);
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
		c->t_move = (float)c->t / dif;
		c->r_move = (float)c->r / dif;
		c->g_move = (float)c->g / dif;
		c->b_move = (float)c->b / dif;
	}
	else
	{
		traveled = dif - find_dif(box);
		set_color2(box, c, traveled);
	}
}
