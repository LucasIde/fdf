/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:24:04 by lide              #+#    #+#             */
/*   Updated: 2022/05/02 14:35:34 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	ft_swap(t_box *box)
// {
// 	if (box->ci->y > box->ce->y)
// 	{
// 		box->ct->x = box->ci->x;
// 		box->ci->x = box->ce->x;
// 		box->ct->y = box->ci->y;
// 		box->ci->y = box->ce->y;
// 	}
// 	else
// 	{
// 		box->ct->x = box->ce->x;
// 		box->ct->y = box->ce->y;
// 	}
// }

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
