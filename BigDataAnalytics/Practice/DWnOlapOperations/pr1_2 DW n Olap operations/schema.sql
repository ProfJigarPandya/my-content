create table JD_Branch_ADM (Branch_Id integer not null,Branch_Category varchar2(15),Branch_Stream varchar2(20),
PRIMARY KEY(Branch_Id));
create table JD_Fellow_ADM (Fellow_Id integer not null,Fellow_Gender char,Fellow_Category varchar2(5),
PRIMARY KEY(Fellow_Id));
create table JD_Period_ADM (Period_Id integer not null,Period_Year integer,Period_TYPE varchar2(5),
PRIMARY KEY(Period_Id));
create table JD_Board_ADM (Board_Id integer not null,Board_TYPE varchar2(5),PRIMARY KEY(Board_Id));


create table JF_ADM (
Branch_Id integer references JD_Branch_ADM,
Fellow_Id integer references JD_Fellow_ADM,
Period_Id integer references JD_Period_ADM,
Board_Id integer references JD_Board_ADM,
Fact_No_Adm integer,
Fact_Avg_Per integer,primary key (Branch_Id,Fellow_Id,Period_Id, Board_Id));



