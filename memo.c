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
