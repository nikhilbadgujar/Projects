#include"Header.h"

char inclusionPath[] = "C:\\Program Files\\Windows Kits\\10\\Include\\10.0.16299.0\\ucrt\\";

void Inclusion(char * buffer, int size )
{
	int start = nextElementAfterSpace(buffer);
	int end = 0;

	for (end = size - 1; end != start; end--)
	{
		if (buffer[end] != ' ')
			break;
	}

	string fName(buffer + start, buffer + end + 1);

	if (buffer[size] == '>')
		fName = inclusionPath + fName;

	FILE *f;
	fopen_s(&f, fName.c_str(), "r");
	if (f == NULL)
		return;

	char buff[BUFFERSIZE + 1];
	int count = 0;

#pragma warning(suppress : 4996)
	while (count = fread(buff, sizeof(char), BUFFERSIZE, f))
	{
		buff[count] = '\0';
		int split = 0, offset = 0;
		do
		{
			split = split + subStringLength(buff + split, '\n');
			analyser(buff + offset, split + 1 - offset);
			offset = ++split;

		} while (split < count);
	}

}