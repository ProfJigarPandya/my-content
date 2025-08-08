DECLARE
 TYPE cursor_type IS REF CURSOR;
 LOOP_COUNTER NUMBER:=1;
 NUMBER_OF_ITEMS NUMBER:=5;
 ii_CURSOR cursor_type;
 iii_CURSOR cursor_type;
 a NUMBER;
 B NUMBER;
 C NUMBER;
 VAL NUMBER;
 str char(5);
 query varchar2(100);
 total_transactions number;
 supportF float;
 VAL_A float;
 VAL_B float;
 val_AANDB float;
 CONFIDENCE_aTOB float;
 CONFIDENCE_BTOA float;
 Support float;
 minimum_support float;
 minimum_confidence float;
BEGIN
  --EXECUTE IMMEDIATE 'DROP TABLE I1';
  EXECUTE IMMEDIATE 'CREATE TABLE  I1 (ITEMID NUMBER)';
  LOOP 
	query:='INSERT INTO I1 VALUES ('||to_char(LOOP_COUNTER)||')';
	execute immediate query;
	LOOP_COUNTER:=LOOP_COUNTER+1;
	EXIT WHEN LOOP_COUNTER>NUMBER_OF_ITEMS;
  END LOOP;
    
  minimum_support:=&minimum_support;
 minimum_confidence:=&minimum_confidence;
    
  select count(*) into total_transactions from mytbl;
  LOOP_COUNTER:=1;
  LOOP
	--find occurances of item in mytbl
	str:='I'||to_char(LOOP_COUNTER);
	query:='select count(*) from mytbl where '||str||'='||1;
	execute immediate query into val;
	
	--find support
	support := (val / trunc(total_transactions,2));
	
	--remove items if having support less than minimum.
	IF support<minimum_support THEN 
		query:='delete I1 where itemid='||to_char(loop_counter);
		execute immediate query;
	ELSE 
		dbms_output.put_line(' the item is not removed. '||str);
	END IF;
	
	loop_counter:=loop_counter+1;
	exit when loop_counter>number_of_items;
  END LOOP;
	
  
  
  --Here somewhere a loop for all LLL should start...
  
  
  
  
  
  EXECUTE IMMEDIATE 'CREATE TABLE II(ITEMID1 NUMBER, ITEMID2 NUMBER)';
  EXECUTE IMMEDIATE 'INSERT INTO II(ITEMID1, ITEMID2) SELECT M1.ITEMID ITEMID1 , M2.ITEMID ITEMID2 FROM I1 M1, I1 M2 WHERE M1.ITEMID<>M2.ITEMID AND M1.ITEMID < M2.ITEMID ';
  --EXECUTE IMMEDIATE 'COMMIT';
  --COMMIT;
  open ii_CURSOR for 'select * FROM II';
  LOOP
        FETCH ii_CURSOR INTO a, b;
        EXIT WHEN ii_CURSOR%NOTFOUND;
        query:='select count(*) from mytbl where I'||to_char(a)||'=1 and I'||to_char(b)||'=1';
        execute immediate query into val;
        
        --find support
		support := (val / total_transactions);
	
		--remove items if having support less than minimum.
		IF support<minimum_support THEN 
			query:='delete ii where itemid1='||to_char(a)||' AND itemid2='||to_char(b);
			execute immediate query;
			dBMS_OUTPUT.PUT_LINE(' ITEM REMOVED.' ||A||' '||B);
		ELSE 
			dbms_output.put_line(' The items is not removed. '||a||' '||b);
		END IF;
   END LOOP;
    close ii_CURSOR; 
    
  
  
  
  EXECUTE IMMEDIATE 'SELECT COUNT(*) FROM II' INTO VAL;
  dBMS_OUTPUT.PUT_LINE(' NO. OF TUPLES IN II '||VAL);
  
  
  EXECUTE IMMEDIATE 'CREATE TABLE III(ITEMID1 NUMBER, ITEMID2 NUMBER, ITEMID3 NUMBER)';
  EXECUTE IMMEDIATE 'INSERT INTO III(ITEMID1, ITEMID2, ITEMID3) SELECT M1.ITEMID ITEMID1 , M2.ITEMID ITEMID2, M3.ITEMID ITEMID3 FROM I1 M1, I1 M2, I1 M3 WHERE (M1.ITEMID<M2.ITEMID) AND (M2.ITEMID < M3.ITEMID)';
  open iiI_CURSOR for 'select * FROM III';
  LOOP
        FETCH iiI_CURSOR INTO a, b, C ;
        EXIT WHEN iiI_CURSOR%NOTFOUND;
        query:='select count(*) from mytbl where I'||to_char(a)||'=1 and I'||to_char(b)||'=1 AND i'||TO_CHAR(C)||'=1';
        execute immediate query into val;
        
        --find support
		support := (val / total_transactions);
	
		--remove items if having support less than minimum.
		IF support<minimum_support THEN 
			query:='delete iiI where itemid1='||to_char(a)||' AND itemid2='||to_char(b)||'AND ITEMID3='||TO_CHAR(C);
			DBMS_OUTPUT.PUT_LINE(' ITEM REMOVED.' ||A||' '||B||' '||C);
			execute immediate query;
		ELSE 
			dbms_output.put_line(' The items is not removed. '||a||' '||b||' '||C);
		END IF;
   END LOOP;
    CLOSE III_CURSOR;
     --EXECUTE IMMEDIATE 'DROP TABLE III';
     
    EXECUTE IMMEDIATE 'SELECT COUNT(*) FROM III' INTO VAL;
    dBMS_OUTPUT.PUT_LINE(' NO. OF TUPLES IN III '||VAL);
    
    
   --ACCORDINT TO MIN CONFIDENCE DO DISPLAY FINAL RESULTS.
  open ii_CURSOR for 'select * FROM II';
  LOOP
        FETCH ii_CURSOR INTO a, b;
        EXIT WHEN ii_CURSOR%NOTFOUND;

        query:='select count(*) from mytbl where I'||to_char(a)||'=1' ;
        execute immediate query into val_A;
  
        query:='select count(*) from mytbl where I'||to_char(B)||'=1' ;
        execute immediate query into val_B;
        
        query:='select count(*) from mytbl where I'||to_char(a)||'=1 and I'||to_char(b)||'=1';
        execute immediate query into val_AANDB;
        
        SupportF:= trunc( VAL_AANDB / total_transactions,2 );
        
        --find CONFIDENCE
		CONFIDENCE_ATOB := trunc(VAL_AANDB  / VAL_A ,2);
		CONFIDENCE_BTOA := trunc(VAL_AANDB / VAL_B ,2);
		
		--display items if having confidence greater than minimum.
		IF CONFIDENCE_ATOB > minimum_confidence THEN 
			dBMS_OUTPUT.PUT_LINE('I'||A||' -> ' ||'I'||B||'   Support:'||SupportF||'   Confidence:'||confidence_atob);
			--dBMS_OUTPUT.PUT_LINE('I'||A||' -> ' ||'I'||B||'   Confidence:'||confidence_atob);
		ELSE 
			dbms_output.put_line('xxx');
		end if;
		
		IF CONFIDENCE_bTOa >= minimum_confidence THEN 
			dBMS_OUTPUT.PUT_LINE('I'||b||' -> ' ||'I'||a||'   Support:'||SupportF||'   Confidence:'||confidence_btoa);
			--dBMS_OUTPUT.PUT_LINE('I'||b||' -> ' ||'I'||a||'   Confidence:'||confidence_btoa);
		ELSE 
			dbms_output.put_line('xxx');
		
			
		END IF;
   END LOOP;
    close ii_CURSOR; 

	   

   
END;
/

