/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:17:35 by loculy            #+#    #+#             */
/*   Updated: 2023/01/17 22:22:54 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

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