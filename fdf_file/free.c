/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:51:30 by lide              #+#    #+#             */
/*   Updated: 2022/05/01 18:56:42 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	freebox(int error, t_box *box)
{
	int	y;
	int	x;
	int	i;

	if (error <= -4)
	{
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
	if (error == -3)
	{
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
	if (error <= -2)
		free(box->he->z);
	if (error <= -1)
		free(box->he);
}

// void	free_box(t_box *box)
// {
// 	int y;
// 	int x;

// 	y = -1;
// 	while (box->he->z[++y])//Error pas de limite
// 		free(box->he->z[y]);
// 	free(box->he->z);
// 	y = -1;
// 	while (box->he->color[++y])
// 	{
// 		x = -1;
// 		while (box->he->color[y][++x])
// 			free(box->he->color[y][x]);
// 		free(box->he->color[y]);
// 	}
// 	free(box->he->color);
// 	free(box->he);
// 	// free(box->img);
// }

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
	while(splited[++i])
		free(splited[i]);
	free(splited);
}
