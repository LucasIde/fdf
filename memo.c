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

// void	dr_map(t_box *box)
// {
// 	int y_m;
// 	int x_m;
// 	int	i;
// 	int	j;
// 	int	j_m;
// 	int	x;
// 	int	y;
// 	int	height;

// 	x = 0;
// 	y = 0;
// 	height = 0;
// 	while (box->he->z[0][x] != 2147483649)
// 		x++;
// 	while (box->he->z[y])
// 		y++;
// 	i = -1;
// 	x_m = 0;
// 	j_m = 0;
// 	box->ci->color = COLOURS;
// 	while (++i < y)
// 	{
// 		// printf("|i %d-y %d\n",i,y);
// 		j = -1;
// 		y_m = 0;
// 		while (++j < x)
// 		{
// 			// printf("|j %d-x %d\n",j,x);
// 			if (j < x && box->he->z[i][j + 1] != 2147483649)
// 			{
// 				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
// 				box->ce->y = ((i + 1 + y_m - box->he->z[i][j + 1] + box->move_y) * box->len) + 400;
// 				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				box->ce->x = ((j + 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				// printf(" x = |%d , %d| |%d , %d|\n", box->ci->x, box->ci->y, box->ce->x, box->ce->y);
// 				dr_line(box);
// 			}
// 			if (i < y && box->he->z[i + 1])
// 			{
// 				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
// 				box->ce->y = ((i + 1 + y_m - box->he->z[i + 1][j] + box->move_y) * box->len) + 400;
// 				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				box->ce->x = ((j - 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				dr_line(box);
// 				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
// 			}
// 			j_m++;
// 			y_m++;
// 		}
// 		j_m = 0;
// 		x_m +=2;
// 	}
// 	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
// 	x = 0;
// 	y = 0;
// 	while (box->he->z[0][x] != 2147483649)
// 		x++;
// 	while (box->he->z[y])
// 		y++;
// 	i = -1;
// 	x_m = 0;
// 	j_m = 0;
// 	box->ci->color = 0x0;
// 	while (++i < y)
// 	{
// 		// printf("|i %d-y %d\n",i,y);
// 		j = -1;
// 		y_m = 0;
// 		while (++j < x)
// 		{
// 			// printf("|j %d-x %d\n",j,x);
// 			if (j < x && box->he->z[i][j + 1] != 2147483649)
// 			{
// 				if (box->he->z[i][j] != 0)
// 					height = box->height;
// 				else
// 					height = 0;
// 				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
// 				box->ce->y = ((i + 1 + y_m - box->he->z[i][j + 1] + box->move_y) * box->len) + 400;
// 				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				box->ce->x = ((j + 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				// printf(" x = |%d , %d| |%d , %d|\n", box->ci->x, box->ci->y, box->ce->x, box->ce->y);
// 				dr_line(box);
// 			}
// 			if (i < y && box->he->z[i + 1])
// 			{
// 				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
// 				box->ce->y = ((i + 1 + y_m - box->he->z[i + 1][j] + box->move_y) * box->len) + 400;
// 				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				box->ce->x = ((j - 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
// 				dr_line(box);
// 				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
// 			}
// 			j_m++;
// 			y_m++;
// 		}
// 		j_m = 0;
// 		x_m +=2;
// 	}
// }



		// // traveled = dif / traveled;
		// // printf("dif == %u\n", dif);
		// // printf("traveled == %u\n", traveled);
		// traveled = (dif - find_dif(box));
		// box->color = box->ci->color;
		// if (c->t_move != 0)
		// 	box->color += ((unsigned int)(c->t_move * (double)traveled)) * 16777216;
		// if (c->r_move != 0)
		// 	box->color += ((unsigned int)(c->r_move * (double)traveled)) * 65536;
		// if (c->g_move != 0)
		// {
		// 	box->color += ((unsigned int)(c->g_move * (double)traveled)) * 256;
		// 	// printf("%u\n", (unsigned int)(c->g_move * traveled) * 256);
		// }
		// if (c->g_move != 0)
		// 	box->color += ((unsigned int)(c->g_move * (double)traveled));
		// // printf("color %u color ce = %u\n", box->color, box->ce->color);
		// if (box->color > box->ce->color)
		// 	box->color = box->ce->color;
		// // if (traveled > c->t_move)
		// // {
		// // 	box->ci->color += 16777216;
		// // 	c->t_move += c->t_move;
		// // 	// printf("c_tmove == %u\n", c->t_move);
		// // }
		// // if (traveled > c->r_move)
		// // {
		// // 	box->ci->color += 65536;
		// // 	c->r_move += c->r_move;
		// // }
		// // if (traveled > c->g_move)
		// // {
		// // 	box->ci->color += 256;
		// // 	c->g_move += c->g_move;
		// // }
		// // if (traveled > c->b_move)
		// // {
		// // 	box->ci->color++;
		// // 	c->b_move += c->b_move;
		// // }
		// // printf("%u\n", box->ci->color);
		// // c->t_add = traveled / c->t_move;
		// // c->r_add = traveled / c->r_move;
		// // c->g_add = traveled / c->g_move;
		// // c->b_add = traveled / c->b_move;
		// // if (c->t_add != 0)
		// // if (c->r_add != 0)
		// // box->ci->color += c->r_add * pow(16, 4);
		// // if (c->g_add != 0)
		// // box->ci->color += c->g_add * pow(16, 2);
		// // box->ci->color += c->b_add;


