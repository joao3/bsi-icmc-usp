SELECT
    t.estado,
    t.tipo,
    COUNT(*),
    AVG(t.saldo_gols)
FROM
    time t
GROUP BY
    t.estado,
    t.tipo
ORDER BY
    t.estado,
    t.tipo;