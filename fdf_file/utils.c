/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:24:04 by lide              #+#    #+#             */
/*   Updated: 2022/05/10 02:17:24 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_swap(t_box *box)
{
	long	tmp;

	if (box->ci->y > box->ce->y)
	{
		tmp = box->ce->x;
		box->ce->x = box->ci->x;
		box->ci->x = tmp;
		tmp = box->ce->y;
		box->ce->y = box->ci->y;
		box->ci->y = tmp;
	}
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (len_c(s1) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

unsigned int	hd_to_d(char *str)
{
	int	len;
	int	i;
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

long	ft_atoi(char *str)
{
	long	j;
	int		i;
	int		x;

	j = 0;
	i = 0;
	x = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j += str[i] - '0';
		if (j > 2147483648 || (x == 1 && j > 2147483647))
			return (2147483649);
		i++;
	}
	return (j * x);
}

int	len_w(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
