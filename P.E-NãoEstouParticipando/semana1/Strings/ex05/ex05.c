#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 100

int usgnstrlen (unsigned char *str) {

	int i, len;
	len = 0;
	for (i = 0; str[i] != '\0'; i++)
		len++;

	return len;

}

int ischar (unsigned char *str, int i) {

	if (str[i] >= 48 && str[i] <= 57) {
		return 1;
	}
	if (str[i] >= 65 && str[i] <= 90) {
		return 1;
	}
	if (str[i] >=  97 && str[i] <= 122){
		return 1;
	}

	if (str[i] == ' ' ){
		return 1;
	}

	return 0;
}

int main () {
	
	char *locale;
	unsigned char str[MAX];
	int len, i, j, k;
	
	setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");

	scanf ("%[^\n]", str);
	printf ("%s\n", str);

	len = usgnstrlen (str);
	for (i = 0; i < len; i++) {
		if (! ischar(str,i)) {
			j = i;
			while (str[j] != '\0') {
				str[j] = str[j + 1];
				j++; 
			}	
			len--;	
		}	
	}

	printf ("%s\n", str);

	return 0;
}
