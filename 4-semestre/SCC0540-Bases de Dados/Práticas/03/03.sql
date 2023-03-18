SELECT
    t.nome,
    t.estado,
    d.nome
FROM
    time    t
    LEFT JOIN diretor d ON t.nome = d.time;