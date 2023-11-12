#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    double data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(double value) {
    Node* newel = malloc(sizeof(Node));
    if (!newel) {
        printf("Dogodila se pogreška pri dinamičkoj alokaciji novog elementa!\n");
        exit(EXIT_FAILURE);
    }

    newel->data = value;
    newel->next = NULL;
    return newel;
}

void push(Node** stack, double value) {
    Node* newnode = createNode(value);
    newnode->next = *stack;
    *stack = newnode;
}

double pop(Node** top) {
    if (*top == NULL) {
        printf("U stogu se više ništa ne nalazi!\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = *top;
    *top = (*top)->next;
    double value = temp->data;
    free(temp);
    return value;
}

double calculatePostfix(char* buffer) {
    Node* stack = NULL;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (isdigit(buffer[i])) {
            push(&stack, buffer[i] - '0');
        } else if (buffer[i] == ' ') {
            continue;
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            switch (buffer[i]) {
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Operacija nije podržana %c\n", buffer[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    if (stack != NULL) {
        double result = pop(&stack);
        if (stack == NULL) {
            return result;
        } else {
            printf("Dobili smo neispravan postfiks izraz!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Stog je prazan!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    FILE* datoteka = fopen("datoteka.txt", "r");
    if (!datoteka) {
        printf("Datoteka nije uspješno otvorena!\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), datoteka);
    fclose(datoteka);

    double rezultat = calculatePostfix(buffer);
    printf("Rezultat izraza je: %lf\n", rezultat);

    return 0;
}
