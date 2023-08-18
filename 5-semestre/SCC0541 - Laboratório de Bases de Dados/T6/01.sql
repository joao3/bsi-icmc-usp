-- Trigger
CREATE or REPLACE FUNCTION VerificaAeroporto() RETURNS TRIGGER AS 
  $$ BEGIN
  
  IF NEW.city IN (SELECT name FROM GEOCITIES15K) THEN
    RETURN NEW;
  END IF;
  
  RAISE EXCEPTION 'Cidade % não encontrada! Operação cancelada.', NEW.city;
END;

$$ LANGUAGE plpgsql;

CREATE or REPLACE TRIGGER TR_Airports 
    BEFORE INSERT OR UPDATE OF city ON AIRPORTS
	FOR EACH ROW
    EXECUTE FUNCTION VerificaAeroporto();

-- Teste insert
INSERT INTO
	airports (
    	ident,
    	type,
    	name,
    	latdeg,
    	longdeg,
    	elevft,
    	continent,
    	isocountry,
    	isoregion,
    	city,
    	scheduled_service,
    	gpscode,
    	iatacode,
    	localcode,
    	homelink,
    	wikipedialink,
    	keywords
	)
VALUES (
    	'0a22dsd',
    	'heliport',
    	'Total Rf Heliport',
    	40.07080078125,
    	-74.93360137939453,
    	'11',
    	NULL,
    	'US',
    	'US-PA',
    	'Invalid City',
    	'no',
    	'00A',
    	NULL,
    	'00A',
    	NULL,
    	NULL,
    	NULL
	);

UPDATE airports
SET
	city = 'Invalid City'
WHERE
	ident = '00A';
