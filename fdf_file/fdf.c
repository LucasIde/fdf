/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/04/26 19:40:44 by lide             ###   ########.fr       */
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

long	ft_atoi(const char *str)
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

int	len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*lstnew(long *arg)
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

void	p_map(char *argv, t_list **list)
{
	int		i;
	int		fd;
	long	*mod;
	char	*line;
	char	**splited;
	t_list	*new;

	i = -1;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	splited = ft_split(line, 32);
	mod = (long *)malloc(sizeof(long) * (len(splited) + 1));
	while (splited[++i])
	{
		mod[i] = ft_atoi(splited[i]);
		if (mod[i] == 2147483649)
			return ; //error
	}
	mod[i] = 2147483649;
	new = lstnew(mod);
	addback(list, new);
}

// int	main(int argc, char **argv)
// {
// 	t_box	box;
// 	t_list	*list;
// 	long *a;
// 	int i = -1;

// 	if (argc != 2)
// 		return (0);
// 	list = NULL;
// 	init_data(&box);
// 	p_map(argv[1], &list);
// 	a = (long*)list->content;
// 	while (a[++i] != 2147483649)
// 		printf("|%ld|\n", a[i]);
// 	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
// 	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
// 	mlx_loop(box.mlx_ptr);
// 	return (0);
// }

int	main(void)
{
	t_box	box;

	init_data(&box);
	dr_pixel(box.img, box.ci->x, box.ci->y, 0xE74C3C);
	mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img->img, 0, 0);
	// dr_line(&box);
	while (box.ce->x <= 1920)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->x++;
	}
	box.ce->x = 1920;
	while (box.ce->y <= 1080)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->y++;
	}
	box.ce->y = 1080;
	while (box.ce->x >= 0)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->x--;
	}
	box.ce->x = 0;
	while (box.ce->y >= 0)
	{
		box.ci->x = 960;
		box.ci->y = 540;
		dr_line(&box);
		box.ce->y--;
	}
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}
//parcing liste chainee gnl split les liste pour avoir tableau double entre
//gerer couleurs avec atoi
