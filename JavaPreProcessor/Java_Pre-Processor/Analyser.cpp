#include"Header.h"

unordered_map<string, string>table;
extern FILE *p;

//gets input as string terminated by '\0' or '\n'
// calls searchHash and nextElementAfterSpace functions
void analyser(char buffer[], int len)
{
	if (buffer[0] == '#' || buffer[nextElementAfterSpace(buffer)] == '#')
	{
		int i = 0;

		if (buffer[0] == '#')
			i = 1 + nextElementAfterSpace(buffer + 1);
		else
		{
			i = nextElementAfterSpace(buffer);
			i++;
			i = i + nextElementAfterSpace(buffer + i);
		}
		if (i + 7 < len)
			if (buffer[i] == 'd' && buffer[i + 1] == 'e' && buffer[i + 2] == 'f' && buffer[i + 3] == 'i' && buffer[i + 4] == 'n' && buffer[i + 5] == 'e')
			{
				i = i + 6;
				i = i + nextElementAfterSpace(buffer + i);	if (i == 0) return;

				int offset = i;
				i = i + wordLength(buffer + i);
				string skey(buffer + offset, buffer + i);
				i = i + nextElementAfterSpace(buffer + i);
				buffer[len - 1] = '\0';
				string sbuffer = buffer + i;
				table.insert(make_pair(skey, sbuffer));

				//Search for existing macro
				unordered_map<string, string>::iterator itr;
				for (itr = table.begin(); itr != table.end(); itr++)
				{
					if (itr->second == skey)
						itr->second = sbuffer;
				}
			}
			else if (buffer[i] == 'i' && buffer[i + 1] == 'n' && buffer[i + 2] == 'c' && buffer[i + 3] == 'l' && buffer[i + 4] == 'u' && buffer[i + 5] == 'd' && buffer[i + 6] == 'e')
			{
				i = i + 7;
				i = i + nextElementAfterSpace(buffer + i);	if (i == 0) return;

				if (buffer[i] == '"')
				{
					int offset = subStringLength(buffer + i, '"');
					if (buffer[offset + i] != '"')
						return;
					Inclusion(buffer + i, offset);
				}

				if (buffer[i] == '<')
				{
					int offset = subStringLength(buffer + i, '>');
					if (buffer[offset + i] != '>')
						return;
					Inclusion(buffer + i + 1, offset - 1);
				}
			}
	}
	else // comment whitespace removal and macro expansions
	{
		char write[BUFFERSIZE + 1];
		int wrOffset = 0;
		int split = nextElementAfterSpace(buffer), offset = 0, temp2;
		unordered_map<string, string>::iterator itr;

		do
		{
			temp2 = wordLength(buffer + split);
			//if element is not a word then insert that single element
			if (temp2 == 0)
			{
				if (buffer[split] == ' ')
				{
					split++;
					continue;
				}
				if ((buffer[split] == '/' && buffer[split + 1] == '/') || buffer[split] == '\n' || buffer[split] == '\0')
				{
					write[wrOffset] = buffer[len - 1];
					break;
				}
				write[wrOffset] = buffer[split];
				wrOffset++;
				split++;

			}
			else
			{
				split = split + temp2;
				//write parsed element or word in char * key
				string skey(buffer + offset, buffer + split);

				//find that key in table
				itr = table.find(skey);
				if (itr == table.end())
				{
					//if not found write that word as it is in char write[]
					for (int loop = offset; loop < split; loop++)
					{
						write[wrOffset] = buffer[loop];
						wrOffset++;
					}
				}
				else
				{
					//else substitute the macro
					int l = (itr->second).length();
					for (int loop = 0; loop < l; loop++)
					{
						write[wrOffset] = itr->second[loop];
						wrOffset++;
					}
				}
			}
			if (buffer[split] == ' ')
			{
				write[wrOffset] = buffer[split];
				wrOffset++;
				split++;
			}

			if ((buffer[split] == '/' && buffer[split + 1] == '/') || buffer[split] == '\n' || buffer[split] == '\0')
			{
				write[wrOffset] = buffer[len - 1];
				break;
			}

			split = split + nextElementAfterSpace(buffer + split);

			offset = split;
		} while (split <= len);
		write[wrOffset] = '\n';
		wrOffset++;
		if (wrOffset > 1)
			fwrite(write, sizeof(char), wrOffset, p);
	}
}
