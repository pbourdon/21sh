/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 18:31:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SH_H
# define SH_H
#ifdef unix
static char term_buffer[2048];
#else
#define term_buffer 0
#endif
# include "stdlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include "libft/includes/libft.h"

void		redir(void);
void		main_run_pipe(void);
int			tgetent(char *bp, const char *name);
int			ft_touche(void);
void		get_first_signint(void);
void		get_sigint(int signal);
t_dlist		*nik_the_norm2(t_dlist *p_list, t_node *p_new, int i);
t_dlist		*nik_the_norm3(t_dlist *p_list, t_node *p_new, int i);
void		ft_show_prompt(void);
t_dlist		*ft_run_unsetenv(char *arg, t_dlist *list);
void		ft_run_setenv(char *arg, t_dlist *list);
t_dlist		*modify_element(t_dlist *list, char *arg, int index, int pos);
int			ft_run_exe(char *path, char **options, t_dlist *list);
void		son_process(char *path, char *arg[], t_dlist *line);
void		ft_run_echo(char *arg, t_dlist *list);
int			ft_run_cd(char *arg, t_dlist *line, char *tmp, char *tmp2);
char		*prev(t_dlist *list);
char		*last_dir(char *path);
char		*home(t_dlist *list);
char		*ft_give_path(char *arg);
int			ft_get_total_path(t_dlist *list);
int			ft_get_size(char *str);
char		*ft_get_path(char *arg);
char		*ft_get_options4(size_t *index, int compteur, char *options,
			char *arg);
char		*ft_get_options3(char *home, int index, int compteur,
			char *options);
char		**ft_get_options2(char *arg, char **options, size_t *index, int *x);
char		**ft_get_options1(char *arg, char **options);
char		*get_ele(t_dlist *list, int pos);
char		**ft_error_home(void);
char		*ft_get_auto_path(int x, t_dlist *list, int drop, int index);
int			ft_check_arg(char *arg, t_dlist *list, int index, char *boucle);
int			ft_check_arg2(char *arg, char **options, t_dlist *list, char *boul);
char		*ft_generate_path(char *arg, t_dlist *list);
char		**ft_get_options(char *arg, t_dlist *list, int x, char **option);
char		*ft_boucle(char *arg);
int			ft_check_arg3(char *boucle, t_dlist *list, char **options);
t_dlist		*ft_choose(char *arg, t_dlist *list);
void		ft_error(char *arg, int version);
int			ft_error_home2(char *tmp2);
t_dlist		*ft_exchange_element2(t_dlist *line, char *oldpwd);
t_dlist		*ft_exchange_element(t_dlist *list, char *test1, char *test2);
int			ft_check_file(char *path);
t_dlist		*ft_check_semicolon(char *arg, t_dlist *list);

#endif
