/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <vzhao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:31:23 by jiliu             #+#    #+#             */
/*   Updated: 2020/03/05 16:52:13 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
boardsize
	- Function that creates a empty string of (.) and (\n) representing
	our empty board that will be filled later
Args:
	size_t b = the board dimension (b of 3 would create a 3x3 board)
Returns:
	char *board = a string representing our empty board
*/

char	*boardsize(size_t b)
{
	char	*board;
	size_t	i;
	size_t	x;
	int		j;

	x = b;
	i = b * (b + 1);
	board = (char*)malloc(sizeof(char) * (i + 1));
	board[i] = '\0';
	j = i - 2;
	while (j >= 0)
	{
		board[j] = '.';
		j--;
	}
	board[0] = '.';
	while (x < i)
	{
		board[x] = '\n';
		x += (b + 1);
	}
	return (board);
}

/*
fillboard
	- Function that continutally attempts to fill the board 
	with the all tetris pieces. Each failed attempt will increase the
	boardsize by 1
	- Ex a 3x3 board will become a 4x4 board if alogrithim fails to fill
Args:
	t_list *tetris = linked list holding each Tetris piece in each node
	size_t p = number of tetris pieces from input
Returns:
	char *board = a string containing the all Tetris pieces fitted onto
		the smallest board
*/

char	*fillboard(t_list *tetris, size_t p)
{
	size_t	b;
	char	*board;
	int		j;

	j = 0;
	if (!tetris)
		return (NULL);
	b = 2;
	// We start with the smallest board size (2x2) and expand our board
	// depending on how much pieces that are read from the input file
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

/*
main
	- Function that reads the input file, checks if input file is valid,
	converts input file into linked list of Tetris pieces, and then 
	implements backtracking algorithim to look for solution of fitting
	all Tetris pieces into smallest square map
Args:
	int ac = argument counter (should be 2; 1 for executable, 1 for input file)
	char **av = argument vector (should be 2; same as above)
Returns:
	0
	Outputs either error, usage case, or smallest square map with all 
	Tetris pieces
*/

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
