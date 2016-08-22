/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:31:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 18:02:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft/includes/libft.h"

void	redir(void)
{
	int		fd = -1;
	pid_t	child = -1;
	char	*filename = NULL;
	char	*cmd = NULL;
	char	*args[3];

	filename = "./output.txt";

	cmd = "/bin/ls";
	args[0] = cmd;
	args[1] = "-lF";
	args[2] = NULL;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("error4 ");
	}
	child = fork();
	if (child == -1)
	{
		close(fd);
		perror("error6");
	}
	else if (child == 0)
	{
		dup2(fd, STDOUT_FILENO);
		execve(cmd, args, NULL);
		perror("error5");
	}
	close (fd);
	wait(NULL);

}
