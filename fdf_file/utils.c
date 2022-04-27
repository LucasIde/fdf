/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:24:04 by lide              #+#    #+#             */
/*   Updated: 2022/04/26 15:11:39 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_swap(t_box *box)
{
	if (box->ci->y > box->ce->y)
	{
		box->ct->x = box->ci->x;
		box->ci->x = box->ce->x;
		box->ct->y = box->ci->y;
		box->ci->y = box->ce->y;
	}
	else
	{
		box->ct->x = box->ce->x;
		box->ct->y = box->ce->y;
	}
}