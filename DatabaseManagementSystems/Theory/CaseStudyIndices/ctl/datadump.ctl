LOAD DATA
INTO TABLE ibm_contracts
FIELDS TERMINATED BY ","
OPTIONALLY ENCLOSED BY '"'
(Transaction,
AwardID,
OrderNumber,
DUNS,
Recipient,
RecipientCity "trim(:RecipientCity)",
RecipientState,
RecipientCD,
RecipientCountry,
PopState,
PopCD,
PopCountry,
AwardAmount "to_number(:AwardAmount,'$999,999,999,999,999.00')" ,
AwardDate date "mm/dd/yyyy",
AwardType,
AwardingAgency,
AwardingBureau,
FundingAgency,
FundingBureau,
CFDACode,
CFDATitle,
FiscalYear,
Role)
