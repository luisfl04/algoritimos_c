#include <stdio.h>


int obter_tamanho_do_vetor(int vetor[]){

    // Criando váriável que irá obter o tamanho;
    int tamanho_do_vetor = 0;

    // Laço 'for' que irá obter o tamanho 
    for(int iteracao = 0; iteracao < vetor[]; iteracao++){
        tamanho_do_vetor++;
    }

    return tamanho_do_vetor;
}

int main(){

    int vetor_de_exemplo[] = {1,2,3};

    int resultado = obter_tamanho_do_vetor(vetor_de_exemplo);

    printf("%d", resultado); 
}