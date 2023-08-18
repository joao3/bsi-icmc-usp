-- Seguindo a dica do enunciado, foi feito um comando para contar as cidades e um para contar os aeroportos.

-- O select mais interno serve para achar o código de todos os países que sediam pelo menos um circuito. 
-- É necessário pois na tabela de circuitos tem o nome inteiro do pais, já as outras tabelas trabalham com a sigla (Ex: BR).

-- Após achar os códigos dos países, é feita a junção com a tabela de cidades, para realizar a contagem.
SELECT COUN_R.CODE,
	COUNT(GC.GEONAMEID) AS NRO_CIDADES
FROM GEOCITIES15K GC
JOIN
	(SELECT DISTINCT CODE
		FROM COUNTRIES CO
		JOIN CIRCUITS CI ON CO.NAME = CI.COUNTRY) AS COUN_R ON GC.COUNTRY = COUN_R.CODE
GROUP BY COUN_R.CODE;

-- Após achar os códigos dos países, é feita a junção com a tabela de aeroportos, para realizar a contagem.
SELECT COUN_R.CODE,
	COUNT(AIR.IDENT) AS NRO_AEROPORTOS
FROM AIRPORTS AIR
JOIN
	(SELECT DISTINCT CODE
		FROM COUNTRIES CO
		JOIN CIRCUITS CI ON CO.NAME = CI.COUNTRY) AS COUN_R ON AIR.ISOCOUNTRY = COUN_R.CODE
GROUP BY COUN_R.CODE;