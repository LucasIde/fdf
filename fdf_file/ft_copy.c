/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:04:49 by lide              #+#    #+#             */
/*   Updated: 2022/05/09 17:15:43 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_error(t_copy *c, t_box *box, int y, int error)
{
	if (error == 0)
		write(2, "Error : wrong value in .fdf\n", 28);
	else if (error == 1)
		write(2, "Error : value superior to an int\n", 33);
	else if (error == 2)
		write(2, "Error : wrong color\n", 20);
	else if (error == 3)
		write(2, "Error : Malloc 3 ft_copy\n", 25);
	else if (error == 4)
		write(2, "Error : value superior to an int\n", 33);
	else
		write(2, "Error : Malloc 4 ft_copy\n", 25);
	if (error >= 1 && error <= 3)
		free_split(c->str);
	free(box->he->color[y]);
	box->he->color[y] = NULL;
	return (-4);
}

int	with_color(t_copy *c, t_box *box, char **splited, int y)
{
	c->str = ft_split(splited[c->x], ',');
	c->tmp = ft_atoi(c->str[0]);
	if (c->tmp == 2147483649)
		return (check_error(c, box, y, 1));
	box->he->z[y][c->x] = (int)c->tmp;
	c->len = len_c(c->str[1]);
	c->tmp = check_color(c->str[1], c->len);
	if (c->tmp == 1)
		return (check_error(c, box, y, 2));
	box->he->color[y][c->x] = (char *)malloc(sizeof(char) * (c->len + 1));
	if (!box->he->color[y][c->x])
		return (check_error(c, box, y, 3));
	c->z = -1;
	while (c->str[1][++c->z])
		box->he->color[y][c->x][c->z] = c->str[1][c->z];
	box->he->color[y][c->x][c->z] = '\0';
	free_split(c->str);
	return (0);
}

int	without_color(t_copy *c, t_box *box, char **splited, int y)
{
	c->tmp = ft_atoi(splited[c->x]);
	if (c->tmp == 2147483649)
		return (check_error(c, box, y, 4));
	box->he->z[y][c->x] = (int)c->tmp;
	box->he->color[y][c->x] = (char *)malloc(sizeof(char) * 1);
	if (!box->he->color[y][c->x])
		return (check_error(c, box, y, 5));
	box->he->color[y][c->x][0] = '\0';
	return (0);
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

int	second_malloc(t_copy *c, t_box *box, char **splited, int y)
{
	c->x = len_w(splited);
	c->error = check_rectangle(y, c, box);
	if (c->error != 0)
		return (c->error);
	box->he->z[y] = (long *)malloc(sizeof(long) * c->x + 1);
	if (!box->he->z[y])
	{
		write (2, "Error : Malloc 1 ft_copy\n", 25);
		return (-3);
	}
	box->he->color[y] = (char **)malloc(sizeof(char *) * (c->x + 1));
	if (!box->he->color[y])
	{
		write (2, "Error : Malloc 2 ft_copy\n", 25);
		return (-4);
	}
	box->he->color[y][c->x] = NULL;
	box->he->z[y][c->x] = 2147483649;
	return (0);
}

int	ft_copy(t_box *box, char **splited, int y)
{
	t_copy	c;

	c.error = second_malloc(&c, box, splited, y);
	if (c.error != 0)
		return (c.error);
	c.x = -1;
	while (splited[++c.x])
	{
		c.error = check_c(splited[c.x]);
		if (c.error == -1)
			return (check_error(&c, box, y, 0));
		else if (c.error == 1)
		{
			c.error = with_color(&c, box, splited, y);
			if (c.error)
				return (c.error != 0);
		}
		else
		{
			c.error = without_color(&c, box, splited, y);
			if (c.error)
				return (c.error != 0);
		}
	}
	return (0);
}
