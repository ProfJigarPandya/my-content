--------------------------------------------------------
--  File created - Saturday-July-25-2015   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table SALES_ORDER
--------------------------------------------------------

  CREATE TABLE "JPANDYA"."SALES_ORDER" 
   (	"S_ORDER_NO" VARCHAR2(6 BYTE), 
	"S_ORDER_DATE" DATE, 
	"CLIENT_NO" VARCHAR2(25 BYTE), 
	"DELY_ADD" VARCHAR2(6 BYTE), 
	"SALESMAN_NO" VARCHAR2(6 BYTE), 
	"DELY_TYPE" CHAR(1 BYTE) DEFAULT 'f', 
	"BILLED_YN" CHAR(1 BYTE), 
	"DELY_DATE" DATE, 
	"ORDER_STATUS" VARCHAR2(25 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
REM INSERTING into JPANDYA.SALES_ORDER
SET DEFINE OFF;
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('019001',to_date('12-JAN-96','DD-MON-RR'),'0001',null,'500001','f','N',to_date('20-JAN-96','DD-MON-RR'),'backorder');
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('019002',to_date('25-JAN-96','DD-MON-RR'),'0002',null,'500002','p','N',to_date('27-JAN-96','DD-MON-RR'),'fullfilled');
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('016865',to_date('18-FEB-96','DD-MON-RR'),'0003',null,'500003','f','Y',to_date('20-FEB-96','DD-MON-RR'),'fullfilled');
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('019003',to_date('03-APR-96','DD-MON-RR'),'0001',null,'500001','f','Y',to_date('07-APR-96','DD-MON-RR'),'fullfilled');
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('046866',to_date('20-MAY-96','DD-MON-RR'),'0004',null,'500004','p','N',to_date('22-MAY-96','DD-MON-RR'),'cancelled');
Insert into JPANDYA.SALES_ORDER (S_ORDER_NO,S_ORDER_DATE,CLIENT_NO,DELY_ADD,SALESMAN_NO,DELY_TYPE,BILLED_YN,DELY_DATE,ORDER_STATUS) values ('010008',to_date('24-MAY-96','DD-MON-RR'),'0005',null,'500004','f','N',to_date('26-MAY-96','DD-MON-RR'),'backorder');
--------------------------------------------------------
--  DDL for Index SYS_C007760
--------------------------------------------------------

  CREATE UNIQUE INDEX "JPANDYA"."SYS_C007760" ON "JPANDYA"."SALES_ORDER" ("S_ORDER_NO") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  Constraints for Table SALES_ORDER
--------------------------------------------------------

  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD PRIMARY KEY ("S_ORDER_NO")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD CHECK (dely_date>=s_order_date) ENABLE;
  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD CHECK (order_status in ('inprocess','fullfilled','backorder','cancelled')) ENABLE;
  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD CHECK (dely_type in ('p','f')) ENABLE;
  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD CHECK (s_order_no like '0%') ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SALES_ORDER
--------------------------------------------------------

  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD FOREIGN KEY ("CLIENT_NO")
	  REFERENCES "JPANDYA"."CLIENT_MASTER" ("CLIENT_NO") ENABLE;
  ALTER TABLE "JPANDYA"."SALES_ORDER" ADD FOREIGN KEY ("SALESMAN_NO")
	  REFERENCES "JPANDYA"."SALESMAN_MASTER" ("SALESMAN_NO") ENABLE;
