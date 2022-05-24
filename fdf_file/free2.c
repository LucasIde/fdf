/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:14:12 by lide              #+#    #+#             */
/*   Updated: 2022/05/24 16:59:57 by lide             ###   ########.fr       */
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
	else if (error == 6)
		write(2, "Error : malloc box->key\n", 24);
	else if (error == 7)
		write(2, "Error : malloc box->rainbow\n", 28);
}

void	free_data_malloc(t_box *box, int error)
{
	if (error > 0 && error < 8)
		print_init_error(error);
	if (error > 1)
		free(box->ci);
	if (error > 2)
		free(box->ce);
	if (error > 3)
		free(box->c_mid);
	if (error > 4)
		free(box->he);
	if (error > 5)
		free(box->img);
	if (error > 6)
		free(box->key);
	if (error > 7)
		free(box->rainbow);
}
