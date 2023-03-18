SELECT
    p.time1,
    p.time2,
    p.data
FROM
         partida p
    JOIN time t1 ON p.time1 = t1.nome
    JOIN time t2 ON p.time2 = t2.nome
WHERE
    t1.estado = 'SP'
    OR t2.estado = 'SP';