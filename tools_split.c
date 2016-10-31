/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:17:11 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:17:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int				add_token(char *str)
{
	int			ret;

	ret = 0;
	while (str && *str && ft_isdigit(*str))
		str += 1;
	if (ft_strstr(str, ">&") != NULL || ft_strstr(str, "<&") != NULL)
		ret = AGGR;
	else if (!(ft_strncmp(str, ">", 1)) || !(ft_strncmp(str, "<", 1)) ||
	!(ft_strcmp(str, "|")))
		ret = REDDIR;
	else if (!(ft_strcmp(str, "&&")) || !(ft_strcmp(str, "||")))
		ret = OPBI;
	else if (!(ft_strcmp(str, ";")))
		ret = SEPP;
	else if (!(ft_strcmp(str, "`")))
		ret = BACK;
	return (ret);
}

t_liste			*create_list(void)
{
	t_liste		*liste;

	if (!(liste = ft_memalloc(sizeof(t_liste))))
		return (NULL);
	liste->next = NULL;
	liste->arg = NULL;
	return (liste);
}
