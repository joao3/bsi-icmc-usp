count([], 0).
count([_|T], X) :- count(T, X1), X is X1 + 1.