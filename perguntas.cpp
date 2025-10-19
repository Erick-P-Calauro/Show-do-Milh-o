#include <stdio.h>
#include <cstdlib>

typedef struct {
    char nivel;
    char descricao[200];
    char alt[4][30];
    char alt_correta;
} Pergunta;

Pergunta ler_pergunta(int id_pergunta, int bloco);
void mostrar_pergunta(Pergunta pergunta, int count_pergunta, float saldo, int[4]);

// id_pergunta = [0,19] e [0,9] para super difícil
// bloco de 0 a 3
Pergunta ler_pergunta(int id_pergunta, int bloco) {

    FILE *perguntas = fopen("./files/perguntas.dat", "r");
    Pergunta pergunta = {};
    int bytes_lidos = 0;

    if(perguntas == NULL) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    if(bloco == 3) { // Bloco de perguntas super difíceis
        fseek(perguntas, 60 * sizeof(Pergunta) + (id_pergunta-1) * sizeof(Pergunta), 0);
    }else { // Demais Blocos de Pergunta
        fseek(perguntas, bloco * sizeof(Pergunta) * 20 + id_pergunta * sizeof(Pergunta), 0);
    }

    bytes_lidos = fread(&pergunta, sizeof(Pergunta), 1, perguntas);
    // Reseta a posição do ponteiro do arquivo
    fseek(perguntas, SEEK_SET,0); 

    if(bytes_lidos == 0) {
        perror("Pergunta não foi encontrada.");
        exit(1);
    }
    
    fclose(perguntas);

    return pergunta;
}

void mostrar_pergunta(Pergunta pergunta, int count_pergunta, float saldo, int recursos[4]) {

    printf("\n==-----------\n");
    printf("== Pergunta %d\n", count_pergunta);
    printf("== Dificuldade : %d\n", pergunta.nivel);
    printf("Voce possui um total acumulado de R$ %.2f\n", saldo);
    printf("\n");
    printf("%s\n", pergunta.descricao);
    printf("a) %s\n", pergunta.alt[0]);
    printf("b) %s\n", pergunta.alt[1]);
    printf("c) %s\n", pergunta.alt[2]);
    printf("d) %s\n", pergunta.alt[3]);
    printf("\n");
    printf("-- Ajuda --\n");
    printf("[1] Pular pergunta (%dx)\n", recursos[0]);
    printf("[2] Pedir ajuda a plateia (%dx)\n", recursos[1]);
    printf("[3] Pedir ajuda aos universitarios (%dx)\n", recursos[2]);
    printf("[4] Pedir ajuda as cartas (%dx)\n", recursos[3]);
    printf("[5] Sair\n");
    printf("~~~~~~~~~~~~~~~\n");

}