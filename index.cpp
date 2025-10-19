#include <stdio.h>
#include <time.h>
#include <math.h>
#include <random>
#include "perguntas.cpp"
#include "utilidades.cpp"

int main() {

    float valor_acumulado = 0;
    int sorteio_pergunta = 0;
    // 1 a 16
    int pergunta_count = 1; 
    // 0,1,2,3 (Define as dificuldades) 
    int bloco = 0;  
    // Pular, Pedir Ajuda da Platéia, Pedir Ajuda dos Universitários, Pedir Ajuda Cartas;
    int recursos[] = {3, 3, 3, 3};  
    int perguntas_realizadas[5] = {0, 0, 0, 0, 0};
    char escolha = 0;
    int continuar = 1;

    srand(time(NULL));

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

        mostrar_pergunta(pergunta, pergunta_count, valor_acumulado, recursos);

        printf("Resposta : \n");
        scanf("%c%*c", &escolha);

        switch(escolha) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                printf("\nVoce saiu com R$ %.2f\n\n", valor_acumulado);
                continuar = 0;
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
                
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
                    printf("Voce foi eliminado\n");
                    printf("Valor acumulado perdido : R$ %.2f\n\n", valor_acumulado);
                    continuar = 0;
                }

                break;
            default:
                printf("Alternativa invalida...");
                break;
        }

        // Realiza mudança das dificuldades
        if(pergunta_count % 5 == 0 && continuar) {
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
    }

    return 0;
}