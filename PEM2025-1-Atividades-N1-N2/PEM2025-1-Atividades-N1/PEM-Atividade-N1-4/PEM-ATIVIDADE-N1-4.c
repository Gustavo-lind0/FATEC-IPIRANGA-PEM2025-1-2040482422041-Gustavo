/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Gerenciamento de Árvore de       *
* Diretórios usando Recursividade (sem dirent.h)         *
* Data - 24/03/2025                                      * 
* Autor: Gustavo Alves Pereira                           *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

// Função para explorar diretórios recursivamente
void explorar_diretorio(const char *caminho, int nivel) {
    DIR *dir;
    struct dirent *entrada;

    if ((dir = opendir(caminho)) == NULL) {
        perror("Erro ao abrir diretório");
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue; // Ignora os diretórios especiais . e ..
        }

        for (int i = 0; i < nivel; i++) {
            printf("  "); // Indentação para representar a hierarquia
        }
        printf("|- %s\n", entrada->d_name);

        // Verifica se é um diretório
        if (entrada->d_type == DT_DIR) {
            char novo_caminho[1024];
            snprintf(novo_caminho, sizeof(novo_caminho), "%s/%s", caminho, entrada->d_name);
            explorar_diretorio(novo_caminho, nivel + 1);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <diretorio>\n", argv[0]);
        return 1;
    }

    printf("Explorando diretório: %s\n", argv[1]);
    explorar_diretorio(argv[1], 0);
    return 0;
}


