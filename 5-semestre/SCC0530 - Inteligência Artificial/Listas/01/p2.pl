maior(X,Y,Z) :- X > Y, Z is X; Z is Y.

max([X], X).
max([H|T], X) :- max(T, X1), maior(X1, H, X).