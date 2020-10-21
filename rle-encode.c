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

	return result_start;
}

int main()
{
	return 0;
}
