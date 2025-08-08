declare
	  totalatt number(7,4);
	  ps26 number(6,4);--priori probability for salary class=26k-30k
	  ps31 number(6,4);--priori probability for salary class=31k-35k
	  ps36 number(6,4);--priori probability for salary class=36k-40k
	  ps41 number(6,4);--priori probability for salary class=41k-45k
	  ps46 number(6,4);--priori probability for salary class=46k-50k
	  ps66 number(6,4);--priori probability for salary class=66k-70k
	  x26 number(6,4);--probability of class being of salary 26k given other attributes 
	  x31 number(6,4);-- prob    of class 31k given other attributes 
	  x36 number(6,4);-- prob  of class 36k 
	  x41 number(6,4);-- prob of class 41 k
	  x46 number(6,4);-- prob of class 46 k
	  x66 number(6,4);--prob of class 66 k given other attributes
	  in_dept_name varchar2(20);--user defined variables to be used for predicting class label
	  in_status varchar2(20);
	  in_age number(2);
	  ddd number(6,4);--probability of dept=in_dept  where salary is xxxx
	  sss number(6,4);--probability of status given by user where salary is xxx
	  aaa number(6,4);--prob of age given by user where salary is xxx
	  max_pr number(6,4);--stores  maximum of all prob found
	  class_pr number(20);--the class with max prob giving the result class label 
begin
        --calculate no of tuples with salarya range

	select sum(count) into ps26 from book where salary = 26000;
	select sum(count) into ps31 from book where salary = 31000;
	select sum(count) into ps36 from book where salary = 36000;
	select sum(count) into ps41 from book where salary = 41000;
	select sum(count) into ps46 from book where salary = 46000;
	select sum(count) into ps66 from book where salary = 66000;

	-- calcualate all tuples
	select sum(count) into totalatt from book;

	max_pr:=0.0;
	class_pr:= -99; 
	
	--initialize input

	in_dept_name:=&in_dept_name;
	in_status:= &in_status;
	in_age:=&in_age;

	--for 26 salary range

	select sum(count) into ddd from book where dept_name = in_dept_name and salary=26000;
	
        
        if ddd is null then
             ddd:= 0;
	end if;
	ddd:= ddd / ps26;

	select sum(count) into sss from book where status = in_status and salary=26000;

	if sss is null then
	   sss:= 0;
	end if;

	sss:= sss / ps26;


	select sum(count) into aaa from book where age = in_age and salary=26000;
        if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps26;

	ps26:= ps26 / totalatt;
	dbms_output.put_line('ps26 '||ps26);
	x26 := ps26 * ddd * sss * aaa;
       if (x26>max_pr) then 
		max_pr:=x26;
		class_pr:=26;		
	end if;	



	--for 31 salary range
	select sum(count) into ddd from book where dept_name = in_dept_name and salary=31000;
	if ddd is null then
             ddd:= 0;
	end if;

	ddd:= ddd / ps31;
	select sum(count) into sss from book where status = in_status and salary=31000;
	if sss is null then
             sss:= 0;
	end if;

	sss:= sss / ps31;
	select sum(count) into aaa from book where age = in_age and salary=31000;
	if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps31;
	ps31:= ps31 / totalatt;
	x31 := ps31 * ddd * sss * aaa;
if (x31>max_pr)
	then max_pr:=x31;
              class_pr:=31;
	end if;	

	--for 36 salary range
	select sum(count) into ddd from book where dept_name = in_dept_name and salary=36000;
	if ddd is null then
             ddd:= 0;
	end if;

	ddd:= ddd / ps36;
	select sum(count) into sss from book where status = in_status and salary=36000;
	if sss is null then
             sss:= 0;
	end if;

	sss:= sss / ps36;
	select sum(count) into aaa from book where age = in_age and salary=36000;
	if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps36;
	ps36:= ps36 / totalatt;
	x36 := ps36 * ddd * sss * aaa;
  if (x36>max_pr)
	then max_pr:=x36;
              class_pr:=36;
	end if;	

	--for 41 salary range
	select sum(count) into ddd from book where dept_name = in_dept_name and salary=41000;
	if ddd is null then
             ddd:= 0;
	end if;

	ddd:= ddd / ps41;
	select sum(count) into sss from book where status = in_status and salary=41000;
	if sss is null then
             sss:= 0;
	end if;

	sss:= sss / ps41;

	select sum(count) into aaa from book where age = in_age and salary=41000;
	if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps41;
	ps41:= ps41 / totalatt;
	x41 := ps41 * ddd * sss * aaa;
if (x41>max_pr)
	then max_pr:=x41;
	class_pr:=41;
	end if;	



	--for 46 salary range
	select sum(count) into ddd from book where dept_name = in_dept_name and salary=46000;

	if ddd is null then
             ddd:= 0;
	end if;

	ddd:= ddd / ps46;

	
	select sum(count) into sss from book where status = in_status and salary=46000;
	if sss is null then
             sss:= 0;
	end if;



	sss:= sss / ps46;

	

	select sum(count) into aaa from book where age = in_age and salary=46000;

	if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps46;


	ps46:= ps46 / totalatt;


	x46 := ps46 * ddd * sss * aaa;
if (x46>max_pr)
	then max_pr:=x46;
	class_pr:=46;
	end if;	



	--for 66 salary range
	select sum(count) into ddd from book where dept_name = in_dept_name and salary=66000;
if ddd is null then
             ddd:= 0;
	end if;

	ddd:= ddd / ps66;
	select sum(count) into sss from book where status = in_status and salary=66000;
if sss is null then
             sss:= 0;
	end if;

	sss:= sss / ps66;

	select sum(count) into aaa from book where age = in_age and salary=66000;
if aaa is null then
             aaa:= 0;
	end if;

	aaa:= aaa / ps66;
	ps66:= ps66 / totalatt;
	x66 := ps66 * ddd * sss * aaa;
if (x66>max_pr)
	then max_pr:=x66;
	class_pr:=66;
	end if;	

	dbms_output.put_line('sal 26-->'||x26);
	dbms_output.put_line('sal 31-->'||x31);
	dbms_output.put_line('sal 36-->'||x36);
	dbms_output.put_line('sal 41-->   '||x41);
	dbms_output.put_line('sal 46--> '||x46);
	dbms_output.put_line('sal 66-->'||x66);
        dbms_output.put_line('max probability is  -->'||max_pr);
	dbms_output.put_line('the sample is dept=' ||in_dept_name||' status= '||in_status||'  age = '||in_age ||'  is predicted to fall under the class salary =  '||class_pr);  
end;
/
