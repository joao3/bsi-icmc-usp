SELECT
    jg.nome,
    jg.data_nasc,
    jg.time,
    p.data,
    p.local,
    j.classico
FROM
         partida p
    JOIN joga    j ON p.time1 = j.time1
                   AND p.time2 = j.time2
    JOIN jogador jg ON jg.time = p.time1
                       OR jg.time = p.time2