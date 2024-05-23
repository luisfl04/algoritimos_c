// Bibliotecas nescessárias:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


// cabeçalhos de função nescessários para execução:
void obter_escolha_do_usuario();

// Criando estrutura para cadastro de produtos(Será permitido cadastrar 5 produtos):
struct cadastro_de_produtos{
    char nome_do_produto[30];
    int codigo_do_produto;
    float preco_do_produto;
}Produtos[5];

// Função que verifica se o valor dado para o código é negativo ou nulo:
int *verificar_codigo_inserido(int *codigo_inserido){
    // A função retorna um ponteiro, pois o valor do código inserido precisa ser atualizado.

    while(*codigo_inserido <= 0){
        printf("\nERRO -> Voce digitou um valor de codigo invalido\nDigite um novo valor aqui -> ");
        scanf("%d", &*codigo_inserido);
    }

    // Retornando código válido:
    return codigo_inserido;
}

// Função que dar um valor aleatório a cada preço de produto(O parâmetro passado é um ponteiro, para que seja possível atualizar o valor na memória):
float *adicionar_preco_aleatorio(float *preco_do_produto){

    // Criando variáveis que definem o valor mínimo e máximo do valor aleatório:
    int preco_minimo = 10, preco_maximo = 100; 

    // Inicializando a semente geradora de números:
    srand(time(NULL)); // -> Foi garantido que a geração de números varíe, ou seja, a cada execução, os números gerados são diferentes.

    // Gerando número:
    *preco_do_produto = rand() % (preco_maximo - preco_minimo + 1) + preco_minimo;  

    // Retornando valor:
    return preco_do_produto;
}

// Função que cadastra os produtos:
void cadastrar_produtos(){

    // Cadastrando:
    for(int iteracao = 0; iteracao < 5; iteracao++){
        printf("\n\n*** CADASTRO DE PRODUTOS ***\n\nPRODUTO -> %d\n\n", iteracao + 1);

        // Nome:
        printf("\nInsira o nome do produto -> ");
        scanf("%s", &Produtos[iteracao].nome_do_produto);

        // Código:
        printf("\nInsira o codigo correspondente ao produto -> ");
        scanf("%d", &Produtos[iteracao].codigo_do_produto);
        // Verificando valor:
        verificar_codigo_inserido(&Produtos[iteracao].codigo_do_produto);

        // Preço:
        // -> O valores relacionados aos preços são adicionados aleatoriamente, usando a função 'adicionar_preco_aleatorio()'.
        adicionar_preco_aleatorio(&Produtos[iteracao].preco_do_produto);
        
        // A cada produto casdastrado, o terminal é limpado:
        system("cls"); 
    }
}

// Função que imprime uma mensagem pedindo para o usuário aguardar pro alguns segundos:
void pausar_execucao(int valor_em_milissegundos){
    // Limpando terminal:
    system("cls"); 

    // Imprimindo mensagem:
    printf("\nAguarde um momento...");

    // Pausando execução:
    Sleep(valor_em_milissegundos);

    // Terminando pausa e limpando terminal novamente:
    system("cls");
}

// Função que printa todos os produtos disponíveis e seus respectivos códigos. Para ser usada em múltiplos locais do arquivo:
void imprimir_produtos_disponiveis(){
    // Limpando terminal:
    system("cls");

    // Imprimindo produtos:
    printf("\n*** PRODUTOS DISPONIVEIS ***\n\n");
    for(int iteracao =  0; iteracao < 5; iteracao++){
        printf("\n--------------------\nNome -> %s\nCodigo -> %d\n--------------------", Produtos[iteracao].nome_do_produto, Produtos[iteracao].codigo_do_produto);
    }
}

// Função que verifica se o valor inserido pelo usuário é negativo, ou diferente de 1 ou 0, e faz o tratamento deste caso:
int *verificar_valor_de_escolha_do_usuario(int *numero_inteiro_inserido){
    /* Explicação do método -> Ao usuário digitar um valor inválido de escolha, ou seja, um valor diferente de 1, 0, ou 
    um valor negativo, é pedido um novo valor até que um valor válido seja inserido. As opções do usuário são printadas 
    a cada valor inválido inserido. */

    while(*numero_inteiro_inserido < 0 || (*numero_inteiro_inserido != 1 && *numero_inteiro_inserido != 0) ){
        // A cada iteração, o terminal é limpado:
        system("cls");

        // Pedindo novo valor:
        printf("\nERRO -> Voce digitou um valor invalido!\nValores correspondentes:\n(1) - Para consultar preco\n(0) - Para encerrar o sistema\n\nDigite um novo valor -> ");
        scanf("%d", &*numero_inteiro_inserido);
    }

    // Verificando se o usuário quer consultar um preço, e printando os produtos disponíveis caso ele queira:
    if(*numero_inteiro_inserido == 1){
       imprimir_produtos_disponiveis();
    }

    // Retornando escolha:
    return numero_inteiro_inserido;
}

