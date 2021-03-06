/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:17:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:17:06 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

char		*transformtab(char *str)
{
	int		i;
	char	*dst;
	int		o;

	o = 0;
	dst = ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		while (str[i] == 9)
		{
			dst[o] = ' ';
			i++;
			o++;
		}
		dst[o] = str[i];
		o++;
		i++;
	}
	dst[o] = '\0';
	ft_memdel((void *)&str);
	return (dst);
}

char		*withoutspace(char *str)
{
	int		i;
	char	*dst;
	int		o;
	int		turn;

	turn = 0;
	o = 0;
	dst = (char *)malloc(sizeof(char ) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		while ((str[i] == 32 || str[i] == 9) && turn == 0)
		{
			i++;
		}
		turn = 1;
		dst[o] = str[i];
		i++;
		o++;
	}
	dst[o] = '\0';
	ft_strdel(&str);
	return (dst);
}

int			countstr(char *str, int i)
{
	while (str[i] != '&')
	{
		if (str[i] == '\0')
			return (-2);
		i++;
	}
	return (i);
}
