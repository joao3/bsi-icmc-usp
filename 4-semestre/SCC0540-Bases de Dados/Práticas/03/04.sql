SELECT
    COUNT(j.classico),
    j.classico
FROM
         joga j
    JOIN partida p ON j.time1 = p.time1
                      AND j.time2 = p.time2
WHERE
    EXTRACT(MONTH FROM p.data) IN ( 1, 2 )
GROUP BY
    j.classico;