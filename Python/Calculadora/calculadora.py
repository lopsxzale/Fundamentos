import os

# Loop eterno
while True:
    #'cls' para Windows, 'clear' para Linux/Mac
    os.system('cls' if os.name == 'nt' else 'clear') 

    print("-" * 40)
    print("Olá, seja bem vindo a calculadora do Alê!")
    print("-" * 40)

    # Tratamento de erro: Se o usuario digitar alguma letra, o programa nao quebra
    try:
        n1 = float(input("Digite o primeiro numero: "))
        n2 = float(input("Digite o segundo numero: "))
    except ValueError:
        print("❌ Erro: Por favor, digite apenas números válidos!")
        input("Pressione Enter para tentar novamente...")
        continue # Faz o while recomeçar

    print("-" * 40)
    print("Operações: (  +  |  -  |  * |  /  )")
    print("-" * 40)

    op = input("Qual operação deseja fazer? ")

    print("-" * 40)
    
    # Processamento com match-case (novo)
    match op:
        case '+':
            resultado = n1 + n2
            print(f"O resultado de {n1} + {n2} é: {resultado}")
        case '-':
            resultado = n1 - n2
            print(f"O resultado de {n1} - {n2} é: {resultado}")
        case '*':
            resultado = n1 * n2
            print(f"O resultado de {n1} * {n2} é: {resultado}")
        case '/':
            if n2 == 0:
                print("Erro! Não é possível dividir um número por zero!")
            else:
                resultado = n1 / n2
                print(f"O resultado de {n1} / {n2} é: {resultado}")
        case _:
            print("Opção inválida! Tente novamente.")

    print("-" * 40)
    
    # Pergunta se o usuário quer continuar
    continuar = input("Deseja fazer outra operação? (S/N): ").strip().upper()
    if continuar == 'N':
        print("Obrigado por usar a calculadora. Até mais!")
        break