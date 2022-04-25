/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/25 21:04:11 by lide             ###   ########.fr       */
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
	*(unsigned int *)dst = color;
}

int	init_data(t_box *box)
{
	box->img = malloc(sizeof(t_data));
	box->ci = malloc(sizeof(t_point));
	box->ct = malloc(sizeof(t_point));
	box->ce = malloc(sizeof(t_point));
	if (!box->img)
		return (1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	box->ci->x = 960;
	box->ci->y = 540;
	box->ce->x = 0;
	box->ce->y = 0;
	return (0);
}

int	main(void)
{
	t_box	box;

	init_data(&box);
	dr_pixel(box.img, box.ci->x, box.ci->y, 0xE74C3C);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img->img, 0, 0);
	// dr_line(&box);
	while (box.ce->x <= 1920)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->x++;
	}
	box.ce->x = 1920;
	while (box.ce->y <= 1080)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->y++;
	}
	box.ce->y = 1080;
	while (box.ce->x >= 0)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->x--;
	}
	box.ce->x = 0;
	while (box.ce->y >= 0)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->y--;
	}
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}
