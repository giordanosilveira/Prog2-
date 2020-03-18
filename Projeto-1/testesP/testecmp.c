#include <stdio.h>
#include <stdlib.h>
int s_cmp (char *dict, char *word) {

    int i = 0;
    while (dict[i] != '\0') {

        if (word[i] != '\0')
            break;
        
        i++;
    }
    return dict[i] - word[i];    

}
int main () {

    char word1[50]; 
    char word2[50]; 

    word1[50] = "banana";
    if ( ! s_cmp (word1,word2))
        printf ("aqui");
    
    else printf ("not aqui");


    return 0;
}