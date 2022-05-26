/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:14:12 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 16:59:46 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_init_error(int error)
{
	if (error == 1)
		write(2, "Error : malloc box->ci\n", 23);
	else if (error == 2)
		write(2, "Error : malloc box->ce\n", 23);
	else if (error == 3)
		write(2, "Error : malloc box->mid\n", 24);
	else if (error == 4)
		write(2, "Error : malloc box->he\n", 23);
	else if (error == 5)
		write(2, "Error : malloc box->img\n", 24);
}

void	free_data_malloc(t_box *box, int error, int verif)
{
	if (error > 0 && error < 6)
		print_init_error(error);
	if (error > 1)
		free(box->ci);
	if (error > 2)
		free(box->ce);
	if (error > 3)
		free(box->c_mid);
	if (error > 4)
		free(box->he);
	if (error > 5 && !verif)
		free(box->img);
}

void	free_p_map_error(t_box *box, int i)
{
	mlx_destroy_image(box->mlx_ptr, box->img);
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	freebox(i, box);
	free_data_malloc(box, 8, 1);
	exit (1);
}

void	free_init_malloc(t_box *box, int error, int event)
{
	if (event == 3)
		mlx_destroy_image(box->mlx_ptr, box->img);
	if (event >= 2)
		mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	if (event == 3)
		free_data_malloc(box, error, 1);
	if (event == 1 || event == 2)
		free_data_malloc(box, error, 0);
	write(2, "Error : init_data\n", 18);
	exit (1);
}

int	free_list_to_box_error(t_parcing *p)
{
	free_list(p->list);
	return (p->verif);
}
