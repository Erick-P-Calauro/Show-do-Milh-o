#include <stdio.h>

bool inteiro_em_vetor(int valor, int* vetor);
void resetar_vetor(int* vetor, size_t tam);

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