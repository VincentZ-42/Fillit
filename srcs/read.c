/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:35:33 by vzhao             #+#    #+#             */
/*   Updated: 2019/06/08 16:20:17 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			check_sum(char *s, int i)
{
	int sum;

	sum = 0;
	if (s[i - 5] == '#' && i >= 5)
		sum++;
	if (s[i + 5] == '#' && i + 5 < 20)
		sum++;
	if (s[i - 1] == '#' && i > 0)
		sum++;
	if (s[i + 1] == '#' && i + 1 < 20)
		sum++;
	return (sum);
}

/*
** This function checks the 4x4 block holding the Tetrimino
** and if all char is valid returns -1 on any errors
** and 1 on valid Tetrimino piece
*/

int			check_input(char *str, char newline_c, char width_c, char block_c)
{
	int i;
	int total;

	i = -1;
	total = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			newline_c++;
			ERROR(width_c != 4);
			width_c = 0;
		}
		else
		{
			ERROR(!(str[i] == '#' || str[i] == '.'));
			block_c += (str[i] == '#') ? 1 : 0;
			total += (str[i] == '#') ? check_sum(str, i) : 0;
			width_c++;
		}
	}
	ERROR(newline_c != 4 || block_c != 4 || (total != 6 && total != 8));
	return (1);
}

int			*get_coord(char *str, int *shape)
{
	int i;
	int elem;

	i = -1;
	elem = 0;
	while (str[++i])
		if (str[i] == '#')
			shape[elem++] = i;
	return (shape);
}

t_list		*read_file(int fd, t_list **head, char index)
{
	int		ret;
	char	temp[21];
	int		*shape;
	t_list	*node;

	if (!(shape = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while ((ret = read(fd, temp, TETRIS_SIZE)) > 0)
	{
		FREE_RET(ret < TETRIS_SIZE);
		temp[TETRIS_SIZE] = '\0';
		FREE_RET(check_input(temp, 0, 0, 0) < 0);
		shape = get_coord(temp, shape);
		node = ft_lstnew(shape, index++);
		ft_lstadd_end(head, node);
		FREE_RET(ft_lstcount(*head) > 26);
		read(fd, temp, 1);
	}
	free(shape);
	if (temp[0] == '\n')
	{
		ft_freelist(*head);
		return (NULL);
	}
	return (*head);
}

/*
** Reads the file and stores it into a str, then converts to an int array
** and stores it into a linked list
*/
