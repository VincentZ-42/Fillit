/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <vzhao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:13:17 by jiliu             #+#    #+#             */
/*   Updated: 2020/03/05 17:13:14 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
mvpiece
	- Function that converts the tetris piece's coordinates from a 5x5 board
	and scales its coordinates to match the boardsize
	- x[i] and y[i] are the coordinates of the piece's location in the board
	obtained by % the coordinates of the piece by 5
Args:
	t_list *tetris = pointer to node containing tetris piece
	int b = boardsize dimension
	int xmin = minimum starting value of where piece can be placed
	int st = start of current index on the board
Returns:
	int *temp = int array containing newly scaled boardsize
*/

int		*mvpiece(t_list *tetris, int b, int xmin, int st)
{
	int	i;
	int	x[5];
	int	y[5];
	int	*temp;
	int	ymin;

	i = 4;
	ymin = xmin;
	temp = (int*)malloc(sizeof(int) * 4);
	while (--i >= 0)
	{
		if ((x[i] = tetris->shape[i] % 5) < xmin)
			xmin = x[i];
		if ((y[i] = tetris->shape[i] / 5) < ymin)
			ymin = y[i];
	}
	while (++i < 4)
	{
		y[i] = y[i] - ymin;
		temp[i] = (tetris->shape[i] - xmin) - (ymin * 5);
		temp[i] = ((temp[i] > 4) ? temp[i] + (y[i] * (b - 4)) : temp[i]) + st;
	}
	return (temp);
}

/*
cvalidity
	- Function checks if placing the tetris piece onto the board is valid
Args:
	int *temp = int array of 4 elements of (#) representing Tetris piece 
	t_list *tetris = node holding all Tetris piece information
	char *board = string representing the board which piece is being placed on
Returns:
	1 for success
	0 for failure
*/

int		cvalidity(int *temp, t_list *tetris, char *board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (board[temp[i]] == '.')
			++i;
		else
			return (0);
	}
	if (i == 4)
	{
		while (j < 4)
		{
			board[temp[j]] = tetris->index;
			j++;
		}
		return (1);
	}
	return (0);
}

/*
rmpiece
	- Function that removes Tetris piece from the board by replacing
	the indexes with (.) characters
Args:
	int *temp = int array holding indexes of # of Tetris piece
	char *board = string that is holding Tetris piece that needs to be cleared
Returns:
	Nothing, manipulates pointers
*/

void	rmpiece(int *temp, char *board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		board[temp[i]] = '.';
		i++;
	}
}

/*
solve
	- Function that uses all of hte functions above to perform the 
	backtracking algorithim
Args:
	t_list *tetris = pointed to a node in linked list holding Tetris pieces
	char *board = string represent our board
	size_t b = dimension of the board
	int i = current index of the board
Returns:
	0 for failure
	1 for completely fitting all Tetris pieces onto single board
*/

int		solve(t_list *tetris, char *board, size_t b, int i)
{
	int *temp;

	if (tetris == NULL)
		return (1);
	while (board[i])
	{
		// This condition is to check if our index is still within
		// the board range
		if (i > (int)(b * b + b - 4))
			return (0);
		temp = mvpiece(tetris, b, 3, i);
		if (cvalidity(temp, tetris, board))
		{
			free(temp);
			if (solve(tetris->next, board, b, 0))
				return (1);
			temp = mvpiece(tetris, b, 3, i);
			rmpiece(temp, board);
			i++;
		}
		else
			i++;
		free(temp);
	}
	return (0);
}
