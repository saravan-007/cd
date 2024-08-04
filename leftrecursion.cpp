#include <stdio.h>
#include <string.h>

int main() {
    char a[50], alpha[50] = "", beta[50] = "", s1[50], s2[50], A;
    int i, ind2 = -1, k = 0, l = 0;

    printf("Enter the Grammar: ");
    scanf("%s", a);

    A = a[0];

    if (a[0] == a[3]) {
        for (i = 0; a[i] != '\0'; i++) {
            if (a[i] == '|') {
                ind2 = i;
                break;
            }
        }

        if (ind2 == -1) {
            printf("Invalid Grammar\n");
            return 1;
        } else {
            for (i = ind2 + 1; a[i] != '\0'; i++) {
                beta[l++] = a[i];
            }
            beta[l] = '\0';

            for (i = 3; i < ind2-1; i++) {
                alpha[k++] = a[i+1];
            }
            alpha[k] = '\0';

            sprintf(s1, "%c -> %s%c'", A, beta, A);
            sprintf(s2, "%c' -> %s%c'|e", A, alpha, A);
            
            printf("%s\n", s1);
            printf("%s\n", s2);
        }
    } else {
        printf("There is no left recursion\n");
    }

    return 0;
}
