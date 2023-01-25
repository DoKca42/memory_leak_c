/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:03:46 by loculy            #+#    #+#             */
/*   Updated: 2023/01/26 00:32:42 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "yy.h"

void	print_list(void)
{
	t_memng	*current;
	t_memng	*head;

	head = *ft_head_lst();
	current = head;
	printf("-----------------\n");
	while (current != NULL)
	{
		if ((unsigned long)current->mem != 0)
			printf(" %lu\n", (unsigned long)current->mem);
		else
			printf(" %lu\n", (unsigned long)current->fd);
		current = current->next;
	}
}

int	main(void)
{
	char	*m;
	char	*a;

	m = ftm_malloc(sizeof(char) * 5);
	a = ftm_malloc(sizeof(char) * 15);
	ft_rr();
	print_list();
	ftm_free_all();
	print_list();
	return (0);
}
