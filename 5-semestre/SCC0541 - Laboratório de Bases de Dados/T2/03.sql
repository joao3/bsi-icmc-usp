SELECT A.Continent, A.Type, COUNT(A.TYPE)
FROM AIRPORTS A
GROUP BY A.CONTINENT,
	A.TYPE ORDER BY A.CONTINENT, A.TYPE;

-- Order by não foi exigido, foi colocado para melhorar a visualização