/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:08:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:08:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int		get_next_word_after(char *str, int c)
{
	while (str[c])
	{
		if (str[c] == ' ')
		{
			while (str[c + 1] == ' ')
				c++;
			return (c);
		}
		c++;
	}
	return (-1);
}

int		get_next_word_before(char *str, int c)
{
	while (c > 0 && str[c])
	{
		if (str[c] != ' ')
		{
			while (c > 0 && str[c - 1] != ' ')
			{
				c--;
			}
			return (c);
		}
		c--;
	}
	return (-1);
}
