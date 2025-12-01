#include <stdio.h>

int main() {
    int i;
    char str[100];

    printf("Enter a string:\n");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' ) 
        {

            printf("%c is vowel\n", str[i]);
        }
        else {
            printf("%c is consonant\n", str[i]);
        }
    }

    return 0;
}
 




