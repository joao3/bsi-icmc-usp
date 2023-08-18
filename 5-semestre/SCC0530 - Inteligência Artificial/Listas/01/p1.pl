progenitor(sara, isaque).
progenitor(abraao, isaque).
progenitor(abraao, ismael).
progenitor(isaque, esau).
progenitor(isaque, jaco).
progenitor(jaco, jose).
gosta(joao, maria).
gosta(maria, lasanha).
gosta(maria, gato).
mulher(sara).
homem(abraao).
homem(isaque).
homem(ismael).
homem(esau).
homem(jaco).
homem(jose).

mae(X, Y) :- mulher(X), progenitor(X, Y).

irmaos(X, Y) :- progenitor(Z, X), progenitor(Z, Y), X \= Y.

avo(X, Y) :- progenitor(Z, Y), progenitor(X, Z).

antecedente(X, Y) :- progenitor(X, Y); progenitor(Z, Y), irmaos(Z, X); progenitor(Z, Y), antecedente(X, Z).

b(Lista) :- findall(X, gosta(maria, X), Lista).