adicionaF([], X, [X]).
adicionaF([H|T], X, [H1|T1]) :- H1 is H, adicionaF(T, X, T1). 

inverte([], []).
inverte([H|T], L) :- inverte(T, L2), adicionaF(L2, H, L).

iguais([H|T], [H|T]).

palindromo(X) :- inverte(X, Y), iguais(X, Y).