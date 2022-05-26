/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:08:54 by lide              #+#    #+#             */
/*   Updated: 2022/05/26 19:32:28 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../get_next_line/get_next_line.h"
# include "struct.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define KEY_ESC 53

void			dr_pixel(t_data *img, int x, int y, int color);
void			dr_line(t_box *box, int end);
void			ft_swap(t_box *box);
void			addback(t_list **list, t_list *new);
void			list_next(t_list **list);
t_list			*lstnew(char *arg);
long			ft_atoi(char *str);
char			*ft_strdup(char *s1);
int				len_w(char **str);
int				len_c(char *str);
int				ft_close(t_box *box);
int				check_color(char *str, int len);
int				check_c(char *splited);
void			freebox(int error, t_box *box);
void			free_list(t_list *list);
void			free_data_malloc(t_box *box, int error, int verif);
void			free_init_malloc(t_box *box, int error, int event);
void			free_list_to_box_error(t_box *box, t_parcing *p);
void			free_p_map_error(t_box *box, int i);
void			free_split(char **splited);
int				p_map(t_box *box, char *argv);
int				ft_copy(t_box *box, char **splited, int y);
void			init_data(t_box *box);
int				key_press(int keycode, t_box *box);
void			dr_map(t_box *box);
unsigned int	hd_to_d(char *str);
void			set_color(t_box *box, int event, t_color *c);
unsigned int	init_color(t_box *box, int y, int x, int event);
void			find_delta(t_box *box, int *dy, int *dx);
int				check_rectangle(int y, t_copy *c, t_box *box);
void			color_and_pixel(t_box *box, t_color *c);
void			line_y_p(t_box *box, t_dr_map *m, int event);
void			line_x_p(t_box *box, t_dr_map *m, int event);
void			line_y_i(t_box *box, t_dr_map *m, int event);
void			line_x_i(t_box *box, t_dr_map *m, int event);
void			line_ci_i(t_box *box, t_dr_map *m, int event);
int				check_empty_line(t_parcing *p);

#endif
