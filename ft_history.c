/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:00:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/14 19:51:06 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_run_history(char *arg, t_dlist *env, t_dlist *histo)
{
	int		index;
	int		number;

	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
			arg[index] == '\n')
		index++;
	if (arg[index] >= '0' && arg[index] <= '9')
	{
		number = ft_atoi(arg + index);
		ft_display_list4(histo, number);
		return;
	}
	else if (arg[index] == '\0')
	{
		ft_display_list3(histo);
		return;
	}
	if (arg[index] == '-')
		index++;
	if (ft_check_options_history(arg, 'c', index) == 1)
	{
		// need to delete list, but need to check his code before 
		// ft_delete_list3(&histo);
		return;
	}
	if (ft_check_options_history(arg, 'd', index) == 1)
	{
		index++;
		number = ft_atoi(arg + index);
		ft_del_ele_list(histo, number, histo->p_head, 0);
		while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
				arg[index] == '\n')
			index++;
		if (arg[index] == '-')
			index++;
	}
	if (ft_check_options_history(arg, 'a', index) == 1)
	{
		ft_write_history_file(histo, 0, ft_strjoin(ft_home(env), "/.42sh"));
		index++;
		while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
				arg[index] == '\n')
			index++;
		if (arg[index] == '-')
			index++;
		// on mets tout dans la liste, quand on ferme on doit rajouter dans le fichier
		// quand cette option est lance, il maj le fichier comme si on sortait maintenant du shell
	}
	if (ft_check_options_history(arg, 'n', index) == 1)
	{
		ft_get_check_file(histo, open(ft_strjoin(ft_home(env), "/.42sh"), O_RDONLY), 0, 0);
		// on recupere les lignes d'historique du fichier, et on ajoute celles non lues
		// cad celles ajoutees au fichier depuis l'ouverture du 42sh.
	}

}
