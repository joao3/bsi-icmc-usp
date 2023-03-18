SELECT
    t.nome,
    t.estado
FROM
         joga j
    JOIN time t ON j.time1 = t.nome
                   OR j.time2 = t.nome
WHERE
    j.classico = 'S';