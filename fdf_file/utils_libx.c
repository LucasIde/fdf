/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:27:36 by lide              #+#    #+#             */
/*   Updated: 2022/05/21 18:38:13 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_close(int keycode, t_box *box)
{
	if (box)
		keycode = 0;
	exit(0);
	return (0);
}

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_value_key(t_box *box)
{
	box->key->w = 0;
	box->key->a = 0;
	box->key->s = 0;
	box->key->d = 0;
	box->key->q = 0;
	box->key->e = 0;
	box->key->r = 0;
	box->key->x = 0;
	box->key->z = 0;
	box->key->i = 0;
	box->key->p = 0;
	box->key->up = 0;
	box->key->left = 0;
	box->key->down = 0;
	box->key->right = 0;
	box->key->minus = 0;
	box->key->plus = 0;
	box->key->tab = 0;
	box->key->esc = 0;
}

void	set_value_box(t_box *box)
{
	box->he->color = NULL;
	box->he->z = NULL;
	box->move_x = 0;
	box->move_y = 0;
	box->height = 1;
	box->len = 10;
	box->color_set = 0;
	box->speed = 5;
	box->rotate_x = 0;
	box->rotate_y = 0;
	box->rotate_z = 0;
	box->view = 0;
	box->help = 0;
}

void	free_data_malloc(t_box *box, int error)
{
	if (error > 1)
		free(box->ci);
	if (error > 2)
		free(box->ce);
	if (error > 3)
		free(box->c_mid);
	if (error > 4)
		free(box->he);
	if (error > 5)
		free(box->img);
	if (error > 6)
		free(box->key);
	if (error > 7)
		free(box->rainbow);
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
	box->key = malloc(sizeof(t_key_set));
	if (!box->key)
		return (6);
	box->rainbow = (unsigned int *)malloc(sizeof(unsigned int) * 7);
	if (!box->rainbow)
		return (7);
	return (0);
}

int	init_data(t_box *box)
{
	int	error;

	error = data_malloc(box);
	if (error != 0)
	{
		free_data_malloc(box, error);
		return (1);
	}
	init_rainbow(box->rainbow);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
	{
		free_data_malloc(box, 8);
		return (1);
	}
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "FDF");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	set_value_box(box);
	set_value_key(box);
	return (0);
}
