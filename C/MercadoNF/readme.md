# Mercadinho - Simulador de Caixa em C

Um sistema interativo de terminal desenvolvido em **C** que simula o fluxo de compras de um mercadinho. O usuário pode visualizar o estoque, adicionar itens ao carrinho e, ao finalizar, o programa calcula os totais e gera automaticamente uma nota fiscal salva em um arquivo `.txt`.

A finalidade desse sistema seria praticar tecnologias dentro do C, adquirindo conhecimento e aprimorando a logica de programação aumentando a capacidade cognitiva de resolver sistemas mais complexos.

---

## Funcionalidades

* **Menu Dinâmico:** Exibe os produtos e preços disponíveis no estoque com formatação visual.
* **Carrinho Inteligente:** Permite a compra de múltiplas unidades do mesmo produto, somando as quantidades perfeitamente no carrinho.
* **Validação de Entrada:** O sistema converte automaticamente a entrada do usuário para letras minúsculas (simulando um `.lower()`), garantindo que o programa encontre o produto independentemente de como foi digitado.
* **Exportação de Recibo:** Gera um arquivo `recibo.txt` na mesma pasta do executável contendo a nota fiscal formatada da compra.

---

## Conceitos e Tecnologias Aplicadas

Este projeto foi desenvolvido para consolidar fundamentos essenciais da linguagem C e da Ciência da Computação:

* **Estruturas de Dados (`struct`):** Uso de `typedef struct` para encapsular as propriedades dos produtos (nome e preço), simulando um comportamento similar a Dicionários/Objetos de linguagens de alto nível.
* **Manipulação de Memória e Ponteiros:** Acesso a endereços de memória (`&`) para impressão e leitura de strings em arrays de caracteres (`char[]`).
* **Manipulação de Strings:** Uso de `<string.h>` para comparação de textos (`strcmp`) e `<ctype.h>` para conversão de caracteres (`tolower`, `toupper`).
* **File I/O (Entrada e Saída de Arquivos):** Utilizei ponteiros de arquivos (`FILE *`), `fopen`, `fprintf` e `fclose` para persistência de dados no disco rígido.

---

## Como rodar este projeto

**Pré-requisitos:** Você precisará de um compilador C (como o GCC) instalado na sua máquina.

1. Clone este repositório ou baixe os arquivos.
2. Abra o terminal e vá até a pasta do projeto.
3. Compile o código executando o comando:
   ```bash
   gcc mercado.c -o mercado