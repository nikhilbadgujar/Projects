#include"Header.h"

// returns identifier size if its not an identifier then returns 0
int wordLength(char buf[])
{
	int i;

	if (buf[0] >= 48 && buf[0] <= 57)
		return 0;

	for (i = 0; buf[i] != '\0' && buf[i] != '\n'; i++)
	{
		if (!((buf[i] >= 48 && buf[i] <= 57) || (buf[i] >= 65 && buf[i] <= 90) || (buf[i] >= 97 && buf[i] <= 122) || buf[i] == '_'))
			break;
	}

	return i;
}

//returns the next element offset except the next char is not space 
//this stops when it gets new line character
int nextElementAfterSpace(char *buf)
{
	int i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		if (buf[i] != ' ')
			return i;
		i++;
	}
	return i;
}

// searches for splitter if found then returns offset else returns the eof
// no failure
int subStringLength(char buf[], char splitter)
{
	int i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		if (buf[i] == splitter)
			return i;
		i++;
	}
	return i;
}