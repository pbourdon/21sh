/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:31:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/20 02:04:26 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "libft/includes/libft.h"


int		voir_touche()
{
	char     buffer[3];
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
	}
	return (0);
}

int		main(void)
{
	char				*name_term;
	struct termios		term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(term_buffer, name_term) == ERR)
			return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	voir_touche();
	return (0);
}
