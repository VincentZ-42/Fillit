/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <vzhao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:35:33 by vzhao             #+#    #+#             */
/*   Updated: 2020/03/05 16:36:31 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
check_sum
	- Function that quickly checks validity of Tetris piece by summing
	adjacent (#) characters above, below, left, and right of current index
Args:
	char *s = pointer to first character in string representing Tetris piece
	int i = index of # in current string representing Tetris piece
Returns:
	int sum = the total count of adjacent #s (should be 6 or 8)
*/

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
check_input
	- Function that checks the validity of Tetris piece according to 
	given instructions (check pdf intstructions for more details)
Args:
	char *str = string representing Tetris piece
	-NOTE: char variables used in place of integers to reduce memory usage
	char newline_c = character count of '\n' in string
	char width_c = character count of width of each line
	char block_c = character count of blocks (#) in each string
Returns:
	(integer)
	1 for valid Tetris piece
	-1 for invalid Tetris piece
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

/*
get_coord
	- Function that gets the index coordinates of 
	each block (#) in given string
Args:
	char *str = string representation of Tetris piece
	int *shape = empty int array used to store each #'s index in string
Returns:
	int *shape = int array of 4 elements (each element = index of #)
*/
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

/*
read_file
	- Function that reads the input file, and stores each tetris piece
	into a node with an index noting its order
Args:
	int fd = file descriptor of input file
	t_list **head = pointer to head of linked list (empty)
	char index = char index of Tetris piece
		Ex. A for 1st piece, B for 2nd piece, C for 3rd piece, etc
Returns:
	t_list *head = linked list of all Tetris pieces in order
*/

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
