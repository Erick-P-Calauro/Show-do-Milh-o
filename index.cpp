#include <stdio.h>
#include "perguntas.cpp"

int main() {

    float valor_acumulado = 0;
    int pergunta = 1; // 1 a 16
    int bloco = 1; // 1,2,3 e 4 (Define as dificuldades)  
    int recursos[] = {3, 3, 3, 3}; // Pular, Pedir Ajuda da Platéia, Pedir Ajuda dos Universitários, Pedir Ajuda Cartas; 

    mostrar_pergunta(ler_pergunta(1, 0), 1, 8, recursos);

    return 0;
}