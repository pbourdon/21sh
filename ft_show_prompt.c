/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 23:29:15 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 18:07:03 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft/includes/libft.h"

void		ft_show_prompt(void)
{
	char	*tmp;

	tmp = getcwd(0, 0);
	ft_putstr("$> ");
	ft_putstr(last_dir(tmp));
	free(tmp);
	ft_putstr(" : ");
}
