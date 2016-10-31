/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdcall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:04:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:04:55 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	cd_call_norm(t_data *data)
{
	char *str;

	if (ft_strlentab(data->args) < 4)
	{
		str = NULL;
		cdcall2(data, str);
	}
	else
	{
		ft_putendl_fd("cd: too many arguments", 2);
		data->binreturn = 255;
	}
	free_new_env(data->args);
	data->args = NULL;
}

void	cdcall(t_data *data)
{
	char	*str;

	data->binreturn = 0;
	if (ft_strlentab(data->args) == 3)
	{
		str = cdiftwo(data);
		to_set_opwd(data);
		chdir(str);
		if (str)
			ft_strdel(&str);
		to_set_pwd(data);
		if (data->voldpwd)
			ft_strdel(&data->voldpwd);
		data->turn = 1;
		return ;
	}
	return (cd_call_norm(data));
}
