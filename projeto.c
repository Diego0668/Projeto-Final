#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 

void limpartela(){
    sleep(5);
    getchar();
	system("cls");

}
  
void mostrarDados(char nome[20],char endereco[40],char senha_digitada[20],char email[20]){
    
    printf("\n---------- Meus Dados ----------\n");
    printf("Nome %s\n", nome);
    printf("Email %s\n", email);
    printf("Senha: %s \n", senha_digitada);
    printf("Endereco: %s \n" , endereco);
    printf("------------------------------\n");

}

void mostrarProd(char lista_prod[10][10]){

    printf("====================================\n");
    printf("Os produtos cadastrados sao \n");
    for (int i = 0; i < 10; i++) { 
        for (int j = 0; j < 10; j++) { 
            
            printf("%c", lista_prod[i][j]);        
        }
        
     printf("\n"); 
    
}
}

void pesquisar(char lista_prod[10][10], int tamanhoDoVetor ) {
    
    char produtoParaBuscar[20]; 
    int valorEncontrado = 0;
    int c;

    // Limpa o buffer do teclado antes de ler a string
    
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
        printf("O produto '%s' foi encontrado na lista de produto\n", produtoParaBuscar);
    } else {
        printf("O produto '%s' nao foi encontrado na lista de produto\n", produtoParaBuscar);
    }
}

void comprar(char lista_prod[10][10] , char endereco[40] ){
     
    int c;   
    int indice_produto;
    int quant;
    int venda;
    char forma_pag [10];
    char total_compra;
    
    printf("Nossos produtos:\n");
    for(int i = 0; i < 10; i++){
        printf("[%d] %s\n", i, lista_prod[i]);
    }
    
    printf("\nDigite o NUMERO do produto que deseja comprar: \n");
    scanf("%d", &indice_produto);

    
    if (indice_produto >= 0 && indice_produto < 10) {
        
    
        printf("Voce escolheu o produto: %s\n", lista_prod[indice_produto]);
        scanf("%c" ,&lista_prod);
        printf("Digite a quantidade desejado\n");
        scanf("%d" , &quant);
        
        printf("Selecione a forma de pagamento (Cartao ou Pix) \n");
        fgets(forma_pag, sizeof(forma_pag) , stdin);
        forma_pag[strcspn(forma_pag, "\n")] = '\0';
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Confirmando seu endereco eh %c? \n" , endereco);

        total_compra = quant * indice_produto;
        
        printf("Total da compra eh %d" , total_compra);

        
        
    } else {
        printf("Erro: Numero de produto invalido!\n");
    }
    

}




int main(){

    char lista_prod [10] [10] = {"Fone","Mouse","Pen Drive" , "Teclado" , "Camisa","Lapis" , "Borracha" , "Caneta" , "Short" , "Blusa"};
    char preco_prod [10] [10] = {"59,99" , "129,99" ,"35,99" ,"195,99" ,"75,99" ,"1,99" ,"2,99" ,"0,99" ,"50,99" ,"89,99" ,};
    char nome[20] = "diego";
    char endereco[40] ="Cuiaba";
    char email[20] ="diego@gmail.com";

    char usuario_correto[10] = "admin"; 
    char senha_correta[10] = "123";

    char senha_digitada[20];
    char usuario_digitado[20];
    
    int i;
    int consulta;
    int ProdParaBuscar; 
    int tamanhoDoVetor = sizeof(lista_prod) / sizeof(lista_prod[0]);
    int valorEncontrado = 0; 


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

    printf("\nBem-vindo ao BombIT %s.\n", usuario_digitado);


        do{

            printf("====================================\n");
            printf("Digite a consulta que deseja fazer \n[1] Meus dados \n[2] Minhas compras\n[3] Lista de produto \n[4] Carrinho\n[5] Pesquisar\n[0] Sair\n");
            printf("====================================\n");
            scanf("%d" , &consulta);    
            
            switch (consulta){ 
            case 1:
                mostrarDados(usuario_digitado,endereco,senha_digitada,email);
                limpartela();
            break;

            case 2:
            break;
            
            case 3:
            mostrarProd(lista_prod);
            break;

            case 4:
            comprar(lista_prod,endereco);
            break;

            case 5:
            pesquisar(lista_prod, tamanhoDoVetor);
            limpartela();
            
            break;


            
            default:
            break;
            }
        } while (consulta != 0);{
            sleep(1);
            printf("Deslogando...");
            limpartela();
        }
        
    
    


}