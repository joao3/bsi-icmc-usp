INSERT INTO equipe VALUES('PALMEIRAS', 'SP', 'PROFISSINAL', 40);
INSERT INTO equipe VALUES('PALMEIRAS', 'SP', 'PROFISSIONAL', 40);

INSERT INTO equipe VALUES('VASCO', 'JJ', 'PROFISSIONAL', 23);
INSERT INTO equipe VALUES('VASCO', 'RJ', 'PROFISSIONAL', 23);

INSERT INTO jogador VALUES ('400.560.298-61', '20002013', 'RONY', TO_DATE('2003/10/03', 'YYYY/MM/DD'), 'SAO PAULO', 'SANTOS');
INSERT INTO jogador VALUES ('400.560.298-61', '20002013', 'RONY', TO_DATE('2003/10/03', 'YYYY/MM/DD'), 'SAO PAULO', 'PALMEIRAS');

INSERT INTO jogador VALUES ('400.560.298-61', '20002013', 'NENE', TO_DATE('1950/10/03', 'YYYY/MM/DD'), 'RIO DE JANEIRO', 'VASCO');
INSERT INTO jogador VALUES ('420.560.298-61', '20042013', 'NENE', TO_DATE('1950/10/03', 'YYYY/MM/DD'), 'RIO DE JANEIRO', 'VASCO');

INSERT INTO joga VALUES ('PALMEIRAS', 'FLAMENGO', 1);
INSERT INTO joga VALUES ('PALMEIRAS', 'VASCO', 1);

insert into partida values ('PALMEIRAS', 'VASCO', TO_DATE('2003/10/03', 'YYYY/MM/DD'), 'SAO PAULO', 'X0');
insert into partida values ('PALMEIRAS', 'VASCO', TO_DATE('2003/10/03', 'YYYY/MM/DD'), 'SAO PAULO', '3X0');

INSERT INTO posicao_jogador VALUES ('400.560.298-69', 'ATAQUE');
INSERT INTO posicao_jogador VALUES ('400.560.298-61', 'ATAQUE');

INSERT INTO diretor VALUES ('GREMIO', 'LEILA');
INSERT INTO diretor VALUES ('PALMEIRAS', 'LEILA');

INSERT INTO uniforme VALUES ('SAO PAULO', 'DOIS', 'VERDE');
INSERT INTO uniforme VALUES ('PALMEIRAS', 'DOIS', 'VERDE');
INSERT INTO uniforme VALUES ('PALMEIRAS', 'TITULAR', 'VERDE');

UPDATE equipe SET saldo_gols = 35 WHERE nome = 'VASCO';

DELETE FROM equipe WHERE estado = 'SP';




