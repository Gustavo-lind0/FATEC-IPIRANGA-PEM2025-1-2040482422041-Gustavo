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
#include <ctype.h> // Necessário para verificar dígitos

#define RUAS 3
#define GONDOLAS 10

// Estrutura para armazenar os produtos
struct Produto {
    char codigo[5]; // Regra de negócio: Código deve seguir o padrão Pnnn
    char descricao[50];
    int ocupada; // Regra de negócio: Um produto ocupa somente 1 gôndola
};

struct Produto estoque[RUAS][GONDOLAS]; // Aspecto Técnico: Implementação de Vetor Multidimensional

int main() {
    int i, j, opcao, rua, gondola;
    
    // Inicialização do estoque
    for (i = 0; i < RUAS; i++) {
        for (j = 0; j < GONDOLAS; j++) {
            estoque[i][j].ocupada = 0;
        }
    }
    
    do {
        printf("\n1 - Armazenar Produto\n2 - Retirar Produto\n3 - Listar Estoque\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) { // Solicitação de produto ao estoque
            printf("Digite rua (0-%d) e gôndola (0-%d): ", RUAS-1, GONDOLAS-1);
            scanf("%d %d", &rua, &gondola);
            if (rua < 0 || rua >= RUAS || gondola < 0 || gondola >= GONDOLAS) { // Programação madura: verificar validade da Rua e da gôndola
                printf("Erro: Rua ou gôndola inválida!\n");
                continue;
            }
            
            if (estoque[rua][gondola].ocupada == 1) { // Programação madura: verificar gôndola ocupada
                printf("Erro: Gôndola ocupada!\n");
            } else {
                printf("Digite o código do produto (Pnnn, ex: P123): ");
                scanf("%4s", estoque[rua][gondola].codigo);
                
                // Verificar se o código segue o formato Pnnn
                if (estoque[rua][gondola].codigo[0] != 'P' || 
                    !isdigit(estoque[rua][gondola].codigo[1]) || 
                    !isdigit(estoque[rua][gondola].codigo[2]) || 
                    !isdigit(estoque[rua][gondola].codigo[3]) || 
                    strlen(estoque[rua][gondola].codigo) != 4) {
                    printf("Erro: Código do produto deve seguir o padrão Pnnn!\n");
                    continue;
                }

                // Ler a descrição usando fgets para permitir espaços
                printf("Digite a descrição do produto: ");
                getchar(); // Para consumir o caractere '\n' deixado pelo scanf anterior
                fgets(estoque[rua][gondola].descricao, 50, stdin);
                
                // Remover o '\n' no final da descrição, caso exista
                size_t len = strlen(estoque[rua][gondola].descricao);
                if (len > 0 && estoque[rua][gondola].descricao[len - 1] == '\n') {
                    estoque[rua][gondola].descricao[len - 1] = '\0';
                }

                estoque[rua][gondola].ocupada = 1; // Efetuação de estocagem (Chegada de produto)
                printf("Produto armazenado!\n");
            }
        } else if (opcao == 2) { // Retirada de produto
            printf("Digite rua e gôndola: ");
            scanf("%d %d", &rua, &gondola);
            
            if (estoque[rua][gondola].ocupada == 0) { // Programação madura: verificar se produto existe (retirar)
                printf("Erro: Nenhum produto nesta gôndola!\n");
            } else {
                estoque[rua][gondola].ocupada = 0;
                printf("Produto retirado!\n");
            }
        } else if (opcao == 3) { // Listagem do estoque
            for (i = 0; i < RUAS; i++) {
                for (j = 0; j < GONDOLAS; j++) {
                    if (estoque[i][j].ocupada == 1) {
                        printf("Rua %d, Gôndola %d: %s - %s\n", i, j, estoque[i][j].codigo, estoque[i][j].descricao);
                    }
                }
            }
        }
    } while (opcao != 0);
    
    return 0;
}
