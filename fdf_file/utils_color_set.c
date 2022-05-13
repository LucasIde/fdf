/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:19:06 by lide              #+#    #+#             */
/*   Updated: 2022/05/12 22:35:07 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_scene(t_box *box)
{
	if (box->key->zero == 1 && box->key->one == 0 && box->key->two == 0)
		box->color_set = 0;
	if (box->key->zero == 0 && box->key->one == 1 && box->key->two == 0)
		box->color_set = 1;
	if (box->key->zero == 0 && box->key->one == 0 && box->key->two == 1)
		box->color_set = 2;
}

void	rainbow_move(t_box *box, unsigned int *template, int size)
{
	static int		ct;
	unsigned int	tmp;
	int				i;

	ct++;
	if (ct >= box->speed)
	{
		i = -1;
		tmp = template[0];
		while (++i < size)
			template[i] = template[i + 1];
		template[size] = tmp;
		ct = 0;
	}
}

void	init_rainbow(unsigned int *tab)
{
	tab[0] = RED;
	tab[1] = ORANGE;
	tab[2] = YELLOW;
	tab[3] = GREEN;
	tab[4] = BLUE;
	tab[5] = INDIGO;
	tab[6] = VIOLET;
}
