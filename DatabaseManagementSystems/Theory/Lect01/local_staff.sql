SELECT * FROM ALL_TABLES;

select * from USER_TABLES ;

SELECT * FROM USER_INDEXES UI;

SELECT * FROM USER_CONSTRAINTS;

SELECT * FROM USER_VIEWS;

CREATE TABLE plants
    ( plant_id    NUMBER PRIMARY KEY, 
      common_name VARCHAR2(15) );

INSERT INTO plants VALUES (1, 'African Violet'); # DML statement

INSERT INTO plants VALUES (2, 'Amaryllis'); # DML statement

ALTER TABLE plants ADD 
    ( latin_name VARCHAR2(40) );

GRANT select ON plants TO jpandya;

REVOKE select ON plants FROM jpandya;

DROP TABLE plants;


