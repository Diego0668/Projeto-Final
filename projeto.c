#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> 



void limpartela(){
    sleep(4);
    getchar();
	system("cls");

}

int main(){

    char usuario_correto[10] = "admin"; 
    char senha_correta[10] = "123";

    char senha_digitada[20];
    char usuario_digitado[20];

    int consulta;

    do{
        printf("Digite o usuario\n");
        fgets(usuario_digitado, sizeof(usuario_digitado), stdin);
        usuario_digitado[strcmp(usuario_digitado , "\n")] = '\0';

        printf("Digite a senha\n");
        fgets(senha_digitada , sizeof(senha_digitada), stdin);
        senha_digitada[strcmp(senha_digitada , "\n")] = '\0';

        if (strcmp(usuario_correto, usuario_digitado) != 0  || strcmp(senha_correta , senha_digitada) != 0){
            printf("Senha ou Usuario incorreta\n");
            
        }
        


        
    } while (strcmp(usuario_correto, usuario_digitado) != 0  || strcmp(senha_correta , senha_digitada) != 0);
        printf("\nBem-vindo ao sistema %s.\n", usuario_digitado);


        do{

            printf("====================================\n");
            printf("Digite a consulta que deseja fazer \n[1] Perfil \n[2] Pesquisar\n");
            printf("====================================\n");

            scanf("%d" , &consulta);    
            switch (consulta)
            {
            case 1:
                
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