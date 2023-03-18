SELECT
    tf.nome
FROM
         time tf
    JOIN partida p ON p.time1 = tf.nome
                      OR p.time2 = tf.nome
WHERE
    tf.nome IN (
        SELECT
            t.nome
        FROM
                 partida p
            JOIN joga j ON p.time1 = j.time1
                           AND p.time2 = j.time2
            JOIN time t ON t.nome = p.time1
                           OR t.nome = p.time2
        WHERE
                j.classico = 'S'
            AND tf.tipo = 'PROFISSIONAL'
    )
    AND ( ( tf.nome = p.time1
            AND REGEXP_LIKE ( p.placar,
                              '^0+X' ) )
          OR ( tf.nome = p.time2
               AND REGEXP_LIKE ( p.placar,
                                 'X0+$' ) ) )
GROUP BY
    tf.nome
HAVING
    COUNT(*) > 1;



