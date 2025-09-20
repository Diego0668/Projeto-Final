#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 

void limpartela(){
    sleep(5);
    getchar();
	system("cls");

}

void mostrarDados(char nome[20], char endereco[40], char senha_digitada[20], char email[20]){
    printf("\n---------- Meus Dados ----------\n");
    printf("Nome: %s\n", nome);
    printf("Email: %s\n", email);
    printf("Senha: %s \n", senha_digitada);
    printf("Endereco: %s \n", endereco);
    printf("------------------------------\n");
}

void mostrarProdLoja(char lista_prod[10][10], float preco_prod[10]){
    printf("====================================\n");
    printf("Produtos da Loja:\n");
    for (int i = 0; i < 10; i++) { 
        if(strlen(lista_prod[i]) > 0) {
            printf("[%d] %-10s - R$ %.2f\n", i, lista_prod[i], preco_prod[i]);
        }
    }
    printf("====================================\n");
}

void pesquisar(char lista_prod[10][10], int tamanhoDoVetor) {
    char produtoParaBuscar[20]; 
    int valorEncontrado = 0;
    int c;
    
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome do produto que deseja procurar: \n");
    fgets(produtoParaBuscar, sizeof(produtoParaBuscar), stdin);
    produtoParaBuscar[strcspn(produtoParaBuscar, "\n")] = '\0';

    for (int i = 0; i < tamanhoDoVetor; i++) {
        if (strcmp(lista_prod[i], produtoParaBuscar) == 0) {
            valorEncontrado = 1; 
            break; 
        }
    }

    if (valorEncontrado) {
        printf("O produto '%s' foi encontrado na lista de produtos.\n", produtoParaBuscar);
    } else {
        printf("O produto '%s' nao foi encontrado na lista de produtos.\n", produtoParaBuscar);
    }
}

void mostrarCarrinho(char carrinho_prod[10][10], float carrinho_preco[10], int carrinho_quant[10], int tamanho_carrinho) {
    printf("\n===CARRINHO===\n");
    if (tamanho_carrinho == 0) {
        printf("Seu carrinho esta vazio.\n");
    } else {
        for (int i = 0; i < tamanho_carrinho; i++) {
            float subtotal = carrinho_preco[i] * carrinho_quant[i];
            printf("[%d] %-10s | %d un. | R$ %.2f\n", i, carrinho_prod[i], carrinho_quant[i], subtotal);
        }
    }
    printf("==============================\n");
}

int adicionarAoCarrinho(int indice, int quant, char lista_prod[10][10], float preco_prod[10], 
                         char carrinho_prod[10][10], float carrinho_preco[10], int carrinho_quant[10], int tamanho_carrinho) {
    
    strcpy(carrinho_prod[tamanho_carrinho], lista_prod[indice]);
    carrinho_preco[tamanho_carrinho] = preco_prod[indice];
    carrinho_quant[tamanho_carrinho] = quant;

    printf("Produto '%s' adicionado ao carrinho!\n", lista_prod[indice]);
    
    return tamanho_carrinho + 1;
}

int removerDoCarrinho(int indice, char carrinho_prod[10][10], float carrinho_preco[10], int carrinho_quant[10], int tamanho_carrinho) {
    if (indice < 0 || indice >= tamanho_carrinho) {
        printf("Indice invalido!\n");
        return tamanho_carrinho; 
    }

    printf("Removendo '%s' do carrinho...\n", carrinho_prod[indice]);

    for (int i = indice; i < tamanho_carrinho - 1; i++) {
        strcpy(carrinho_prod[i], carrinho_prod[i + 1]);
        carrinho_preco[i] = carrinho_preco[i + 1];
        carrinho_quant[i] = carrinho_quant[i + 1];
    }
    
    return tamanho_carrinho - 1; 
}

