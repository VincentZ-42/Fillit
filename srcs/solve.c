/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:13:17 by jiliu             #+#    #+#             */
/*   Updated: 2019/07/03 12:36:56 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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
** This moves the piece to the top left hand corner of the board and
** scales it to the size of the board.
** x[i] and y[i] are the coordinates of the piece's location in the board,
** obtained by % / / the coordinates of the piece respectively by 5
** , which accounts for the \n each row.
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

int		solve(t_list *tetris, char *board, size_t b, int i)
{
	int *temp;

	if (tetris == NULL)
		return (1);
	while (board[i])
	{
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
