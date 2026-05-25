# TAD: Lista Encadeada Genérica em C

Este projeto consiste em uma implementação robusta de um **Tipo Abstrato de Dados (TAD)** para uma Lista Encadeada Genérica na linguagem C, desenhada para ser independente do tipo de dado que armazena.

A biblioteca abstrai a complexidade do gerenciamento de memória e fornece uma interface de alto nível utilizando **Ponteiros Genéricos (`void *`)** e **Callbacks Funcionais (Ponteiros de Função)**, permitindo recursos avançados como filtragem, ordenação dinâmica e injeção de dependências.

---

## Tecnologias e Conceitos Aplicados

* **Ponteiros Ocultos e Genéricos (`void*`):** Desacoplamento arquitetural entre a estrutura de dados e as regras de negócio do cliente.
* **Programação Funcional no C:** Implementação de funções de alta ordem (High-Order Functions) simulando métodos de linguagens modernas:
  * `lstgen_filtra` (Similar ao `filter()`)
  * `lstgen_ordena` (Similar ao `sort()` com comparador injetado)
  * `lstgen_percorre` (Similar ao `map()` / `forEach()`)
* **Persistência de Dados via CSV:** Funções genéricas `lstgen_grava_csv` e `lstgen_carrega_csv` que delegam ao cliente o algoritmo de parsing e serialização das strings.
* **Manipulação Manual de Memória:** Controle rigoroso de alocações na Heap com tratamento contra *Memory Leaks*.

---

## Exemplos Reais de Aplicação

Para demonstrar a versatilidade da biblioteca, desenvolvi dois cenários práticos focados em **Infraestrutura e Suporte de TI**, onde a mesma estrutura (sem nenhuma alteração no core) gerencia contextos completamente diferentes:

1. **`main_chamados.c` (Fila de Suporte ITIL):** * Simula um sistema de HelpDesk.
   * Utiliza a função `lstgen_ordena` para organizar os tickets por nível de urgência (Alta, Média, Baixa) de forma automática.
   * Utiliza a função genérica de CSV para exportar o relatório de chamados no final do expediente.

2. **`main_servidores.c` (Monitoramento de Infraestrutura):**
   * Lê ativamente um arquivo `.csv` contendo IPs, Hostnames e taxa de uso de CPU.
   * Utiliza a função `lstgen_carrega_csv` para converter os textos do disco em `structs` na RAM.
   * Utiliza o `lstgen_filtra` para isolar e exibir apenas servidores com carga crítica (CPU > 85%).

---

## Como Compilar e Executar

Certifique-se de ter o compilador GCC instalado. Para testar o poder genérico da lista, você deve compilar o núcleo da biblioteca (`ListaGen.c`) juntamente com o cenário que deseja testar.

**Exemplo 1: Triagem de Chamados**
```bash
gcc main_chamados.c ListaGen.c -o chamados
./chamados