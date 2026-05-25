# Sistema de Lembrete de Hidratação (Water Reminder)

Um script de automação desenvolvido em **Python** que roda em segundo plano e envia notificações nativas para o sistema operacional (Windows/Mac/Linux) lembrando o usuário de beber água em intervalos de tempo personalizáveis.

Aliás, é de suma importância estar sempre hidratado! Completamente normal esquercermos, e esse script resolve essa dor e mantém os usuários saudáveis.

---

## Funcionalidades

* **Intervalo Personalizável:** O usuário define de quantos em quantos minutos deseja receber o alerta através de uma interface interativa no terminal.
* **Notificações Nativas:** Integração direta com a interface do Sistema Operacional para exibir *pop-ups* visuais de alerta, sem a necessidade de manter a janela do terminal aberta na tela.
* **Saída Graciosa (Graceful Exit):** Suporte para interrupção limpa do programa via `Ctrl+C`, evitando rastros de erro no terminal.
* **Prevenção de Quebras:** Tratamento de entradas inválidas (`ValueError`) para garantir que o script não seja encerrado abruptamente por erros de digitação.

---

## Conceitos e Tecnologias Aplicadas

* **Integração com SO:** Uso da biblioteca externa `plyer` para enviar requisições à API de notificações do sistema operacional local.
* **Gerenciamento de Tempo:** Uso do módulo nativo `time` (`time.sleep`) para controle de execução em segundo plano (daemons).
* **Tratamento Avançado de Exceções:** * Captura de exceções de conversão de dados (`ValueError`).
  * Captura de sinais do teclado (`KeyboardInterrupt`) para manipulação de encerramento do script.
* **Estruturação Padrão Python:** Utilização da verificação `if __name__ == "__main__":` para isolar a execução do programa.

---

## Como rodar este projeto

**Pré-requisitos:** Python instalado e gerenciador de pacotes `pip`.

1. Clone o repositório ou baixe o arquivo do script.
2. Abra o terminal na pasta do projeto e instale a dependência externa executando:
   ```bash
   pip install plyer