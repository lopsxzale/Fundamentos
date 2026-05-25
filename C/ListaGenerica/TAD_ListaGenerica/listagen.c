#include <stdio.h>
#include <stdlib.h>
#include "ListaGen.h"

ListaGen* lstgen_cria(){
    return NULL;
}

int lstgen_vazia(ListaGen* l){
    return l == NULL; // Se retornar 0 é verdadeiro, se 1 é falso.
}

ListaGen* lstgen_insere(ListaGen* l, void* elemento){
    ListaGen* novo = (ListaGen*)malloc(sizeof(ListaGen));

    if(!novo){
        printf("\nAcabou a memória para guardarmos o próximo elemento na lista...\n");
        exit(1);
    }

    novo->info = elemento;
    novo->prox = l;

    return novo;
}

void lstgen_libera(ListaGen* l){
    ListaGen* p = l;

    while(p != NULL){
        free(p->info);
        ListaGen* temp = p->prox;
        free(p);
        p = temp;
    }
}

void lstgen_percorre(ListaGen* l, void (*processa)(void*)){
    ListaGen* p = l;

    while(p != NULL){
        processa(p->info);
        p = p->prox;
    }
}

void* lstgen_busca(ListaGen* l, int (*compara)(void*, void*), void* dado){
    ListaGen* p = l;

    while(p != NULL){
        if(compara(p->info, dado))
            return p->info;
        
        p = p->prox;
    }

    return NULL;
}

ListaGen* lstgen_retira(ListaGen* l, int (*compara)(void*, void*), void* dado){
    ListaGen* p = l;
    ListaGen* ant = NULL;

    while(p != NULL){
        if(compara(p->info, dado)){

            if(ant == NULL){
                ListaGen* temp = p->prox;
                free(p);
                l = temp;
            } else {
                ant->prox = p->prox;
                free(p);
            }

            return l;
        }

        ant = p;
        p = p->prox;
    }

    return l;
}

ListaGen* lstgen_duplica(ListaGen* l, void* (*duplica)(void*)){
    ListaGen* copia = lstgen_cria();

    for(ListaGen* p = l; p != NULL; p = p->prox){
        copia = lstgen_insere(copia, duplica(p->info));
    }

    return copia;
}

ListaGen* lstgen_filtra(ListaGen* l, int (*criterio)(void*)){
    ListaGen* lst_filtrada = lstgen_cria();
    ListaGen* p = l;

    while(p != NULL){
        if(criterio(p->info)){
            lst_filtrada = lstgen_insere(lst_filtrada, p->info);
        }

        p = p->prox;
    }

    return lst_filtrada;
}

ListaGen* lstgen_ordena(ListaGen* l, int (*compara)(void*, void*)){
    for(ListaGen* p = l; p != NULL; p = p->prox){
        ListaGen* q = p->prox;

        while(q != NULL){
            if(compara(p->info, q->info)){
                void* aux = q->info;
                q->info = p->info;
                p->info = aux;
            }

            q = q->prox;
        }
    }

    return l;
}

// CSV

int lstgen_grava_csv(ListaGen* l, char* nome_arquivo_csv, char* (*cria_linha_csv)(void*)){
    FILE* saida_csv = fopen(nome_arquivo_csv, "wt");
    char* string_csv;

    if(!saida_csv){
        printf("Nao foi possivel criar o arquivo no caminho %s...\n", nome_arquivo_csv);
        return 0;
    }

    for(ListaGen* p = l; p != NULL; p = p->prox){
        string_csv = cria_linha_csv(p->info);
        int i = 0;
        while(string_csv[i] != '\0'){
            fputc(string_csv[i], saida_csv);
            i++;
        }

        free(string_csv);
    }

    fclose(saida_csv);

    return 1;
}

ListaGen* lstgen_carrega_csv(char* nome_arquivo_csv, void* (*cria_elemento)(char* linha_csv)){
    FILE* entrada = fopen(nome_arquivo_csv, "rt");
    char linha[121];
    ListaGen* l = lstgen_cria();

    if(!entrada){
        printf("Nao pude abrir o arquivo %s", nome_arquivo_csv);
        return NULL;
    }

    while(fgets(linha, 121, entrada) != NULL){
        void* novo_elemento = cria_elemento(linha);

        // Caso o callback do cliente retorna NULL, significa dizer que a linha será descartada.
        if(!novo_elemento)
            continue;

        l = lstgen_insere(l, novo_elemento);
    }

    return l;
}