fat(0, 1).
fat(X, Y) :- X1 is X - 1, fat(X1, Z), Y is X * Z.