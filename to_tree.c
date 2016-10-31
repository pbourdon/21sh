/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:16:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:16:47 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

t_tree		*new_node(t_tk *tk)
{
	t_tree	*tree;

	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	tree->arg = tk->arg;
	tree->tk = tk->tk;
	tree->right = NULL;
	tree->left = NULL;
	return (tree);
}

int			is_base(t_tk **tk, t_tk **base, t_tk **save)
{
	if (*tk == *base)
	{
		*save = (*tk)->next;
		*base = NULL;
		ft_memdel((void *)(&(*tk)));
		*tk = *save;
		if (*tk == NULL)
			return (0);
	}
	else if ((*save = *base))
	{
		while ((*save)->next != *tk)
			*save = (*save)->next;
		*tk = (*tk)->next;
		if (*base == *save)
			ft_memdel((void *)(&(*base)->next));
		else
			ft_memdel((void *)&(*save)->next);
	}
	return (1);
}

t_tree		*sub_to_tree(t_tk *tk, t_tree *tree, const char *str)
{
	if (!str)
		tree = new_node(tk);
	else if (!ft_strcmp(str, "left"))
	{
		tree->left = new_node(tk);
		tree = tree->left;
	}
	else if (!ft_strcmp(str, "right"))
	{
		tree->right = new_node(tk);
		tree = tree->right;
	}
	return (tree);
}

t_tree		*to_tree(t_tree *tree, t_tk *tk, int prio, char *str)
{
	t_tk	*save;
	t_tk	*base;

	base = tk;
	while (prio != -1)
	{
		tk = base;
		while (tk)
		{
			if (tk->tk == prio)
			{
				tree = sub_to_tree(tk, tree, str);
				if (!is_base(&tk, &base, &save))
					return (tree);
				if (base)
					to_tree(tree, base, (prio - 1), "left");
				if (tk)
					to_tree(tree, tk, prio, "right");
				return (tree);
			}
			tk = tk->next;
		}
		prio--;
	}
	return (tree);
}
