/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:24:04 by vzhao             #+#    #+#             */
/*   Updated: 2019/06/08 16:18:31 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR(x) if (x) return (-1);
# define FREE_RET(x) if (x){ free(shape); return (NULL); }
# define TETRIS_SIZE 20

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

int		check_input(char *str, char newline_c, char width_c, char bock_c);
int		check_sum(char *s, int i);
int		*get_coord(char *str, int *shape);
t_list	*read_file(int fd, t_list **head, char index);

char	*fillboard(t_list *tetris, size_t p);
int		solve(t_list *tetris, char *board, size_t b, int i);
void	rmpiece(int *temp, char *board);
int		cvalidity(int *temp, t_list *tetris, char *board);
int		complete(char *board, size_t p);
int		*mvpiece(t_list *tetris, int b, int xmin, int st);
char	*boardsize(size_t b);

#endif
