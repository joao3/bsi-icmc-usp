count([], _, N) :- N is 0.
count([H|T], H, N) :- count(T, H, N1), N is 1 + N1.
count([H|T], X, N) :- H \= X, count(T, X, N).