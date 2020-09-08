#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int main () {

	char str[MAX];
	int i, len, yes;

	fgets (str, MAX, stdin);

	len = strlen (str);

	i = 0;
	yes = 0;
	while (i < len) {
		if (str[i] == str[i + 1]) {
			j = i;
			yes = 1;
			while (str[j] != '\0') {
				str[j] = str[j + 1];
				j++;
			}
			len--;
		}
		else {
			if (yes) {	
				j = i;
				while (str[j] != '\0') {
					str[j] = str[j + 1];
					j++;
				}
				len--
			}
			i++;
			yes = 0;
		} 	
	}


	return 0;
}
