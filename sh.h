/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 19:30:44 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SH_H
# define SH_H
#ifdef unix
static char term_buffer[2048];
#else
#define term_buffer 0
#endif
# define KEY_CTRL_D				4
# define KEY_RIGHT				4414235
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

int			ft_tc(void);
void		ft_get_user_input(void);
t_dlist		*ft_deal_input(char *buffer, t_dlist *list);
t_dlist		*ft_deal_input2(char *buffer, t_dlist *list);

int			ft_detect_right(char *buffer);
int			ft_detect_down(char *buffer);
int			ft_detect_left(char *buffer);
int			ft_detect_up(char *buffer);
int			ft_detect_ctrl_d(char *buffer);
int			ft_detect_end(char *buffer);
int			ft_detect_home(char *buffer);
int			ft_detect_shift_home(char *buffer);
int			ft_detect_shift_end(char *buffer);
int			ft_detect_second_delete(char *buffer);

void		ft_get_info_from_list(t_dlist *list);

t_dlist		*ft_left(t_dlist *list);
t_dlist		*ft_right(t_dlist *list);
t_dlist		*ft_up(t_dlist *list);
t_dlist		*ft_down(t_dlist *list);
t_dlist		*ft_move_end(t_dlist *list);
t_dlist		*ft_move_home(t_dlist *list);
t_dlist		*ft_move_shift_home(t_dlist *list);
t_dlist		*ft_move_shift_end(t_dlist *list);
t_dlist		*ft_second_delete(t_dlist *list);

t_dlist		*ft_delete_on_shell(t_dlist *list);
int			ft_clear_n_char(int n);

t_dlist		*ft_finish_command(t_dlist *list);

t_dlist		*ft_add_element(t_dlist *list, char *buffer);
#endif
