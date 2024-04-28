#include <stdio.h>

//Declarando a matriz que armazena os valores globalmente. Para que eu consiga acessar os seus valores em qualquer local do arquivo:
float medida_dos_lados[5][3];
int tipo_de_triangulo[5]; // Criei este vetor que armazena os cinco valores de tipos de triângulos obtidos.


// Função que ler a medida dos lados:
void LePositivo(){

    // obtendo os valores dos lados:
    for(int linha = 0; linha < 5; linha++){

        printf("\nTriangulo -> %d", linha + 1);

        for(int coluna = 0; coluna < 3; coluna++){
            printf("\nDigite o valor do lado %d\ndigite aqui -> ", coluna + 1);
            scanf("%f", &medida_dos_lados[linha][coluna]);

            // fazendo tratamento de erro caso o usuário digite um valor negativo para o lado do triângulo:
            while(medida_dos_lados[linha][coluna] < 0){
                printf("\nVoce digitou um valor negativo!\ndigite novamente -> ");
                scanf("%f", &medida_dos_lados[linha][coluna]);
            }
        
        }
    
    }

}

// Implementando a função que verifica o tipo do triângulo:
void TipoTriangulo(){

    // Iterando sobre os valores de cada triângulo para verificar o tipo dele:
    for(int triangulo = 0; triangulo < 5; triangulo++){
        
        // Se todos os lados são iguais, ele é equilátero.
        if( (medida_dos_lados[triangulo][0] == medida_dos_lados[triangulo][1]) && 
        (medida_dos_lados[triangulo][0] == medida_dos_lados[triangulo][2]) 
        ){
            tipo_de_triangulo[triangulo] = 1; 
        }  
        // verificando se pelo menos dois dos lados são iguais:
        else if((medida_dos_lados[triangulo][0] == medida_dos_lados[triangulo][1]) || 
        (medida_dos_lados[triangulo][0] == medida_dos_lados[triangulo][2]) ||
        (medida_dos_lados[triangulo][1] == medida_dos_lados[triangulo][2])
        ){
            tipo_de_triangulo[triangulo] = 2;
        }
        // se nenhum dos lados são iguais, ele é escaleno.
        else{
            tipo_de_triangulo[triangulo] = 3;
        }

    }

}

void verificar_tipo(){
    
    for(int i = 0; i < 5; i++){
        printf("%d\t", tipo_de_triangulo[i]);
    }

}


// função que verifica se é um triângulo válido
int EhTriangulo(){

    // Basicamente vou iterar sobre os valores dos lados de cada triângulo informado, e se esses valores forem positivos, ele é um trinângulo válido:
    for(int linha = 0; linha < 5; linha++){

        for(int coluna = 0; coluna < 3; coluna++){
            // Fazendo verificação:
            if(medida_dos_lados[linha][coluna] > 0){
                return 1;
            }
            else{
                return 0;
            }
       
       }
    
    }

}

void main(){    

    // Obtendo os valores dos Triangulos:
    LePositivo();

    TipoTriangulo();

    verificar_tipo();


    // // verificando se os triângulos informados são válidos:
    // if(EhTriangulo() == 1){
    //     printf("\nApos a verificacao, os valores dos lados dos triangulos foram validados!\n");
    // }
    // else{
    //     printf("\nErro, A valores inválidos relacionados aos triangulos informados!\n");
    // }
    
    // // Iterando sobre o vetor com os tipos de triângulos para verificar e printar o tipo de cada triângulo informado:
    // for(int triangulo = 0; triangulo < 5; triangulo++){
    //     // verificando tipo:
    //     if(tipo_de_triangulo[triangulo] == 1){
    //         printf("\nO triangulo %d eh do tipo Equilatero.", triangulo + 1);
    //     }
    //     else if(tipo_de_triangulo[triangulo] == 2){
    //         printf("\nO triangulo %d eh do tipo Isosceles.", triangulo + 1);
    //     }
    //     else{
    //         printf("\nO triangulo %d eh do tipo Escaleno.", triangulo + 1);
    //     }
    
    // }



}
