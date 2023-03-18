SELECT
    t.nome,
    COUNT(t.nome),
    EXTRACT(YEAR FROM p.data)
FROM
         partida p
    JOIN joga j ON p.time1 = j.time1
                   AND p.time2 = j.time2
    JOIN time t ON p.time1 = t.nome
                   OR p.time2 = t.nome
WHERE
    j.classico = 'S'
GROUP BY
    EXTRACT(YEAR FROM p.data),
    t.nome;