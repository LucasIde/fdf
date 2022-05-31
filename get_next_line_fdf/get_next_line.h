/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:26 by lide              #+#    #+#             */
/*   Updated: 2022/04/27 15:53:31 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		backspace(char *s);
int		ft_find(char *s);
int		ft_strlen(char *s);
char	*ft_line(char *save, int len);
char	*ft_save(char *save, int len);
int		get_next_line(int fd, char **line);
char	*ft_read(int fd, char *save);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
char	**ft_split(char const *s, char c);

#endif
