CREATE TABLE equipe (
    nome       VARCHAR2(30) NOT NULL,
    estado     CHAR(2) DEFAULT NULL,
    tipo       VARCHAR2(12) NOT NULL,
    saldo_gols NUMBER DEFAULT 0,
    CONSTRAINT pk_equipe PRIMARY KEY ( nome ),
    CONSTRAINT ck_estado CHECK ( upper(estado) IN ( 'AC', 'AL', 'AM', 'AP', 'BA',
                                                    'CE', 'ES', 'GO', 'MA', 'MG',
                                                    'MS', 'MT', 'PA', 'PB', 'PE',
                                                    'PI', 'PR', 'RJ', 'RN', 'RO',
                                                    'RR', 'RS', 'SC', 'SE', 'SP',
                                                    'TO' ) ),
    CONSTRAINT ck_tipo CHECK ( upper(tipo) IN ( 'AMADOR', 'PROFISSIONAL' ) )
);

CREATE TABLE joga (
    equipe1  VARCHAR2(30) NOT NULL,
    equipe2  VARCHAR2(30) NOT NULL,
    classico NUMBER(1) NOT NULL,        /* 0 -> NÃO CLASSICO, 1 -> CLASSICO */

    CONSTRAINT pk_joga PRIMARY KEY ( equipe1,
                                     equipe2 ),
    CONSTRAINT fk2_joga FOREIGN KEY ( equipe2 )
        REFERENCES equipe ( nome )
            ON DELETE CASCADE,
    CONSTRAINT fk1_joga FOREIGN KEY ( equipe1 )
        REFERENCES equipe ( nome )
            ON DELETE CASCADE,
    CONSTRAINT ck_classico CHECK ( classico = 0
                                   OR classico = 1 )
);

CREATE TABLE partida (
    equipe1 VARCHAR2(30) NOT NULL,
    equipe2 VARCHAR2(30) NOT NULL,
    data    DATE NOT NULL,
    local   VARCHAR2(20) NOT NULL,
    placar  VARCHAR2(10) DEFAULT '0X0',
    CONSTRAINT pk_partida PRIMARY KEY ( equipe1,
                                        equipe2,
                                        data ),
    CONSTRAINT fk_partida FOREIGN KEY ( equipe1,
                                        equipe2 )
        REFERENCES joga ( equipe1,
                          equipe2 )
            ON DELETE CASCADE,
    CONSTRAINT ck_placar CHECK ( REGEXP_LIKE ( placar,
                                               '^[0-9]+X[0-9]+$' ) )
);

CREATE TABLE jogador (
    cpf          CHAR(14) NOT NULL,
    rg           CHAR(8) NOT NULL,
    nome         VARCHAR2(30) NOT NULL,
    data_nasc    DATE NOT NULL,
    naturalidade VARCHAR2(15) NOT NULL,
    equipe       VARCHAR2(30) NOT NULL,
    CONSTRAINT pk_jogador PRIMARY KEY ( cpf ),
    CONSTRAINT fk_jogador FOREIGN KEY ( equipe )
        REFERENCES equipe ( nome )
            ON DELETE SET NULL,
    CONSTRAINT k_jogador UNIQUE ( rg,
                                  nome )
);

CREATE TABLE posicao_jogador (
    jogador CHAR(14) NOT NULL,
    posicao VARCHAR2(10) NOT NULL,
    CONSTRAINT pk_posicao_jogador PRIMARY KEY ( jogador,
                                                posicao ),
    CONSTRAINT fk_posicao_jogador FOREIGN KEY ( jogador )
        REFERENCES jogador ( cpf )
            ON DELETE CASCADE
);

CREATE TABLE diretor (
    equipe VARCHAR2(30) NOT NULL,
    nome   VARCHAR2(30) NOT NULL,
    CONSTRAINT pk_diretor PRIMARY KEY ( equipe,
                                        nome ),
    CONSTRAINT fk_diretor FOREIGN KEY ( equipe )
        REFERENCES equipe ( nome )
            ON DELETE CASCADE
);

CREATE TABLE uniforme (
    equipe        VARCHAR2(30) NOT NULL,
    tipo          CHAR(7) NOT NULL,
    cor_principal VARCHAR2(15) NOT NULL,
    CONSTRAINT pk_uniforme PRIMARY KEY ( equipe,
                                         tipo ),
    CONSTRAINT fk_uniforme FOREIGN KEY ( equipe )
        REFERENCES equipe ( nome )
            ON DELETE CASCADE,
    CONSTRAINT ck_tipo_uniforme CHECK ( upper(tipo) IN ( 'TITULAR', 'RESERVA' ) )
);