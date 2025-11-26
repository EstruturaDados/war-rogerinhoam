#include <stdio.h>
#include <string.h>

// Definição da struct Territorio conforme solicitado
// Serve para agrupar dados de diferentes tipos (char e int) em uma única entidade
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Declaração de um vetor de structs para armazenar 5 territórios
    struct Territorio territorios[5];
    int i;

    printf("=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n");
    printf("Por favor, insira os dados de 5 territorios.\n\n");

    // --- ENTRADA DE DADOS ---
    // Laço de repetição para preencher o vetor
    for (i = 0; i < 5; i++) {
        printf("Cadastro do Territorio %d:\n", i + 1);

        // Leitura do Nome (usando fgets para permitir espaços, ex: "America do Sul")
        printf("Nome do territorio: ");
        fgets(territorios[i].nome, 30, stdin);
        
        // Remove o caractere de nova linha (\n) que o fgets captura
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;

        // Leitura da Cor
        printf("Cor do exercito: ");
        scanf("%s", territorios[i].cor);

        // Leitura da Quantidade de Tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        // Limpeza do buffer do teclado
        // Isso é necessário porque o scanf deixa um '\n' no buffer, 
        // que pularia o próximo fgets se não fosse removido.
        while(getchar() != '\n');

        printf("--------------------------------\n");
    }

    // --- EXIBICAO DOS DADOS ---
    printf("\n=== RESUMO DOS TERRITORIOS CADASTRADOS ===\n");
    
    // Percorre o vetor novamente para mostrar os dados
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("--------------------------------\n");
    }

    return 0;
}