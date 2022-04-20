/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/20 19:33:05 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	ft_key(int keycode)
{
	if (keycode == 53)
		close(0);
	return (0);
}

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	dr_line(t_box *box, int x, int y)
// {
// 	int dx;
// 	int dy;
// 	int pk;
// 	int pk2;

// 	dx = x - box->x;
// 	dy = y - box->y;
// //dx  >= dy && x haut > x bas
// 	pk = (2 * dy) - dx;
// 	while ((box->y < y && y < 1080)|| (box->x < x && x < 1920))
// 	{
// 		if (pk > 0)
// 		{
// 			pk2 = pk + (2 * dy) - (2 * dx);
// 			box->x++;
// 			box->y++;
// 		}
// 		else if (pk <= 0)
// 		{
// 			pk2 = pk + (2 * dy);
// 			box->x++;
// 			printf("%d\n", box->y);
// 		}
// 		dr_pixel(box->img, box->x, box->y, 0xE74C3C);
// 		pk = pk2;
// 	}
// 	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
// }

void	dr_line(t_box *box, int x, int y)
{
	int dx;
	int dy;
	int pk;

	if (y <= box->y && (x <= box->x || box->x < x))
	{
		dx = x;
		x = box->x;
		box->x = dx;
		dy = y;
		y = box->y;
		box->y = dy;
	}

	if (x >= box->x)
	{
		dx = x - box->x;
		dy = y - box->y;
	}
	if (x < box->x)
	{
		dx = box->x - x;
		dy = y - box->y;
	}

	if (dx >= dy)
	{
		pk = (2 * dy) - dx;
		while ((box->y < y && y <= 1080)|| (box->x < x && x <= 1920))
		{
			if (pk > 0)
			{
				pk = pk + (2 * dy) - (2 * dx);
				if (x >= box->x)
					box->x++;
				else if (x < box->x)
					box->x--;
				box->y++;
			}
			else if (pk <= 0)
			{
				pk = pk + (2 * dy);
				if (x >= box->x)
					box->x++;
				else if (x < box->x)
					box->x--;
			}
			dr_pixel(box->img, box->x, box->y, 0xE74C3C);
		}
	}
	else if (dx < dy)
	{
		pk = (2 * dx) - dy;
		while ((box->y < y && y < 1080)|| (box->x < x && x < 1920))
		{
			if (pk > 0)
			{
				pk = pk + (2 * dx) - (2 * dy);
				if (x >= box->x)
					box->x++;
				else if (x < box->x)
					box->x--;
				box->y++;
			}
			else if (pk <= 0)
			{
				pk = pk + (2 * dx);
				box->y++;
			}
			dr_pixel(box->img, box->x, box->y, 0xE74C3C);
		}
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}

int	init_data(t_box *box)
{
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return(1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr , 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
								&box->img->line_lenght, &box->img->endian);
	box->x = 960;
	box->y = 540;
	return (0);
}

int	main(void)
{
	t_box box;
	int x;
	int y;
//probleme x=600 y=299
	x = 0;
	y = 0;
	init_data(&box);
	dr_pixel(box.img, box.x, box.y, 0xE74C3C);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img->img, 0, 0);
	while (x < 1921)
	{
		dr_line(&box, x, y);
		x++;
	}
	x--;
	while (y < 1081)
	{
		dr_line(&box, x, y);
		y++;
	}
	y--;
	while (x > -1)
	{
		dr_line(&box, x, y);
		x--;
	}
	x++;
	while (y > 0)
	{
		dr_line(&box, x, y);
		y--;
	}
	mlx_hook(box.win_ptr, 17, 1L<<17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L<<0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}
