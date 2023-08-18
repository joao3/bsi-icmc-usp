-- Trigger itens A, B e C
CREATE OR REPLACE FUNCTION AtualizaContagem() RETURNS TRIGGER AS $$
	DECLARE
		Contagem_Anterior Results_Status.Contagem%TYPE;
		Contagem_Atual Results_Status.Contagem%TYPE;
	BEGIN
		CASE TG_OP
			WHEN 'INSERT' THEN
				UPDATE Results_Status
					SET Contagem = Contagem + 1
					WHERE StatusID = NEW.StatusID;
				SELECT Contagem INTO Contagem_Atual from Results_Status WHERE StatusID = NEW.StatusID;
				RAISE NOTICE 'StatusID: %, Contagem: %.', NEW.StatusID, Contagem_Atual;
			
			WHEN 'DELETE' THEN
				UPDATE Results_Status
					SET Contagem = Contagem - 1
					WHERE StatusID = OLD.StatusID;
				SELECT Contagem INTO Contagem_Atual from Results_Status WHERE StatusID = OLD.StatusID;
				RAISE NOTICE 'StatusID: %, Contagem: %.', OLD.StatusID, Contagem_Atual;
			
			WHEN 'UPDATE' THEN
				UPDATE Results_Status
					SET Contagem = Contagem - 1
					WHERE StatusID = OLD.StatusID;
				SELECT Contagem INTO Contagem_Anterior from Results_Status WHERE StatusID = OLD.StatusID;
				RAISE NOTICE 'StatusID Anterior: %, Contagem: %.', OLD.StatusID, Contagem_Anterior;
				
				UPDATE Results_Status
					SET Contagem = Contagem + 1
					WHERE StatusID = NEW.StatusID;
				SELECT Contagem INTO Contagem_Atual from Results_Status WHERE StatusID = NEW.StatusID;
				
				RAISE NOTICE 'StatusID Atual: %, Contagem: %.', NEW.StatusID, Contagem_Atual;

		END CASE;
		
	RETURN NEW;
	
	END; $$ LANGUAGE plpgsql;
	
CREATE OR REPLACE TRIGGER TR_ResultsStatus AFTER INSERT OR UPDATE OF StatusID OR DELETE ON Results
	FOR EACH ROW
	EXECUTE FUNCTION AtualizaContagem();

-- Teste item A
INSERT INTO Results VALUES(3333333, 18, 1, 1, 22, 1, 1, '1', 1, 10, 58, '1:34:50.616', 5690616, 39, 2, '1:27.452', '218.300', 1);

-- Teste item B
DELETE FROM Results WHERE resultid = 3333333;

-- Teste item C (faz o insert primeiro para poder dar o update)
INSERT INTO Results VALUES(3333333, 18, 1, 1, 22, 1, 1, '1', 1, 10, 58, '1:34:50.616', 5690616, 39, 2, '1:27.452', '218.300', 1);
UPDATE RESULTS SET STATUSID = 2 WHERE RESULTID = 3333333;

-- Trigger item D
CREATE OR REPLACE FUNCTION VerificaStatus() RETURNS TRIGGER AS $$
	BEGIN
		RAISE EXCEPTION 'StatusID Negativo! Operação cancelada.';

	END; $$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER TR_Results BEFORE INSERT OR UPDATE OF StatusID ON RESULTS
	FOR EACH ROW
	WHEN (NEW.StatusID < 0)
	EXECUTE FUNCTION VerificaStatus();

-- Teste item D
INSERT INTO Results VALUES(3333333, 18, 1, 1, 22, 1, 1, '1', 1, 10, 58, '1:34:50.616', 5690616, 39, 2, '1:27.452', '218.300', -1);
UPDATE Results SET StatusID = -5 WHERE ResultID = 1;
