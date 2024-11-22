#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura do jogador
typedef struct {
    char nome[50];
    int vitorias;
} Jogador;

// Função para criar um jogador dinamicamente
Jogador* criarJogador(const char* nome) {
    Jogador* jogador = (Jogador*) malloc(sizeof(Jogador));
    if (!jogador) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(jogador->nome, nome);  // acessa o campo 'nome' apontado pela estrutura 'jogador'
    jogador->vitorias = 0;
    return jogador;
}

// Função para jogar o dado (gera número aleatório entre 1 e 6)
int jogarDado() {
    return (rand() % 6) + 1;
}

// Função para comparar os valores dos dados e atualizar o número de vitórias
void compararDados(Jogador* jogador1, Jogador* jogador2, int dado1, int dado2) {
    printf("%s jogou: %d\n", jogador1->nome, dado1);
    printf("%s jogou: %d\n", jogador2->nome, dado2);
    
    if (dado1 > dado2) {
        printf("%s venceu esta rodada!\n\n", jogador1->nome);
        jogador1->vitorias++;
    } else if (dado2 > dado1) {
        printf("%s venceu esta rodada!\n\n", jogador2->nome);
        jogador2->vitorias++;
    } else {
        printf("Empate nesta rodada!\n\n");
    }
}

// Função para exibir os resultados finais
void exibirResultados(Jogador* jogador1, Jogador* jogador2) {
    printf("\nResultados finais:\n");
    printf("%s: %d vitória(s)\n", jogador1->nome, jogador1->vitorias);
    printf("%s: %d vitória(s)\n", jogador2->nome, jogador2->vitorias);
}

// Função para liberar a memória alocada para os jogadores
void liberarMemoria(Jogador* jogador1, Jogador* jogador2) {
    free(jogador1);
    free(jogador2);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa a semente para números aleatórios

    char nome1[50], nome2[50];
    printf("Digite o nome do jogador 1: ");
    scanf("%s", nome1);
    printf("Digite o nome do jogador 2: ");
    scanf("%s", nome2);

    // Criar jogadores dinamicamente
    Jogador* jogador1 = criarJogador(nome1);
    Jogador* jogador2 = criarJogador(nome2);

    char continuar;
    do {
        // Jogar os dados
        int dado1 = jogarDado();
        int dado2 = jogarDado();

        // Comparar resultados
        compararDados(jogador1, jogador2, dado1, dado2);

        // Perguntar se os jogadores desejam continuar
        printf("Desejam jogar novamente? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Exibir resultados finais
    exibirResultados(jogador1, jogador2);

    // Liberar memória alocada
    liberarMemoria(jogador1, jogador2);

    return 0;
}