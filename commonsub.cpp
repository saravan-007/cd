#include <stdio.h>
#include <string.h>

// Define the structure to hold expressions
typedef struct {
    char result[10];
    char operand1[10];
    char operand2[10];
    char operator;
} Expression;

// Function to eliminate common subexpressions
void eliminateCommonSubexpressions(Expression expr[], int n) {
    int i, j, tempCount = 0;
    char tempVar[10];

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            // Check if the current expression is a common subexpression
            if (strcmp(expr[i].operand1, expr[j].operand1) == 0 &&
                strcmp(expr[i].operand2, expr[j].operand2) == 0 &&
                expr[i].operator == expr[j].operator) {
                // Generate a temporary variable name
                sprintf(tempVar, "t%d", tempCount++);

                // Replace the common subexpression with the temporary variable
                strcpy(expr[j].result, tempVar);
                strcpy(expr[i].operand1, tempVar);
                strcpy(expr[i].operand2, "");

                break;
            }
        }
    }

    // Print the optimized expressions
    printf("Optimized expressions:\n");
    for (i = 0; i < n; i++) {
        if (strlen(expr[i].operand2) > 0) {
            printf("%s = %s %c %s\n", expr[i].result, expr[i].operand1, expr[i].operator, expr[i].operand2);
        } else {
            printf("%s = %s\n", expr[i].result, expr[i].operand1);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of expressions: ");
    scanf("%d", &n);

    Expression expr[n];
    printf("Enter the expressions (result = operand1 operator operand2):\n");
    for (i = 0; i < n; i++) {
        scanf("%s = %s %c %s", expr[i].result, expr[i].operand1, &expr[i].operator, expr[i].operand2);
    }

    eliminateCommonSubexpressions(expr, n);

    return 0;
}
