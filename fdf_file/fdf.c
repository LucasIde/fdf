/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:44:27 by lide              #+#    #+#             */
/*   Updated: 2022/05/02 18:36:44 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_box	box;
	int		i;

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
	printf("| %ld | %s | \n", box.he->z[1][0], box.he->color[1][0]);
	if (i == 0)
		i = -4;
	freebox(i, &box);
	system("leaks fdf");
	// mlx_hook(box.win_ptr, 17, 1L << 17, close, &box);
	// mlx_hook(box.win_ptr, 2, 1L << 0, &ft_key, &box);
	// mlx_loop(box.mlx_ptr);
	return (0);
}
