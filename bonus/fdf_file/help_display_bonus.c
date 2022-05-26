/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:44:15 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:10:12 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	need_help(t_box *box, int screen)
{
	if (screen == 1)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0x0, HELP);
	if (screen == 0)
		mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, 0xffffff, HELP);
}

void	color_help(t_box *box, int screen)
{
	int				y;
	int				x;
	unsigned int	color;

	color = 0;
	if (screen == 0)
		color = 0x0;
	else if (screen == 1)
		color = 0x01ffffff;
	y = -1;
	while (++y < 60)
	{
		x = -1;
		while (++x < 1500)
		{
			dr_pixel(box->img, x, y, color);
		}
	}
}

void	help_display(t_box *box, int screen)
{
	unsigned int	color;

	if (screen == 1)
		color = 0x0;
	if (screen == 0)
		color = 0xffffff;
	mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 10, color, H_COLOR);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 10, 30, color, H_RAINBOW);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 310, 10, color, H_HEIGHT);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 310, 30, color, H_ROTATION);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 670, 10, color, H_SIZE);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 670, 30, color, H_MOVE);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1050, 10, color, H_RESET);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1050, 30, color, H_VIEW);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 1350, 10, color, H_QUIT);
}
