adicionaF([], X, [X]).
adicionaF([H|T], X, [H1|T1]) :- H1 is H, adicionaF(T, X, T1). 