/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/28 21:01:25 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	ft_key(int keycode)
{
	if (keycode == 53)
		close(0);
	return (0);
}

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	init_data(t_box *box)
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

void	free_box(t_box *box)
{
	int i;
	int j;

	i = -1;
	while (box->he->z[++i])//error pas de limite
		free(box->he->z[i]);
	free(box->he->z);
	printf("yo\n");
	i = -1;
	j = -1;
	while (box->he->color[++i])
	{
		printf("salut\n");
		while (box->he->color[i][++j])
		{
			printf("coucou\n");
			free(box->he->color[i][j]);
		}
		free(box->he->color[i]);
	}
	printf("salut\n");
	free(box->he->color);
	free(box->he);
	free(box->img);
	printf("hello\n");
}

void	free_split(char **splited)
{
	int	i;

	i = -1;
	while(splited[++i])
		free(splited[i]);
	free(splited);
}

int	check_c(char *splited)
{
	int	i;

	i = -1;
	while (splited[++i])
	{
		if (splited[i]<= '0' && splited[i] >= '9')
		{
			if (splited[i] == ',')
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
		return (1);
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

void	ft_copy(t_box *box, char **splited, int j)
{
	int		i;
	int		x;
	int		len;
	int		verif;
	char	**str;
	long	tmp;

	i = -1;
	x = len_w(splited);
	printf("x = %d\n", x);
	box->he->z[j] = (long *)malloc(sizeof(long) * x);
	if (!box->he->z[j])
		write (2, "error", 5);
	box->he->color[j] = (char **)malloc(sizeof(char *) * (x + 1));
	box->he->color[j][x] = NULL;
	if (!box->he->z[j])
		write (2, "error", 5);
	while (splited[++i])
	{
		verif = check_c(splited[i]);
		if (verif == -1)
			write(2, "error", 5);
		else if (verif == 1)
		{
			str = ft_split(splited[i], ',');
			tmp = ft_atoi(str[0]);
			if (tmp == 2147483649)
				write(2, "error copy", 10);
			box->he->z[j][i] = (int)tmp;
			len = len_c(str[i]);
			tmp = check_color(str[1], len);
			if (tmp == 1)
				write(2, "error copy", 10);
			box->he->color[j][i] = (char *)malloc(sizeof(char) * (len + 1));
			x = -1;
			while (str[1][++x])
				box->he->color[j][i][x] = str[i][x];
			box->he->color[j][i][x] = '\0';
			free_split(str);
		}
		else
		{
			tmp = ft_atoi(splited[i]);
			if (tmp == 2147483649)
				write(2, "error copy", 10);
			box->he->z[j][i] = (int)tmp;
			box->he->color[j][i] = (char *)malloc(sizeof(char) * 1);
			box->he->color[j][i][0] = '\0';
		}
	}
	// box->he->color[j][i] = NULL;
}


void	p_map(t_box *box, char *argv)
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
	fd = open(argv, O_RDONLY);
	while (i == 1)
	{
		i = get_next_line(fd, &line);
		if (i == -1)
			write(2, "error", 5);
		if (i == 0)
			break;
		new = lstnew(ft_strdup(line));
		addback(&list, new);
		free(line);
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
		write(2, "error", 5);
	box->he->color = (char ***)malloc(sizeof(char **) * (i + 2));
	if (!box->he->color)
		write(2, "error", 5);
	while (++j <= i)
	{
		splited = ft_split((char *)list->content, ' ');
		printf("content : %s\n", list->content);
		ft_copy(box, splited, j);
		free_split(splited);
		list = list->next;
	}
	box->he->z[j] = NULL;
	box->he->color[j] = NULL;
}


int	main(int argc, char **argv)
{
	t_box	box;

	if (argc != 2)
		return (0);
	init_data(&box);
	p_map(&box, argv[1]);
	printf("| %ld | %s | \n", box.he->z[1][1], box.he->color[1][1]);
	free_box(&box);
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}
