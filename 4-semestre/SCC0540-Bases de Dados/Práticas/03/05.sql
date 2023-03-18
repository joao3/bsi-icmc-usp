SELECT
    COUNT(j.classico),
    EXTRACT(MONTH FROM p.data)
FROM
         joga j
    JOIN partida p ON j.time1 = p.time1
                      AND j.time2 = p.time2
WHERE
        EXTRACT(YEAR FROM p.data) = 2018
    AND j.classico = 'S'
GROUP BY
    EXTRACT(MONTH FROM p.data);