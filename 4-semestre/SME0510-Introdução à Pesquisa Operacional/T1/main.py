import numpy as np
from texttable import Texttable

def simplex_l(c, A, b, B_l, return_base=False):

    m, n = A.shape

    # Calcula os índices das variáveis não básicas.
    N_l = [i for i in range(n) if i not in B_l]

    # Calcula a base
    B = A[:, B_l]
    # Resolve o sistema com a base inicial.
    x_B = np.linalg.solve(B, b)

    retval = {}

    while True:
        # Monta matriz só com as colunas das variáveis não básicas.
        N = A[:, N_l]

        # Custo das variáveis não básicas e básicas.
        c_N = c[N_l]
        c_B = c[B_l]

        # Resolve o sistema com a transposta da base e o vetor de custo das variáveis básicas.
        v = np.linalg.solve(B.T, c_B)
        #  Para cada variável não básica, calcula o valor do custo da mesma menos o produto matricial
        # entre o resultado do sistema acima e a submatriz de A somente com as colunas referentes as
        # variáveis não  básicas.
        z = c_N - v @ N

        # Pega o mínimo valor do vetor calculado acima.
        i = np.argmin(z)
        #  Se esse valor é maior ou igual que 0, achou um ponto ótimo, se não, continua para os próximos
        # passos com z[i] sendo uma variável a entrar na base

        if z[i] >= 0.0:
            if return_base:
                return B_l
            x = np.zeros((n, ))
            x[B_l] = x_B
            retval['status'] = 'Sucesso'
            retval['x'] = x
            return retval

        # Resolve o sistema com a base e a coluna relativa a variável achada acima.
        y = np.linalg.solve(B, N[:, i])

        #  Se o valor máximo do vetor obtido a partir da resolução do sistema acima é menor ou igual
        # que 0, o sistema pode ser melhorado indeterminadamente.
        if y[np.argmax(y)] <= 0:
            if return_base:
                return B_l
            x = np.zeros((n, ))
            x[B_l] = x_B
            d = np.zeros((n, ))
            d[B_l] = y
            d[N_l[i]] = 1.0
            retval['status'] = 'Ilimitado'
            retval['x'] = x
            retval['d'] = d
            return retval

        # Acha o índice da variável que irá sair da base.
        eps = float('inf')
        l = None
        for k in range(m):
            if y[k] > 0:
                if x_B[k] / y[k] < eps:
                    eps = x_B[k] / y[k]
                    l = k

        # Altera a base e continua para as próximas iterações.
        x_B = x_B - y * eps
        x_B[l] = eps
        tmp = B_l[l]
        B_l[l] = N_l[i]

        N_l[i] = tmp
        B = A[:, B_l]


def simplex(c, A, b):
    # Modifica a função objetivo, para que somente as variáveis artificiais que serão inseridas, tenham peso.
    m, n = A.shape
    c_tilde = np.zeros((n + m, ))
    c_tilde[n:] = 1.0

    # Monta matriz quadrada com os valores das (des)igualdades na diagonal.
    I_tilde = np.zeros((m, m))
    I_tilde[range(m), range(m)] = b

    # Monta nova matriz A_tilde, concatenando a matriz anterior a matriz original A.
    A_tilde = np.empty((m, n + m))
    A_tilde[:, : n] = A
    A_tilde[:, n:] = I_tilde

    # Monta a lista com o índice as colunas que serão usadas como base no simplex, no caso, as colunas referentes as variáveis artificiais.
    B_l = list(range(n, n + m))

    # Chama o metódo simplex com o modedlo alterado, com o parâmetro para a função retornar a base.
    B_l = simplex_l(c_tilde, A_tilde, b, B_l, return_base=True)

    retval = {}
    # Se o maior índice das colunas da base retornada é maior ou igual que n, o modelo é inviável.
    if max(B_l) >= n:
        retval['status'] = 'Invabilidade detectada'
        return retval
    # Se não, achou uma base inicial e chama o simplex para resolver o modelo original.
    return simplex_l(c, A, b, B_l)

# Função objetiva, está com os valores negativos para transformar um problema de maximização em um de minimização. Os coeficientes nulos, correspondem as variáveis de folga.
c = np.array([
    -900, -850, -250, -650, -50, -50, -250, -180, -
    80, -200, -300, -600, -1000, -400, -350, -450,
    -550, -80, -150, -750, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
])

