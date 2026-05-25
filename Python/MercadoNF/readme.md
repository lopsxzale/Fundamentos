# Simulador de Caixa em Python (Mercadinho)

Um sistema de terminal interativo desenvolvido em **Python** para simular o funcionamento de um caixa de supermercado. O projeto foca em gerenciar estoque, processar múltiplos inputs do usuário e gerar uma nota fiscal formatada.

**Nota de Desenvolvimento:** Inicialmente, desenvolvi este sistema em Python para construir uma base sólida em uma linguagem de alto nível, aproveitando suas funções nativas e estruturas de dados diretas. Em seguida, recriei o mesmo projeto em **C** para aprimorar meus conhecimentos em manipulação de memória e eficiência algorítmica (você pode conferir a versão em C nas pastas deste repositório).

---

## Funcionalidades

* **Cardápio Interativo:** Exibe o estoque com formatação alinhada e amigável ao usuário.
* **Carrinho Inteligente:** Se o usuário escolher o mesmo produto várias vezes, o sistema não duplica o item, mas sim soma a quantidade dinamicamente no carrinho.
* **Filtro de Entradas (Case-Insensitive):** Aplicação do método `.lower()` para garantir que o programa entenda o pedido, independentemente de como for digitado (ex: "BOLA", "Bola" ou "bola").
* **Geração de Recibo:** Cálculo automático de subtotais e total final, com exibição de um "Cupom Fiscal" perfeitamente centralizado no terminal.

---

## Conceitos e Tecnologias Aplicadas

* **Dicionários (Hash Maps):** Uso extensivo da estrutura de dados `dict` (`{}`) tanto para armazenar o estoque (chaves e valores monetários) quanto para gerenciar as quantidades do carrinho.
* **Iteração Avançada:** Uso de `for chave, valor in dicionario.items()` para varrer coleções e renderizar menus/recibos de forma escalável.
* **Formatação de Strings (f-strings):** Utilização avançada de formatação (`:.2f`) para exibir os preços sempre com duas casas decimais e do método `.center()` para centralizar o layout do cupom fiscal.
* **Validação Condicional:** Estruturas `if/else` para evitar erros de `KeyError` no dicionário, checando previamente se o produto existe no estoque antes de adicioná-lo.

---

## Como rodar este projeto

**Pré-requisitos:** Python 3.x instalado na máquina.

1. Baixe ou clone o arquivo do projeto.
2. Abra o terminal na mesma pasta do arquivo.
3. Execute o comando:
   ```bash
   python mercadinho.py