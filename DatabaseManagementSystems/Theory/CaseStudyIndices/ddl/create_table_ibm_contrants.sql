drop table ibm_contracts;

create table ibm_contracts
(
Transaction varchar2(255) primary key,
AwardID varchar2 (255),
OrderNumber varchar2(255),
DUNS varchar2(9),
Recipient varchar2(255),
RecipientCity varchar2(255),
RecipientState varchar2(255),
RecipientCD varchar2(255),
RecipientCountry varchar2(255),
PopState varchar2(255),
PopCD varchar2(255),
PopCountry varchar2(255),
AwardAmount number(20,2),
AwardDate date,
AwardType varchar2(255),
AwardingAgency varchar2(255),
AwardingBureau varchar2(255),
FundingAgency varchar2(255),
FundingBureau varchar2(255),
CFDACode varchar2(255),
CFDATitle varchar2(255),
FiscalYear number(4),
Role varchar2(255)
);

exit;
