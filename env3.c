/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:06:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:06:22 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	printab(char **tabb)
{
	int	i;

	i = 0;
	while (tabb[i] != NULL)
	{
		ft_putendl(tabb[i]);
		i++;
	}
}

void	freeargs(t_data *data, int i)
{
	int	n;

	n = 0;
	while (n < i)
	{
		free(data->args[n]);
		n++;
	}
}

void	argsifenv(t_data *data, int n)
{
	int		i;
	int		o;
	char	**dst;

	freeargs(data, n);
	i = n;
	o = 0;
	dst = (char **)malloc(sizeof(char *) * ft_strlentab(data->args));
	while (data->args[i])
	{
		dst[o] = data->args[i];
		o++;
		i++;
	}
	dst[o] = NULL;
	free(data->args);
	data->args = dst;
}

void	callenvtool(t_data *data, char **tabb)
{
	(void)data;
	printab(tabb);
	freetab(tabb);
}

char	**printifenv(char **tabb, char *str)
{
	int		i;
	int		o;
	char	**dst;

	dst = (char **)malloc(sizeof(char *) * (ft_strlentab(tabb) + 1));
	i = 0;
	o = 0;
	while (tabb[i] != NULL)
	{
		if (rognagestring(tabb[i], str) == 1)
		{
			dst[o] = ft_strdup(str);
			o++;
			i++;
		}
		dst[o] = ft_strdup(tabb[i]);
		o++;
		i++;
	}
	dst[o] = NULL;
	freetab(tabb);
	return (dst);
}
