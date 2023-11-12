#include <stdio.h>
#include <stdlib.h>

struct Polynom{
    int coef;
    int exp;
    struct Polynom* next;
};

typedef struct Polynom Polynom;

Polynom* create_element(int k, int e){
    Polynom* newel = malloc(sizeof(Polynom));
    if (!newel){
        printf("Novi element je neuspješno dinamički alociran!\n");
        return NULL; 
    }

    newel->coef = k;
    newel->exp = e;
    newel->next = NULL;

    return newel;
}

void insert_sorted(Polynom** head, int k, int e){
    Polynom* newel = create_element(k, e);
    
    while (*head && (*head)->exp > e){
        head = &(*head)->next;
    } 
    if (*head && (*head)->exp == e){
        (*head)->coef += k;
        free(newel);
        return;
    }
    newel->next = *head;
    *head = newel;
}

void print_polynom(Polynom* first) {
    if (!first) {
        printf("Polinom je prazan.\n");
        return;
    }
    while (first) {
        if (first->exp == 0) {
            printf(" %d ", first->coef);
        } else if (first->exp == 1) {
            if (first->coef == 1) {
                printf(" X ");
            } else {
                printf(" %dX ", first->coef);
            }
        } else {
            if (first->coef == 1) {
                printf(" X^%d ", first->exp);
            } else {
                printf(" %dX^%d ", first->coef, first->exp);
            }
        }
        if (first->next) {
            printf("+");
        }
        first = first->next;
    }
    printf("\n");
}

void delete_all(Polynom* head) {
    while (head) {
        Polynom* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    char imedatoteke[1024];
    printf("Unesite ime datoteke: ");
    scanf(" %s", imedatoteke);

    FILE* datoteke = fopen(imedatoteke, "r");
    if (!datoteke) {
        printf("Datoteka se neuspješno otvorila!\n");
        return EXIT_FAILURE; 
    }

    Polynom* head1 = NULL;
    Polynom* head2 = NULL;
    Polynom* headsum = NULL;
    Polynom* headproduct = NULL;

    char buffer[1024];
    int e, k;

    while (fgets(buffer, sizeof(buffer), datoteke)) {
        if (sscanf(buffer, " %d %d", &k, &e) == 2) {
            insert_sorted(&head1, k, e);
        }
        if (!fgets(buffer, sizeof(buffer), datoteke)) {
            break;
        }
        if (sscanf(buffer, " %d %d", &k, &e) == 2) { 
            insert_sorted(&head2, k, e);
        }
    }

    printf("Zbroj polinoma:\n");
    headsum = NULL;

    while (head1 || head2) {
        if (head1 && (!head2 || head1->exp > head2->exp)) {
            insert_sorted(&headsum, head1->coef, head1->exp);
            head1 = head1->next;
        } else if (head2 && (!head1 || head2->exp > head1->exp)) {
            insert_sorted(&headsum, head2->coef, head2->exp);
            head2 = head2->next;
        } else {
            int sum_coef = head1->coef + head2->coef;
            if (sum_coef != 0) {
                insert_sorted(&headsum, sum_coef, head1->exp);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    print_polynom(headsum);

    printf("Umnožak polinoma:\n");
    headproduct = NULL;
    Polynom* temp1 = head1;
    while (temp1) {
        Polynom* temp2 = head2;
        while (temp2) {
            int prod_coef = temp1->coef * temp2->coef;
            int prod_exp = temp1->exp + temp2->exp;
            insert_sorted(&headproduct, prod_coef, prod_exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    print_polynom(headproduct);

    delete_all(head1);
    delete_all(head2);
    delete_all(headsum);
    delete_all(headproduct);

    fclose(datoteke);

    return EXIT_SUCCESS;
}
