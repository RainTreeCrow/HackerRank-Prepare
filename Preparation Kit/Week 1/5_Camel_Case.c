#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void splitCamelCase(char* input, char type) {
    if (type == 'M') {
        input[strlen(input) - 2] = '\0';  // Remove "()"
    }
    if (type == 'C') {
        printf("%c", tolower(input[0]));
    } else {
        printf("%c", input[0]);
    }

    for (int i = 1; input[i] != '\0'; i++) {
        if (isupper(input[i])) {
            printf(" ");
            printf("%c", tolower(input[i]));
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}

void combineCamelCase(char* input, char type) {
    if (type == 'C') {
        printf("%c", toupper(input[0]));
    } else {
        printf("%c", input[0]);
    }
    int flag = 0;
    
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            flag = 1;
        } else {
            if (flag == 1) {
                printf("%c", toupper(input[i]));
                flag = 0;
            }
            else {
                printf("%c", input[i]);
            }
        }
    }
    if (type == 'M') printf("()");
    printf("\n");
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';

        char operation, type;
        char input[1024];

        if (sscanf(line, "%c;%c;%[^\n]", &operation, &type, input) == 3) {

            if (operation == 'S') {
                splitCamelCase(input, type);
            } else if (operation == 'C') {
                combineCamelCase(input, type);
            }
        }
    }

    return 0;
}