A = np.array([
    [24 , 25 , 12  , 20 , 4   , 3   , 4   , 3   , 2   , 3  , 6   , 8   , 10  , 30  , 10 , 10 , 10 , 5   , 8   , 25 , ],
    [4  , 5  , 1   , 3  , 0.25, 0.25, 0.15, 0.2 , 0.1 , 3  , 3   , 2   , 1   , 3   , 3  , 3  , 0.6, 0.2 , 3   , 2  , ],
    [8  , 8  , 0   , 0.5, 0.5 , 0   , 2   , 1   , 0.5 , 0  , 1   , 3   , 0   , 0   , 0  , 1  , 0  , 0.35, 3.5 , 2  , ],
    [0.2, 0.2, 0.1 , 0  , 0   , 0.1 , 0   , 0   , 0   , 0  , 0   , 0.2 , 0.1 , 0.2 , 0.2, 0.1, 0  , 0   , 0.1 , 0.1, ],
    [0.1, 0.1, 0.05, 0.1, 0.01, 0   , 0.5 , 0.01, 0.01, 0  , 0.01, 0.02, 0.01, 0.05, 0.1, 0.1, 0.7, 0.01, 0.02, 0.1, ],
    [0.5, 0  , 0.5 , 0  , 0   , 0   , 0   , 0   , 0.4 , 3.5, 3.5 , 0   , 1   , 0.2 , 0.7, 0.7, 0  , 0.1 , 0   , 0  , ],
    [0  , 0  , 0   , 4  , 0.25, 0.25, 0   , 0   , 0   , 0  , 0   , 0   , 0   , 0   , 0  , 0  , 0  , 0.2 , 0   , 0  , ],
    [0  , 0  , 20  , 0  , 0   , 6   , 0   , 0   , 0   , 5  , 0   , 0   , 2   , 5   , 3  , 0.1, 18 , 2   , 0   , 20 , ],
    [4  , 4  , 10  , 15 , 3   , 3   , 2   , 2   , 1.5 , 7  , 12  , 12  , 30  , 20  , 25 , 20 , 1  , 7   , 7   , 30 , ],
    [0  , 0  , 1   , 0  , 0   , 0.5 , 0   , 0   , 0   , 1  , 0   , 0   , 0.2 , 0.5 , 0.4, 0.2, 0.4, 0.1 , 2   , 3  , ],
    [0  , 0  , 0   , 0  , 0   , 0   , 50  , 0   , 100 , 0  , 100 , 100 , 0   , 100 , 0  , 100, 0  , 50  , 150 , 0  , ],
])

# Os valores positivos correspondem aos recursos disponíveis.
# Os valores negativos correspondem aos valores mínimos de produção de cada equipamento.
# As desigualdades de ">=" foram multiplicadas por -1. a >= b => -a <= -b.
b = np.array([
    70000,  # homens/hora/mes
    9000,  # capacidade de estoque
    40000,  # madeira MDF
    50000,  # plástico
    70000,  # parafusos / pregos / rebites (kg)
    30000,  # vidro temperado m²
    40000,  # tecido (m²)
    60000,  # aço (kg)
    100000,  # horas de máquina
    30000,  # Tinta (L)
    30000,  # cola (g)
    -40, # Armário MDF
    -40, # Guarda-Roupas
    -9 , # Fogão
    -5 , # Sofá
    -40, # Cadeira de Madeira
    -40, # Cadeira Aço
    -20, # Painel de TV
    -10, # Escrivaninha
    -30, # Gabinete
    -10, # Mesa de Aço
    -10, # Mesa de Madeira
    -10, # Cama de Madeira
    -30, # Mesa de Vidro
    -10, # Armário de Aço
    -20, # Janela de Aço
    -10, # Janela de Madeira
    -9 , # Estante de Aço
    -40, # Tábua e Passar Roupa
    -30, # Sapateira
    -7   # Cama de Aço
])

equipamento = [
    "Armário MDF", "Guarda-Roupas", "Fogão", "Sofá", "Cadeira de Madeira",
    "Cadeira Aço", "Painel de TV", "Escrivaninha", "Gabinete", "Mesa de Aço",
    "Mesa de Madeira", "Cama de Madeira", "Mesa de Vidro", "Armário de Aço",
    "Janela de Aço", "Janela de Madeira", "Estante de Aço",
    "Tábua e Passar Roupa", "Sapateira", "Cama de Aço"
]

m, n = A.shape

# Monta uma matriz com o lado esquerdo das restrições de mínimo de equipamento, que será adicionada na matriz A.
# A matriz que será adicionada é preenchida com -1 na diagonal. Para representar a desigualdade de ">=".
min_values = np.zeros((n, n))
np.fill_diagonal(min_values, -1)

# Monta matriz identidade referente as variáveis de folga, será adicionada na matriz A.
slack_variables = np.zeros((m+n, m+n))
np.fill_diagonal(slack_variables, 1)

# Junta as matrizes.
A = np.concatenate((A, min_values), axis=0)
A = np.concatenate((A, slack_variables), axis=1)

# Calcula e imprime a solução.
resultado = simplex(c, A, b)

print(resultado['status'])

x = resultado['x']

itens_produzidos_table = Texttable()
itens_produzidos_table.add_row(["item", "quantidade"])

index = 0

for value in x[:n]:
    itens_produzidos_table.add_row([equipamento[index], "{:.0f}".format(value)])
    index += 1

itens_produzidos_table.set_cols_align(['r', 'l'])
print(itens_produzidos_table.draw())

index = 0
soma_total = 0

for value in x[:n]:
    soma_total += float(round(value) * (c[index] * -1))
    index += 1

print("Lucro total: R$ {:.2f}".format(soma_total))