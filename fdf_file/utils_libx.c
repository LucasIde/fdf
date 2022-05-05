/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:27:36 by lide              #+#    #+#             */
/*   Updated: 2022/05/05 19:37:26 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

// void	win_reset(t_box *box)
// {
// 	int y;

// 	y = 0;
// 	box->ci->x = 0;
// 	box->ce->x = 1920;
// 	while (y < 1081)
// 	{
// 		box->ci->y = y;
// 		box->ce->y = y;
// 		y++;
// 		dr_line(box);
// 	}
// }

int	scroll(int mouse, int x, int y, t_box *box)
{
	(void)x;
	(void)y;
	(void)box;
	if (mouse == 4)
		box->len += 1;
	else if (mouse == 5 /*&& box->len > 0*/)
		box->len -= 1;
	return (0);
}

int	key_release(int keycode, t_box *box)
{
	if (keycode == KEY_UP)
		box->key->up = 0;
	else if (keycode == KEY_LEFT)
		box->key->left = 0;
	else if (keycode == KEY_DOWN)
		box->key->down = 0;
	else if (keycode == KEY_RIGHT)
		box->key->right = 0;
	else if (keycode == KEY_W)
		box->key->w = 0;
	else if (keycode == KEY_A)
		box->key->a = 0;
	else if (keycode == KEY_S)
		box->key->s = 0;
	else if (keycode == KEY_D)
		box->key->d = 0;
	else if (keycode == KEY_ESC)
		box->key->esc = 0;
	return (0);
}

int	key_press(int keycode, t_box *box)
{
	if (keycode == KEY_UP)
		box->key->up = 1;
	else if (keycode == KEY_LEFT)
		box->key->left = 1;
	else if (keycode == KEY_DOWN)
		box->key->down = 1;
	else if (keycode == KEY_RIGHT)
		box->key->right = 1;
	else if (keycode == KEY_W)
		box->key->w = 1;
	else if (keycode == KEY_A)
		box->key->a = 1;
	else if (keycode == KEY_S)
		box->key->s = 1;
	else if (keycode == KEY_D)
		box->key->d = 1;
	else if (keycode == KEY_ESC)
		box->key->esc = 1;
	return (0);
}

int	key_move(t_box *box)
{
	if (box->key->up == 1)
		box->move_y--;
	if (box->key->down == 1)
		box->move_y++;
	if (box->key->left == 1)
		box->move_x--;
	if (box->key->right == 1)
		box->move_x++;
	if (box->key->esc == 1)
	{
		free(box->img);
		close(0);
	}
	// if (box->key->up == 1 || box->key->down == 1 || box->key->left == 1 || box->key->right == 1)
	test_map(box);
	return (0);
}

void	dr_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_value_key(t_box *box)
{
	box->key->w = 0;
	box->key->a = 0;
	box->key->s = 0;
	box->key->d = 0;
	box->key->up = 0;
	box->key->left = 0;
	box->key->down = 0;
	box->key->right = 0;
	box->key->esc = 0;
}

int	init_data(t_box *box)
{
	box->ci = malloc(sizeof(t_point));
	if (!box->ci)
		return (1);
	box->ce = malloc(sizeof(t_point));
	if (!box->ce)
		return (1);
	box->he = malloc(sizeof(t_height));
	if (!box->he)
		return (1);
	box->img = malloc(sizeof(t_data));
	if (!box->img)
		return (1);
	box->key = malloc(sizeof(t_key_set));
	if (!box->key)
		return (1);
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		return (1);
	box->win_ptr = mlx_new_window(box->mlx_ptr, 1920, 1080, "defenestrer");
	box->img->img = mlx_new_image(box->mlx_ptr, 1920, 1080);
	box->img->addr = mlx_get_data_addr(box->img->img, &box->img->bits_per_pixel,
			&box->img->line_lenght, &box->img->endian);
	box->he->color = NULL;
	box->he->z = NULL;
	box->move_x = 0;
	box->move_y = 0;
	box->len = 10;
	set_value_key(box);
	return (0);
}
	// box->ci->x = 960;
	// box->ci->y = 540;
	// box->ce->x = 0;
	// box->ce->y = 0;
