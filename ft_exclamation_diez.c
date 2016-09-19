/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclamation_diez.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:28:41 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/19 15:51:42 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_exclamation_diez(char *str)
{
	int		index;
	char	*tmp;

	tmp = malloc(sizeof(char) * ft_strlen(str));
	while (str[index] != '\0')
	{
		if (str[index] == '!' && str[index + 1] == '#')
		{
			tmp[index] = '\0';
			return (tmp);
		}
		tmp[index] = str[index];
		index++;
	}
	return (NULL);
}
