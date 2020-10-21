#include <stdlib.h>
#include <stdio.h>

char *encode(char *str)
{
	char *result;
	char temp = *str;
	int cnt_char = 1;
	int cnt_result = 0;

	for(; str != "\0"; str++)
	{
		if(temp == *str)
		{
			cnt_char++;
		}
		else
		{
			result = result + cnt_result;
			*result = temp;
			cnt_result++;
			result = result + cnt_result;
			*result = "%i", cnt_char;
			cnt_result++;
			temp = *str;
			cnt_char = 1;
		}	
	}
	result = result + cnt_result;
	*result = temp;
	cnt_result++;
	result = result + cnt_result;
	*result = "%i", cnt_char;

	return *result;
}

int main()
{
	return 0;
}