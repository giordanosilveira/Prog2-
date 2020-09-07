#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>

#define MAX 128

void handle_sigint (int sig) {

	char c;

	printf ("Do you really want to quit?\n");
	printf ("Press y for yes, n for no\n");

	c = getchar ();

	if (c == 'Y' || c == 'y')
		exit(0);
	else
		signal (SIGINT, handle_sigint);
	getchar ();

}
int main () {

	char string[MAX+1]; //string lenght + 1 (\0)	
	int len;

	signal(SIGINT, handle_sigint);

	while (1) {
		fgets (string, MAX, stdin);
		for (len = strlen (string); len >= 0; len--)
			printf ("%c", string[len]);
		printf("\n");

		sleep(1);
	}
	return 0;
}

