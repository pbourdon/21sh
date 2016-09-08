/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:39:39 by pbourdon         ###   ########.fr       */
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
# include <sys/ioctl.h>


int			ft_tc(void);
void		ft_get_user_input(void);
int			ft_deal_input(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste);
int			ft_deal_input2(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste);

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
int			ft_detect_paste(char *buffer);
int			ft_detect_copy(char *buffer);
int			ft_detect_cut(char *buffer);
int			ft_detect_tab(char *buffer);
int			ft_detect_page_up(char *buffer);
int			ft_detect_page_down(char *buffer);

t_dlist		*ft_get_info_from_list(t_dlist *list, t_dlist *histo);

int			ft_check_correct_entry(t_dlist *list);
int			ft_check_dquo(char *str);

int			ft_left(t_dlist *list);
int			ft_right(t_dlist *list);
int			ft_up(t_dlist *list);
int			ft_down(t_dlist *list);
int			ft_move_end(t_dlist *list);
int			ft_move_home(t_dlist *list);
int			ft_move_shift_home(t_dlist *list);
int			ft_move_shift_end(t_dlist *list);
int			ft_move_page_up(t_dlist *list);
int			ft_move_page_down(t_dlist *list);

int			ft_second_delete(t_dlist *list);
int			ft_move_begin(void);

int			ft_copy(t_dlist *list, t_dlist *to_paste);
int			ft_cut(t_dlist *list, t_dlist *to_paste, int index, char *buffer);
int			ft_paste(t_dlist *list, t_dlist *to_paste, int index, char *str);

int			ft_previous_histo(t_dlist *list, t_dlist *histo);
int			ft_next_histo(t_dlist *list, t_dlist *histo);

int			ft_delete_on_shell(t_dlist *list);
int			ft_clear_n_char(int n);
int			ft_clear_line(void);

int			ft_finish_command(t_dlist *list, t_dlist *histo);

int			ft_add_element(t_dlist *list, char *buffer);
#endif
