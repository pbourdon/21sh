/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:30:18 by hlouar            #+#    #+#             */
/*   Updated: 2016/05/23 14:03:23 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_fill_line(int const fd, char **line, char **r)
{
	int		ret;
	char	*del;

	ret = 1;
	if (ft_strchr(r[fd], '\n'))
	{
		del = r[fd];
		*line = ft_strsub(r[fd], 0, ft_strchr(r[fd], '\n') - r[fd]);
		if (!line)
			ret = -1;
		r[fd] = ft_strsub(r[fd], ft_strchr(r[fd], '\n') - r[fd] + 1,
				ft_strlen(r[fd]));
		if (!r[fd])
			ret = -1;
		ft_strdel(&del);
	}
	else
	{
		if (!(*line = ft_strdup(r[fd])))
			ret = -1;
		ft_strdel(&r[fd]);
	}
	return (ret);
}

int	get_next_line(int const fd, char **line)
{
	int			ret;
	char		*del;
	char		buf[BUFF_SIZE + 1];
	static char	*r[255];

	if (!line || fd < 0 || fd > 255 || BUFF_SIZE < 1)
		return (-1);
	if (!(r[fd] = (r[fd] == NULL ? ft_strnew(1) : r[fd])))
		return (-1);
	while (!ft_strchr(r[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		del = r[fd];
		if (!(r[fd] = ft_strjoin(r[fd], buf)))
			return (-1);
		ft_strdel(&del);
	}
	if (ret == -1)
		return (-1);
	if (ft_fill_line(fd, line, r) == -1)
		return (-1);
	return (!r[fd] && !ft_strlen(*line) ? 0 : 1);
}
