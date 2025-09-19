#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura do Produto
typedef struct {
    char nome[50];
    double preco;
    int estoque;
    int vendas;
} Produto;

// Constantes
#define MAX_PRODUTOS 5
#define MAX_CARRINHO 10

// Variáveis Globais (simples para este exemplo)
Produto catalogo[MAX_PRODUTOS];
int carrinho_indices[MAX_CARRINHO];
int carrinho_quantidades[MAX_CARRINHO];
int num_itens_carrinho = 0;

// Protótipos das funções
void inicializarCatalogo();
void mostrarCatalogo();
int buscarProdutoPorNome(const char* nome);
void adicionarAoCarrinho();
void mostrarCarrinho();
void finalizarCompra();
void mostrarRelatorioVendas();

int main() {
    inicializarCatalogo();
    int opcao;

    do {
        printf("\n--- Bem-vindo a Loja C ---\n");
        printf("1. Ver produtos\n");
        printf("2. Adicionar produto ao carrinho\n");
        printf("3. Ver carrinho\n");
        printf("4. Finalizar compra\n");
        printf("5. Ver relatorio de vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: mostrarCatalogo(); break;
            case 2: adicionarAoCarrinho(); break;
            case 3: mostrarCarrinho(); break;
            case 4: finalizarCompra(); break;
            case 5: mostrarRelatorioVendas(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void inicializarCatalogo() {
    // Produto 0
    strcpy(catalogo[0].nome, "Mouse");
    catalogo[0].preco = 50.00;
    catalogo[0].estoque = 10;
    catalogo[0].vendas = 0;
    // Produto 1
    strcpy(catalogo[1].nome, "Teclado");
    catalogo[1].preco = 120.50;
    catalogo[1].estoque = 5;
    catalogo[1].vendas = 0;
    // Produto 2
    strcpy(catalogo[2].nome, "Monitor");
    catalogo[2].preco = 750.00;
    catalogo[2].estoque = 3;
    catalogo[2].vendas = 0;
    // Produto 3
    strcpy(catalogo[3].nome, "Fone");
    catalogo[3].preco = 80.75;
    catalogo[3].estoque = 8;
    catalogo[3].vendas = 0;
    // Produto 4
    strcpy(catalogo[4].nome, "Webcam");
    catalogo[4].preco = 200.00;
    catalogo[4].estoque = 4;
    catalogo[4].vendas = 0;
}

void mostrarCatalogo() {
    printf("\n--- Catalogo de Produtos ---\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Nome: %-10s | Preco: R$ %6.2f | Estoque: %d\n", catalogo[i].nome, catalogo[i].preco, catalogo[i].estoque);
    }
}

int buscarProdutoPorNome(const char* nome) {
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (stricmp(catalogo[i].nome, nome) == 0) { // stricmp ignora maiúsculas/minúsculas
            return i;
        }
    }
    return -1;
}

void adicionarAoCarrinho() {
    if (num_itens_carrinho >= MAX_CARRINHO) {
        printf("ERRO: O carrinho esta cheio!\n");
        return;
    }
    char nomeBusca[50];
    printf("Digite o nome do produto: ");
    scanf("%s", nomeBusca);

    int indiceProduto = buscarProdutoPorNome(nomeBusca);

    if (indiceProduto == -1) {
        printf("ERRO: Produto '%s' nao encontrado!\n", nomeBusca);
        return;
    }
    if (catalogo[indiceProduto].estoque <= 0) {
        printf("ERRO: Produto '%s' fora de estoque!\n", nomeBusca);
        return;
    }

    int quantidade;
    printf("Estoque disponivel: %d. Digite a quantidade: ", catalogo[indiceProduto].estoque);
    scanf("%d", &quantidade);

    if (quantidade <= 0 || quantidade > catalogo[indiceProduto].estoque) {
        printf("ERRO: Quantidade invalida!\n");
        return;
    }

    carrinho_indices[num_itens_carrinho] = indiceProduto;
    carrinho_quantidades[num_itens_carrinho] = quantidade;
    num_itens_carrinho++;
    catalogo[indiceProduto].estoque -= quantidade;
    printf("'%s' adicionado ao carrinho!\n", nomeBusca);
}

void mostrarCarrinho() {
    if (num_itens_carrinho == 0) {
        printf("\nO carrinho esta vazio!\n");
        return;
    }
    printf("\n--- Meu Carrinho ---\n");
    double total = 0;
    for (int i = 0; i < num_itens_carrinho; i++) {
        int indice = carrinho_indices[i];
        int qtde = carrinho_quantidades[i];
        double subtotal = catalogo[indice].preco * qtde;
        printf("%dx %-10s | Preco Unit.: R$ %6.2f | Subtotal: R$ %6.2f\n", qtde, catalogo[indice].nome, catalogo[indice].preco, subtotal);
        total += subtotal;
    }
    printf("-------------------------------------------\n");
    printf("Total a pagar: R$ %.2f\n", total);
}

void finalizarCompra() {
    if (num_itens_carrinho == 0) {
        printf("O carrinho esta vazio!\n");
        return;
    }
    
    printf("\n--- Finalizando Compra ---\n");
    for (int i = 0; i < num_itens_carrinho; i++) {
        int indiceProduto = carrinho_indices[i];
        int quantidade = carrinho_quantidades[i];
        catalogo[indiceProduto].vendas += quantidade;
    }
    printf("Compra realizada com sucesso!\n");
    num_itens_carrinho = 0; // Esvazia o carrinho
}

void mostrarRelatorioVendas() {
    printf("\n--- Relatorio de Vendas ---\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Produto: %-10s | Unidades Vendidas: %d\n", catalogo[i].nome, catalogo[i].vendas);
    }
}