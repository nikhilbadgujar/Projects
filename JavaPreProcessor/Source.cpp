#include"Header.h"

FILE *p;

int main(int argv, char* argc[])
{
		FILE *f ;
		fopen_s(&f,"C:\\Users\\abc\\Desktop\\Generic_LinkedList_All.cpp","r");
		if (f == NULL)
			return 0;
		
		 fopen_s(&p,"C:\\Users\\abc\\Desktop\\preprocessed.cpp", "w");
		if (p == NULL)
			return 0;

		char buffer[BUFFERSIZE + 1];
		int count = 0;
		
#pragma warning(suppress : 4996)
		while (count = fread(buffer,sizeof(char) , BUFFERSIZE, f))
		{
			buffer[count] = '\0';
			int split = 0 , offset = 0;
			do
			{
				split = split + subStringLength(buffer + split , '\n');
				analyser(buffer + offset, split + 1 - offset);
				offset = ++split;
			
			} while (split < count);
		}

	return 0;
}
