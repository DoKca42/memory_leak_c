#include <stdio.h>
#include <stdlib.h>
#include "leak_detector_c/leak_detector_c.h"
//#include "leak_detector_c/leak_detector_c.c"


void ca()
{
	char *matrice;
	matrice = malloc(sizeof(char) * (4 + 1));
	matrice[0] = 'a';
	matrice[1] = 'b';
	matrice[2] = 'g';
	matrice[3] = 'd';
	matrice[4] = '\0';
	printf("%s\n", matrice);
	free(matrice);
}

int main()
{
	ca();
	atexit(report_mem_leak);
	return (0);
}
