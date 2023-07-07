Select sum(Fact_No_Adm)
from JD_Branch_ADM B,JD_Fellow_ADM F,JD_Period_ADM D,JF_ADM FACT 
where
B.Branch_Id = FACT.Branch_Id and
F.Fellow_Id = FACT.Fellow_Id and
D.Period_Id = FACT.Period_Id and 
B.Branch_Category = 'ENG'
group by B.Branch_Category;
