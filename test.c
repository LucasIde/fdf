/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:10:36 by lide              #+#    #+#             */
/*   Updated: 2022/04/28 16:53:21 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_box *box)
{
	printf("%d\n", keycode);
	if (keycode == KEY_W || keycode == 126)
	{
		for (int i = 0; i < SPEED; i++)
		{
			if (box->y == 10)
				return (0);
			box->y--;
			dr_pixel(box->img, box->x, box->y, COLOURS);
		}
	}
	else if (keycode == 1 || keycode == 125)
	{
		for (int i = 0; i < SPEED; i++)
		{
			if (box->y == 1070)
				return (0);
			box->y++;
			dr_pixel(box->img, box->x, box->y, COLOURS);
		}
	}
	else if (keycode == 0 || keycode == 123)
	{
		for (int i = 0; i < SPEED; i++)
		{
			if (box->x == 10)
				return (0);
			box->x--;
			dr_pixel(box->img, box->x, box->y, COLOURS);
		}
	}
	else if (keycode == 2 || keycode == 124)
	{
		for (int i = 0; i < SPEED; i++)
		{
			if (box->x == 1910)
				return (0);
			box->x++;
			dr_pixel(box->img, box->x, box->y, COLOURS);
		}
	}
	else if (keycode == 53)
		close(0);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	return (0);
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

	init_data(&box);
	dr_pixel(box.img, box.x, box.y, 0xE74C3C);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img->img, 0, 0);
	mlx_hook(box.win_ptr, 17, 1L<<17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L<<0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}

// void	dr_line(t_box *box)
// {
// 	int	dx;
// 	int	dy;
// 	int	p;

// 	if (box->ci->y > box->ce->y)
// 	{
// 		box->ct->x = box->ci->x;
// 		box->ct->y = box->ci->y;
// 		box->ci->x = box->ce->x;
// 		box->ci->y = box->ce->y;
// 		dr_pixel(box->img, box->ce->x, box->ce->y, 0xE74C3C);
// 		// printf("%d\n", y);
// 	}
// 	else
// 	{
// 		box->ct->x = box->ce->x;
// 		box->ct->y = box->ce->y;
// 	}
// 	if (box->ct->x >= box->ci->x)
// 		dx = box->ct->x - box->ci->x;
// 	else if (box->ct->x < box->ci->x)
// 		dx = box->ci->x - box->ct->x;
// 	dy = box->ct->y - box->ci->y;

// 				// printf("x init %d | y init %d | x end %d | y end %d\n", box->ci->x, box->ci->y, x, y);
// 				// if (box->ci->x == 960)
// 				// 	printf("x = %d | y = %d\n", box->ci->x, box->ci->y);
// 	if (box->ct->x >= box->ci->x)
// 	{
// 		if (dx >= dy)
// 		{
// 			p = 2 * (dy - dx);
// 			while (box->ci->x <= box->ct->x && box->ci->y <= box->ct->y && box->ct->y < 1081 && box->ct->x < 1921 && box->ct->x > -1 && box->ct->y > -1)
// 			{
// 				if (p < 0)
// 				{
// 					p = p + (2 * dy);
// 					box->ci->x++;
// 				}
// 				else if (p >= 0)
// 				{
// 					p = p + (2 * (dy - dx));
// 					box->ci->x++;
// 					box->ci->y++;
// 				}
// 				dr_pixel(box->img, box->ci->x, box->ci->y, 0xbaaaaa);
// 			}
// 		}
// 		else if (dx < dy)
// 		{
// 			p = 2 * (dx - dy);
// 			while (box->ci->x <= box->ct->x && box->ci->y <= box->ct->y && box->ct->y < 1081 && box->ct->x < 1921 && box->ct->x > -1 && box->ct->y > -1)
// 			{
// 				if (p <= 0)
// 				{
// 					p = p + (2 * dx);
// 					box->ci->y++;
// 				}
// 				else if (p >0)
// 				{
// 					p = p + (2 * (dx - dy));
// 					box->ci->x++;
// 					box->ci->y++;
// 				}
// 				dr_pixel(box->img, box->ci->x, box->ci->y, 0xE74C3C);
// 			}
// 		}
// 	}
// 	else if (box->ct->x < box->ci->x)
// 	{
// 		if (dx > dy)
// 		{
// 			p = 2 * (dy - dx);
// 			while ((box->ct->x <= box->ci->x && box->ct->y >= box->ci->y) && box->ct->y < 1081 && box->ct->x < 1921 && box->ct->x > -1 && box->ct->y > -1)
// 			{
// 				if (p <= 0)
// 				{
// 					p = p + (2 * dy);
// 					box->ci->x--;
// 				}
// 				else if (p > 0)
// 				{
// 					p = p + (2 * (dy - dx));
// 					box->ci->x--;
// 					box->ci->y++;
// 				}
// 				dr_pixel(box->img, box->ci->x, box->ci->y, 0xB22222);
// 			}
// 		}
// 		else if (dx <= dy)
// 		{
// 			p = 2 * (dx - dy);
// 			while ((box->ct->x <= box->ci->x && box->ct->y >= box->ci->y) && box->ct->y < 1081 && box->ct->x < 1921 && box->ct->x > -1 && box->ct->y > -1)
// 			{
// 				if (p < 0)
// 				{
// 					p = p + (2 * dx);
// 					box->ci->y++;
// 				}
// 				else if (p >= 0)
// 				{
// 					p = p + (2 * (dx - dy));
// 					box->ci->x--;
// 					box->ci->y++;
// 				}
// 				dr_pixel(box->img, box->ci->x, box->ci->y, 0xE74C3C);
// 			}
// 		}
// 	}
// 	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
// }


// long	hd_to_d(char *str);
// {
// 	long	color;
// 	int		len;
// 	int		tmp;
// 	int		i;

// 	i = -1;
// 	color = 0;
// 	len = len_c(str);
// 	tmp = check_color(str, len);
// 	if (tmp == 1);
// 		write(2, "error", 5);
// 	while (++i < len - 2)
// 	{
// 		if (str[len - i - 1] >= '0' && str[len - i - 1] <= '9')
// 			color += (str[len - i - 1] - '0') * pow(16, i);
// 		else if (str[len - i - 1] >= 'a' && str[len - i - 1] <= 'f')
// 			color += (str[len - i - 1] - 'a' + 10) * pow(16, i);
// 		else if (str[len - i - 1] >= 'A' && str[len - i - 1] <= 'F')
// 			color += (str[len - i - 1] - 'A' + 10) * pow(16, i);
// 	}
// 	return (color);
// }
