SELECT
    t.nome
FROM
    time t
WHERE
    NOT EXISTS (
        (
            SELECT DISTINCT
                local
            FROM
                partida
            WHERE
                time1 = 'SANTOS'
                OR time2 = 'SANTOS'
                AND local IS NOT NULL
        )
        MINUS
        (
            SELECT DISTINCT
                p.local
            FROM
                partida p
            WHERE
                t.nome = p.time1
                OR t.nome = p.time2
        )
    )
        AND t.estado = 'SP'
        AND t.nome <> 'SANTOS';