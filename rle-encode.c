#include <stdlib.h>
#include <stdio.h>

char *encode(char *str)
{
	char *result_start;
	char *result;
	result = result_start;
	
	char temp = *str;
	
	char *str_temp;
	str_temp = str++;

	for(; str != "\0"; str++)
	{
		if(temp != *str)
		{
			*result = temp;
			*(++result) = str-str_temp;
			result++;
			str_temp = str;
			temp = *str;
		}	
	}
	*result = temp;
	*(++result) = str-str_temp;

	return *result_start;
}

int main()
{
	return 0;
}
