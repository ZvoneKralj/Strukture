#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 6

struct Osoba {
    char ime[maxsize];
    char prezime[maxsize];
    int godiste;
    struct Osoba* sljedeca;
};

typedef struct Osoba Osoba;

void dodajosobu(Osoba* glava, int naPocetak) {
    Osoba* novaOsoba = malloc(sizeof(Osoba));

    if (!novaOsoba) {
        printf("Dogodila se greška prilikom dinamičke alokacije memorije!\n");
        return;
    }

    printf("Unesite ime nove osobe: \n");
    scanf(" %s", novaOsoba->ime);

    printf("Unesite prezime nove osobe:\n");
    scanf(" %s", novaOsoba->prezime);

    printf("Unesite godinu rođenja nove osobe: \n");
    scanf("%d", &novaOsoba->godiste);

    if (naPocetak) {
        novaOsoba->sljedeca = glava->sljedeca;
        glava->sljedeca = novaOsoba;
    } else {
        novaOsoba->sljedeca = NULL;
        while (glava->sljedeca != NULL) {
            glava = glava->sljedeca;
        }
        glava->sljedeca = novaOsoba;
    }
}

void ispisilistu(Osoba* glava){
    while(glava != NULL){
        printf(" %s %s %d\n", glava->ime, glava->prezime, glava->godiste);
        glava = glava->sljedeca;
    }
}

void pronadiosobu(Osoba* glava, char prezime){
    while (glava != NULL){
        if (strcpy(prezime, glava->prezime) == 0){
            printf();
        }
        glava = glava->sljedeca;
    }
}

void izbrisiosobu(Osoba* glava, int prezime){
    while (glava->sljedeca != NULL){
        if (strcpy(prezime, glava->sljedeca->prezime) == 0){
            Osoba* temp = glava->sljedeca;
            glava->sljedeca = temp->sljedeca;
        }
        glava = glava->sljedeca;
    }
}

void main(){
    Osoba glava = {.ime = "", .prezime = "", .godiste = 0, .sljedeca = NULL};

    char prezime[maxsize];
    int izbor;

    while (1) {
        printf("\nIzbornik:\n"
            "0 - izlaz\n"
            "1 - Dodaj osobu na početak liste\n"
            "2 - Ispis liste\n"
            "3 - Dodaj osobu na kraj liste\n"
            "4 - Pronađi osobu po prezimenu i ispiši\n"
            "5 - Obriši osobu iz liste\n");

        scanf(" %d", &izbor);

    switch(izbor){
        case 0:
            return 0;
        case 1:
            dodajosobu(&glava, 1);
        case 2:
            ispisilistu(glava.sljedeca);
        case 3:
            dodajosobu(&glava, 0);
        case 4:
            printf("Upisi prezime osobe koju trazis: ");
            scanf(" %s", prezime);
            pronadiosobu(&glava, prezime);
        case 5:
            printf("Upisi prezime osobe koju trazis: ");
            scanf(" %s", prezime);
            izbrisiosobu(&glava, prezime);
    }

   
}


}