// void	line_x(t_box *box, t_dr_map *m, int event)
// {
// 	box->ci->color = init_color(box, m->y, m->x, event);
// 	box->ce->color = init_color(box, m->y, m->x + 1, event);
// 	box->ci->y = m->y + m->iso_y;
// 	box->ci->y = (box->ci->y * box->len);
// 	box->ce->y = m->y + m->iso_y + 1;
// 	box->ce->y = (box->ce->y * box->len);
// 	box->ci->x = m->x + m->i - m->iso_x;
// 	box->ci->x = (box->ci->x * box->len);
// 	box->ce->x = m->x + m->i + 2 - m->iso_x;
// 	box->ce->x = (box->ce->x * box->len);
// 	box->ci->y -= ((m->len_y / 2) * box->len);
// 	box->ce->y -= ((m->len_y / 2) * box->len);
// 	box->ci->x -= ((m->len_x / 2) * box->len);
// 	box->ce->x -= ((m->len_x / 2) * box->len);
// 	x_axis(box, m);
// 	y_axis(box);
// 	z_axis(box);
// 	box->ci->y += box->move_y * box->len;
// 	box->ce->y += box->move_y * box->len;
// 	box->ci->x += box->move_x * box->len;
// 	box->ce->x += box->move_x * box->len;
// 	box->ci->y -= box->var_zi;
// 	box->ce->y -= box->var_ze;
// 	box->ci->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ce->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ci->x += 960 - ((m->len_x / 2) * box->len);
// 	box->ce->x += 960 - ((m->len_x / 2) * box->len);
// 	dr_line(box, event);
// }

// void	line_y(t_box *box, t_dr_map *m, int event)
// {
// 	box->ci->color = init_color(box, m->y, m->x, event);
// 	box->ce->color = init_color(box, m->y + 1, m->x, event);
// 	box->ci->y = m->y + m->iso_y;
// 	box->ci->y = (box->ci->y * box->len);
// 	box->ce->y = m->y + m->iso_y + 1;
// 	box->ce->y = (box->ce->y * box->len);
// 	box->ci->x = m->x + m->i - m->iso_x;
// 	box->ci->x = (box->ci->x * box->len);
// 	box->ce->x = m->x + m->i - 2 - m->iso_x;
// 	box->ce->x = (box->ce->x * box->len);
// 	box->ci->y -= ((m->len_y / 2) * box->len);
// 	box->ce->y -= ((m->len_y / 2) * box->len);
// 	box->ci->x -= ((m->len_x / 2) * box->len);
// 	box->ce->x -= ((m->len_x / 2) * box->len);
// 	x_axis2(box, m);
// 	y_axis2(box);
// 	z_axis2(box);
// 	box->ci->y += box->move_y * box->len;
// 	box->ce->y += box->move_y * box->len;
// 	box->ci->x += box->move_x * box->len;
// 	box->ce->x += box->move_x * box->len;
// 	box->ci->y -= box->var_zi;
// 	box->ce->y -= box->var_ze;
// 	box->ci->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ce->y += 540 - ((m->len_y / 2) * box->len);
// 	box->ci->x += 960 - ((m->len_x / 2) * box->len);
// 	box->ce->x += 960 - ((m->len_x / 2) * box->len);
// 	dr_line(box, event);
// }

// void	x_axis(t_box *box, t_dr_map *m)
// {
// 	double	y;
// 	double	z;

// 	y = box->ci->y;
// 	z = box->he->z[m->y][m->x] * (m->height * box->len);
// 	box->ci->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
// 	box->var_zi = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
// 	y = box->ce->y;
// 	z = box->he->z[m->y][m->x + 1] * (m->height2 * box->len);
// 	box->ce->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
// 	box->var_ze = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
// }

// void	y_axis(t_box *box)
// {
// 	double	x;
// 	double	z;

// 	x = box->ci->x;
// 	z = box->var_zi;
// 	box->ci->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
// 	box->var_zi = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
// 	x = box->ce->x;
// 	z = box->var_ze;
// 	box->ce->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
// 	box->var_ze = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
// }

// void	z_axis(t_box *box)
// {
// 	double	x;
// 	double	y;

// 	x = box->ci->x;
// 	y = box->ci->y;
// 	box->ci->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
// 	box->ci->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
// 	x = box->ce->x;
// 	y = box->ce->y;
// 	box->ce->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
// 	box->ce->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
// }

// void	x_axis2(t_box *box, t_dr_map *m)
// {
// 	double	y;
// 	double	z;

// 	y = box->ci->y;
// 	z = box->he->z[m->y][m->x] * (m->height * box->len);
// 	box->ci->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
// 	box->var_zi = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
// 	y = box->ce->y;
// 	z = box->he->z[m->y + 1][m->x] * (m->height2 * box->len);
// 	box->ce->y = (y * cos(box->rotate_y)) + (z * sin(box->rotate_y));
// 	box->var_ze = (-y * sin(box->rotate_y)) + (z * cos(box->rotate_y));
// }

// void	y_axis2(t_box *box)
// {
// 	double	x;
// 	double	z;

// 	x = box->ci->x;
// 	z = box->var_zi;
// 	box->ci->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
// 	box->var_zi = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
// 	x = box->ce->x;
// 	z = box->var_ze;
// 	box->ce->x = (z * sin(box->rotate_z)) + (x * cos(box->rotate_z));
// 	box->var_ze = (z * cos(box->rotate_z)) + (-x * sin(box->rotate_z));
// }

// void	z_axis2(t_box *box)
// {
// 	double	x;
// 	double	y;

// 	x = box->ci->x;
// 	y = box->ci->y;
// 	box->ci->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
// 	box->ci->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
// 	x = box->ce->x;
// 	y = box->ce->y;
// 	box->ce->x = (x * cos(box->rotate_x)) - (y * sin(box->rotate_x));
// 	box->ce->y = (x * sin(box->rotate_x)) + (y * cos(box->rotate_x));
// }
