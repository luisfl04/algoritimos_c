/* ESCOPOS DOS METODOS(Este arquivo é organizado com base nestes escopos):
MÉTODOS DE EXECUÇÃO -> São os método que serão explicitamente chamados, ou seja, o método 'main' fará a chamada deles;
MÉTODOS DE VERIFICAÇÃO -> Métodos relacionados a verificação de dados que o usuário insere ou oriúndos de outros locais.
MÉTODOS GERAIS -> Implementações gerais que auxiliam na execução do arquivo.
*/

// * BIBLIOTECAS NESCESSÁRIAS * :
    #include <stdio.h>
    #include <stdlib.h>

// * CABEÇALHOS DE FUNÇÕES IMPLEMENTADOS * :

// * ATRIBUTOS GLOBAIS *:

    // Vetor que armazena os valores das 10 matriculas:
    int matriculas_dos_alunos[10];

// * MÉTODOS DE VERIFICAÇÃO * :

    int *verificar_quantidade_de_digitos(int *valor_de_matricula_inserido){

        /* Explicação do método -> Basicamente, ele recebe o valor que o usuário passou de matricula e verifica se este valor tem quatro dígitos, pois somente valores com
        quatro dígitos são aceitos. Um novo valor é pedido até que o usuário digite um valor válido. */
        
        // verificando:
        while( *valor_de_matricula_inserido < 1000 || *valor_de_matricula_inserido > 9999){

            // Limpando teerminal a cada valor inválido:
            system("cls");

            // pedindo novo valor:
            printf("ERRO -> O valor que voce inseriu eh invalido\nSomente valores de matricula com quatro digitos sao aceitos\nDigite um valor valido aqui -> ");
            scanf("%d", &*valor_de_matricula_inserido);
        } 

    }

    int *verificar_valores_iguais(int *valor_de_matricula_inserido, int indice_do_valor_inserido){

        /* Explicação do método -> É feita a verificação de se o valor que foi inserido já foi inserido anteriormente. É feita a obtenção de um novo valor enquanto estes valores
        forem iguais. */

        // Implementação da verificação:

            // Variável que irá determinar se foi encontrado um valor igual:
            int achei_valores_iguais = 0;
            int indice_em_que_o_valor_eh_igual; /* -> Se for encontrado um valor igual a um que já foi inserido, o valor do indice em que foi
            encontrado um valor igual é armazenado, para fins de comparação posteriormente. */

            // loop que verifica:
            for(int valor_de_comparacao = indice_do_valor_inserido; valor_de_comparacao >= 0; valor_de_comparacao--){
                
                // Verifico se o valor que foi passado é igual ao valor do índice anterior do ponteiro:
                if(matriculas_dos_alunos[indice_do_valor_inserido] == matriculas_dos_alunos[valor_de_comparacao - 1]){
                    achei_valores_iguais = 1;
                    indice_em_que_o_valor_eh_igual = valor_de_comparacao;
                    break;
                }
            }

        // Se foi encontrado um valor igual, peço um novo valor enquanto eles forem iguais:
        if(achei_valores_iguais == 1){

            // Pedindo valor: 
            while(*valor_de_matricula_inserido == matriculas_dos_alunos[indice_em_que_o_valor_eh_igual]){
                // Implementar obtenção de um novo valor...
            }
        
        }
    
    }



// * MÉTODOS GERAIS * :

// * MÉTODOS DE EXECUÇÃO * :

    void obter_matriculas(){
        
        /* Explicação do método -> Esté método faz a obtenção dos valores das 10 matriculas relacionadas aos 'alunos'. Os valores também são verificados por um submétodo 
        correspondente. Somente valores de até 4 dígitos são aceitos. */

        // Obtendo valores:
        for(int matricula_atual = 0; matricula_atual < 10; matricula_atual++){
            
            // Para cada matricula, o terminal é limpado:
            system("cls");

            // Titulo de descrição:
            printf("\tCADASTRO DE MATRCULAS\n\nNumero do processo -> %d\n\n", matricula_atual + 1);

            // Obtendo apartir do teclado:
            printf("\nInsira o numero da matricula(Somente valores de 4 digitos):\nDigite o valor aqui -> ");
            scanf("%d", &matriculas_dos_alunos[matricula_atual]);

            // Verificando se o valor que o usuário inseriu tem 4 digitos:
            verificar_quantidade_de_digitos(&matriculas_dos_alunos[matricula_atual]);
        
            // Verificando se o valor inserido ja foi inserido anteriormente:
            verificar_valores_iguais(&matriculas_dos_alunos[matricula_atual], matricula_atual);

        }

    }

    int main(){
        
        // Chamando método que obtém as matriculas dos alunos:
        obter_matriculas();

        return 0;
    }

    
