#include <ctype.h>
#include <stdio.h>
#include "getungetch.h"

/* getword:  get next word or character from input */
int getaword(char *word, int lim)
{
	int c;
	char *w = word;

	while(isspace(c = getch()))
	{
		if(c == '\n')
		{
			*w++ = c;
			*w = '\0';
			return word[0];
		}
	}

	if(c != EOF)
		*w++ = c;

	/* comments */
	if(c == '/')
	{
		*w = getch();
		if(*w  == '*')
		{
			w++;
			for(; --lim > 0; w++)
			{
				*w = getch();
				if(*w == '/' && c == '*')	/* tests to see if c previously held asterisk */
				{
					w++;
					break;
				}

				c = *w;				/* if the loop got this far store previous character in c for next run's check */
			}
		}
		else if(*w == '/')	// checks for cpp style comments
		{
			w++;
			for(; --lim > 0; w++)
			{
				*w = getch();
				if(*w == '\n')
					break;
			}
		}
	}
	/* preprocessor control directives */
	else if(c == '#')
	{
		for(; --lim > 0; w++)
			if(!isalnum(*w = getch()))
			{
				ungetch(*w);
				break;
			}
	}
	/* string constants */
	else if(c == '"')
	{
		for(; --lim > 0; w++)
		{
			*w = getch();

			if(*w == '"' || *w == '\n')
			{
				w++;
				break;
			}
		}
	}
	// Numbers
	else if(isdigit(c))
	{
		for(; --lim > 0; w++)
		{
			if(!isdigit(*w = getch()))
			{
				ungetch(*w);
				break;
			}
		}
	}
	/* keywords now accepts underscores */
	else
	{
		if(!(isalpha(c) || c == '_'))
		{
			*w = '\0';
			return c;
		}

		for(; --lim > 0; w++)
			if(!(isalnum(*w = getch()) || *w == '_'))
			{
				ungetch(*w);
				break;
			}
	}

	*w = '\0';
	return word[0];
}
