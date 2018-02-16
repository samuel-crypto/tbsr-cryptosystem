#include <stdio.h>
#include <stdlib.h>
#include "tbsr.h"
#define USAGE_STR "tbsr operation \"key\"\nwhere operation can be either 'encrypt' or 'decrypt'"
#define USAGE_DESC_STR "To encrypt a message:\necho \"message_goes_here\" | tbsr encrypt \"key_goes_here\"\nTo decrypt a message:\necho \"message_goes_here\" | tbsr decrypt \"key_goes_here\"\nTo encrypt a file containing the message:\ncat \"file_name_goes_here\" | tbsr encrypt \"key_goes_here\"\nTo decrypt a file containing the message:\ncat \"file_name_goes_here\" | tbsr decrypt \"key_goes_here\"\nNOTE: Dictionary must be in the same directory as the executable"
#define WORD_MAX 1024

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		fprintf(stderr, "Not a good number of parameters\nUSAGE: %s\nDetailed help:\n%s", USAGE_STR, USAGE_DESC_STR);
		exit(-1);
	}
	else
	{
		char *key = argv[1];
		size_t keysize;
		if((keysize = strlen(argv[1])) >= 1)
		{	
			if(!tbsr_init_dicts())
			{
				fprintf(stderr, "Dictionaries not found/not accessible!\n");
				exit(-5);
			}		

			//NOTE: NOT timing attack safe code ahead! :P
			if(!strcmp(argv[1], "encrypt"))
			{
				int c;
				char word[WORD_MAX];
				char *crypted;
				while((c = fgetc(stdin)) != EOF)
				{
					if(c == ' ')
					{
						if(strlen(word) >= 1)
						{
							if((crypted = tbsr_encrypt(word, key)) != NULL)
							{
								fprintf(stdout, "%s ", crypted);
							}
							else
							{
								fprintf(stderr, "Invalid character in word or word is not in dictionary! Please use english words in the dictionary\n");
								break;
							}
						}
						else
						{
							continue;
						}
					}
				}

				if(crypted != NULL)
					free(crypted);
				else
				{
					exit(-3);
				}
			}
			else if(!strcmp(argv[1], "decrypt"))
			{
				int c;
				char word[WORD_MAX];
				char *crypted;
				while((c = fgetc(stdin)) != EOF)
				{
					if(c == ' ')
					{
						if(strlen(word) >= 1)
						{
							if((crypted = tbsr_decrypt(word, key)) != NULL)
							{
								fprintf(stdout, "%s ", crypted);
							}
							else
							{
								fprintf(stderr, "Invalid character in word or word is not in dictionary! Please use english words in the dictionary\n");
								break;
							}
						}
						else
						{
							continue;
						}
					}
				}

				if(crypted != NULL)
					free(crypted);
				else
				{
					exit(-4);
				}
			}
		}
		else
		{
			fprintf(stderr, "I know you like short passwords, but I'm sorry to say we don't support 0-length passwords yet!\n");
			exit(-2);
		}
	}
}
