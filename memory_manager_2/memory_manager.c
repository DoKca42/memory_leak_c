/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:39:10 by loculy            #+#    #+#             */
/*   Updated: 2023/01/25 20:43:01 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manager.h"

void	*ftm_malloc(size_t sz)
{
	void	*mem;
	t_memng	*new;
	t_memng	**mng;

	mem = malloc(sz);
	if (!mem)
		return (0);
	mng = ft_head_lst();
	new = ft_memnew_manager(mem, 0, 0);
	ft_memadd_back_manager(mng, new);
	return (mem);
}

void	ftm_free(void *mem)
{
	t_memng	*current;
	t_memng	*back;
	t_memng	**mng;

	if (!mem)
		return ;
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
			free(mem);
			free(current);
			return ;
		}
		back = current;
		current = current->next;
	}
	free(mem);
}

int	ftm_open(char *pathname, int flags)
{
	int		fd;
	t_memng	*new;
	t_memng	**mng;

	fd = open(pathname, flags);
	if (fd < 0)
		return (fd);
	mng = ft_head_lst();
	new = ft_memnew_manager(0, 1, fd);
	ft_memadd_back_manager(mng, new);
	return (fd);
}

void	ftm_close(int fd)
{
	t_memng	*current;
	t_memng	*back;
	t_memng	**mng;

	if (fd < 0)
		return ;
	mng = ft_head_lst();
	current = *mng;
	back = 0;
	while (current != NULL)
	{
		if (current->fd == fd)
		{
			if (back != 0)
				back->next = current->next;
			else
				*mng = current->next;
			close(fd);
			free(current);
			return ;
		}
		back = current;
		current = current->next;
	}
	close(fd);
}

void	ftm_free_all(void)
{
	t_memng	*current;
	t_memng	*tmp;
	t_memng	**mng;

	mng = ft_head_lst();
	current = *mng;
	if (!current)
		return ;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		if (tmp->type == 1)
			close(tmp->fd);
		else
			free(tmp->mem);
		free(tmp);
	}
	*mng = NULL;
}
