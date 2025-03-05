/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Variáveis Compostas Homogêneas   *
* Data - 27/02/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATOS 50
#define MAX_NOME 100

// Função para calcular a soma das notas centrais, removendo a maior e a menor
float soma_notas_centrais(float notas[], int tamanho) {
    float maior = notas[0], menor = notas[0], soma = 0.0;
    int i;
    
    for (i = 1; i < tamanho; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }
    
    for (i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    
    return soma - maior - menor;
}

// Estrutura para armazenar os dados de um candidato
typedef struct {
    char nome[MAX_NOME];
    float notas_PE[4], notas_AC[5], notas_PP[10], notas_EB[3];
    float nota_final;
} Candidato;

// Função para comparar candidatos para ordenação (usado no qsort)
int comparar(const void *a, const void *b) {
    Candidato *c1 = (Candidato *)a;
    Candidato *c2 = (Candidato *)b;
    if (c2->nota_final > c1->nota_final) return 1;
    if (c2->nota_final < c1->nota_final) return -1;
    return 0;
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int numbcandidatos, i;
    
    printf("Digite o numero de candidatos (maximo %d): ", MAX_CANDIDATOS);
    scanf("%d", &numbcandidatos);
    
    if (numbcandidatos > MAX_CANDIDATOS) {
        printf("Numero maximo de candidatos excedido!\n");
        return 1;
    }
    
    for (i = 0; i < numbcandidatos; i++) {
        printf("\nDigite o n do candidato %d: ", i + 1);
        scanf(" %s", candidatos[i].nome);
        
        printf("Digite as 4 notas da Prova Escrita (PE): ");
        for (int j = 0; j < 4; j++) scanf("%f", &candidatos[i].notas_PE[j]);
        
        printf("Digite as 5 notas da Analise Curricular (AC): ");
        for (int j = 0; j < 5; j++) scanf("%f", &candidatos[i].notas_AC[j]);
        
        printf("Digite as 10 notas da Prova Pratica (PP): ");
        for (int j = 0; j < 10; j++) scanf("%f", &candidatos[i].notas_PP[j]);
        
        printf("Digite as 3 notas da Entrevista em Banca Avaliadora (EB): ");
        for (int j = 0; j < 3; j++) scanf("%f", &candidatos[i].notas_EB[j]);
        
        float PE = soma_notas_centrais(candidatos[i].notas_PE, 4);
        float AC = soma_notas_centrais(candidatos[i].notas_AC, 5);
        float PP = soma_notas_centrais(candidatos[i].notas_PP, 10);
        float EB = soma_notas_centrais(candidatos[i].notas_EB, 3);
        
        candidatos[i].nota_final = (PE * 0.3) + (AC * 0.1) + (PP * 0.4) + (EB * 0.2);
    }
    
    // Ordenar candidatos por nota final (decrescente)
    qsort(candidatos, numbcandidatos, sizeof(Candidato), comparar);
    
    // Exibir os 15 melhores candidatos ou o número total, caso seja menor que 15
    printf("\nClassificação dos 15 melhores candidatos:\n");
    int limite = numbcandidatos < 15 ? numbcandidatos : 15;
    for (i = 0; i < limite; i++) {
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].nota_final);
    }
    
    return 0;
}
