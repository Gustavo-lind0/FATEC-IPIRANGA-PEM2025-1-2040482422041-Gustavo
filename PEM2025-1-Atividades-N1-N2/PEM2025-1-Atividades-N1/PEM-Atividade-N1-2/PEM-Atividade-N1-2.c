/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Diagrama de blocos               *
* Data - 05/03/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/



#include <stdio.h>
#include <string.h>

#define MAX_RUAS 3
#define MAX_GONDOLAS 10
#define MAX_PRODUTOS 100

typedef struct {
    char cod[10];
    char desc[50];
} Prod;

typedef struct {
    Prod prod;
    int ocup;
} Gond;

typedef struct {
    Gond gonds[MAX_GONDOLAS];
} Rua;

Rua estq[MAX_RUAS];

void InicEstq() {
    for (int i = 0; i < MAX_RUAS; i++) {
        for (int j = 0; j < MAX_GONDOLAS; j++) {
            estq[i].gonds[j].ocup = 0;
        }
    }
}

int ArmazProd(char *cod, char *desc, int rua, int gond) {
    if (estq[rua].gonds[gond].ocup) {
        printf("Erro: Gond ocupada!\n");
        return 0;
    }
    strcpy(estq[rua].gonds[gond].prod.cod, cod);
    strcpy(estq[rua].gonds[gond].prod.desc, desc);
    estq[rua].gonds[gond].ocup = 1;
    printf("Prod armazenado!\n");
    return 1;
}

int RetiraProd(int rua, int gond) {
    if (!estq[rua].gonds[gond].ocup) {
        printf("Erro: Nenhum prod nesta gond!\n");
        return 0;
    }
    estq[rua].gonds[gond].ocup = 0;
    printf("Prod retirado!\n");
    return 1;
}

void ListEstq() {
    for (int i = 0; i < MAX_RUAS; i++) {
        for (int j = 0; j < MAX_GONDOLAS; j++) {
            if (estq[i].gonds[j].ocup) {
                printf("Rua %d, Gond %d: %s - %s\n", i, j,
                       estq[i].gonds[j].prod.cod,
                       estq[i].gonds[j].prod.desc);
            }
        }
    }
}

int main() {
    InicEstq();
    ArmazProd("S123", "Sabonete", 0, 9);
    ListEstq();
    RetiraProd(0, 9);
    ListEstq();
    return 0;
}
