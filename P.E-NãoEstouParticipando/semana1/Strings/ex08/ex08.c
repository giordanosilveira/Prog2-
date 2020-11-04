#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define ERRO -2
#define DNE -1
#define EXIST 0
int busca (char *str1, char *str2) {

	int len1, len2, i, j;

	len1 = strlen (str1);
	len2 = strlen (str2);

	if ((len1 <= len2) && (!len1 && !len2)) 
		return ERRO;
	else if (len1 == 1 && len2 == 1) {
		if (str1[0] == '\n' && str2[0] == '\n')
			return ERRO;
	}
	
	for (i = 0; i < len2 - len1 + 1; i++) {
		j = 0;
		while (str1[j] == str2[j + i]) {
			//printf ("%c -  %c\n", str1[j], str2[j + i]);
			//printf ("%d -  %d\n", j, len1);
			if ( j == len1 - 2)
				return i;
			j++;
		}
	}

	return DNE;
		
}
int main () {
	
	char palheiro[MAX],agulha[MAX]; 
	int back;

	fgets (palheiro, MAX, stdin);
	fgets (agulha, MAX, stdin);

	back = busca(agulha, palheiro);

	if (back == ERRO) 
		printf ("there was an error\n");
	else if (back == DNE)
		printf ("the string '%s' was not found\n", agulha);
	else
		printf ("The string '%s' was found and starts at position %d\n", agulha, back);
	return 0;

}
