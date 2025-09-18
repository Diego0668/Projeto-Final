#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 


void limpartela(){
    sleep(4);
    getchar();
	system("cls");

}
  
void mostrarDados(char nome[20],char endereco[40],char senha_digitada[]){
    char nomeDado[20];
    char senhaDado[20];
    char enderecoDado[20];
    char emailDado[20];


    
    printf("Nome %s\n", nomeDado);
    printf("Email %s\n", emailDado);
    printf("Senha: %s \n", senhaDado);
    printf("Endereco: %s \n" , enderecoDado);
}
 

int main(){


    char nome[20] = "diego";
    char endereco[40] ="Cuiaba";


    char usuario_correto[10] = "admin"; 
    char senha_correta[10] = "123";

    char senha_digitada[20];
    char usuario_digitado[20];
 mostrarDados(nome,endereco,senha_digitada);
    

   


    
    int consulta,cadastrar;

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
            printf("Digite a consulta que deseja fazer \n[1] Meus dados \n[2] Minhas compras\n[3] Lista de produto \n[4] Carrinho\n[5] Pesquisar\n");
            printf("====================================\n");

            scanf("%d" , &consulta);    
            switch (consulta)
            {
            case 1:
                mostrarDados(usuario_digitado,endereco,senha_digitada);
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