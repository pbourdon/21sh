/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:34:16 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/19 16:19:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_process(char *line, t_dlist *env, t_dlist *histo)
{
	int		total;
	char	*line2;
	char	**str;
	int		compteur;

	compteur = 0;
	total = ft_detect_dot_coma(line);
	if (total > 1)
	{
		str = ft_separate_dot_coma(str, line, total);
		while (compteur < total)
		{
			line2 = ft_delete_tab(str[compteur]);
			env = ft_choose(line2, env, histo);
			compteur++;
			free(line2);
			line2 = NULL;
		}
	}
	else
	{
		line2 = ft_delete_tab(line);
		env = ft_choose(line2, env, histo);
		free(line2);
	}
	free(line);
	if (env == NULL)
		return (1);
	ft_show_prompt();
	return (0);
}
