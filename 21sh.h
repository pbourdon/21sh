/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:03:36 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 17:51:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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


typedef struct		s_node
{
	char			*data;
	struct s_node	*p_next;
	struct s_node	*p_prev;
}					t_node;

typedef struct		s_dlist
{
	struct s_node	*p_tail;
	struct s_node	*p_head;
}					t_dlist;

#endif
