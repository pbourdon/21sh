/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:14:40 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:14:42 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

char			**shell_lvl_less(char **env, int i)
{
	int			len;
	int			x;
	int			ret;
	char		*str;

	len = 0;
	x = 0;
	ret = 0;
	str = ft_strdup(env[i]);
	len = ft_strlen(env[i]);
	while (x < len - 1)
	{
		str++;
		x++;
	}
	ret = ft_atoi(str);
	ret -= 1;
	str = ft_itoa(ret);
	env[i][len - 1] = str[0];
	return (env);
}

char			**shell_lvl_plus(char **env, int i)
{
	int			len;
	int			x;
	int			ret;
	char		*str;

	len = 0;
	x = 0;
	ret = 0;
	str = ft_strdup(env[i]);
	len = ft_strlen(env[i]);
	while (x < len - 1)
	{
		str++;
		x++;
	}
	ret = ft_atoi(str);
	ret += 1;
	str = ft_itoa(ret);
	env[i][len - 1] = str[0];
	return (env);
}

char			**shell_lvl(char **env, int z)
{
	int			i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp(env[i], "SHLVL", 5) == 0) && (z == 0))
			env = shell_lvl_plus(env, i);
		else if ((ft_strncmp(env[i], "SHLVL", 5) == 0) && (z == 1))
			env = shell_lvl_less(env, i);
		i++;
	}
	return (env);
}
