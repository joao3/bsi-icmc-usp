SELECT
    *
FROM
    jogador,
    time;

SELECT
    j.cpf,
    j.nome,
    ( ( sysdate - j.data_nasc ) / 365 ),
    t.nome,
    t.estado
FROM
         jogador j
    JOIN time t ON j.time = t.nome;