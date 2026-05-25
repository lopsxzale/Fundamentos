# Simulador de Chat Local em Terminal (Python)

Um script interativo desenvolvido em **Python** que simula uma sala de bate-papo local por meio do console. O programa gerencia o fluxo de entrada de dados e renderiza o histórico de mensagens de forma dinâmica.

---

## Funcionalidades

* **Efeito de Linha do Tempo (Timeline):** Utiliza a limpeza sistemática do console (`os.system`) a cada nova mensagem enviada, criando uma experiência visual fluida que imita um feed de chat em tempo real.
* **Histórico Estruturado:** Armazena e exibe o nome do autor e o conteúdo da mensagem de forma organizada.
* **Comando de Saída:** Encerramento seguro do loop ao digitar a palavra-chave `fim`.

---

## Conceitos e Tecnologias Aplicadas

Este mini projeto demonstra o domínio de conceitos estruturais importantes no Python:

* **Matrizes Dinâmicas e Coleções (List of Dicts):** Uso de uma lista (`list`) para simular um banco de dados em memória, populada dinamicamente com objetos do tipo dicionário (`dict`) para associar chaves (`nome`, `texto`) aos seus respectivos valores.
* **Loops de Execução Contínua:** Controle de fluxo baseado em `while True` com interrupção condicionada por flag (`break`).
* **CLI UI (Interface de Linha de Comando):** Manipulação do estado do terminal usando o módulo nativo `os` para melhorar a experiência e a estética visual do usuário.

---

## Como rodar este projeto

**Pré-requisitos:** Python instalado na máquina (qualquer versão 3.x).

1. Navegue até a pasta do projeto no seu terminal.
2. Execute o script Python:
   ```bash
   python chat.py