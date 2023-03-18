SELECT
    j.time1,
    j.time2,
    COUNT(p.data)
FROM
    joga    j
    LEFT JOIN partida p ON j.time1 = p.time1
                           AND j.time2 = p.time2
WHERE
    j.classico = 'S'
GROUP BY
    j.time1,
    j.time2;