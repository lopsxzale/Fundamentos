import os

mensagens = []

nome = input("Digite seu nome: ")

while True:

    # Limpa o terminal (Windows e MacOs/Linux)
    os.system('cls' if os.name == 'nt' else 'clear')

    if len(mensagens) > 0:
        for m in mensagens:
            print(m['nome'], "-", m['texto'])

    print("_______________")

    # Pega o texto do usuario
    texto = input("mensagem: ")
    
    if texto == "fim":
        break

    # Vai adicionando as mensagens na lista
    mensagens.append({
        "nome": nome,
        "texto": texto
    })