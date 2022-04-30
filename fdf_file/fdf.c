/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/30 17:50:29 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	init_data(t_box *box)// a mettre dans libxutils
{
	// box->ci = malloc(sizeof(t_point));
	// if (!box->ci)
	// 	return (1);
	// box->ct = malloc(sizeof(t_point));
	// if (!box->ct)
	// 	return (1);
	// box->ce = malloc(sizeof(t_point));
	// if (!box->ce)
	// 	return (1);
	box->he = malloc(sizeof(t_height));
	if (!box->he)
		return (1);
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return (1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	box->he->color = NULL;
	box->he->z = NULL;
	// box->ci->x = 960;
	// box->ci->y = 540;
	// box->ce->x = 0;
	// box->ce->y = 0;
	return (0);
}

void	freebox(int error, t_box *box)
{
	int	y;
	int	x;

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
	}
	y = -1;
	if (error <= -3)
	{
		while (box->he->z[++y])
			free(box->he->z[y]);
		free(box->he->color);
	}
	if (error <= -2)
		free(box->he->z);
	if (error <= -1)
		free(box->he);
}

void	free_box(t_box *box)
{
	int y;
	int x;

	y = -1;
	while (box->he->z[++y])//Error pas de limite
		free(box->he->z[y]);
	free(box->he->z);
	y = -1;
	while (box->he->color[++y])
	{
		x = -1;
		while (box->he->color[y][++x])
			free(box->he->color[y][x]);
		free(box->he->color[y]);
	}
	free(box->he->color);
	free(box->he);
	// free(box->img);
}

void	free_list(t_list *list)
{
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

int	ft_copy(t_box *box, char **splited, int j)
{
	int		i;
	int		x;
	int		len;
	int		verif;
	char	**str;
	long	tmp;

	i = -1;
	x = len_w(splited);
	box->he->z[j] = (long *)malloc(sizeof(long) * x);
	if (!box->he->z[j])
	{
		write (2, "Error\n", 6);
		return (-3);
	}
	box->he->color[j] = (char **)malloc(sizeof(char *) * (x + 1));
	if (!box->he->z[j])
	{
		write (2, "Error\n", 6);
		return (-4);
	}
	box->he->color[j][x] = NULL;
	while (splited[++i])
	{
		verif = check_c(splited[i]);
		if (verif == -1)
		{
			box->he->z[j] = NULL;
			write(2, "Error\n", 6);
			return (-4);
		}
		else if (verif == 1)
		{
			str = ft_split(splited[i], ',');
			tmp = ft_atoi(str[0]);
			if (tmp == 2147483649)
			{
				box->he->z[j] = NULL;
				write(2, "Error copy 1", 12);
				return (-4);
			}
			box->he->z[j][i] = (int)tmp;
			len = len_c(str[1]);
			tmp = check_color(str[1], len);
			if (tmp == 1)
			{
				box->he->z[j] = NULL;
				write(2, "Error copy 2", 12);
				return (-4);
			}
			box->he->color[j][i] = (char *)malloc(sizeof(char) * (len + 1));
			if (!box->he->color[j][i])
			{
				box->he->z[j] = NULL;
				write(2, "Error copy 2", 12);
				return (-4);
			}
			x = -1;
			while (str[1][++x])
				box->he->color[j][i][x] = str[1][x];
			box->he->color[j][i][x] = '\0';
			free_split(str);
		}
		else
		{
			tmp = ft_atoi(splited[i]);
			if (tmp == 2147483649)
			{
				box->he->z[j] = NULL;
				write(2, "Error copy 2", 12);
				return (-4);
			}
			box->he->z[j][i] = (int)tmp;
			box->he->color[j][i] = (char *)malloc(sizeof(char) * 1);
			if (!box->he->color[j][i])
			{
				box->he->z[j] = NULL;
				write(2, "Error copy 2", 12);
				return (-4);
			}
			box->he->color[j][i][0] = '\0';
		}
	}
	return (0);
}

int	p_map(t_box *box, char *argv)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splited;
	t_list	*list;
	t_list	*new;

	i = 1;
	j = -1;
	list = NULL;
	fd = open(argv, O_RDONLY);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		if (i == -1)
		{
			free_list(list);
			write(2, "Error\n", 6);
			return (-1);
		}
		if (i == 0)
			break;
		new = lstnew(line);
		if (!new)
		{
			free_list(list);
			get_next_line(-1, NULL);
			write(2, "Error\n", 6);
			return (-1);
		}
		addback(&list, new);
	}
	while (list->next != NULL && list->next->line != -1)
	{
		i++;
		list = list->next;
	}
	while (list->line != -1)
		list = list->next;
	box->he->z = (long **)malloc(sizeof(long *) * (i + 2));
	if (!box->he->z)
	{
		free_list(list);
		write(2, "Error\n", 6);
		return (-1);
	}
	box->he->color = (char ***)malloc(sizeof(char **) * (i + 2));
	if (!box->he->color)
	{
		// free(box->he->z);// ou mettre z a null et passer par box
		free_list(list);
		write(2, "Error\n", 6);
		return (-2);
	}
	while (++j <= i)
	{
		splited = ft_split((char *)list->content, ' ');
		fd = ft_copy(box, splited, j);
		free_split(splited);
		if (fd < 0)
		{
			free_list(list);
			return (fd);
		}
		if (list->next != NULL)
			list = list->next;
	}
	free_list(list);
	box->he->z[j] = NULL;
	box->he->color[j] = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_box	box;
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	// init_data(&box);
	box.he = malloc(sizeof(t_height));
	if (!box.he)
		return (1);
	box.he->color = NULL;
	box.he->z = NULL;
	i = p_map(&box, argv[1]);
	printf("| %ld | %s | \n", box.he->z[0][0], box.he->color[0][0]);
	if (i != 0)
		freebox(i, &box);
	else
		free_box(&box);
	system("leaks fdf");
	// mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	// mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	// mlx_loop(box.mlx_ptr);
	return (0);
}
