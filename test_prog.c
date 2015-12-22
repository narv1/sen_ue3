/*******************************************************************************************/
/*                           Willkommen zum ersten Projekt!                                */
/*               Dieses Programm zielt darauf ab einen besseren Umgang mit:                */
/*                                     -Arrays                                             */
/*                   -Verbesserung der Eingabe einer Stringzerlegung                       */
/*                  -Berechnung einfacher mathematischer Sachverhalte                      */
/*******************************************************************************************/


/*******************************************************************************************/
/*                               Author: Stefan Hermeter                                   */
/*                                  Klasse:5/6 ABETI                                       */
/*                                 Datum:  14.11.2015                                      */
/*******************************************************************************************/


/*****************************************/
/*      Die verwendeten Libaries         */
/* bzw. die maximale Anzahl der Vektoren */
/*****************************************/ 
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "myString.h"
#define N 200

/**********************************/
/*         Testprogramm           */
/**********************************/
int main(int argc, char *argv[])
{
  int opt;
  int i, j;
  char array1[N];
  char nstr[N], dstr[N];
  
  while ((opt = getopt(argc, argv, "a:b:c:d:e:h")) != -1) {
    switch (opt) {
    case 'h':
      printf("Dieses Programm überprüft mithilfe von Eingabe Argumenten, ob die geschribenen Frunktionen der 'myString.h' Bibliothek Reibungslos laufen.\n\nBeschreibung:\n\t-a \"...\"\tGibt die Länge des eingegeben Arguments zurück.\n\t-b \"...\"\tSpiegelt das Eingegebene wieder.\n\t-c \"...\"\tSucht im eingegebenen String nach der zweiten Eingabe.\n\t-d \"...\"\tErsetzt im eingegeben String Buchstaben/Wörter.\n\t-e \"...\"\tKopiert vom eingegebenen String einen Part in einen neuen String.\n\t-h \"...\"\tÖffnet diese Hilfe.\nDieses Programm ist auf mehrere Worte ausgelegt. Bei einzelnen Wörter gibt es noch Probleme.\n");
      break;
    case 'a':
      i = strlength(argv[2], N);
      
      // Ausgabe des Rückgabewertes      
      if( i == -1){
	printf("Es ist ein Fehler aufgetreten!\n");
      }else{
	printf("Die länge des arrays ist: %d\n", i );
      }
      break;
    case 'b':
      i = strmirror(argv[2], N);
      break;
    case 'c':
      // Eingabe des 2ten Wortes
      printf("Bitte geben sie das zusuchende Wort ein: ");
      fgets(array1, N, stdin);
      i = strsearch(array1, N, argv[2]);

      if(i == -1){
	printf("Es ist ein Fehler aufgetreten.\n");
      }else{
	printf("Das Wort befindet sich an der %d stelle\n", i+1);
      }
      break;
    case 'd':
      printf("Was soll ersetzt werden:\n");
      fgets(array1, N, stdin);
      printf("Was soll eingesetzt werden:\n");
      fgets(nstr, N, stdin);
      i =  strreplace(dstr, N,  argv[2], array1, nstr);
      break;
    case 'e':
      printf("Was soll kopiert werden:\n");
      fgets(array1, N, stdin);
      i = strsearch(array1, N, argv[2]);
      j = strlength(array1, N);
      i = strsubstr(dstr, N, argv[2], i, j);
      break;
    case '?':
      if (optopt == 'c')
	fprintf (stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint (optopt))
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
      fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
    }
  }

  if(argc == 1){
    printf("Sie haben kein Argument angegeben!\nGeben sie %s -h um mehr zu erfahren.\n", argv[0]);
  }
  
  return 0;
}
