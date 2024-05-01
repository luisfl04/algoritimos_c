#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função correspondente:
void verificarNome(char nome_inserido[], char vogais_e_consoantes[2][100]){

    // criando indices auxilares para ajudar na iterção das colunas da matriz. Onde se a condição for verdadeira, é incrementado um valor de um para ele.
    int indice_auxiliar_vogal = 0, indice_auxliar_consoante = 0;

    // Iterando sobre o nome inserido:
    for(int iteracao = 0; iteracao < strlen(nome_inserido); iteracao++){
        //Fazendo verificação, se é vogal ou consoante, e atribuindo os valores a matriz:
        if( (nome_inserido[iteracao] == 'A') ||
            (nome_inserido[iteracao] == 'E') ||
            (nome_inserido[iteracao] == 'I') ||
            (nome_inserido[iteracao] == 'O') ||
            (nome_inserido[iteracao] == 'U')
        ){
            vogais_e_consoantes[0][indice_auxiliar_vogal] = nome_inserido[iteracao];
            indice_auxiliar_vogal++;
        }
        else{
            vogais_e_consoantes[1][indice_auxliar_consoante] = nome_inserido[iteracao];
            indice_auxliar_consoante++;
        }
    }
}

int main(){
    // Criando vetor que armazenará o nome que o usuário digitar:
    char nome_inserido_pelo_usuario[20];

    // Criando matriz que armazena os valores adas vogais e consoantes vazia. Os valores serão passados para ela por meio de parâmetros, sem precisar usar o 'retun'.
    char vogais_e_consoantes[2][100];

    // Pedindo o nome ao usuário:
    printf("Ola, insira um nome qualquer, e verificaremos quais letras sao vogais e quais sao consoantes\nDigite o nome aqui -> ");
    scanf("%s", &nome_inserido_pelo_usuario);

    // Transformando letra a letra do nome inserido pelo usuário em maiúsculas, para facilitar a comparação na função.
    for(int iteracao = 0; iteracao < strlen(nome_inserido_pelo_usuario); iteracao++){
        nome_inserido_pelo_usuario[iteracao] = toupper(nome_inserido_pelo_usuario[iteracao]);
    }

    // Chamando função e passando os parâmetros nescessários:
    verificarNome(nome_inserido_pelo_usuario, vogais_e_consoantes);

    // Printando infos:
    // Palavra:
    printf("\nPalavra inserida -> %s", nome_inserido_pelo_usuario);

    // vogais:
    printf("\nVogais da palavra -> ");
    for(int iteracao = 0; iteracao < strlen(vogais_e_consoantes[0]); iteracao++){
        printf("%c", vogais_e_consoantes[0][iteracao]);
    }

    // Consoantes:
    printf("\nConsoantes da palara -> ");
    for(int iteracao = 0; iteracao < strlen(vogais_e_consoantes[1]); iteracao++){
        printf("%c", vogais_e_consoantes[1][iteracao]);
    }

    return 0;
}

// Implementações a fazer:
// 1 - Tratamento de erro caso as letras se repetem
// 2 - Verificar o por que de aparecerem letras aleatórias na impressão das vogais e consoantes.

