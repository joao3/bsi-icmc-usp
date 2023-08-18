-- Consulta
SELECT Name, Lat, Long, Population FROM Geocities15k WHERE Country = 'BR' AND Name LIKE 'São%';

-- Plano de consulta
EXPLAIN ANALYZE SELECT Name, Lat, Long, Population FROM Geocities15k WHERE Country = 'BR' AND Name LIKE 'São%';

-- Função de testes
CREATE OR REPLACE FUNCTION Mede_Tempo(Q TEXT)
	RETURNS TABLE (Name TEXT, Lat NUMERIC, Long Numeric, Population BIGINT) AS $$
	DECLARE
		TIni TIME; TFim TIME;
		i DOUBLE PRECISION;
		Diff DOUBLE PRECISION;
	BEGIN
		-- Registra o tempo inicial
		TIni := CLOCK_TIMESTAMP();
		FOR i IN 0..100 LOOP
			EXECUTE Q;
		END LOOP;
		-- Registra o tempo final
		TFim := CLOCK_TIMESTAMP();
		-- Calcula a diferenca em milisegundos
		Diff := ((EXTRACT(EPOCH FROM TFim) -
						EXTRACT(EPOCH FROM TIni) )/10);
		RAISE NOTICE '% - % := %', TFim , TIni , Diff;
		-- Retorna o resultado da consulta recebida
		RETURN QUERY EXECUTE Q;
	END;
$$ LANGUAGE plpgsql;

-- Executando a função de teste com a consulta
SELECT Mede_Tempo('SELECT Name, Lat, Long, Population FROM Geocities15k WHERE Country = ''BR'' AND Name LIKE ''São%'';');

-- Índice btree
CREATE INDEX IdxNomeCidade ON Geocities15k USING BTREE (Name) INCLUDE (Lat, Long, Population)  WHERE (Country = 'BR');
