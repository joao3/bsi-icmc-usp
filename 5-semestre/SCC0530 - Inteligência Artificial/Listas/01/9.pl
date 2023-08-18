append([], L2, L2).
append([C1|R1], L2, [C1|R]) :- append(R1, L2, R).