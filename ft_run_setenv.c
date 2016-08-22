/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 01:16:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 18:06:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft/includes/libft.h"

t_dlist			*modify_element(t_dlist *list, char *arg, int index, int pos)
{
	char	*new;
	char	*tmp;
	char	*tmp3;

	tmp = ft_strcup(arg + index);
	pos = ft_search_list(list, tmp);
	new = ft_strdup(arg + index + ft_strlen(tmp));
	tmp3 = ft_strjoin(tmp, new);
	free(new);
	if (pos != 0)
	{
		list = ft_del_ele_list(list, pos, list->p_head, 1);
		if (pos >= ft_list_size(list->p_head))
			ft_add_data(list, tmp3);
		else
			list = ins_avant(list, tmp3, list->p_head, pos);
	}
	else
	{
		pos = ft_list_size(list->p_head) + 1;
		list = ft_add_data(list, tmp3);
	}
	free(tmp);
	free(tmp3);
	return (list);
}

void			ft_run_setenv(char *arg, t_dlist *list)
{
	int			index;

	index = 6;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n' ||
		arg[index] == '\r')
		index++;
	list = modify_element(list, arg, index, 0);
}
