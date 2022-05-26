/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:51:30 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:10:12 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	free_color_first(t_box *box)
{
	int	i;
	int	y;
	int	x;

	y = -1;
	while (box->he->color[++y])
	{
		x = -1;
		while (box->he->color[y][++x])
			free(box->he->color[y][x]);
		free(box->he->color[y]);
	}
	i = 0;
	while (i <= y && box->he->z[i])
	{
		free(box->he->z[i]);
		i++;
	}
	free(box->he->color);
}

void	free_z_first(t_box *box)
{
	int	i;
	int	y;
	int	x;

	i = -1;
	y = 0;
	while (box->he->z[++i])
		free(box->he->z[i]);
	while (y < i && box->he->color[y])
	{
		x = -1;
		while (box->he->color[y][++x])
			free(box->he->color[y][x]);
		free(box->he->color[y]);
		y++;
	}
	free(box->he->color);
}

void	freebox(int error, t_box *box)
{
	if (error <= -4)
		free_color_first(box);
	if (error == -3)
		free_z_first(box);
	if (error <= -2)
		free(box->he->z);
}

void	free_list(t_list *list)
{
	if (!list)
		return ;
	if (list && list->next != NULL)
		list_next(&list);
	if (list->next == NULL)
	{
		free(list->content);
		free(list);
		return ;
	}
	while (list->line != 1)
	{
		list = list->next;
		free(list->before->content);
		free(list->before);
	}
	free(list->content);
	free(list);
}

void	free_split(char **splited)
{
	int	i;

	i = -1;
	while (splited[++i])
		free(splited[i]);
	free(splited);
}
