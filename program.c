#include <stdio.h>

// Função que retorna o tipo de figura escolhida:
int verificaFigura(){

    // pedindo a figura escolhida a partir de um número.
    // este numero será retornado
    int escolha_do_usuario;
    printf("\nEscolha uma das figuras para calcular a area\n'1' -> Para quadrado\n'2' -> Para triangulo\n'3' -> Para retangulo\nDigite o valor aqui -> ");
    scanf("%d", &escolha_do_usuario);

    // Fazendo tratamento de erro caso ele digite um número inválido:
    while(escolha_do_usuario < 1 || escolha_do_usuario > 3){
        printf("\nERRO -> Voce digitou um valor invalido\nDigite novamente aqui -> ");
        scanf("%d", &escolha_do_usuario);
    }

    return escolha_do_usuario;
}

// Função de calculo do quadrado:
void calculaQuadrado(){

    // Criando uma variável que armazena o valor de um lado do quadrado.Como os lados de um quadrado tem o mesmo comprimento, eu só nescessito saber de um valor:
    float lado_quadrado;

    // Obtendo valores dos lados:
    printf("\nCerto, voce escolheu o quadrado!\nDigite o valor correspondente do lado do quadrado -> ");
    scanf("%f", &lado_quadrado);
    
    // fazendo tratamento de erro caso o usuário digite um valor negativo:
    while(lado_quadrado < 0){
        printf("\nERRO -> Voce digitou um valor negativo!\nDigite novamente o valor -> ");
        scanf("%f", &lado_quadrado);
    }

    // Calculando a área:
    float area_do_quadrado = lado_quadrado * lado_quadrado;

    // printando as informações:
    printf("\nFigura escolhida -> Quadrado\nValor do lado -> %.2f\nArea correspondente -> %.2f",lado_quadrado, area_do_quadrado);

} 

// Função de calculo do triangulo:
void calculaTriangulo(){

    // criando variáveis nescessárias para fazer o calculo:
    float base_do_triangulo, altura_do_triangulo, area_do_triangulo;
    
    
    // Pedindo a base e a altura correspondente para o usuário, para que seja possível fazer o calculo da aréa:
    printf("\nCerto, voce escolheu o triangulo!\nPrimeiramente, digite o valor da base(valor de um dos lados):\nDigite aqui -> ");
    scanf("%f", &base_do_triangulo);

    // fazendo tratamento de erros de digitação:
    while(base_do_triangulo < 0){
        printf("\nERRO -> Voce digitou um valor negativo!\nDigite novamente o valor -> ");
        scanf("%f", &base_do_triangulo);
    }

    // pedindo a altura:
    printf("\nAgora, digite a altura correspondente\nDigite aqui -> ");
    scanf("%f", &altura_do_triangulo);

    // Fazendo tratamento de erros:
    while(altura_do_triangulo < 0){
        printf("\nERRO -> Voce digitou um valor negativo!\nDigite novamente o valor -> ");
        scanf("%f", &altura_do_triangulo);
    }

    // calculando área:
    area_do_triangulo = (base_do_triangulo * altura_do_triangulo) / 2;

    // printando as informações:
    printf("\nFigura escolhida -> Triangulo\nBase informada -> %.2f\nAltura informada -> %.2f\nArea correspondente -> %.2f", base_do_triangulo, altura_do_triangulo, area_do_triangulo);

}

// Função que calcula a area do retângulo:
void calculaRetangulo(){

    // criando as variáveis nescessárias:
    float altura_retangulo, base_retangulo, area_do_retangulo;
    
    //pedindo a altura:
    printf("\nCerto, voce escolheu o retangulo!\nPrimeiramente, digite o valor da altura(comprimento)\ndigite aqui -> ");
    scanf("%f", &altura_retangulo);

    // tratamento de erros:
    while(altura_retangulo < 0){
        printf("\nERRO -> Voce digitou um valor negativo!\nDigite novamente o valor -> ");
        scanf("%f", &altura_retangulo);
    }

    // Pedindo a base:
    printf("\nAgora, digite o valor da base(largura)\ndigite aqui -> ");
    scanf("%f", &base_retangulo);

    // tratamento de erros:
    while(base_retangulo < 0){
        printf("\nERRO -> Voce digitou um valor negativo!\nDigite novamente o valor -> ");
        scanf("%f", &base_retangulo);
    }

    // calculando a área:
    area_do_retangulo = altura_retangulo * base_retangulo;

    // Printando as informações:
    printf("\nFigura escolhida -> Retangulo\nAltura informada -> %.2f\nBase informada -> %.2f\nArea correspondente -> %.2f", altura_retangulo, base_retangulo, area_do_retangulo);

}

void main(){

    // Chamando a função que pede a figura e armazenando o valor de retorno na variável:
    int escolha_do_usuario = verificaFigura();

    // Verificando qual foi a escolha do usuário e chamando a função correspondente:  
    if(escolha_do_usuario == 1){
        calculaQuadrado();
    }
    else if(escolha_do_usuario == 2){
        calculaTriangulo();
    }
    else{
        calculaRetangulo();
    }
  
}