int gerenciarCarrinho(char lista_prod[10][10], char endereco[40], float preco_prod[10],
                       char carrinho_prod[10][10], float carrinho_preco[10], int carrinho_quant[10], int tamanho_carrinho) {
    
    int opcao = -1;
    float total_compra = 0;

    while(opcao != 0) {
        mostrarProdLoja(lista_prod, preco_prod);
        mostrarCarrinho(carrinho_prod, carrinho_preco, carrinho_quant, tamanho_carrinho);
        
        total_compra = 0;
        for (int i = 0; i < tamanho_carrinho; i++) {
            total_compra += carrinho_preco[i] * carrinho_quant[i];
        }
        if (tamanho_carrinho > 0) {
            printf("TOTAL DO CARRINHO: R$ %.2f\n", total_compra);
            printf("=============================\n");
        }


        printf("Digite o NUMERO do produto para ADICIONAR.\n");
        printf("Digite [10] para REMOVER um item do carrinho.\n");
        printf("Digite [11] para FINALIZAR A COMPRA.\n");
        printf("Digite [0] para VOLTAR AO MENU PRINCIPAL.\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 0 && opcao < 10) { 
            if (tamanho_carrinho < 10) {
                int quant;
                printf("Digite a quantidade desejada de '%s': ", lista_prod[opcao]);
                scanf("%d", &quant);
                if (quant > 0) {
                    tamanho_carrinho = adicionarAoCarrinho(opcao, quant, lista_prod, preco_prod, carrinho_prod, carrinho_preco, carrinho_quant, tamanho_carrinho);
                } else {
                    printf("Quantidade invalida.\n");
                }
            } else {
                printf("Seu carrinho esta cheio!\n");
            }
        } else if (opcao == 10) { 
            if (tamanho_carrinho > 0) {
                int indice_remover;
                printf("Digite o NUMERO do item para remover do seu carrinho: ");
                scanf("%d", &indice_remover);
                tamanho_carrinho = removerDoCarrinho(indice_remover, carrinho_prod, carrinho_preco, carrinho_quant, tamanho_carrinho);
            } else {
                printf("Carrinho vazio. Nao ha itens para remover.\n");
            }
        } else if (opcao == 11) { 
            if (tamanho_carrinho > 0) {
                char forma_pag[20];
                int c;

                printf("Selecione a forma de pagamento (Cartao ou Pix): ");
                while ((c = getchar()) != '\n' && c != EOF); 
                fgets(forma_pag, sizeof(forma_pag), stdin);
                forma_pag[strcspn(forma_pag, "\n")] = '\0';
                
                printf("\n====================================\n");
                printf("Sua compra foi confirmada!\n");
                printf("====================================\n");
                mostrarCarrinho(carrinho_prod, carrinho_preco, carrinho_quant , tamanho_carrinho);
                printf("TOTAL DA COMPRA: R$ %.2f\n", total_compra);
                printf("Endereco de entrega: %s\n", endereco);
                printf("Forma de pagamento: %s\n", forma_pag);
                
                tamanho_carrinho = 0; 
                opcao = 0; 
            } else {
                 printf("Carrinho vazio. Adicione itens para finalizar a compra.\n");
            }
        } else if (opcao == 0) {
            printf("Voltando ao menu principal...\n");
        } else {
            printf("Opcao invalida!\n");
        }
        sleep(2);
        limpartela();
    }
    return tamanho_carrinho;
}

int main(){
    char lista_prod[10][10] = {"Fone", "Mouse", "Pen Drive", "Teclado", "Camisa", "Lapis", "Borracha", "Caneta", "Short", "Blusa"};
    float preco_prod[10] = {59.99, 129.99, 35.99, 195.99, 75.99, 1.99, 2.99, 0.99, 50.99, 89.99};

    char carrinho_prod[10][10];
    float carrinho_preco[10];
    int carrinho_quant[10];
    int tamanho_carrinho = 0;

    char nome[20];
    char endereco[40]; 
    char email[20]; 
    char usuario_correto[10]; 
    char senha_correta[10];
    char senha_digitada[20];
    char usuario_digitado[20];
    int consulta;
    int tamanhoDoVetor = 10;

    do {
        

        printf("Digite seu usuario:\n");
        fgets(usuario_digitado, sizeof(usuario_digitado), stdin);
        usuario_digitado[strcspn(usuario_digitado, "\n")] = '\0';

        printf("Digite sua senha:\n");
        fgets(senha_digitada, sizeof(senha_digitada), stdin);
        senha_digitada[strcspn(senha_digitada, "\n")] = '\0';

        
        if (strcmp(usuario_correto, usuario_digitado) != 0 || strcmp(senha_correta, senha_digitada) != 0) {
            printf("\nUsuario ou senha incorretos. Tente novamente.\n\n");
        }

     } while (strcmp(usuario_correto, usuario_digitado) != 0 || strcmp(senha_correta, senha_digitada) != 0);

    printf("\nBem-vindo ao BombIT %s.\n", nome);

    do {
        printf("\n====================================\n");
        printf("Digite a consulta que deseja fazer:\n[1] Meus dados\n[2] Lista de produtos\n[3] Carrinho\n[4] Pesquisar\n[0] Sair\n");
        printf("====================================\n");
        scanf("%d", &consulta);
        
        switch (consulta) { 
            case 1:
                mostrarDados(usuario_digitado, endereco, senha_digitada, email);
                limpartela();
                break;
            case 2:
                mostrarProdLoja(lista_prod, preco_prod);
                limpartela();
                break;
            case 3: 
                tamanho_carrinho = gerenciarCarrinho(lista_prod, endereco, preco_prod, carrinho_prod, carrinho_preco, carrinho_quant, tamanho_carrinho);
                break;
            case 4: 
                pesquisar(lista_prod, tamanhoDoVetor);
                limpartela();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
                limpartela();
                break;
        }
    } while (consulta != 0);
    
    printf("Deslogando...\n");
    sleep(1);

    return 0;
}