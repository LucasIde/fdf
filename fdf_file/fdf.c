/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/05/11 04:05:32 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print(t_box *box)
{
	int	y;
	int	x;

	y = -1;
	while (box->he->z[++y])
	{
		x = -1;
		while (box->he->z[y][++x] != 2147483649)
			printf("-| %ld , %s |-\n", box->he->z[y][x], box->he->color[y][x]);
		printf("\n");
	}
}

// void	test_map(t_box *box)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	y;
// 	int box->len;

// 	x = 0;
// 	y = 0;
// 	while (box->he->z[0][x] != 2147483649)
// 		x++;
// 	while (box->he->z[y])
// 		y++;
// 	box->len = 100;
// 	i = -1;

// 	while (++i <= y)
// 	{
// 		j = -1;
// 		while (++j <= x)
// 		{
// 			if (j < x)
// 			{
// 				box->ci->y = (i * box->len) + 400;
// 				box->ce->y = box->ci->y;
// 				box->ci->x = (j * box->len) + 400;
// 				box->ce->x = ((j + 1) * box->len) + 400;
// 				// printf(" x = |%d , %d|\n", box->ci->x, box->ce->x);
// 				dr_line(box);
// 			}
// 			if (i < y)
// 			{
// 				box->ci->y = (i * box->len) + 400;
// 				box->ce->y = ((i + 1) * box->len) + 400;
// 				box->ci->x = (j * box->len) + 400;
// 				box->ce->x = box->ci->x;
// 				dr_line(box);
// 				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
// 			}
// 		}
// 	}
// }

int	check_fdf(char *argv)
{
	int len;

	len = len_c(argv);
	if (argv[len - 1] != 'f' || argv[len - 2] != 'd'
		|| argv[len - 3] != 'f' || argv[len - 4] != '.')
	{
		write(2, "Error : only .fdf file is accepted\n", 35);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_box	box;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	if (check_fdf(argv[1]))
		return (0);
	init_data(&box);
	i = p_map(&box, argv[1]);
	if (i == -4 || i == -1)
		return (0);
	// print(&box);
	dr_map(&box);
	if (i == 0)
		i = -4;
	// freebox(i, &box);
	// system("leaks fdf");
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &key_press, &box);
	mlx_hook(box.win_ptr, 3, 1L << 0, &key_release, &box);
	mlx_hook(box.win_ptr, 4, 1L << 2, &scroll, &box);
	mlx_loop_hook(box.mlx_ptr, &key_move, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}


//truc a check :
//ajouter le close fd a close
//check error init data
//proteger mlx (init ...)
//free rainbow
