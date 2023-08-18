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


conectado(A,B,D) :- conectado1(A,B,[],D).

conectado1(A, B, _, D) :- aresta(A,B,D).
conectado1(A,B,V,D) :- aresta(A,C,D1), not(member(C,V)), conectado1(C,B,[C|V],D2), D is D1 + D2.
    

