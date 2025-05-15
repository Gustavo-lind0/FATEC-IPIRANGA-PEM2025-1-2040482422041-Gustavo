/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Ordenação de dados Insertion Sort*                                    
* Data - 26/05/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/

#include <stdio.h>

// Funcao que realiza a ordenacao pelo metodo Insertion Sort
// Utiliza ponteiros e passagem de parametros
void insertionSort(int *vetor, int n) {
    for (int i = 1; i < n; i++) {
        // Salva o valor atual na variavel 'key'
        int key = *(vetor + i);
        int j = i - 1;

        // Move os elementos maiores que 'key' para a direita
        while (j >= 0 && *(vetor + j) > key) {
            *(vetor + j + 1) = *(vetor + j);
            j--;
        }

        // Insere a 'key' na posicao correta
        *(vetor + j + 1) = key;
    }
}

int main() {
    int n;

    // Solicita ao usuario a quantidade de numeros que serao ordenados
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int vetor[n]; // Cria o vetor com 'n' posicoes

    // Loop para leitura dos elementos do vetor
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Chamada da funcao de ordenacao Insertion Sort
    insertionSort(vetor, n);

    // Exibe o vetor ja ordenado
    printf("\nVetor ordenado (Insertion Sort): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}
