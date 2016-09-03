/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 20:16:39 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*dlist_new(t_dlist *p_new)
{
	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->pos = 0;
		p_new->p_head = NULL;
		p_new->prev = NULL;
		p_new->next = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
