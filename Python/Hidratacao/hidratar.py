import time
import os
from plyer import notification

def limpar_tela():
    # limpa o terminal no windows ou mac/linux
    os.system('cls' if os.name == 'nt' else 'clear')

def enviar_notificacao(tempo_minutos):
    # envia a notificação para o S.O.
        notification.notify(
        title = "💧 Lembrete de Hidratação",
        message = f"Já se passaram {tempo_minutos} minutos. Beba um copo d'água!",
        app_name = "Hidratação Automática",
        timeout = 10 # a notificação some após 10 segundos
    )

def main():
    limpar_tela()
    print("=" * 40)
    print("Sistema de Lembrete de Hidratação".center(40))
    print("=" * 40)

    # loop para garantir que o usuário digite um tempo válido
    while True:
        try:
            tempo = int(input("Deseja ser lembrado a cada quantos minutos?\n"))
            if tempo <= 0:
                print("Ai nao dá... Digite um valor maior que zero.")
                continue
            break
        except ValueError:
            print("Dá não... Digite apenas números inteiros.")

    print("-" * 40)
    print(f"Ok! Vou te avisar a cada {tempo} minutos.")
    print("Rodando em segundo plano... (Pressione Ctrl+C para encerrar)")
    print("-" * 40)

    # loop infinito que aguarda o tempo e envia a notificação
    try:
        while True:
            time.sleep(tempo * 60)
            enviar_notificacao(tempo)
    except KeyboardInterrupt:
        print("=" * 40)
        print("\n\nLembrete de hidratação encerrado. Até mais!\n".center(40))

# Padrão profissional para iniciar scripts em Python
if __name__ == "__main__":
    main()