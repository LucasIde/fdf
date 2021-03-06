/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:11:08 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 17:10:12 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	key_release_letter(int keycode, t_box *box)
{
	if (keycode == KEY_W)
		box->key->w = 0;
	else if (keycode == KEY_A)
		box->key->a = 0;
	else if (keycode == KEY_S)
		box->key->s = 0;
	else if (keycode == KEY_D)
		box->key->d = 0;
	else if (keycode == KEY_Q)
		box->key->q = 0;
	else if (keycode == KEY_E)
		box->key->e = 0;
	else if (keycode == KEY_Z)
		box->key->z = 0;
	else if (keycode == KEY_X)
		box->key->x = 0;
	else if (keycode == KEY_I)
		box->key->i = 0;
	else if (keycode == KEY_P)
		box->key->p = 0;
	else if (keycode == KEY_TAB)
		box->key->tab = 0;
}

int	key_release(int keycode, t_box *box)
{
	key_release_letter(keycode, box);
	if (keycode == KEY_MINUS)
		box->key->minus = 0;
	else if (keycode == KEY_PLUS)
		box->key->plus = 0;
	else if (keycode == KEY_0 || keycode == KEY_0_N)
		box->key->zero = 0;
	else if (keycode == KEY_1 || keycode == KEY_1_N)
		box->key->one = 0;
	else if (keycode == KEY_2 || keycode == KEY_2_N)
		box->key->two = 0;
	else if (keycode == KEY_3 || keycode == KEY_3_N)
		box->key->three = 0;
	else if (keycode == KEY_UP)
		box->key->up = 0;
	else if (keycode == KEY_LEFT)
		box->key->left = 0;
	else if (keycode == KEY_DOWN)
		box->key->down = 0;
	else if (keycode == KEY_RIGHT)
		box->key->right = 0;
	else if (keycode == KEY_ESC)
		box->key->esc = 0;
	return (0);
}

void	key_press_letter(int keycode, t_box *box)
{
	if (keycode == KEY_W)
		box->key->w = 1;
	else if (keycode == KEY_A)
		box->key->a = 1;
	else if (keycode == KEY_S)
		box->key->s = 1;
	else if (keycode == KEY_D)
		box->key->d = 1;
	else if (keycode == KEY_Q)
		box->key->q = 1;
	else if (keycode == KEY_E)
		box->key->e = 1;
	else if (keycode == KEY_R)
		box->key->r = 1;
	else if (keycode == KEY_Z)
		box->key->z = 1;
	else if (keycode == KEY_X)
		box->key->x = 1;
	else if (keycode == KEY_I)
		box->key->i = 1;
	else if (keycode == KEY_P)
		box->key->p = 1;
	else if (keycode == KEY_TAB)
		box->key->tab = 1;
}

int	key_press(int keycode, t_box *box)
{
	key_press_letter(keycode, box);
	if (keycode == KEY_MINUS)
		box->key->minus = 1;
	else if (keycode == KEY_PLUS)
		box->key->plus = 1;
	else if (keycode == KEY_0 || keycode == KEY_0_N)
		box->key->zero = 1;
	else if (keycode == KEY_1 || keycode == KEY_1_N)
		box->key->one = 1;
	else if (keycode == KEY_2 || keycode == KEY_2_N)
		box->key->two = 1;
	else if (keycode == KEY_3 || keycode == KEY_3_N)
		box->key->three = 1;
	else if (keycode == KEY_UP)
		box->key->up = 1;
	else if (keycode == KEY_LEFT)
		box->key->left = 1;
	else if (keycode == KEY_DOWN)
		box->key->down = 1;
	else if (keycode == KEY_RIGHT)
		box->key->right = 1;
	else if (keycode == KEY_ESC)
		box->key->esc = 1;
	return (0);
}
