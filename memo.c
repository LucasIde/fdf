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




// int	p_map(t_box *box, char *argv)
// {
// 	int		i;
// 	int		j;
// 	int		fd;
// 	int		tmp;
// 	char	*line;
// 	char	**splited;
// 	t_list	*list;
// 	t_list	*new;

// 	i = 1;
// 	j = -1;
// 	list = NULL;
// 	fd = open(argv, O_RDONLY);
// 	tmp = fd;
// 	while (i == 1)
// 	{
// 		i = get_next_line(fd, &line);
// 		if (i == -1)
// 		{
// 			free_list(list);
// 			return (-1);
// 		}
// 		if (i == 0)
// 			break;
// 		new = lstnew(line);
// 		if (!new)
// 		{
// 			if (!list)
// 				free(line);
// 			free_list(list);
// 			get_next_line(-1, NULL);
// 			write(2, "Error : Malloc lstnew\n", 22);
// 			return (-1);
// 		}
// 		addback(&list, new);
// 	}
// 	while (list->next != NULL && list->next->line != -1)
// 	{
// 		i++;
// 		list = list->next;
// 	}
// 	if (list->next != NULL)
// 		list = list->next;
// 	box->he->z = (long **)malloc(sizeof(long *) * (i + 2));
// 	if (!box->he->z)
// 	{
// 		free_list(list);
// 		write(2, "Error : Malloc 1 p_map\n", 23);
// 		return (-1);
// 	}
// 	box->he->color = (char ***)malloc(sizeof(char **) * (i + 2));
// 	if (!box->he->color)
// 	{
// 		free_list(list);
// 		write(2, "Error : Malloc 2 p_map\n", 23);
// 		return (-2);
// 	}
// 	while (++j <= i)
// 	{
// 		splited = ft_split((char *)list->content, ' ');
// 		fd = ft_copy(box, splited, j);
// 		free_split(splited);
// 		if (fd < 0)
// 		{
// 			free_list(list);
// 			return (fd);
// 		}
// 		if (list->next != NULL)
// 			list = list->next;
// 	}
// 	free_list(list);
// 	box->he->z[j] = NULL;
// 	box->he->color[j] = NULL;
// 	// close(tmp);
// 	return (0);
// }



// int	ft_copy(t_box *box, char **splited, int j)
// {
// 	int		i;
// 	int		x;
// 	int		len;
// 	int		verif;
// 	char	**str;
// 	long	tmp;

// 	i = -1;
// 	x = len_w(splited);
// 	box->he->z[j] = (long *)malloc(sizeof(long) * x);
// 	if (!box->he->z[j])
// 	{
// 		write (2, "Error : Malloc 1 ft_copy\n", 25);
// 		return (-3);
// 	}
// 	box->he->color[j] = (char **)malloc(sizeof(char *) * (x + 1));
// 	if (!box->he->color[j])
// 	{
// 		write (2, "Error : Malloc 2 ft_copy\n", 25);
// 		return (-4);
// 	}
// 	box->he->color[j][x] = NULL;
// 	while (splited[++i])
// 	{
// 		verif = check_c(splited[i]);
// 		if (verif == -1)
// 		{
// 			free(box->he->color[j]);
// 			box->he->color[j]=NULL;
// 			write(2, "Error : a comma is missing before the colors\n", 45);
// 			return (-4);
// 		}
// 		else if (verif == 1)
// 		{
// 			str = ft_split(splited[i], ',');
// 			tmp = ft_atoi(str[0]);
// 			if (tmp == 2147483649)
// 			{
// 				free_split(str);
// 				free(box->he->color[j]);
// 				box->he->color[j]=NULL;
// 				write(2, "Error : value superior to an int\n", 33);
// 				return (-4);
// 			}
// 			box->he->z[j][i] = (int)tmp;
// 			len = len_c(str[1]);
// 			tmp = check_color(str[1], len);
// 			if (tmp == 1)
// 			{
// 				free_split(str);
// 				free(box->he->color[j]);
// 				box->he->color[j]=NULL;
// 				write(2, "Error : wrong color\n", 20);
// 				return (-4);
// 			}
// 			box->he->color[j][i] = (char *)malloc(sizeof(char) * (len + 1));
// 			if (!box->he->color[j][i])
// 			{
// 				free_split(str);
// 				free(box->he->color[j]);
// 				box->he->color[j]=NULL;
// 				write(2, "Error : Malloc 3 ft_copy\n", 25);
// 				return (-4);
// 			}
// 			x = -1;
// 			while (str[1][++x])
// 				box->he->color[j][i][x] = str[1][x];
// 			box->he->color[j][i][x] = '\0';
// 			free_split(str);
// 		}
// 		else
// 		{
// 			tmp = ft_atoi(splited[i]);
// 			if (tmp == 2147483649)
// 			{
// 				free(box->he->color[j]);
// 				box->he->color[j]=NULL;
// 				write(2, "Error : value superior to an int\n", 33);
// 				return (-4);
// 			}
// 			box->he->z[j][i] = (int)tmp;
// 			box->he->color[j][i] = (char *)malloc(sizeof(char) * 1);
// 			if (!box->he->color[j][i])
// 			{
// 				free(box->he->color[j]);
// 				box->he->color[j]=NULL;
// 				write(2, "Error : Malloc 4 ft_copy\n", 25);
// 				return (-4);
// 			}
// 			box->he->color[j][i][0] = '\0';
// 		}
// 	}
// 	return (0);
// }