// Método que imprime uma mensagem de informando o fim da execução do sistema:
void informar_fim_de_execucao(){
    // Limpo o terminal, informo a mensagem, e pauso a execução.
    system("cls");
    printf("\nSistema encerrado...");
    Sleep(2000);
}

// Função que faz a consulta do preco do produto de acordo com o valor de código de produto que o usuário insere insere:
void consultar_preco(){

    // Criando variavel que ira ser comparada com o código do produto:
    int codigo_de_consulta;

    // Pedindo o valor do código do produto:
    printf("\n---------------------------\n\nInsira o valor do codigo do produto:\nDigite aqui -> ");
    scanf("%d", &codigo_de_consulta);
    // Verificando valor inserido:
    verificar_codigo_inserido(&codigo_de_consulta);

    // Se o valor é valido, faço a comparação para verificar se ele corresponde a algum produto cadastrado:
    int achei_o_codigo_do_produto = 0; // -> Variável que irá controlar se o código do produto foi achado ou não.
    int indice_em_que_o_produto_foi_achado; /* -> Esta variável irá armazenar o indice do vetor de produtos em que o codigo de busca é igual ao
    código do produto, ou seja, o índice em que ele foi encontrado. */
    // Loop 'for' que irá verificar se o código corresponde a algum produto:
    for(int iteracao = 0; iteracao < 5; iteracao++){
        // Comparando:
        if(codigo_de_consulta == Produtos[iteracao].codigo_do_produto){
            achei_o_codigo_do_produto = 1;
            indice_em_que_o_produto_foi_achado = iteracao;
        }
    }

    // Imprimindo mensagem conforme ter achado o produto ou não:
    if(achei_o_codigo_do_produto == 1){
        // Limpando terminal:
        system("cls");

        // Imprimindo informações do produto buscado:
        printf("\nProduto encontrado!\nNome do produto -> %s\nPreco -> R$%.1f\nCodigo correspondente -> %d", Produtos[indice_em_que_o_produto_foi_achado].nome_do_produto, Produtos[indice_em_que_o_produto_foi_achado].preco_do_produto, Produtos[indice_em_que_o_produto_foi_achado].codigo_do_produto);
    }
    else{
        // Limpando terminal:
        system("cls");

        // Imprimindo que o código inserido não corresponde a nenhum produto:
        printf("\nProduto nao encontrado!\nO codigo que voce inseriu nao corresponde a nenhum produto cadastrado em nossa base de dados.");
    }

    // Perguntando ao usuário se ele deseja realizar uma nova consulta:
    // Criando variável que irá armazenar a escolha do usuário:
    int escolha_do_usuario;
    printf("\n\nDeseja realizar uma nova consulta?\n(1) - Para consultar novamente\n(0) - Para encerrar o sistema\nDigite aqui -> ");
    scanf("%d", &escolha_do_usuario);
    // Verificando valo digitado:
    verificar_valor_de_escolha_do_usuario(&escolha_do_usuario);

    // Redirecionando usuário conforme a sua escolha:
    if(escolha_do_usuario == 1){
        obter_escolha_do_usuario();
    }
    else{
        informar_fim_de_execucao();
    }

}

// Função que imprime os produtos disponíveis e pergunta ao usuário se ele deseja realizar uma consulta:
void obter_escolha_do_usuario(){

    // Chamando função que pausa a execução do sistema em alguns segundos:
    pausar_execucao(3000);

    // Listando os produtos para o usuário:
    imprimir_produtos_disponiveis();

   
    int escolha_do_usuario; // -> Está variável irá armazenar o valor que irá determinar o fluxo do sistema, ou seja, fazer uma consulta ou encerrar o sistema.

    // pedindo escolha para o usuário:
    printf("\nOpcoes disponiveis:\n(1) - Para consultar preco de um produto\n(0) - Para encerrar o sistema\n");
    scanf("%d", &escolha_do_usuario);
    // Fazendo verificação do valor inserido por meio da função 'verificar_valor_de_escolha_do_usuario()':
    verificar_valor_de_escolha_do_usuario(&escolha_do_usuario);

    // Se o usuário deseja realizar uma consulta de preco, a função 'consultar_produto()' é chamada:
    if(escolha_do_usuario == 1){
        consultar_preco();
    }
    else{
        // Imprimindo mensagem de fim de execução do sistema:
        informar_fim_de_execucao();
    }
    
}

int main(){

    // Primeiramente, chamando função que realiza o cadastro dos produtos:
    cadastrar_produtos();

    // Função que faz a consulta do preço do produto por meio do seu código:
    obter_escolha_do_usuario();

    return 0;
}


