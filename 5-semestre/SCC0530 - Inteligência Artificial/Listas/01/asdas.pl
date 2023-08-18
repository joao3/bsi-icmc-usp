aresta(a,b, 3).
aresta(a,c, 3).
aresta(a,d, 3).
aresta(b,c, 3).
aresta(b,a, 3).
aresta(b,e, 3).
aresta(c,a, 3).
aresta(c,b, 3).
aresta(c,d, 3).
aresta(c,e, 3).
aresta(d,a, 3).
aresta(d,c, 3).
aresta(d,e, 3).
aresta(d,g, 3).
aresta(d,f, 3).
aresta(e,c, 3).
aresta(e,b, 3).
aresta(e,d, 3).
aresta(e,f, 3).
aresta(f,e, 3).
aresta(f,d, 3).
aresta(f,g, 3).
aresta(g,d, 3).
aresta(g,f, 3).

append([], X, X).
append([H|T], X, [H|T1]) :- append(T, X, T1).

filhos(A, R, L) :-q
busca(O, D, C) :- busca2([[O]], D, C).

busca2([[D|R]|_], D, [D|R]).
busca2([[A|R]|Outros], D, C) :-
    filhos(A, R, L),
    append(L, Outros, L1),
    busca2(L1, D, C).

inverte([X], [X]).
inverte([H|T], L) :- inverte(T, L1), append(L1, H, L).