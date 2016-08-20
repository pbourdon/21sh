/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:31:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/20 01:20:39 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "libft/includes/libft.h"

void	run_pipe(void)
{
	int const READ_END = 0;
	int const WRITE_END = 1;
	pid_t child = -1;
	char *cmd1 = NULL;
	char *cmd2 = NULL;
	char *args1[3];
	char *args2[3];
	int pdes[2];

	cmd1 = "/bin/ls";
	args1[0] = cmd1;
	args1[1] = "-lF";
	args1[2] = NULL;

	cmd2 = "/bin/cat";
	args2[0] = cmd2;
	args2[1] = "-e";
	args2[2] = NULL;

	pipe(pdes);
	child = fork();
	if (child == -1)
	{
		close(pdes[READ_END]);
		close(pdes[WRITE_END]);
		perror("error3");
	}
	else if (child == 0)
	{
		dup2(pdes[WRITE_END], STDOUT_FILENO); // la sortie standard ce programme qui lance ls est desormais copie vers l'entree standard du deuxieme cote du pipe
		close(pdes[READ_END]); // on vire la lecture standard de ce cote du pype car inutile
		execve(cmd1, args1, NULL); // on execute ce cote du pipe et on renvoit ce qu'on recupere vers l'entree standard de l'autre cote du pype
	}
	dup2 (pdes[READ_END], STDIN_FILENO); // on recupere l'entree standard comme prevu
	close(pdes[WRITE_END]); // on vire l'ecriture car inutile de ce cote du pype, elle renvoit rien
	wait(NULL); // on attends que le programme fils lance ls et le renvoit vers l'entree standard du pere
	execve(cmd2, args2, NULL); // le pere vient de recuperer ce que le fils a renvoye (le ls) et execute maintenant le cat -e
}

void	main_run_pipe(void)
{
	pid_t		child = -1;

	child = fork();
	if (child == -1)
	{
		perror("error");
	}
	else if (child == 0)
	{
		run_pipe();
		perror("error2");
	}
	wait (NULL);
}
