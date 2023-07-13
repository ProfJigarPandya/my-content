create or replace FUNCTION sf_NoOfSupplier
return number
AS
v_count number(3);
BEGIN
  select count(*) into v_count from supplier;
  return v_count;
END;