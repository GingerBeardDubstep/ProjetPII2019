insert into airports values(13727, 'Aratika-Nord Airport',-15.4855556,-145.4647222222222,'RKA','NTKK','airport','user');
insert into localisation values(-15.4855556,-145.4647222222222,'Aratika','French Polynesia',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13727
where airport_dep = 'RKA' or airport_dest = 'RKA';

insert into airports values(13728, 'Waterfall Seaplane Base',55.2963889,-133.2433333333333,'KWF',NULL,'airport','user');
insert into localisation values(55.2963889,-133.2433333333333,'Waterfall','Alaska',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13728
where airport_dep = 'KWF' or airport_dest = 'KWF';

insert into airports values(13729, 'Edna Bay Seaplane Base',55.953701020,-133.651001000,'EDA','KEDA','airport','user');
insert into localisation values(55.953701020,-133.651001000,'Edana Bay','USA',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13729
where airport_dep = 'EDA' or airport_dest = 'EDA';


insert into airports values(13729, 'Edna Bay Seaplane Base',55.953701020,-133.651001000,'EDA','KEDA','airport','user');
insert into localisation values(55.953701020,-133.651001000,'Edana Bay','USA',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13372
where airport_dep = 'QUV' or airport_dest = 'QUV';

select routeid from routes where airport_dep = 'TQA' or airport_dest = 'TQA';
delete from equipement where routeid in (select routeid from routes where airport_dep = 'TQA' or airport_dest = 'TQA');
delete from routes where airport_dep = 'TQA' or airport_dest = 'TQA';

select routeid from routes where airport_dep = 'TQI' or airport_dest = 'TQI';
delete from equipement where routeid in (select routeid from routes where airport_dep = 'TQI' or airport_dest = 'TQI');
delete from routes where airport_dep = 'TQI' or airport_dest = 'TQI';

insert into airports values(13730, 'Jajao Airport',-8.2222222,159.26666666666668,'JJA','AGJO','airport','user');
insert into localisation values(-8.2222222,159.26666666666668,' Isabel Province','Solomon Island',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13730
where airport_dep = 'JJA' or airport_dest = 'JJA';

insert into airports values(13731, 'Matthew Spain Airport',17.1858333,-83.00972222222222,'SQS','MZCF','airport','user');
insert into localisation values(17.1858333,-83.00972222222222,'San Ignacio','Belize',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13731
where airport_dep = 'SQS' or airport_dest = 'SQS';


insert into airports values(13732, 'Orange Walk Airport',17.0466667,-88.58333333333333,'ORZ','MZTH','airport','user');
insert into localisation values(17.0466667,-88.58333333333333,'Orange Walk Town','Belize',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13732
where airport_dep = 'ORZ' or airport_dest = 'ORZ';

insert into airports values(13733, 'Gunsan Airbase',17.0466667,-88.58333333333333,'ORZ','MZTH','airport','user');
insert into localisation values(17.0466667,-88.58333333333333,'Orange Walk Town','Belize',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 6003
where airport_dep = 'KUZ' or airport_dest = 'KUZ';

insert into airports values(13734, 'Nogliki Airport',51.783889, 143.141667,'NGK','UHSN','airport','user');
insert into localisation values(51.783889, 143.141667,'Nogliki','Russia',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13734
where airport_dep = 'NGK' or airport_dest = 'NGK';

update routes
    set airport_depid = 13365
where airport_dep = 'AOQ' or airport_dest = 'AOQ';

delete from equipement where routeid in (select routeid from routes where airport_dep = 'KHQ' or airport_dest = 'KHQ');
delete from routes where airport_dep = 'KHQ' or airport_dest = 'KHQ';

insert into airports values(13735, 'Sangir Airport',-8.3666696548, 118.3333587646,'SAE',NULL,'airport','user');
insert into localisation values(-8.3666696548,118.3333587646,'Sangir-Simbawa Island','Indonesia',NULL,NULL,NULL,NULL);
update routes
    set airport_depid = 13735
where airport_dep = 'SAE' or airport_dest = 'SAE';

select * from airports where IATA = 'AOQ';
select * from airports where icao = 'WBGY';
select * from airports a join localisation l on a.latitude=l.latitude and a.longitude = l.longitude where l.pays='Korea (South)';
select distinct airport_dep from routes where airport_depid is NULL;