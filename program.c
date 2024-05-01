#include <stdio.h>

int somarElementos(int vetor_de_inteiros[], int tamanho_do_vetor_de_inteiros){

    // criando variável que irá armazenar a soma dos inteiros presentes no vetor:
    int soma_dos_inteiros = 0;

    // Iterando sobre o vetor e fazendo a soma:
    for(int iteracao = 0; iteracao < tamanho_do_vetor_de_inteiros; iteracao++){
        soma_dos_inteiros = soma_dos_inteiros + vetor_de_inteiros[iteracao];
    }

    // retornado o valor:
    return soma_dos_inteiros;
}



int main(){
    // Criando variável e vetor nescessários:
    int tamanho_do_vetor, vetor_de_numeros_inteiros[10];

    // Criei esta variável para obter o tamanho do vetor:
    int iteracao;

    // pedindo os valores dos elementos do vetor:
    printf("# Vetor de 10 elementos");
    for(iteracao = 0; iteracao < 10; iteracao++){
        printf("\nDigite um valor para a posicao %d do vetor:\ndigite aqui -> ", iteracao);
        scanf("%d", &vetor_de_numeros_inteiros[iteracao]);
    }

    // Obtendo tamanho do vetor:
    tamanho_do_vetor = iteracao + 1; // adicionei 1 ao valor pois iterações começam a ser contadas em 0, e por isso o tamanho seria definido como 9, o que não é o caso.

    // Criando instância, chamando a função e passando os parâmetros:
    int soma_dos_elementos = somarElementos(vetor_de_numeros_inteiros, tamanho_do_vetor);

    // Printando resultado:
    printf("\nO resultado da soma dos vetores foi -> %d", soma_dos_elementos);

    return 0;
}
