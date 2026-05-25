#ifndef __ListaGen__
#define __ListaGen__

    // ==========================================================
    //   Estrutura de encadeamento
    // ==========================================================
    typedef struct listagen {
        void* info;
        struct listagen* prox;
    } ListaGen;

    // ==========================================================
    //   Funções Base
    // ==========================================================
    ListaGen* lstgen_cria();

    int lstgen_vazia(ListaGen* l);

    ListaGen* lstgen_insere(ListaGen* l, void* elemento);

    void lstgen_libera(ListaGen* l);

    // ==========================================================
    //   Funções com Callbacks
    // ==========================================================
    void lstgen_percorre(ListaGen* l, void (*processa)(void*));

    void* lstgen_busca(ListaGen* l, int (*compara)(void*, void*), void* dado);

    ListaGen* lstgen_retira(ListaGen* l, int (*compara)(void*, void*), void* dado);

    ListaGen* lstgen_duplica(ListaGen* l, void* (*duplica)(void*));

    ListaGen* lstgen_filtra(ListaGen* l, int (*criterio)(void*));

    ListaGen* lstgen_ordena(ListaGen* l, int (*compara)(void*, void*));

    // ==========================================================
    //   Arquivos CSV
    // ==========================================================
    int lstgen_grava_csv(ListaGen* l, char* nome_arquivo_csv, char* (*cria_linha_csv)(void*));

    ListaGen* lstgen_carrega_csv(char* nome_arquivo_csv, void* (*cria_elemento)(char* linha_csv));

#endif