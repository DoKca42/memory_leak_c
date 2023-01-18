#include <stdio.h>
#include <stdlib.h>
#include "memory_manager.h"
#include "utils_manager.c"
#include "memory_manager.c"

void	print_list(t_memng *head)
{
	t_memng	*current;

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

void function_de_qualite(t_memng **m)
{
	char *a = ftm_malloc(sizeof(char) * (4 + 1), m);
	a[0] = 0;
	a[1] = 'L';
	a[2] = 'K';
	a[3] = 'd';
	a[4] = '\0';
}

int main()
{
	t_memng	*m;

	m = NULL;
	function_de_qualite(&m);
	print_list(m);
	ftm_free_all(&m);
	print_list(m);
	return (0);
}