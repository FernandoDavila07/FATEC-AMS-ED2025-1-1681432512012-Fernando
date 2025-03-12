#include <stdio.h>
#include <string.h>

const int MAX_CANDIDATOS = 50;
const int MAX_NOTAS_PE = 4;
const int MAX_NOTAS_AC = 5;
const int MAX_NOTAS_PP = 10;
const int MAX_NOTAS_EB = 3;

typedef struct {
    char nome[100];
    float notas_PE[4];
    float notas_AC[5];
    float notas_PP[10];
    float notas_EB[3];
    float nota_final;
} Candidato;

float soma_excluindo_extremos(float *notas, int tamanho) {
    float menor = *notas, maior = *notas, soma = 0;

    for (float *p = notas; p < notas + tamanho; p++) {
        soma += *p;
        if (*p < menor) menor = *p;
        if (*p > maior) maior = *p;
    }
    
    return soma - (menor + maior);
}

float calcular_nota_final(float *notas_PE, float *notas_AC, float *notas_PP, float *notas_EB) {
    float soma_PE = soma_excluindo_extremos(notas_PE, 4);
    float soma_AC = soma_excluindo_extremos(notas_AC, 5);
    float soma_PP = soma_excluindo_extremos(notas_PP, 10);
    float soma_EB = soma_excluindo_extremos(notas_EB, 3);

    return (soma_PE * 0.3) + (soma_AC * 0.1) + (soma_PP * 0.4) + (soma_EB * 0.2);
}

void ordenar_candidatos(Candidato candidatos[], int num_candidatos) {
    for (int i = 0; i < num_candidatos - 1; i++) {
        for (int j = 0; j < num_candidatos - i - 1; j++) {
            if (candidatos[j].nota_final < candidatos[j + 1].nota_final) {
                Candidato temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }
}

void exibir_classificacao(Candidato candidatos[], int num_candidatos) {
    printf("\nClassificação dos 5 melhores candidatos:\n");
    printf("------------------------------------------------------------\n");

    ordenar_candidatos(candidatos, num_candidatos);

    for (int i = 0; i < 5 && i < num_candidatos; i++) {
        printf("Posição: %d\n", i + 1);
        printf("Nome: %s\n", candidatos[i].nome);
        printf("Nota Final: %.2f\n\n", candidatos[i].nota_final);
    }
}

void verificar_nota(const char* tipo, float* nota, int indice) {
    do {
        printf("%s %d ", tipo, indice + 1);
        scanf("%f", nota);
        if (*nota < 0.0 || *nota > 10.0) {
            printf("Nota inválida! Insira um valor entre 0.0 e 10.0.\n");
        }
    } while (*nota < 0.0 || *nota > 10.0);
}

int main() {
    Candidato candidatos[50];
    int num_candidatos = 0;
    char nome[100];

    while (num_candidatos < 50) {
        printf("Digite o nome do candidato %d (ou 'fim' para terminar): ", num_candidatos + 1);
        scanf(" %[^\n]", nome);

        if (strcmp(nome, "fim") == 0) break; //olá prof! o senhor tinha mostrado na aula o strcpy "string copy" fiquei curioso e pesquisei sobre e acabei achando o strcmp "string compare" e achei mais facil para fazer uma verificação onde o usuario podera escolher se deseja continuar inserindo canditados ou deseja parar

        strcpy(candidatos[num_candidatos].nome, nome);

        printf("Digite as notas da Prova Escrita (PE):\n");
        for (int i = 0; i < 4; i++) {
            verificar_nota("Nota PE", &candidatos[num_candidatos].notas_PE[i], i);
        }

        printf("Digite as notas da Análise Curricular (AC):\n");
        for (int i = 0; i < 5; i++) {
            verificar_nota("Nota AC", &candidatos[num_candidatos].notas_AC[i], i);
        }

        printf("Digite as notas da Prova Prática (PP):\n");
        for (int i = 0; i < 10; i++) {
            verificar_nota("Nota PP", &candidatos[num_candidatos].notas_PP[i], i);
        }

        printf("Digite as notas da Entrevista em Banca Avaliadora (EB):\n");
        for (int i = 0; i < 3; i++) {
            verificar_nota("Nota EB", &candidatos[num_candidatos].notas_EB[i], i);
        }

        candidatos[num_candidatos].nota_final = calcular_nota_final(
            candidatos[num_candidatos].notas_PE,
            candidatos[num_candidatos].notas_AC,
            candidatos[num_candidatos].notas_PP,
            candidatos[num_candidatos].notas_EB
        );

        num_candidatos++;
    }

    exibir_classificacao(candidatos, num_candidatos);

    return 0;
}
