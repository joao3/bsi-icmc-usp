sum([], Z) :- Z is 0.
sum([H|T], Z) :- sum(T, Y), Z is H + Y.