/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/05/05 19:57:12 by lide             ###   ########.fr       */
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
	int y_m;
	int x_m;
	int	i;
	int	j;
	int	j_m;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (box->he->z[0][x] != 2147483649)
		x++;
	while (box->he->z[y])
		y++;
	i = -1;
	x_m = 0;
	j_m = 0;
	box->ci->color = COLOURS;
	while (++i < y)
	{
		// printf("|i %d-y %d\n",i,y);
		j = -1;
		y_m = 0;
		while (++j < x)
		{
			// printf("|j %d-x %d\n",j,x);
			if (j < x && box->he->z[i][j + 1] != 2147483649)
			{
				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
				box->ce->y = ((i + 1 + y_m - box->he->z[i][j + 1] + box->move_y) * box->len) + 400;
				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				box->ce->x = ((j + 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				// printf(" x = |%d , %d| |%d , %d|\n", box->ci->x, box->ci->y, box->ce->x, box->ce->y);
				dr_line(box);
			}
			if (i < y && box->he->z[i + 1])
			{
				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
				box->ce->y = ((i + 1 + y_m - box->he->z[i + 1][j] + box->move_y) * box->len) + 400;
				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				box->ce->x = ((j - 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				dr_line(box);
				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
			}
			j_m++;
			y_m++;
		}
		j_m = 0;
		x_m +=2;
	}
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->img->img, 0, 0);
	x = 0;
	y = 0;
	while (box->he->z[0][x] != 2147483649)
		x++;
	while (box->he->z[y])
		y++;
	i = -1;
	x_m = 0;
	j_m = 0;
	box->ci->color = 0x0;
	while (++i < y)
	{
		// printf("|i %d-y %d\n",i,y);
		j = -1;
		y_m = 0;
		while (++j < x)
		{
			// printf("|j %d-x %d\n",j,x);
			if (j < x && box->he->z[i][j + 1] != 2147483649)
			{
				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
				box->ce->y = ((i + 1 + y_m - box->he->z[i][j + 1] + box->move_y) * box->len) + 400;
				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				box->ce->x = ((j + 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				// printf(" x = |%d , %d| |%d , %d|\n", box->ci->x, box->ci->y, box->ce->x, box->ce->y);
				dr_line(box);
			}
			if (i < y && box->he->z[i + 1])
			{
				box->ci->y = ((i + y_m - box->he->z[i][j] + box->move_y) * box->len) + 400;
				box->ce->y = ((i + 1 + y_m - box->he->z[i + 1][j] + box->move_y) * box->len) + 400;
				box->ci->x = ((j + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				box->ce->x = ((j - 2 + j_m + box->move_x) * box->len) + 400 - (x_m * box->len);
				dr_line(box);
				// printf(" y = |%d , %d|\n", box->ci->y, box->ce->y);
			}
			j_m++;
			y_m++;
		}
		j_m = 0;
		x_m +=2;
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
	// printf("yo\n");
	// print(&box);
	test_map(&box);
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
// segfault si .txt vide
//chiffre a virgule (check_c et atoi)
//accepter que les .fdf
//check error init data
