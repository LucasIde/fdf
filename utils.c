/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:24:04 by lide              #+#    #+#             */
/*   Updated: 2022/04/22 08:50:52 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(t_box *box)
{
	int	tmp;

	tmp = box->x_e;
	box->x_e = box->x;
	box->x = tmp;
	tmp = box->y_e;
	box->y_e = box->y;
	box->y = tmp;
	dr_pixel(box->img, box->x, box->y, 0xE74C3C);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
}
