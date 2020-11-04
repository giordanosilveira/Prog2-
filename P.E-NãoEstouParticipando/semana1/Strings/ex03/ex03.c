#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAX 100

int main () {

	unsigned char str[MAX];
	char *locale;
	int len, i;

	locale = setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");

	if (!locale) {
		perror ("Can't set the specified locale");
		exit (1);
	}

	scanf ("%[^\n]", str);
	
	len = 0;
	for (int i = 0; str[i] != '\0'; i++)
		len++;

	for (i = 0; i < len; i++) {
	//	printf ("%d %c\n", str[i], str[i]);
		if ((str[i] <= 122 && str[i] >= 97) || (str[i] <= 251 && str[i] >= 224 ))
			str[i] = str[i] - 32;
	}

	printf ("%s\n", str);
	

	return 0;
}
