SELECT
    t1.nome,
    t1.estado
FROM
         time t1
    JOIN uniforme u1 ON t1.nome = u1.time
WHERE
        u1.tipo = 'TITULAR'
    AND u1.cor_principal IS NULL;