#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double parse_expression(char** str);
double parse_term(char** str);
double parse_factor(char** str);
double parse_number(char** str);

double parse_expression(char** str) {
    double result = parse_term(str);
    while (**str == '+' || **str == '-') {
        char op = **str;
        (*str)++;
        if (op == '+') {
            result += parse_term(str);
        } else {
            result -= parse_term(str);
        }
    }
    return result;
}

double parse_term(char** str) {
    double result = parse_factor(str);
    while (**str == '*' || **str == '/') {
        char op = **str;
        (*str)++;
        if (op == '*') {
            result *= parse_factor(str);
        } else {
            result /= parse_factor(str);
        }
    }
    return result;
}

double parse_factor(char** str) {
    double result;
    if (**str == '(') {
        (*str)++;
        result = parse_expression(str);
        if (**str == ')') {
            (*str)++;
        }
    } else if (isdigit(**str) || **str == '.') {
        result = parse_number(str);
    } else {
        result = 0; // error in input
    }
    return result;
}

double parse_number(char** str) {
    double result = strtod(*str, str);
    return result;
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    char* str = expression;
    double result = parse_expression(&str);

    printf("The result is: %lf\n", result);

    return 0;
}

