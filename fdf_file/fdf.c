/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/05/03 17:36:15 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print(t_box *box)
{
	int y;
	int x;

	y = -1;
	while (box->he->z[++y])
	{
		x = -1;
		while (box->he->z[y][++x] != 2147483649)
			printf("-| %ld , %s |-\n", box->he->z[y][x], box->he->color[y][x]);
		printf("\n");
	}
}

void	test_map(t_box *box)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int len;

	x = 0;
	y = 0;
	while (box->he->z[0][x] != 2147483649)
		x++;
	while (box->he->z[y])
		y++;
	len = 100;
	i = -1;

	while (++i <= y)
	{
		j = -1;
		while (++j <= x)
		{
			if (j < x)
			{
				box->ci->y = (i * len) + 40;
				box->ce->y = box->ci->y;
				box->ci->x = (j * len) + 60;
				box->ce->x = ((j + 1) * len) + 60;
				// printf(" x = |%d , %d|\n", box->ci->x, box->ce->x);
				dr_line(box);
			}
			if (i < y)
			{
				box->ci->y = (i * len) + 40;
				box->ce->y = ((i + 1) * len) + 40;
				box->ci->x = (j * len) + 60;
				box->ce->x = box->ci->x;
				dr_line(box);
				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_box	box;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	init_data(&box);
	// box.he = malloc(sizeof(t_height));
	// if (!box.he)
	// 	return (1);
	// box.he->color = NULL;
	// box.he->z = NULL;
	i = p_map(&box, argv[1]);
	printf("yo\n");
	print(&box);
	test_map(&box);
	if (i == 0)
		i = -4;
	// freebox(i, &box);
	// system("leaks fdf");
	mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	mlx_loop(box.mlx_ptr);
	return (0);
}
