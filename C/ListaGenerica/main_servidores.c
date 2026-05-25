#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaGenerica/listagen.h"

// Struct
typedef struct {
    char hostname[50];
    char ip[20];
    int uso_cpu; // 0 a 100%
} Servidor;

void imprime_servidor(void* info) {
    Servidor* s = (Servidor*)info;
    printf("Servidor: %-15s | IP: %-15s | CPU: %d%%\n", s->hostname, s->ip, s->uso_cpu);
}

int filtra_cpu_critica(void* info) {
    Servidor* s = (Servidor*)info;
    return (s->uso_cpu > 85); // Se uso > 85 return 1
}

// Callback para transformar uma linha do CSV em uma Struct Servidor
void* csv_para_servidor(char* linha_csv) {
    Servidor* s = (Servidor*)malloc(sizeof(Servidor));
    if(!s) return NULL;
    
    // Lê no formato: Hostname, IP, CPU
    sscanf(linha_csv, "%[^,],%[^,],%d", s->hostname, s->ip, &s->uso_cpu);
    return s;
}

// Função auxiliar apenas pra criar um CSV falso pra teste
void gerar_csv_teste() {
    FILE* f = fopen("dados_servidores.csv", "w");
    fprintf(f, "SRV-WEB-01,192.168.0.10,45\n");
    fprintf(f, "SRV-DB-MASTER,10.0.0.50,92\n");
    fprintf(f, "SRV-FILE-01,192.168.0.15,12\n");
    fprintf(f, "SRV-DB-SLAVE,10.0.0.51,88\n");
    fclose(f);
}

int main() {
    gerar_csv_teste(); // Cria o CSV de teste no disco

    printf("=== DASHBOARD DE INFRAESTRUTURA ===\n\n");
    
    printf("=> Carregando dados do arquivo 'dados_servidores.csv'...\n");
    ListaGen* parque_maquinas = lstgen_carrega_csv("dados_servidores.csv", csv_para_servidor);

    if (lstgen_vazia(parque_maquinas)) {
        printf("Nenhum dado carregado.\n");
        return 1;
    }

    printf("\nStatus Geral do Parque de Maquinas:\n");
    lstgen_percorre(parque_maquinas, imprime_servidor);

    printf("\n=> ALERTA: Filtrando servidores com CPU > 85%%...\n");
    ListaGen* servidores_criticos = lstgen_filtra(parque_maquinas, filtra_cpu_critica);
    
    lstgen_percorre(servidores_criticos, imprime_servidor);

    lstgen_libera(parque_maquinas);
    
    ListaGen* p = servidores_criticos;
    while(p != NULL) {
        ListaGen* temp = p->prox;
        free(p);
        p = temp;
    }

    return 0;
}