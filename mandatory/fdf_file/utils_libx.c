/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:27:36 by lide              #+#    #+#             */
/*   Updated: 2022/05/27 15:00:37 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_close(t_box *box)
{
	mlx_destroy_image(box->mlx_ptr, box->img);
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	freebox(-4, box);
	free_data_malloc(box, 8, 1);
	exit(0);
	return (0);
}

void	set_value_box(t_box *box)
{
	box->he->color = NULL;
	box->he->z = NULL;
	box->height = 1;
	box->len = 10;
}

int	data_malloc(t_box *box)
{
	box->ci = malloc(sizeof(t_point));
	if (!box->ci)
		return (1);
	box->ce = malloc(sizeof(t_point));
	if (!box->ce)
		return (2);
	box->c_mid = malloc(sizeof(t_point));
	if (!box->c_mid)
		return (3);
	box->he = malloc(sizeof(t_height));
	if (!box->he)
		return (4);
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return (5);
	return (0);
}

void	init_data(t_box *box)
{
	int	error;

	error = data_malloc(box);
	if (error != 0)
		free_init_malloc(box, error, 1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		free_init_malloc(box, 8, 1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "FDF");
	if (!box->win_ptr)
		free_init_malloc(box, 8, 1);
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	if (!box->img->img)
		free_init_malloc(box, 8, 2);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	if (!box->img->addr)
		free_init_malloc(box, 8, 3);
	set_value_box(box);
}
