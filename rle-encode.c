#include <stdlib.h>
#include <stdio.h>

char *encode(char *str)
{
	char *result_start;
	char *result;
	result = result_start;
	char temp = *str;
	int cnt_char = 1;

	for(; str != "\0"; str++)
	{
		if(temp == *str)
		{
			cnt_char++;
		}
		else
		{
			*result = temp;
			*(++result) = "%i", cnt_char;
			result++;
			temp = *str;
			cnt_char = 1;
		}	
	}
	*result = temp;
	*(++result) = "%i", cnt_char;

	return *result_start;
}

int main()
{
	return 0;
}
