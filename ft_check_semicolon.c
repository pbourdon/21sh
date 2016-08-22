/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_semicolon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 18:26:25 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 18:41:28 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft/includes/libft.h"

t_dlist		*ft_check_semicolon(char *arg, t_dlist *list)
{
	int		index;
	char	*str;

	str = malloc(sizeof(ft_strlen(arg) + 1));
	index = 0;
	while (arg[index] != '\0' && arg[index] != ';')
	{
		str[index] = arg[index];
		index++;
	}
	str[index] = '\0';
	index = index + 2;
	if (arg[index] != '\0' && index < ft_strlen(arg))
	{
		list = ft_choose(str, list);
		list = ft_check_semicolon(arg + index, list);
		free(str);
	}
	list = ft_choose(str, list);
	return (list);
}
