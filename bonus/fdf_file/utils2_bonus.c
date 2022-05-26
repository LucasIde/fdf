/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:30:24 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:58:20 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

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

unsigned int	hd_to_d(char *str)
{
	int				len;
	int				i;
	unsigned int	color;

	i = -1;
	color = 0;
	len = len_c(str);
	len--;
	while (++i < len - 1)
	{
		if (str[len - i] >= '0' && str[len - i] <= '9')
			color += (str[len - i] - '0') * pow(16, i);
		else if (str[len - i] >= 'a' && str[len - i] <= 'f')
			color += ((str[len - i] - 'a') + 10) * pow(16, i);
		else if (str[len - i] >= 'A' && str[len - i] <= 'F')
			color += ((str[len - i] - 'A') + 10) * pow(16, i);
	}
	return (color);
}

int	check_rectangle(int y, t_copy *c, t_box *box)
{
	static int	len;

	if (y == 0)
		len = c->x;
	else
	{
		if (c->x != len)
		{
			write(2, "the map must be rectangle\n", 26);
			box->he->z[y] = NULL;
			return (-3);
		}
	}
	return (0);
}
