#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int main () {

	char str[MAX];
	int len, i;

	fgets (str, MAX, stdin);
	len = strlen (str);
	for (i = 0; i < len; i++) {
		if ((str[i] <= 122 && str[i] >= 97) || (str[i] <= 251 && str[i] >= 224 ))
			str[i] = str[i] - 32;
	}

	printf ("%s\n", str);
	

	return 0;
}
