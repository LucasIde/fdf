/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:23:40 by lide              #+#    #+#             */
/*   Updated: 2022/11/09 13:54:23 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	scroll(int mouse, int x, int y, t_box *box)
{
	(void)x;
	(void)y;
	if (mouse == 4 && box->len < 50)
		box->len += 1;
	else if (mouse == 5 && box->len > 1)
		box->len -= 1;
	return (0);
}
