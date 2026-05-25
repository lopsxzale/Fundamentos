#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#define TAM 3

typedef struct{
    char nome[30];
    float preco;
} Produto;

void exibeIntro(char nome[]){
    printf("========================================\n");
    printf("     Bem vindo ao '%s'\n", nome);
    printf("========================================\n");
}

void exibeEstoque(Produto estoque[]){
    for(int i = 0; i < TAM; i++)
        printf("- %c%s :  R$ %.2f\n", toupper(estoque[i].nome[0]), &estoque[i].nome[1], estoque[i].preco);
    printf("----------------------------------------\n");
}

void exibe_salva_recibo(Produto estoque[], int quantidade[]){
    char nome[30];

    printf("Insira o nome do cliente: \n");
    scanf("%s", nome);

    FILE* arquivo = fopen("recibos.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao criar o recibo...");
        return;
    }

    printf("\n========================================\n");
    printf("               NOTA FISCAL\n");
    printf("----------------------------------------\n");

    // PRINTA NO ARQUIVO
    fprintf(arquivo, "\n========================================\n");
    fprintf(arquivo, "               NOTA FISCAL\n");
    fprintf(arquivo, "----------------------------------------\n");

    float subtotal = 0;
    float totalCompra = 0;

    for(int i = 0; i < TAM; i++){
        if(quantidade[i] > 0){
            subtotal = estoque[i].preco * quantidade[i];
            totalCompra += subtotal;
            printf("%dx %c%s = %.2f\n", quantidade[i], toupper(estoque[i].nome[0]), &estoque[i].nome[1], subtotal);
            fprintf(arquivo, "%dx %c%s = %.2f\n", quantidade[i], toupper(estoque[i].nome[0]), &estoque[i].nome[1], subtotal);
        }
    }

    printf("========================================\n");
    printf("      TOTAL A PAGAR: R$ %.2f\n", totalCompra);
    printf("========================================\n");
    printf("       AGRADECEMOS A PREFERENCIA\n");
    printf("        VOLTE SEMPRE, %s!\n", nome);
    printf("========================================\n");

    // PRINTA NO ARQUIVO
    fprintf(arquivo, "========================================\n");
    fprintf(arquivo, "       TOTAL A PAGAR: R$ %.2f\n", totalCompra);
    fprintf(arquivo, "========================================\n");
    fprintf(arquivo, "        AGRADECEMOS A PREFERENCIA\n");
    fprintf(arquivo, "         VOLTE SEMPRE, %s!\n", nome);
    fprintf(arquivo, "========================================\n"); 
    fprintf(arquivo, "\n****************************************\n");

    fclose(arquivo);
}

int main(){
    char nome_loja[] = "Mercadinho da Budega";

    Produto estoque[TAM] = {
        {"bola", 20.00},
        {"luva", 14.90},
        {"jaqueta", 39.90}
    };

    exibeIntro(nome_loja);
    exibeEstoque(estoque);

    int quantidades_carrinho[TAM] = {0, 0, 0};
    
    while(1){
        char pedido[30];

        printf("Qual produto voce deseja comprar? Caso queira encerrar digite 'sair'.\n");
        scanf("%s", pedido);

        for(int i = 0; pedido[i] != '\0'; i++)
            pedido[i] = tolower(pedido[i]);

        if(strcmp(pedido, "sair") == 0)
            break;
        
        int encontrou = 0;

        for(int j = 0; j < TAM; j++){
            if(strcmp(pedido, estoque[j].nome) == 0){
                int qtd_temp;

                printf("Quantas unidades voce quer?\n");
                scanf("%d", &qtd_temp);

                quantidades_carrinho[j] += qtd_temp;

                printf("- %dx %c%s adicionado ao carrinho.\n", qtd_temp, toupper(estoque[j].nome[0]), &estoque[j].nome[1]);
                printf("----------------------------------------\n");
                encontrou = 1; // Encontrou
                break;
            }
        }

        if(encontrou == 0)
            printf("Esse produto tem aqui nao brother...\n");
    }

    // Recibo
    exibe_salva_recibo(estoque, quantidades_carrinho);

    return 0;
}