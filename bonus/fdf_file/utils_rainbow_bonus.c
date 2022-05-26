/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rainbow_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:19:06 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:10:12 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

unsigned int	rainbow_road(unsigned int *template, int size, int y, int x)
{
	static int	i = -1;

	i++;
	if (i >= size || (x == 0 && y == 0))
		i = 0;
	return (template[i]);
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
