/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Ordenação de  dados Bubblesort   *                                    
* Data - 16/05/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/

#include <stdio.h>

// Funcao que realiza a ordenacao Bubble Sort
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Troca os elementos de lugar
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Quantos numeros deseja ordenar (Bubble Sort)? ");
    scanf("%d", &n);
    int arr[n];

    // Entrada dos elementos
    for (int i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Chamada da funcao
    bubbleSort(arr, n);

    // Impressao dos elementos ordenados
    printf("Numeros ordenados (Bubble Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}