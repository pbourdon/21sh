/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:34:16 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:44:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_process(char *line, t_dlist *env)
{
	char	*line2;

	line2 = ft_delete_tab(line);
	env = ft_choose(line2, env);
	free(line2);
	free(line);
	if (env == NULL)
		return (1);
	ft_show_prompt();
	return (0);
}
