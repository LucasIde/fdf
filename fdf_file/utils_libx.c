/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:27:36 by lide              #+#    #+#             */
/*   Updated: 2022/05/11 03:53:00 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close(int keycode)
{
	keycode = 0;
	exit(0);
	return (0);
}

int	scroll(int mouse, int x, int y, t_box *box)
{
	(void)x;
	(void)y;
	(void)box;
	if (mouse == 4)
		box->len += 1;
	else if (mouse == 5 && box->len > 1)
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
	else if (keycode == KEY_MINUS)
		box->key->minus = 0;
	else if (keycode == KEY_PLUS)
		box->key->plus = 0;
	else if (keycode == KEY_W)
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
	else if (keycode == KEY_0)
		box->key->zero = 0;
	else if (keycode == KEY_1)
		box->key->one = 0;
	else if (keycode == KEY_2)
		box->key->two = 0;
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
	else if (keycode == KEY_MINUS)
		box->key->minus = 1;
	else if (keycode == KEY_PLUS)
		box->key->plus = 1;
	else if (keycode == KEY_W)
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
	else if (keycode == KEY_0)
		box->key->zero = 1;
	else if (keycode == KEY_1)
		box->key->one = 1;
	else if (keycode == KEY_2)
		box->key->two = 1;
	else if (keycode == KEY_ESC)
		box->key->esc = 1;
	return (0);
}

void	reset_key(t_box *box)
{
	box->move_x = 0;
	box->move_y = 0;
	box->height = 1;
	box->len = 10;
	box->color_set = 0;
	box->key->r = 0;
}

void	color_scene(t_box *box)
{
	if (box->key->zero == 1 && box->key->one == 0 && box->key->two == 0)
		box->color_set = 0;
	if (box->key->zero == 0 && box->key->one == 1 && box->key->two == 0)
		box->color_set = 1;
	if (box->key->zero == 0 && box->key->one == 0 && box->key->two == 1)
		box->color_set = 2;
}

void	rainbow_move(unsigned int *template, int size)
{
	unsigned int	tmp;
	int				i;

	i = -1;
	tmp = template[0];
	while (++i < size)
		template[i] = template[i + 1];
	template[size] = tmp;
	// printf("%u\n", template[0]);
}

int	key_move(t_box *box)
{
	static int cmp;

	if (box->key->up == 1)
		box->move_y--;
	if (box->key->down == 1)
		box->move_y++;
	if (box->key->left == 1)
		box->move_x--;
	if (box->key->right == 1)
		box->move_x++;
	if (box->key->q == 1)
		box->height++;
	if (box->key->e == 1)
		box->height--;
	if (box->key->minus == 1)
		box->speed++;
	if (box->key->plus == 1)
		box->speed--;
	if (box->key->r == 1)
		reset_key(box);
	if (box->key->zero == 1 || box->key->one == 1 || box->key->two == 1 )
		color_scene(box);
	if (box->key->esc == 1)
	{
		free(box->img);
		close(0);
	}
	if (box->color_set == 1)
	{
		cmp++;
		if (cmp >= box->speed)
		{
			rainbow_move(box->rainbow, 6);
			cmp = 0;
		}
	}
	// printf("%d\n", box->speed);
	// printf("%d\n", cmp);
	dr_map(box);
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
	box->key->q = 0;
	box->key->e = 0;
	box->key->r = 0;
	box->key->up = 0;
	box->key->left = 0;
	box->key->down = 0;
	box->key->right = 0;
	box->key->minus = 0;
	box->key->plus = 0;
	box->key->esc = 0;
}

void	init_rainbow(unsigned int *tab)
{
	tab[0] = RED;
	tab[1] = ORANGE;
	tab[2] = YELLOW;
	tab[3] = GREEN;
	tab[4] = BLUE;
	tab[5] = INDIGO;
	tab[6] = VIOLET;
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
	box->rainbow = (unsigned int *)malloc(sizeof(unsigned int) * 7);
	if (!box->rainbow)
		return (1);
	init_rainbow(box->rainbow);
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
	box->height = 1;
	box->len = 10;
	box->color_set = 0;
	box->speed = 5;
	box->rotate = 1;
	set_value_key(box);
	return (0);
}
	// box->ci->x = 960;
	// box->ci->y = 540;
	// box->ce->x = 0;
	// box->ce->y = 0;
