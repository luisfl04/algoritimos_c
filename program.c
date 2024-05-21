// Bibliotecas nescessárias:
#include <stdio.h>
#include <stdlib.h>


// Criando estrutura que armazena os dados de 10 estudantes:
struct dados_dos_estudantes{
    // Criando membros:
    char nome[30];
    int numero_de_matricula;
    float media_final;
}Estudantes[10];

// Criando vetores dos aprovados e reprovados globalmente:
/*Explicação sobre estes vetores -> Estes vetores irão receber os índices do vetor de "Estudantes" respectivamente 
para cada caso. Ou seja, se por exemplo o valor de média final do índice 5 do vetor de Estudantes for maior que 5,
 o índice respectivo irá ser atribuido ao 'vetor_dos_aprovados'.
*/
int vetor_dos_aprovados[], vetor_dos_reprovados[];  

// Função que ler os dados dos 10 estudantes:
void ler_dados_dos_estudantes(){

    // Criando laço 'for' que irá iterar sobre os dados de cada estudante:
    for(int iteracao = 0; iteracao < 10; iteracao++){

        // Printando o número do estudante correspondente ao que se está obtendo os dados:
        printf("\n#Estudante %d", iteracao);

        // Pedindo dados:
        printf("\nInsira o nome:\nDigite aqui -> ");
        scanf("%s", &Estudantes[iteracao].nome);
        system("cls");

        printf("\nQual seu numero de matricula?\nDigite aqui -> ");
        scanf("%d", &Estudantes[iteracao].numero_de_matricula);
        system("cls");

        printf("\nCerto %s, nos informe a sua media final:\nDigite aqui -> ", Estudantes[iteracao].nome);
        scanf("%f", &Estudantes[iteracao].media_final);
        system("cls");
    }
}

// Função que verifica o valor da média final do estudante, e atribui ao vetor correspondente:
void verificar_media_final(){

    /* Criação de duas variáveis do tipo inteiro que irão ser usadas como 'indices' auxiliares no momento
    da atribuição de valores ao vetores de 'aprovados' e 'reprovados':
    */
   int indice_auxiliar_vetores_dos_aprovados = 0, indice_auxiliar_vetores_dos_reprovados = 0;

    // Laço 'for' nescessário para iteração:
    for(int iteracao = 0; iteracao < 10; iteracao++){

        // Fazendo verificação:
        if(Estudantes[iteracao].media_final >= 5.0){
            vetor_dos_aprovados[indice_auxiliar_vetores_dos_aprovados] = iteracao;
            indice_auxiliar_vetores_dos_aprovados++;
        }
        else{
            vetor_dos_reprovados[indice_auxiliar_vetores_dos_reprovados] = iteracao;
            indice_auxiliar_vetores_dos_reprovados++;
        }
    }

}

// Função que recebe um vetor e verifica qual é o tamanho dele:
int obter_tamanho_do_vetor(int vetor[]){

    // Criando váriável que irá obter o tamanho;
    int tamanho_do_vetor = 0;

    // Laço 'for' que irá obter o tamanho 
    for(int iteracao = 0; iteracao < vetor[iteracao]; iteracao++){
        tamanho_do_vetor++;
    }

    return tamanho_do_vetor;
}



// Função que imprime o vetor dos aprovados e reprovados:
void imprimir_resultado(){

    // Irá ser utilizado um laço for para cada vetor.
    
    // aprovados:
    /* Foi criado uma variável do tipo inteiro que irá servir como variável auxiliar, para que eu consiga
    iterar sobre todos os valores do vetor de aprovados.
    */
    // int indice_auxiliar_vetor_dos_aprovados = 0;
    // printf("\n-------------------------\nAlunos Aprovados\n-------------------------");
    // for(int iteracao = vetor_dos_aprovados[indice_auxiliar_vetor_dos_aprovados]; iteracao < ; iteracao++){
    //     printf("\nNome -> %s\nNumero de matricula -> %d\n\n", Estudantes[])
    // }

}


int main(){
    
    // Chamando função correspondente para ler os dados dos 10 estudantes:
    ler_dados_dos_estudantes();

    int vetor[] = {1,2,3};

    int resultado = obter_tamanho_do_vetor(vetor);


    printf("%d", resultado);



    return 0;
}
