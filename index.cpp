#include <stdio.h>
#include <time.h>
#include <math.h>
#include <random>
#include <string.h>
#include "perguntas.cpp"
#include "utilidades.cpp"

int main() {

    float valor_acumulado = 0;
    int sorteio_pergunta = 0;
    
    // 1 a 16
    int pergunta_count = 1; 
    int perguntas_realizadas[5] = {0, 0, 0, 0, 0};

    // 0,1,2,3 (Define as dificuldades) 
    int bloco = 0;  
    
    // Pular, Pedir Ajuda da Platéia, Pedir Ajuda dos Universitários, Pedir Ajuda Cartas;
    int recursos[] = {3, 3, 3, 3};  
    
    // Alternativa Escolhida ([1,2,3,4,5 - a,b,c,d])
    char escolha = 0;

    // Flags para continuidade do jogo e passagem para proxima pergunta
    int continuar = 1, resposta_valida = 1; 

    srand(time(0));

    while(continuar) {

        do {
            if(bloco == 3) {
                sorteio_pergunta = rand() % 10 + 1;
            }else {
                sorteio_pergunta = rand() % 20 + 1;
            }
        
        // Se a pergunta já foi sorteada, então sorteie a pergunta novamente
        }while (inteiro_em_vetor(sorteio_pergunta, perguntas_realizadas, 5));
        perguntas_realizadas[pergunta_count % 5] = sorteio_pergunta;

        Pergunta pergunta = ler_pergunta(sorteio_pergunta, bloco);

        // Loop do while para verificar a validade da resposta
        // Se for selecionados recursos já utilizados a resposta é inválida
        // A invalidez da resposta mostra a mesma pergunta novamente
        do{ 
            resposta_valida = 1;

            mostrar_pergunta(pergunta, pergunta_count, valor_acumulado, recursos);
            printf("Resposta : \n");
            scanf("%c%*c", &escolha);

            switch(escolha) {
                // Pular pergunta
                case '1':

                    // Se tem recurso[0] (Pular) pula a pergunta
                    if(recursos[0] == 0) {
                        resposta_valida = 0;
                    }else {
                        recursos[0]--;
                    }

                    break;
                // Pedir ajuda à plateia
                case '2':

                    resposta_valida = 0;

                    if(recursos[1] != 0) {
                        
                        int contagem_plateia[] = {0,0,0,0}; // a,b,c,d
                        int *probabilidades = criar_array_plateia(pergunta.alt_correta);

                        // Fazendo o sorteio das 30 perguntas com base no array probabilidades
                        for(int i = 0; i < 30; i++) {
                            contagem_plateia[probabilidades[rand() % 10]]++;
                        }

                        printf("Respostas da Plateia : \n");
                        printf("A : %d - B : %d - C : %d - D : %d\n", contagem_plateia[0], contagem_plateia[1], contagem_plateia[2], contagem_plateia[3]);

                        recursos[1]--;
                        free(probabilidades);
                    }
                
                    break;
                // Pedir ajuda aos universitarios
                case '3':

                    resposta_valida = 0;

                    if(recursos[2] != 0) {
                        char contagem_universitarios[] = {'\0', '\0', '\0'};
                        int *probabilidades = criar_array_universitarios(pergunta.alt_correta);

                        // Atribuindo as respostas dos universitarios com base na probabilidade
                        // A soma de 97 se deve aos pormenores do array de probabilidades (Ver utilidades.cpp)
                        for(int i = 0; i < 3; i++) {
                            contagem_universitarios[i] = probabilidades[rand() % 10] + 97;
                        }

                        printf("Respostas dos Universitarios : \n");
                        printf("Universitario 1 : %c\nUniversitario 2 : %c\nUniversitario 3 : %c\n", contagem_universitarios[0], contagem_universitarios[1], contagem_universitarios[2]);
                        
                        recursos[2]--;
                        free(probabilidades);
                    }

                    break;
                // Pedir ajuda às cartas
                case '4':

                    resposta_valida = 0;

                    if(recursos[3] != 0) {
                        int escolha_cartas;
                        int alternativa_correta = pergunta.alt_correta % 97;

                        printf("Escolha uma carta (0,1,2 ou 3) : ");
                        scanf("%d%*c", &escolha_cartas);

                        if(escolha_cartas == 3) {
                            for(int i = 0; i < 4; i++) {
                                if(i != alternativa_correta) {
                                    strcpy(pergunta.alt[i], "");
                                }
                            }
                        }

                        if(escolha_cartas == 2) {
                            int *cartas = (int*) malloc(sizeof(int) * 2);
                            
                            do {
                               cartas[0] = rand() % 4;
                               cartas[1] = rand() % 4;
                            }while(cartas[0] == alternativa_correta || cartas[1] == alternativa_correta || cartas[0] == cartas[1]);

                            strcpy(pergunta.alt[cartas[0]], "");
                            strcpy(pergunta.alt[cartas[1]], "");

                            free(cartas);
                        }

                        if(escolha_cartas == 1) {
                            int carta;
                            
                            do {
                                carta = rand() % 4;
                            }while(carta == alternativa_correta);

                            strcpy(pergunta.alt[carta], "");
                        }

                        recursos[3]--;
                    }

                    break;
                // Sair
                case '5':
                    printf("\nVoce saiu com R$ %.2f\n\n", valor_acumulado);
                    continuar = 0;
                    break;
                // Alternativas de resposta
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                    
                    // Lógica acerca das respostas
                    if(escolha == pergunta.alt_correta) {
                        
                        if(pergunta_count == 16) {
                            printf("\n\nParabens, voce foi o grande vencedor do show do milhao !!\n\n");
                            valor_acumulado += 400000;
                            printf("Valor acumulado : R$ %.2f\n\n", valor_acumulado);
                            continuar = 0;
                        }else {
                            printf("\nAlternativa Correta !!\n");
                            printf("Voce ganhou R$ %.2f\n", pow(10, 3 + bloco));
                            valor_acumulado += pow(10, 3 + bloco);
                        }

                    }else {
                        printf("\nAlternativa escolhida : %c\n", escolha);
                        printf("Alternativa Correta : %c\n", pergunta.alt_correta);
                        printf("Voce foi eliminado.\n");
                        printf("Valor acumulado perdido : R$ %.2f\n\n", valor_acumulado);
                        continuar = 0;
                    }

                    // Realiza mudança das dificuldades
                    if(pergunta_count % 5 == 0 && continuar) {
                        printf("%d\n", bloco);

                        bloco += 1;
                        resetar_vetor(perguntas_realizadas, 5);

                        if(bloco == 1) {
                            printf("Passou para o bloco de dificuldade 2 e ganhou R$ 5000\n");
                            valor_acumulado += 5000;

                        }else if(bloco == 2) {
                            printf("Passou para o bloco de dificuldade 3 e ganhou R$ 40000\n");
                            valor_acumulado += 40000;

                        }else if(bloco == 3) {
                            printf("Passou para a ultima pergunta !");
                        }

                    }

                    pergunta_count++; 

                    break;
                // Caso a resposta seja inválida
                default:
                    printf("Alternativa invalida...\n");
                    resposta_valida = 0;
                    break;
            }

        }while(!resposta_valida);
    }

    return 0;
}