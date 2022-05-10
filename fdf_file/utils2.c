/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:30:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/09 16:35:35 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_c(char *split)
{
	int	i;

	i = -1;
	if (split[1] && split[0] == '-')
		i++;
	while (split[++i])
	{
		if (split[i] < '0' || split[i] > '9')
		{
			if (split[i] == ',' && split[i + 1] == '0' && split[i + 2] == 'x')
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

int	check_color(char *str, int len)
{
	int	i;

	i = 2;
	if (len < 3 || len > 10)
	{
		return (1);
	}
	if (str[0] != '0' || str[1] != 'x')
		return (1);
	while (i < len)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'f')
			&& (str[i] < 'A' || str[i] > 'F'))
			return (1);
		i++;
	}
	return (0);
}
