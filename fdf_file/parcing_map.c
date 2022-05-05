/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:14:04 by lide              #+#    #+#             */
/*   Updated: 2022/05/05 17:35:40 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_list(t_box *box, char *argv, t_parcing *p)
{
	p->fd = open(argv, O_RDONLY);
	while (p->i == 1)
	{
		p->i = get_next_line(p->fd, &(p->line));
		if (p->i == -1)
		{
			free_list(p->list);
			return (-1);
		}
		if (p->i == 0)
			break ;
		p->new = lstnew(p->line);
		if (!p->new)
		{
			if (!p->list)
				free(p->line);
			free_list(p->list);
			get_next_line(-1, NULL);
			write(2, "Error : Malloc lstnew\n", 22);
			return (-1);
		}
		addback(&p->list, p->new);
	}
	box->fd = (p->fd);
	return (0);
}

int	first_malloc(t_box *box, t_parcing *p)
{
	while (p->list->next != NULL && p->list->next->line != -1)
	{
		p->len++;
		p->list = p->list->next;
	}
	if (p->list->next != NULL)
		p->list = p->list->next;
	box->he->z = (long **)malloc(sizeof(long *) * (p->len + 2));
	if (!box->he->z)
	{
		free_list(p->list);
		write(2, "Error : Malloc 1 p_map\n", 23);
		return (-1);
	}
	box->he->color = (char ***)malloc(sizeof(char **) * (p->len + 2));
	if (!box->he->color)
	{
		free_list(p->list);
		write(2, "Error : Malloc 2 p_map\n", 23);
		return (-2);
	}
	return (0);
}

int	list_to_box(t_box *box, t_parcing *p)
{
	while (++p->y <= p->len)
	{
		p->splited = ft_split((char *)p->list->content, ' ');
		p->verif = ft_copy(box, p->splited, p->y);
		free_split(p->splited);
		if (p->verif < 0)
		{
			free_list(p->list);
			return (p->verif);
		}
		if (p->list->next != NULL)
			p->list = p->list->next;
	}
	free_list(p->list);
	return (0);
}

int	p_map(t_box *box, char *argv)
{
	t_parcing	p;

	p.i = 1;
	p.y = -1;
	p.len = 0;
	p.list = NULL;
	p.new = NULL;
	p.verif = create_list(box, argv, &p);
	if (p.verif != 0)
		return (p.verif);
	p.verif = first_malloc(box, &p);
	if (p.verif != 0)
		return (p.verif);
	p.verif = list_to_box(box, &p);
	if (p.verif != 0)
		return (p.verif);
	box->he->z[p.y] = NULL;
	box->he->color[p.y] = NULL;
	return (0);
}
