#include <stdio.h>

void concatenateStrings(char str1[], char str2[]) {
    int i = 0, j = 0;
    // Find the end of the first string
    while (str1[i] != '\0') {
        i++;
    }
    // Append second string to first
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; // Null terminate the result
}

int main() {
    char str1[200], str2[100];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    
    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}
