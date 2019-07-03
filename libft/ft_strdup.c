/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:19 by vzhao             #+#    #+#             */
/*   Updated: 2019/05/16 17:03:49 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
