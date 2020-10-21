// Autor: Patrick Wintner
// Dieses Programm berechnet die Primzahlen von 0 bis 500 mithilfe des Sieb des Erastosthenes 
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int Sieb[501];
	for(int i = 0; i <= 500; i++)
	{
		Sieb[i] = i; // das Array "Sieb" wird mit Zahlen gefuellt
	}
	for(int i = 2; i <= 500; i++) // i wird verwendet, um alle Zahlen von 2 bis 500 zu pruefen
	{
		if(Sieb[i] != 0) // Wenn bereits 0 => Zahl bereits gestrichen => alle Vielfachen ebenfalls bereits gestrichen
		{
			for(int j = 2; j*i <= 500; j++) // j wird verwendet, um alle Vielfachen der Zahl i zu finden
			{
				Sieb[j*i] = 0; // alle Vielfachen des Laufindexes i werden "gestrichen"
			}
		}
	}
	printf("Primzahlen von 2 bis 500:");
	for(int i = 2; i<= 500; i++)
	{
		if(Sieb[i] != 0) printf(" %i", Sieb[i]); // gestrichene Zahlen werden nicht ausgegeben
	}
	return 0;
}