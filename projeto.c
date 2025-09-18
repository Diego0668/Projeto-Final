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

void pesquisar(char lista_prod[10][10]){

    printf("Pesquisar...\n");
    scanf("%c" , lista_prod);





}
 

int main(){

    char lista_prod [10] [10] = {"Fone","Mouse","Pen Drive" , "Teclado" , "Camisa","Lapis" , "Borracha" , "Caneta" , "Short" , "Blusa"};
    char nome[20] = "diego";
    char endereco[40] ="Cuiaba";
    char email[20] ="diego@gmail.com";


    char usuario_correto[10] = "admin"; 
    char senha_correta[10] = "123";

    char senha_digitada[20];
    char usuario_digitado[20];
    
    int i;
    int consulta;

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
            
            break;

            case 5:
            pesquisar(lista_prod);
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