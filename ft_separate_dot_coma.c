/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_dot_coma.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 11:11:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 12:00:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_get_str(char *tab3, char *str, int mem)
{
	int		index2;
	int		alpha;

	alpha = 0;
	index2 = 0;
	while (index2 < mem)
	{
		tab3[alpha] = str[index2];
		alpha++;
		index2++;
	}
	tab3[alpha] = '\0';
	ft_putstr(tab3);
	return (tab3);
}

char		**ft_separate_dot_coma(char **tab3, char *line, int total)
{
	int		index;
	int		mem;
	int		compteur;

	index = 0;
	mem = 0;
	compteur = 0;
	tab3 = malloc(sizeof(char *) * total);
	while (line[index] != '\0')
	{
		if (line[index] == ';')
		{
			tab3[compteur] = malloc(sizeof(char) * mem + 1);
			tab3[compteur] = ft_get_str(tab3[compteur], line, mem);
			compteur++;
			mem = 0;
		}
		else if (line[index] == '\0')
		{
			tab3[compteur] = malloc(sizeof(char) * mem + 1);
			tab3[compteur] = ft_get_str(tab3[compteur], line, mem);
			compteur++;
			mem = 0;
		}
		mem++;
		index++;
	}
	return (tab3);
}
