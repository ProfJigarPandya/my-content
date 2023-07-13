create or replace procedure sp_InOut (sp_IO in out varchar2) is
begin
	sp_IO:=sp_IO||'and Something Else';
end;