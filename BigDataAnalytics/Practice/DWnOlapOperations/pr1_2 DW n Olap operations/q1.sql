Select Fact_No_Adm, Fact_Avg_Per
from JD_Branch_ADM B,JD_Fellow_ADM F,JD_Period_ADM D,JF_ADM FACT 
where (
B.Branch_Id = FACT.Branch_Id and
F.Fellow_Id = FACT.Fellow_Id and
D.Period_Id = FACT.Period_Id and
F.Fellow_Gender = 'M' and
F.Fellow_Category = 'OPEN');
