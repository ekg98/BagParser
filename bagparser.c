// Bagparser:  Since I don't know any sql.  This program will help me modify my current character DB's bags from 28 slot data field to a 32 slot data field.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "getaword.h"
#include "getungetch.h"

#define MAXIMUM	256

int main()
{
	char word[MAXIMUM];
	int i, zeroCounter;

	printf("Bag parser bag fix.  Copy and paste your data field to convert from 28 slot bag to 32 slot bag.  (Ctrl+D to exit) (Enter to convert)\n\n");

	for(i = 1; getaword(word, MAXIMUM) != EOF ; i++)
	{
		if(i == 1)	// if first line generate a space between the command prompt
			printf("\n");



		if(i <= 106)	// print the word set up to and including word 106
			printf("%s ", word);

		if(i == 106)	// after set 106 generate 16 zeros
		{
			for(zeroCounter = 1; zeroCounter <= 16; zeroCounter++)
				printf("0 ");

			printf("\n\n");
			
			i = 0;	// reset i for next word set
		}
	}

	return 0;
}
