homem(barb).
homem(jay).
homem(frank).
homem(bo).
homem(cameron).
homem(mitchel).
homem(joe).
homem(manny).
homem(phil).
homem(calhoun).
homem(rexford).
homem(dylan).
homem(alex).
homem(luke).
homem(george).
homem(javier).

mulher(merle).
mulher(gloria).
mulher(dede).
mulher(grace).
mulher(pameron).
mulher(claire).
mulher(lily).
mulher(haley).
mulher(poppy).

genitor(barb, pameron).
genitor(merle, pameron).
genitor(barb, cameron).
genitor(merle, cameron).

genitor(javier, manny).
genitor(gloria, manny).

genitor(gloria, joe).
genitor(jay, joe).

genitor(jay, mitchel).
genitor(dede, mitchel).
genitor(jay, claire).
genitor(dede, claire).

genitor(grace, phil).
genitor(frank, phil).

genitor(bo, calhoun).
genitor(pameron, calhoun).

genitor(cameron, lily).
genitor(mitchel, lily).

genitor(cameron, rexford).
genitor(mitchel, rexford).

genitor(claire, haley).
genitor(phil, haley).
genitor(claire, alex).
genitor(phil, alex).
genitor(claire, luke).
genitor(phil, luke).

genitor(dylan, george).
genitor(haley, george).
genitor(dylan, poppy).
genitor(haley, poppy).



mae(X, Y) :- mulher(X), genitor(X, Y).

pai(X, Y) :- homem(X), genitor(X, Y).

pais(X, Y, Z) :- genitor(X, Z), genitor(Y, Z), X \= Y.

irmaos(X, Y) :- genitor(Z, X), genitor(Z, Y), X \= Y.

tio_tia(X, Y) :- genitor(Z, Y), irmaos(Z, X).

avo(X, Y) :- genitor(Z, Y), genitor(X, Z).

avo_materna(X, Y) :- mae(Z, Y), mae(X, Z).

primos(X, Y) :- genitor(Z, X), genitor(W, Y), irmaos(Z, W).

ancestral(X, Y) :- genitor(X, Y); genitor(Z, Y), irmaos(Z, X); genitor(Z, Y), primos(Z, X).
ancestral(X, Y) :- genitor(Z, Y), ancestral(X, Z).