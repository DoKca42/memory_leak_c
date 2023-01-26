/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:17:35 by loculy            #+#    #+#             */
/*   Updated: 2023/01/26 04:15:35 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

t_memng	**ft_head_lst(void)
{
	static t_memng	*m;
	static int		i;

	if (i < 1)
	{
		m = NULL;
		i++;
	}
	return (&m);
}

t_memng	*ft_memnew_manager(void *mem, int type, int fd)
{
	t_memng			*addmem;

	addmem = malloc(sizeof(t_memng));
	if (!addmem)
		return (0);
	addmem->mem = mem;
	addmem->type = type;
	addmem->fd = fd;
	addmem->next = NULL;
	return (addmem);
}

void	ft_memadd_back_manager(t_memng **lst, t_memng *new)
{
	t_memng	*act;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	act = *lst;
	while (act->next != NULL)
		act = act->next;
	act->next = new;
}

int	ft_is_in_lst(void *mem)
{
	t_memng	*current;
	t_memng	*back;
	t_memng	**mng;

	if (!mem)
		return (0);
	mng = ft_head_lst();
	current = *mng;
	back = 0;
	while (current != NULL)
	{
		if ((unsigned long)current->mem == (unsigned long)mem)
		{
			if (back != 0)
				back->next = current->next;
			else
				*mng = current->next;
			return (1);
		}
		back = current;
		current = current->next;
	}
	return (0);
}
