/*
Titel: file_copy
Beschreibung: Die Funktion file_copy kopiert den Inhalt einer Datei. Dafuer werden
POSIX-Systemcalls (open, read, write, close) sowie ein 20-Byte-Buffer verwendet.
Autor: Patrick Wintner
Datum der letzten Bearbeitung: 27.10.2020
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF_SIZE 20

int file_copy(const char *filename, const char *newfilename)
{
	int handle_0;
	int handle_1;
	void *buf;
	int nread;

	handle_0 = open(filename, O_RDONLY);
	if(handle_0 == -1) return -1;
	handle_1 = open(newfilename, O_CREAT | O_EXCL | O_WRONLY);
	if(handle_1 == -1) 
	{
		close(handle_0);
		return -2;
	}
	for(;;)
	{
		nread = read(handle_0, buf, BUF_SIZE);
		if(nread < 20)
		{
			if(nread == -1) 
			{
				close(handle_0);
				close(handle_1);
				return -3;
			}
			break;
		}
		if (write(handle_1, buf, BUF_SIZE) == -1) 
		{
			close(handle_0);
			close(handle_1);
		 	return -4;
		}
	}
	if (write(handle_1, buf, BUF_SIZE) == -1)
	{
		close(handle_0);
	 	close(handle_1);
		return -4;
	}
	close(handle_0);
	close(handle_1);
	return 0;
}

int main()
{
	char *filename;
	char *newfilename;

	printf("Bitte Namen der zu kopierenden Datei eingeben: ");
	scanf("%s", filename);
	printf("\nBitte Namen der neuen Datei eigeben: ");
	scanf("%s", newfilename);

	return file_copy(filename, newfilename);
}
