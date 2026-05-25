#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaGenerica/listagen.h"

// Struct
typedef struct {
    int id;
    char setor[30];
    char problema[50];
    int prioridade; // 1 = Baixa, 2 = Media, 3 = Alta
} Chamado;

void imprime_chamado(void* info) {
    Chamado* c = (Chamado*)info;
    char nivel[10];
    if(c->prioridade == 3) strcpy(nivel, "ALTA");
    else if(c->prioridade == 2) strcpy(nivel, "MEDIA");
    else strcpy(nivel, "BAIXA");

    printf("[#%03d] Prioridade: %-5s | Setor: %-15s | Problema: %s\n", 
           c->id, nivel, c->setor, c->problema);
}

int compara_prioridade(void* info1, void* info2) {
    Chamado* c1 = (Chamado*)info1;
    Chamado* c2 = (Chamado*)info2;
    return (c2->prioridade > c1->prioridade);
} // Retorna 1 se o chamado 2 for mais urgente que o 1 (Ordenação Decrescente)

// A função grava_csv dá free() na string, então usar malloc
char* chamado_para_csv(void* info) {
    Chamado* c = (Chamado*)info;
    char* linha = (char*)malloc(150 * sizeof(char));
    snprintf(linha, 150, "%d,%s,%s,%d\n", c->id, c->setor, c->problema, c->prioridade);
    return linha;
}

int main() {
    printf("=== SISTEMA DE TRIAGEM DE SUPORTE ===\n\n");
    ListaGen* fila = lstgen_cria();

    // Alocando chamados dinamicamente (para o lstgen_libera funcionar corretamente)
    Chamado* c1 = malloc(sizeof(Chamado)); *c1 = (Chamado){1, "RH", "Impressora sem toner", 1};
    Chamado* c2 = malloc(sizeof(Chamado)); *c2 = (Chamado){2, "Diretoria", "Sem acesso a internet", 3};
    Chamado* c3 = malloc(sizeof(Chamado)); *c3 = (Chamado){3, "Vendas", "Teclado falhando", 1};
    Chamado* c4 = malloc(sizeof(Chamado)); *c4 = (Chamado){4, "Servidores", "Banco de Dados offline", 3};

    // Insere na lista (a ordem inverte pois insere no início)
    fila = lstgen_insere(fila, c1);
    fila = lstgen_insere(fila, c2);
    fila = lstgen_insere(fila, c3);
    fila = lstgen_insere(fila, c4);

    printf("=> Fila Bruta (Ordem de Entrada):\n");
    lstgen_percorre(fila, imprime_chamado);

    printf("\n=> Aplicando Ordenacao por Prioridade...\n");
    fila = lstgen_ordena(fila, compara_prioridade);
    
    printf("\n=> Fila Organizada para Atendimento:\n");
    lstgen_percorre(fila, imprime_chamado);

    printf("\n=> Exportando relatorio para 'relatorio_chamados.csv'...\n");
    if(lstgen_grava_csv(fila, "relatorio_chamados.csv", chamado_para_csv)) {
        printf("Arquivo salvo com sucesso!\n");
    }

    lstgen_libera(fila);
    return 0;
}