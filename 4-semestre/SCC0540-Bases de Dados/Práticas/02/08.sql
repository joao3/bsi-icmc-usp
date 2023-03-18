SELECT
    t.nome,
    u.cor_principal
FROM
         time t
    JOIN uniforme u ON t.nome = u.time
WHERE
        t.estado = 'MG'
    AND t.tipo = 'PROFISSIONAL'
    AND u.tipo = 'TITULAR';