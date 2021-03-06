/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:08:45 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:08:47 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

char		**get_tabhash(char **new, int b)
{
	static char		**tabhash = NULL;
	int				i;

	if (b != 0)
	{
		if (tabhash == NULL)
			return (NULL);
		i = -1;
		while (++i < 4096)
		{
			if (tabhash[i])
			{
				ft_strdel(&tabhash[i]);
				tabhash[i] = NULL;
			}
		}
		free(tabhash);
		tabhash = NULL;
	}
	if (tabhash == NULL && (tabhash = new))
		return (NULL);
	return (tabhash);
}

char		*ft_chrbin(char *path)
{
	int		i;

	if (!path)
		return (0);
	i = ft_strlen(path);
	while (path[--i])
	{
		if (path[i] == '/')
		{
			i++;
			return (path + i);
		}
	}
	return (0);
}

int			hash_bin(char *bin)
{
	int		i;
	int		res;

	i = -1;
	res = 1;
	while (bin[++i])
		res = res + (bin[i] * 3);
	while (res > 2048)
		res = (res >> 2);
	return (res);
}

void		set_open_adressing(char **tabhash, int res, char *path)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (tabhash[res] != NULL)
	{
		if (l == 2 || !(ft_strcmp(ft_chrbin(path), ft_chrbin(tabhash[res]))))
		{
			free(path);
			return ;
		}
		res++;
		if (res > 2048 && l && (++l))
			res = 0;
		else if (res > 2048 && (++l))
			res /= 7 + (++i);
	}
	tabhash[res] = path;
}

char		*ft_str2join(char *bar, char *yoo, char *foo)
{
	char	*tmp;
	char	*t;

	tmp = ft_strjoin(bar, yoo);
	t = ft_strjoin(tmp, foo);
	ft_strdel(&tmp);
	return (t);
}
