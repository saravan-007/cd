#include <stdio.h>
#include <string.h>

int main() {
    int has_b = 0, valid = 1, i, len;
    char str[50];

    printf("Enter the string according to S->ab , S->Sb, S->aS S->e: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        if (str[0] == 'a') {
            for (i = 1; str[i] != '\0'; i++) {
                if (str[i] == 'a' && has_b) {
                    valid = 0;
                    break;
                } else if (str[i] == 'b') {
                    has_b = 1;
                } else if (str[i] != 'a' && str[i] != 'b') {
                    valid = 0;
                    break;
                }
            }
            if (valid && (has_b || str[i - 1] == 'a')) {
                printf("String Accepted\n");
            } else {
                printf("String Rejected\n");
            }
        } else {
            printf("String Rejected\n");
        }
    } else {
        printf("String Rejected\n");
    }

    return 0;
}
