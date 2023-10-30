#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 50

struct Osoba {
    char ime[maxsize];
    char prezime[maxsize];
    int godiste;
    struct Osoba* sljedeca;
};

typedef struct Osoba Osoba;

void dodajosobu(Osoba* glava, int napocetak) {
    Osoba* novaosoba = malloc(sizeof(Osoba)); 

    if (!novaosoba) {
        printf("Dogodila se greška tokom alociranja nove osobe!\n");
        return;
    }

    printf("Napisi ime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->ime);
    printf("Napisi prezime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->prezime);
    printf("Napisi godiste osobe koju zelis dodati: \n");
    scanf("%d", &novaosoba->godiste);

    if (napocetak) {
        novaosoba->sljedeca = glava->sljedeca;
        glava->sljedeca = novaosoba;
    } else {
        novaosoba->sljedeca = NULL;
        while (glava->sljedeca != NULL) {
            glava = glava->sljedeca;
        }
        glava->sljedeca = novaosoba;
    }
}

void ispisilistu(Osoba* glava) {
    while (glava != NULL) {
        printf("%s %s %d\n", glava->ime, glava->prezime, glava->godiste);
        glava = glava->sljedeca;
    }
}

void pronadiiispisi(Osoba* glava, char prezime[maxsize]) {
    while (glava != NULL) {
        if (strcmp(prezime, glava->prezime) == 0) {
            printf("%s %s %d\n", glava->ime, glava->prezime, glava->godiste);
        }
        glava = glava->sljedeca;
    }
}

void obrisiosobu(Osoba* glava, char prezime[maxsize]) {
    while (glava->sljedeca != NULL) {
        if (strcmp(prezime, glava->sljedeca->prezime) == 0) {
            Osoba* temp = glava->sljedeca;
            glava->sljedeca = temp->sljedeca;
            free(temp);
        }
        glava = glava->sljedeca;
    }
}

void dodajosobuiza(Osoba* glava, char prezime[maxsize]) {
    Osoba* novaosoba = malloc(sizeof(Osoba)); 

    if (!novaosoba) {
        printf("Dogodila se greška tokom alociranja nove osobe!\n");
        return;
    }

    printf("Napisi ime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->ime);
    printf("Napisi prezime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->prezime);
    printf("Napisi godiste osobe koju zelis dodati: \n");
    scanf("%d", &novaosoba->godiste);

    while (glava != NULL) {
        if (strcmp(prezime, glava->prezime) == 0) {
            novaosoba->sljedeca = glava->sljedeca;
            glava->sljedeca = novaosoba;
            return;
        }
        glava = glava->sljedeca;
    }

    printf("Osoba s tim prezimenom nije pronađena!\n");
    free(novaosoba);
}

void dodajisprid(Osoba* glava, char prezime[maxsize]) {
    Osoba* novaosoba = malloc(sizeof(Osoba)); 

    if (!novaosoba) {
        printf("Dogodila se greška tokom alociranja nove osobe!\n");
        return;
    }

    printf("Napisi ime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->ime);
    printf("Napisi prezime osobe koju zelis dodati: \n");
    scanf(" %s", novaosoba->prezime);
    printf("Napisi godiste osobe koju zelis dodati: \n");
    scanf("%d", &novaosoba->godiste);

    if (strcmp(prezime, glava->sljedeca->prezime) == 0) {
        novaosoba->sljedeca = glava->sljedeca;
        glava->sljedeca = novaosoba;
    } else {
        Osoba* trenutna = glava->sljedeca;
        while (trenutna->sljedeca != NULL) {
            if (strcmp(prezime, trenutna->sljedeca->prezime) == 0) {
                novaosoba->sljedeca = trenutna->sljedeca;
                trenutna->sljedeca = novaosoba;
                return;
            }
            trenutna = trenutna->sljedeca;
        }
    }
}

void upisiudatoteku(Osoba* glava) {
    FILE* datoteka = fopen("studenti.txt", "w");
    if (!datoteka) {
        printf("Dogodila se pogreška tokom otvaranja datoteke!\n");
        return;
    }

    Osoba* trenutna = glava->sljedeca;
    while (trenutna != NULL) {
        fprintf(datoteka, "%s %s %d\n", trenutna->ime, trenutna->prezime, trenutna->godiste);
        trenutna = trenutna->sljedeca;
    }

    fclose(datoteka); 
}

void citajizdatoteke(Osoba* glava) {
    FILE* datoteka = fopen("studenti.txt", "r");
    if (!datoteka) {
        printf("Datoteka se nije uspješno otvorila!\n");
        return;
    }

    Osoba* trenutna = glava;
    Osoba* novaosoba;

    while (1) {
        novaosoba = malloc(sizeof(Osoba));
        if (!novaosoba) {
            printf("Dogodila se greška prilikom dinamičke alokacije memorije!\n");
            break;
        }

        if (fscanf(datoteka, "%s %s %d", novaosoba->ime, novaosoba->prezime, &novaosoba->godiste) == 3) {
            novaosoba->sljedeca = NULL;
            trenutna->sljedeca = novaosoba;
            trenutna = novaosoba;
        } else {
            free(novaosoba); 
        }
    }

    fclose(datoteka); 
}

int main() {
    Osoba glava = {.ime = "", .prezime = "", .godiste = 0, .sljedeca = NULL};

    int odabir;
    char prezime[maxsize];

    while (1) {
        printf("\nIzbornik:\n"
            "0 - izlaz\n"
            "1 - Dodaj osobu na početak liste\n"
            "2 - Ispis liste\n"
            "3 - Dodaj osobu na kraj liste\n"
            "4 - Pronađi osobu po prezimenu i ispiši\n"
            "5 - Obriši osobu iz liste\n"
            "6 - Dodaj osobu iza određenog elementa\n"
            "7 - Dodaj osobu ispred određenog elementa\n"
            "8 - Upiši listu u datoteku\n"
            "9 - Čitaj listu iz datoteke\n");

        scanf(" %d", &odabir);

        switch (odabir) {
            case 0:
                return 0;
            case 1:
                dodajosobu(&glava, 1);
                break; 
            case 2:
                ispisilistu(glava.sljedeca);
                break;
            case 3:
                dodajosobu(&glava, 0);
                break;
            case 4:
                printf("Upisi prezime osobe koju zelis ispisati: ");
                scanf(" %s", prezime);
                pronadiiispisi(glava.sljedeca, prezime);
                break;
            case 5:
                printf("Upisi prezime osobe koju zelis izbrisati: ");
                scanf(" %s", prezime);
                obrisiosobu(&glava, prezime);
                break;
            case 6:
                printf("Upisi prezime osobe iza koje zelis dodati novu osobu: ");
                scanf(" %s", prezime);
                dodajosobuiza(&glava, prezime);
                break;
            case 8:
                upisiudatoteku(&glava);
                break;
            case 9:
                citajizdatoteke(&glava);
                break;
            default:
                printf("Nepoznata opcija, unesite ponovno.\n");
                break;
        }
    }

    return 0; 
}
