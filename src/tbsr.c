#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tbsr.h"

char *tbsr_encrypt (char *word, char *key)
{
	char *result = (char *)malloc(sizeof(char) * 100);
	if(result == NULL)
	{
		fprintf(stderr, "Error allocating string!\n");
		return NULL;
	}
	else
	{
		strcpy(result, word);
	}
	return result;
}

char *tbsr_decrypt (char *word, char *key)
{
	char *result = (char *)malloc(sizeof(char) * 100);
	if(result == NULL)
	{
		fprintf(stderr, "Error allocating string!\n");
		return NULL;
	}
	else
	{
		strcpy(result, word);
	}
	return result;
}

int tbsr_init_dicts()
{
	return 1;
}
