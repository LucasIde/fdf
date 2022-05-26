/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:04:56 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 16:53:59 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	init_color(t_box *box, int y, int x, int event)
{
	if (event == 0)
	{
		if (!*box->he->color[y][x])
			return (0xffffff);
		else
			return (hd_to_d(box->he->color[y][x]));
	}
	else
		return (0x0);
}
