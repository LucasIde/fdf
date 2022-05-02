/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:27:36 by lide              #+#    #+#             */
/*   Updated: 2022/05/02 17:01:02 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_box *box)
{
	if (keycode == 53)
		free(box->img);
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
	box->he = malloc(sizeof(t_height));
	if (!box->he)
		return (1);
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return (1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	box->he->color = NULL;
	box->he->z = NULL;
	return (0);
}
	// box->ci = malloc(sizeof(t_point));
	// if (!box->ci)
	// 	return (1);
	// box->ct = malloc(sizeof(t_point));
	// if (!box->ct)
	// 	return (1);
	// box->ce = malloc(sizeof(t_point));
	// if (!box->ce)
	// 	return (1);
	// box->ci->x = 960;
	// box->ci->y = 540;
	// box->ce->x = 0;
	// box->ce->y = 0;
