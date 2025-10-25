#include <stdio.h>
#include <stdlib.h>

bool inteiro_em_vetor(int valor, int* vetor);
void resetar_vetor(int* vetor, size_t tam);
int* criar_array_probabilidades(char alt_correta);

bool inteiro_em_vetor(int valor, int* vetor, size_t tam) {
    
    for(int i = 0; i < tam; i++) {
        if(vetor[i] == valor) {
            return true;
        }
    }

    return false;
}

void resetar_vetor(int* vetor, size_t tam) {
    for(int i = 0; i < tam; i++) {
        vetor[i] = 0;
    }
}

int* criar_array_plateia(char alt_correta) {
    const char alternativas[] = {'a', 'b', 'c', 'd'};
    int count = 3;
    int *probabilidades = (int *) malloc(sizeof(int) * 10);

    // 4/10 alternativas certas
    for(int i = 0; i < 4; i++) {
        probabilidades[i] = alt_correta % 97;
    }

    // 2/10 cada alternativa errada
    for(int i = 0; i < 4; i++) {
        if(alternativas[i] != alt_correta) {
            probabilidades[count+1] = alternativas[i] % 97;
            probabilidades[count+2] = alternativas[i] % 97;
            count += 2;
        }
        
    }

    // Array com 4/10 certo e 6/10 errado.
    return probabilidades;
}

int* criar_array_universitarios(char alt_correta) {
    const char alternativas[] = {'a', 'b', 'c', 'd'};
    int count = 6;
    int *probabilidades = (int *) malloc(sizeof(int) * 10);

    // 7/10 alternativas certas
    for(int i = 0; i < 7; i++) {
        probabilidades[i] = alt_correta % 97;
    }

    // 1/10 cada alternativa errada
    for(int i = 0; i < 4; i++) {
        if(alternativas[i] != alt_correta) {
            probabilidades[count+1] = alternativas[i] % 97;
            count++;
        }
        
    }

    // Array com 4/10 certo e 6/10 errado.
    return probabilidades;

}