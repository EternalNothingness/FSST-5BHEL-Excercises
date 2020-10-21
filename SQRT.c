// Autor: Patrick Wintner
// Dieses Programm berechnet die Wurzel von ganzzahligen, positiven Zahlen, Brueche werden abgerundet

#include <stdlib.h>
#include <stdio.h>

int myqdr(int iValue) // Diese Funktion quadriert den ihr uebergebenen Wert
{
    int iResult = 0;
    
	int i0 = 0;
	i0++; // damit bei '1' gestartet werden kann
	for(; i0 <= iValue; i0++) // Anzahl der Durchlaeufe entspricht iValue
		{
			int i1 = 0; // Reset des zweiten Laufindexes
			i1++; // damit bei '1' gestartet werden kann
			for(; i1 <= iValue; i1++) // Pro Durchlauf wird das Ergebnis um den Wert von iValue erhoeht
				{
					iResult++;
				}
		}
	return iResult;
}

int mysqrt(int iValue) // Diese Funktion liefert die Wurzel des uebergebenen Wertes
{
	int iResult;

	if(iValue <= -1) return -1; // Funktion ist nur fuer positive Werte gedacht
	
	for(int i = 0; myqdr(i) <= iValue; i++)
		{
			iResult = i; // solange die Quadratur des Indexes kleiner ist als jener Wert, von welchem die Wurzel gezogen wird, wird das Ergebnis auf iResult gespeichert
		}
	return iResult;
}

int main()
{
	for (int i = -1; i <= 100; i++)
	{
		printf("%i = sqrt(%i)\n", mysqrt(i), i);
	}
	return 0;
}