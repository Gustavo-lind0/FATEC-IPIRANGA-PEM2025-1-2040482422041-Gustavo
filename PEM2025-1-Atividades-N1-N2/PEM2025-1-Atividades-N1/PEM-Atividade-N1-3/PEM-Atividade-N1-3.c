/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Refatorar e Modularizaçao        *
* Data - 14/03/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Necessario para verificar digitos

#define RUAS 3
#define GONDOLAS 10

// Estrutura para armazenar os produtos
struct Produto {
    char codigo[5]; // Codigo deve seguir o padrao Pnnn
    char descricao[50];
    int ocupada; // Um produto ocupa somente 1 gondola
};

struct Produto estoque[RUAS][GONDOLAS]; // Implementacao de Vetor Multidimensional

// Inicializa o estoque, marcando todas as gondolas como vazias
void inicializarEstoque(struct Produto (*estoque)[GONDOLAS]) {
    int i, j;
    for (i = 0; i < RUAS; i++) {
        for (j = 0; j < GONDOLAS; j++) {
            estoque[i][j].ocupada = 0;
        }
    }
}

// Verifica se o codigo comeca com 'P' e tem 3 numeros
int validarCodigo(char *codigo) {
    return (codigo[0] == 'P' && isdigit(codigo[1]) && isdigit(codigo[2]) && isdigit(codigo[3]) && strlen(codigo) == 4);
}

// Funcao para armazenar um produto no estoque
void armazenarProduto(struct Produto (*estoque)[GONDOLAS]) {
    int rua, gondola;
    printf("Digite rua (0-%d) e gondola (0-%d): ", RUAS-1, GONDOLAS-1);
    scanf("%d %d", &rua, &gondola);
    
    if (rua < 0 || rua >= RUAS || gondola < 0 || gondola >= GONDOLAS) {
        printf("Erro: Rua ou gondola invalida!\n");
        return;
    }
    
    struct Produto *p = &estoque[rua][gondola];
    
    if (p->ocupada) {
        printf("Erro: Gondola ocupada!\n");
        return;
    }
    
    printf("Digite o codigo do produto (Pnnn, ex: P123): ");
    scanf("%4s", p->codigo);
    
    if (!validarCodigo(p->codigo)) {
        printf("Erro: Codigo do produto deve seguir o padrao Pnnn!\n");
        return;
    }
    
    printf("Digite a descricao do produto: ");
    getchar(); // Consome o '\n' deixado pelo scanf anterior
    fgets(p->descricao, 50, stdin);
    p->descricao[strcspn(p->descricao, "\n")] = 0; // Remove o '\n' caso exista
    p->ocupada = 1; // Marca a gondola como ocupada
    printf("Produto armazenado!\n");
}

// Funcao para retirar um produto do estoque
void retirarProduto(struct Produto (*estoque)[GONDOLAS]) {
    int rua, gondola;
    printf("Digite rua e gondola: ");
    scanf("%d %d", &rua, &gondola);
    
    if (rua < 0 || rua >= RUAS || gondola < 0 || gondola >= GONDOLAS) {
        printf("Erro: Rua ou gondola invalida!\n");
        return;
    }
    
    struct Produto *p = &estoque[rua][gondola];
    
    if (!p->ocupada) {
        printf("Erro: Nenhum produto nesta gondola!\n");
        return;
    }
    
    p->ocupada = 0; // Marca a gondola como vazia
    printf("Produto retirado!\n");
}

// Funcao para listar os produtos armazenados no estoque
void listarEstoque(struct Produto (*estoque)[GONDOLAS]) {
    int i, j;
    for (i = 0; i < RUAS; i++) {
        for (j = 0; j < GONDOLAS; j++) {
            struct Produto *p = &estoque[i][j];
            if (p->ocupada) {
                printf("Rua %d, Gondola %d: %s - %s\n", i, j, p->codigo, p->descricao);
            }
        }
    }
}

// Funcao principal
int main() {
    int opcao;
    inicializarEstoque(estoque);
    
    do {
        // Menu de opcoes
        printf("\n1 - Armazenar Produto\n2 - Retirar Produto\n3 - Listar Estoque\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            armazenarProduto(estoque);
        } else if (opcao == 2) {
            retirarProduto(estoque);
        } else if (opcao == 3) {
            listarEstoque(estoque);
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
