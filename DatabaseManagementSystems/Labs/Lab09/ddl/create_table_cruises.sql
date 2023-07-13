

create table cruises
(cruise_id number,
 cruise_name varchar2(30),
 start_date date,
 end_date date,
 constraint cruise_id_pk primary key (cruise_id),
 constraint cruise_name_ck check (cruise_name in ('Hawaii','Bahamas','Bermuda','Mexico','Day at Sea'))
);

exit;
