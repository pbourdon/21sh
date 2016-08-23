/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:18:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/23 18:35:35 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <term.h>

int		ft_putchar(int c)
{
	write (1, &c, 1);
	return (0);
}

void	move_cursor(int x, int y)
{
	char	*res;

	res = tgetstr("cm", NULL);
	tputs(tgoto(res, 2, 2), 1, ft_putchar);
}

void	ft_left(void)
{
	char	*res;
	
	res = tgetstr("le", NULL);
	tputs(res, 0, ft_putchar);
}



int		voir_touche()
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27 && buffer[2] == 'C')
		{
			printf("C'est une fleche droite ! \n");
		}
		else if (buffer[0] == 27 && buffer[2] == 'D')
			printf("C'est une fleche gauche ! \n");
		else if (buffer[0] == 27 && buffer[2] == 'A')
			printf("C'est une fleche haute ! \n");
		else if (buffer[0] == 27 && buffer[2] == 'B')
			printf("C'est une fleche bas ! \n");
		else if (buffer[0] == 4)
		{
			printf("ctrl + d on quitte ! \n");
			return (0);
		}
	}
	return (0);
}

int		main(void)
{
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	voir_touche();
	return (0);
}
