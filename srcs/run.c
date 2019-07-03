/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:31:23 by jiliu             #+#    #+#             */
/*   Updated: 2019/07/03 12:36:42 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*fillboard(t_list *tetris, size_t p)
{
	size_t	b;
	char	*board;
	int		j;

	j = 0;
	if (!tetris)
		return (NULL);
	b = 2;
	while (p * 4 > b * b)
		b++;
	board = boardsize(b);
	while (!solve(tetris, board, b, 0))
	{
		if (b > p + 3)
			break ;
		free(board);
		b++;
		board = boardsize(b);
	}
	return (board);
}

int		main(int ac, char **av)
{
	int		fd;
	t_list	*head;
	char	*board;

	head = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		head = read_file(fd, &head, 'A');
		if (fd < 0 || head == NULL)
		{
			write(1, "error\n", 6);
			ft_freelist(head);
			return (0);
		}
		ft_putstr(board = fillboard(head, ft_lstcount(head)));
		ft_freelist(head);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
