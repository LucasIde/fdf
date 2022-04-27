/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/27 19:36:47 by lide             ###   ########.fr       */
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
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return (1);
	box->ci = malloc(sizeof(t_point));
	if (!box->ci)
		return (1);
	box->ct = malloc(sizeof(t_point));
	if (!box->ct)
		return (1);
	box->ce = malloc(sizeof(t_point));
	if (!box->ce)
		return (1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	box->ci->x = 960;
	box->ci->y = 540;
	box->ce->x = 0;
	box->ce->y = 0;
	return (0);
}


int	w_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	c_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*lstnew(char *arg)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->line = -1;
	list->content = (void *)arg;
	list->next = NULL;
	list->before = NULL;
	return (list);
}

void	addback(t_list **list, t_list *new)
{
	t_list	*tmp;

	tmp = *list;
	if (!list)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp->before = new;
		while (tmp->next != NULL && tmp->line != 1)
			tmp = tmp->next;
		if (tmp->line == 1)
			tmp->line = 0;
		new->next = *list;
		new->line = 1;
		new->before = tmp;
		tmp->next = new;
	}
}

// void	p_map(char *argv, t_list **list)
// {
// 	int		i;
// 	int		fd;
// 	long	*mod;
// 	char	*line;
// 	char	**splited;
// 	t_list	*new;

// 	i = -1;
// 	fd = open(argv, O_RDONLY);
// 	get_next_line(fd, &line);
// 	splited = ft_split(line, 32);
// 	mod = (long *)malloc(sizeof(long) * (len(splited) + 1));
// 	while (splited[++i])
// 	{
// 		mod[i] = ft_atoi(splited[i]);
// 		if (mod[i] == 2147483649)
// 			return ; //error
// 	}
// 	mod[i] = 2147483649;
// 	new = lstnew(mod);
// 	addback(list, new);
// }


char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *)malloc(sizeof(char) * (c_len(s1) + 1));
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

void	ft_copy(t_size ***size, char **splited, int j)
{
	int		i;
	int		x;
	int		verif;
	char	**str;
	long	tmp;

	i = -1;
	**size = (t_size *)malloc(sizeof(t_size) * w_len(splited));
	while (splited[++i])
	{
		verif = check_c(splited[i]);
		if (verif == -1)
			write(2, "error", 5);
		else if (verif == 1)
		{
			str = ft_split(splited[i], ',');
			tmp = atoi(str[0]);
			size[j][i]->si = tmp;
			x = c_len(str[1]);
			(*size)[j][i].colours = (char *)malloc(sizeof(char) * (x + 1));
			x = 0;
			while (str[1][x])
			{
				(*size)[j][i].colours[x] = str[1][x];
				x++;
			}
			(*size)[j][i].colours[x] = '\0';
		}
		else
		{
			tmp = atoi(splited[i]);
			if (tmp == 2147483649)
				write(2, "error", 5);
			size[j][i]->si = (int)tmp;
			(*size)[j][i].colours = NULL;
		}
	}
}

t_size	**p_map(char *argv)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**splited;
	t_list	*list;
	t_list	*new;
	t_size	**size;

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
	size = (t_size **)malloc(sizeof(t_size *) * (i + 1));
	while (++j <= i)
	{
		splited = ft_split((char *)list->content, ' ');
		// printf("|\n%s|\n", (char *)list->content);
		ft_copy(&size, splited, j);
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_box	box;
	t_size	**size;
	// int i = -1;

	if (argc != 2)
		return (0);
	init_data(&box);
	size = p_map(argv[1]);
	// printf("%d\n", size[0][3].si);
	// while (a[++i] != 2147483649)
	// 	printf("|%ld|\n", a[i]);
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	t_box	box;

// 	init_data(&box);
// 	dr_pixel(box.img, box.ci->x, box.ci->y, 0xff);
// 	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img->img, 0, 0);
// 	// dr_line(&box);
// 	while (box.ce->x <= 1920)
// 	{
// 		box.ci->x = 960;
// 		box.ci->y = 540;
// 		dr_line(&box);
// 		box.ce->x++;
// 	}
// 	box.ce->x = 1920;
// 	while (box.ce->y <= 1080)
// 	{
// 		box.ci->x = 960;
// 		box.ci->y = 540;
// 		dr_line(&box);
// 		box.ce->y++;
// 	}
// 	box.ce->y = 1080;
// 	while (box.ce->x >= 0)
// 	{
// 		box.ci->x = 960;
// 		box.ci->y = 540;
// 		dr_line(&box);
// 		box.ce->x--;
// 	}
// 	box.ce->x = 0;
// 	while (box.ce->y >= 0)
// 	{
// 		box.ci->x = 960;
// 		box.ci->y = 540;
// 		dr_line(&box);
// 		box.ce->y--;
// 	}
// 	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
// 	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
// 	mlx_loop(box.mlx_ptr);
// 	return (0);
// }
// //parcing liste chainee gnl split les liste pour avoir tableau double entre
// //gerer couleurs avec atoi
