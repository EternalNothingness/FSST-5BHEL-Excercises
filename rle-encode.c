/*
Titel: Einfache Kompression von Strings
Beschreibung: Die Funktion *encode() "komprimiert" Strings,
indem sie Anzahl gleicher Zeichen in Serie durch das entsprechende
Zeichen, gefolgt von der Anzahl der Wiederholungen, ersetzt, z. B. 
wird der String "AAbBc" in "A2b1B1c1" umgewandelt.
Autor: Patrick Wintner
Datum der letzten Bearbeitung: 21.10.2020
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_RLEN 42

char *encode(char *str)
{
	char *result_start;
	char *result;
	result = result_start;
	
	char *str_temp;
	str_temp = str++;

	for(; str != "\0"; str++)
	{
		if(*str_temp != *str)
		{
			*result = str_temp[0];
			*(++result) = str-str_temp;
			result++;
			str_temp = str;
		}	
	}
	*result = *str_temp;
	*(++result) = str-str_temp;

	return result_start;
}

int main(int argc, char **argv)
{
	char str[MAX_RLEN];
      
       	do {	
		if (fgets(str, MAX_RLEN, stdin) == NULL) break;
		str[MAX_RLEN-1] = 0;    // TODO: is this really needed?
		str[strlen(str)-1] = 0; // TODO: why is this here?
		char* res = encode(str);
		printf(">%s\n", res);
		free(res);              // see: malloc
	} while (strlen(str) > 1);
}

