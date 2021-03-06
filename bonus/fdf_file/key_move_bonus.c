/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:54:02 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:10:12 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	reset_key(t_box *box)
{
	box->move_x = 0;
	box->move_y = 0;
	box->height = 1;
	box->speed = 5;
	box->rotate_x = 0;
	box->rotate_y = 0;
	box->rotate_z = 0;
	box->len = 10;
	box->key->r = 0;
}

void	rotate_xyz(t_box *box)
{
	if (box->key->a == 1)
		box->rotate_x -= 0.02;
	if (box->key->d == 1)
		box->rotate_x += 0.02;
	if (box->key->w == 1)
		box->rotate_y -= 0.02;
	if (box->key->s == 1)
		box->rotate_y += 0.02;
	if (box->key->q == 1)
		box->rotate_z -= 0.02;
	if (box->key->e == 1)
		box->rotate_z += 0.02;
	if (box->rotate_x > 360.0 || box->rotate_x < -360.0)
		box->rotate_x = 0.0;
	if (box->rotate_y > 360.0 || box->rotate_y < -360.0)
		box->rotate_y = 0.0;
	if (box->rotate_z > 360.0 || box->rotate_z < -360.0)
		box->rotate_z = 0.0;
}

void	key_move2(t_box *box)
{
	if (box->key->up == 1 && box->move_y > -1000000)
		box->move_y --;
	if (box->key->down == 1 && box->move_y < 1000000)
		box->move_y++;
	if (box->key->left == 1 && box->move_x > -1000000)
		box->move_x--;
	if (box->key->right == 1 && box->move_x < 1000000)
		box->move_x++;
	if (box->key->z == 1 && box->height < 1000)
		box->height++;
	if (box->key->x == 1 && box->height > -1000)
		box->height--;
	if (box->key->minus == 1 && box->speed < 100)
		box->speed++;
	if (box->key->plus == 1 && box->speed > 1)
		box->speed--;
	rotate_xyz(box);
}

void	tab_press(t_box *box)
{
	static int	tab;

	if (box->key->tab == 1 && tab == 0)
	{
		if (box->help == 0)
			box->help = 1;
		else if (box->help == 1)
			box->help = 0;
		tab = 1;
	}
	if (box->key->tab == 0 && tab == 1)
		tab = 0;
}

int	key_move(t_box *box)
{
	key_move2(box);
	tab_press(box);
	if (box->key->r == 1)
		reset_key(box);
	if (box->key->zero == 1 || box->key->one == 1 || box->key->two == 1
		|| box->key->three == 1)
		color_scene(box);
	if (box->color_set == 1)
		rainbow_move(box, box->rainbow, 6);
	if (box->key->i == 1 && box->key->p == 0)
		box->view = 0;
	else if (box->key->i == 0 && box->key->p == 1)
		box->view = 1;
	if (box->key->esc == 1)
		ft_close(box);
	dr_map(box);
	return (0);
}
