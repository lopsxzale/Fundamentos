# Calculadora CLI em Python

Uma calculadora interativa de linha de comando desenvolvida em Python. O projeto foca em oferecer uma experiência de usuário fluida e livre de falhas (crash-free) através da implementação de tratamentos de erros.

Um programa simples mas 

---

## Funcionalidades

* **Operações Básicas:** Suporte para adição, subtração, multiplicação e divisão.
* **Execução Contínua:** Estrutura em loop (`while True`) que permite realizar múltiplos cálculos sem precisar reiniciar o programa.
* **Prevenção de Quebras (Error Handling):** * Captura de `ValueError` com o bloco `try-except` para evitar que o programa pare caso o usuário digite texto em vez de números.
  * Validação lógica para impedir `ZeroDivisionError` (divisão por zero).
* **Interface Limpa:** Limpeza automática do terminal (`os.system`) a cada nova operação para manter a tela organizada, com suporte multiplataforma (Windows/Linux/Mac).

---

## Conceitos Aplicados

* **Estruturas de Repetição:** Controle de fluxo com loops interativos.
* **Tratamento de Exceções:** Uso de `try/except` para validação segura de *inputs*.
* **Match-Case:** Uso do *Structural Pattern Matching* (introduzido no Python 3.10) para uma tomada de decisão limpa e legível nas operações matemáticas.
* **Manipulação de SO:** Integração com a biblioteca `os` para interação direta com o terminal do sistema operacional.

---

## Como rodar este projeto

**Pré-requisitos:** Python 3.10 ou superior instalado.

1. Vá até a pasta do projeto no terminal.
2. Execute o arquivo Python:
   ```bash
   python calculadora.py