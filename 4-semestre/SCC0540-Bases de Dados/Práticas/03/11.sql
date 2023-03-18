SELECT
    t.nome,
    t.estado,
    t.saldo_gols
FROM
    time t
WHERE
    (
        SELECT
            MIN(saldo_gols)
        FROM
            time
        WHERE
            estado = t.estado
    ) = t.saldo_gols;