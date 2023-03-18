SELECT
    p.time1,
    p.time2,
    p.data,
    p.placar,
    j.classico
FROM
         joga j
    JOIN partida p ON j.time1 = p.time1
                      AND j.time2 = p.time2
WHERE
    p.local = 'SANTOS';