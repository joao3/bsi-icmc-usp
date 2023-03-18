SELECT
    t.nome
FROM
    time t
WHERE
    t.nome NOT IN (
        SELECT
            t.nome
        FROM
                 partida p
            JOIN time t ON p.time1 = t.nome
                           OR p.time2 = t.nome
        WHERE
            p.local IN ( 'SAO CARLOS', 'BELO HORIZONTE' )
    );