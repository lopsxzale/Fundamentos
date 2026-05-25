# Nome do estabelecimento
nome_loja = "Mercado da Budega"

estoque = {
    "bola": 20.00,
    "luva": 15.00,
    "jaqueta": 39.90
}

# Mostra o Menu de itens para compra
def exibe_estoque(estoque):
    print("=" * 40)
    print("NOSSO MENU".center(40))
    print("-" * 40)

    for produto, preco in estoque.items():
        print(f"- {produto.capitalize()}: R$ {preco:.2f}")
    
    print("=" * 40)
    
def agradecimento():
    print("=" * 40)
    print("Agradecemos a preferência!".center(40))
    print("=" * 40)

carrinho = {}

print("=" * 40)
print(f"Bem vindo ao {nome_loja}".center(40))
print("=" * 40)

exibe_estoque(estoque)

while True:
    pedido = input("Qual item você deseja levar? (Ou digite 'Finalizar' para ir encerrar a compra').\n").lower()

    if pedido == 'finalizar':
        break

    if pedido in estoque:
        quantidade = int(input("Quantas unidades?\n"))
        if pedido in carrinho:
            carrinho[pedido] += quantidade
            print(f"{quantidade}x {pedido.capitalize()} adicionado ao carrinho.")
            print("-" *40)
        else:
            carrinho[pedido] = quantidade
            print(f"{quantidade}x {pedido.capitalize()} adicionado ao carrinho.")
            print("-" *40)
    else:
        print("Pedido inválido, esse produto nao existe!")

# Recibo
print("=" * 40)
print("NOTA FISCAL".center(40))
print("=" * 40)

total = 0

for item, qtd in carrinho.items():
    preco_unitario = estoque[item]
    subtotal = preco_unitario * qtd
    total += subtotal

    print(f"{qtd}x {item.capitalize()} - R$ {subtotal:.2f}".center(40))

print("=" * 40)
print(f"TOTAL DA COMPRA: R$ {total:.2f}".center(40))

agradecimento()