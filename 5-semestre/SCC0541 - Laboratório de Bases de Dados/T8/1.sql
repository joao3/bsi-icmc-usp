-- Consulta
SELECT (Forename || ' ' || Surname), Nationality from Driver WHERE (Forename || ' ' || Surname) = 'Ayrton Senna';

-- Plano da consulta
EXPLAIN ANALYZE SELECT (Forename || ' ' || Surname), Nationality from Driver WHERE (Forename || ' ' || Surname) = 'Ayrton Senna';

-- Função de testes
CREATE OR REPLACE FUNCTION Mede_Tempo(Q TEXT)
	RETURNS TABLE (Name TEXT , Nationality TEXT) AS $$
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
SELECT Mede_Tempo('SELECT (Forename || '' '' || Surname), Nationality from Driver WHERE (Forename || '' '' || Surname) = ''Ayrton Senna'';');

-- Índice hash
CREATE INDEX IdxNomeExato ON Driver USING HASH ((Forename || ' ' || Surname));
