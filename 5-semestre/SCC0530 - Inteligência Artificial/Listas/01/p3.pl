aresta(a,b).
aresta(a,c).
aresta(a,d).
aresta(b,c).
aresta(b,a).
aresta(b,e).
aresta(c,a).
aresta(c,b).
aresta(c,d).
aresta(c,e).
aresta(d,a).
aresta(d,c).
aresta(d,e).
aresta(d,g).
aresta(d,f).
aresta(e,c).
aresta(e,b).
aresta(e,d).
aresta(e,f).
aresta(f,e).
aresta(f,d).
aresta(f,g).
aresta(g,d).
aresta(g,f).

append([], X, X).
append([H|T], X, [H|T1]) :- append(T, X, T1).

todos_filhos(A,R,L):-
    findall([X,A|R],
    (aresta(A,X),
    not(member(X,R))),L).

caminho1(O,D,Cam) :-
    caminho2([[O]],D,Cam).

caminho2([[D|C]|_],D,[D|C]).
caminho2([[A|R]|Outros],D,C):-
    todos_filhos(A,R,L),
    append(Outros,L,L1),
    caminho2(L1,D,C).