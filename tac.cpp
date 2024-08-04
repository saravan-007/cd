#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char expression[100];
    char lhs[100], rhs[100];
    char operand1[100], operand2[100], op;
    int i = 0, j = 0, k = 0, m = 0;
    int temp_count = 0;

    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);

    // Split the expression into LHS and RHS
    while (expression[i] != '=' && expression[i] != '\0') {
        lhs[i] = expression[i];
        i++;
    }
    lhs[i] = '\0';
    if (expression[i] == '\0') {
        printf("Invalid expression. No assignment found.\n");
        return 1;
    }
    i++; // Skip the '='
    while (expression[i] != '\0') {
        rhs[j++] = expression[i++];
    }
    rhs[j] = '\0';

    // Parse the first operand
    while (rhs[k] != '+' && rhs[k] != '-' && rhs[k] != '*' && rhs[k] != '/' && rhs[k] != '\0') {
        operand1[k] = rhs[k];
        k++;
    }
    operand1[k] = '\0';
    if (rhs[k] == '\0') {
        printf("%s = %s\n", lhs, operand1);
        return 0;
    }

    // Parse the operator
    op = rhs[k++];

    // Parse the second operand
    while (rhs[k] != '\0') {
        operand2[m++] = rhs[k++];
    }
    operand2[m] = '\0';

    // Generate intermediate code
    printf("t%d = %s %c %s\n", temp_count, operand1, op, operand2);
    printf("%s = t%d\n", lhs, temp_count);

    return 0;
}

