/*********************/
/*   include guard   */
/*********************/
#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>

/******************************************/
/*               strlength                */
/******************************************/
int strlength(const char array1[], int n){
  int i;

  // Zähler der Stringlänge
  for(i = 0; array1[i] != '\0'; i++);
  // i--;
  return i;
}

/******************************************/
/*               strmirror                */
/******************************************/
int strmirror(char array1[], int n){
  char array2[n];
  int k = 0, i = 0;
  // umschichten der arrays
  i = strlength(array1, n);
  i--;
  while(array1[k++] != '\0'){
    array2[i]= array1[k-1];
    i--;
  }

  array2[k-1] = '\0';
  
  printf("Der gespiegelte String lautet:\n\n%s\n", array2);
   return 0;
}

/******************************************/
/*               strsearch                */
/******************************************/
int strsearch(const char sstr[], int N, const char str[]){
  //suchen auf Gleichheit eines Wortes in einem String
  int i = 0, j = 0, k = 0, l = 0;
  l = strlength(sstr, N);
  //j--;
  for(i = 0; i < l; i++){
    for(j = 0; j < l; j++){
      printf("\n %d   %d",i+j,l);
      if(sstr[i+j] == str[k]){
	k++;
	//	printf("\n %d   %d",k,l);
	if(k == l){
	  return 0;
	}	
      }
    }
  }/*
  if(strlength(sstr, N)- 1 <= strlength(str, N))
    for(i = 0; i < N; i++)
      for(j = 0; j < strlength(sstr, N)- 1; j++) {
	if(str[i + j] != sstr[j])   
	  break;
	if(sstr[j + i] == 0 || sstr[j] == 10 || sstr[j] == 32 || sstr[j] == 8)  // 0    bzw    10
	  return i;
      }

  return -1;
  }*/

/******************************************/
/*               strreplace               */
/******************************************/ 
int strreplace(char dstr[], int n ,const char sstr[], const char str[],const char nstr[]){
  int a;
  int i, j, k = 0, m;

  // benötigte varibalen für  strreplace
  i = strsearch(str, n, sstr);
  i++;
  j = strlength(nstr, n);

  k = strlength(sstr, n);
  m = strlength(str, n);
  k = k - m + j;

  // befüllen bis zum gesuchten Wort
  for(a = 0; a <  i; a++){
    if(i <= 0 || i > k){
      return 0;
    }
    dstr[a] = sstr[a];
  }
  j--;
   // befüllen des neuen Wortes
  for(a = 0; a < j; a++){
    dstr[i + a] = nstr[a];
  }
  
  // befüllen des Restes
  for(; i < k; i++){
    if(k + j >= n){
      return 0;
    }
    dstr[i + a] = sstr[i-1 + m];
    }
  printf("\n%s\n", dstr);

  i = strlength(dstr, n);

  return i;
}

/******************************************/
/*               strsubstr                */
/******************************************/ 
int strsubstr( char dstr[], unsigned dstrsize, const char sstr[], unsigned startpos, unsigned len ){
  // erste kontrolle der eingaben
  if (dstrsize >= len + 1 && startpos > 0) {
    unsigned i;
    startpos++;
    // schleife zum kopieren des ersten in den zweiten String
    for (i = 0; i < len; i++)
      if (sstr[startpos + i] != 0 || sstr[startpos + i] != 10)
	dstr[i] = sstr[startpos + i];
    // bei Fehlerfall break and return 0
      else
	break;
    i++;
    dstr[i] = 0;
    printf("%s\n", dstr);
    return i;
  }
  return 0;
}

#endif
