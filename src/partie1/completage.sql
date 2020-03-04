select distinct country from airlines where country not in (select country from city);


UPDATE planes
SET nb_de_sieges = 94,
  vitesse_de_croisiere = 763,
  autonomie = 3075,
  carburant = 11728
WHERE iata = 'AR7';


UPDATE planes
SET nb_de_sieges = 128,
  vitesse_de_croisiere = 763,
  autonomie = 2760,
  carburant = 12875
WHERE iata = 'AR1';


UPDATE planes
SET nb_de_sieges = 112,
  vitesse_de_croisiere = 763,
  autonomie = 2965,
  carburant = 12253
WHERE iata = 'AR8';

UPDATE planes
SET nb_de_sieges = 15,
  vitesse_de_croisiere = 193,
  autonomie = 450,
  carburant = 1250
WHERE iata = 'BH2';

UPDATE planes
SET nb_de_sieges = 370,
  vitesse_de_croisiere = 980,
  autonomie = 16450,
  carburant = 184660
WHERE iata = '74L';

UPDATE planes
SET nb_de_sieges = 498,
  vitesse_de_croisiere = 1050,
  autonomie = 13160,
  carburant = 144304
WHERE iata = '74R';

UPDATE planes
SET nb_de_sieges = 263,
  vitesse_de_croisiere = 952,
  autonomie = 6574,
  carburant = 43492
WHERE iata = '74R';

UPDATE planes
SET nb_de_sieges = 263,
  vitesse_de_croisiere = 952,
  autonomie = 6574,
  carburant = 43492
WHERE iata = '757';

UPDATE planes
SET nb_de_sieges = 255,
  vitesse_de_croisiere = 851,
  autonomie = 7300,
  carburant = 90770
WHERE iata = '767';

UPDATE planes
SET nb_de_sieges = 21,
  vitesse_de_croisiere = 326,
  autonomie = 2000,
  carburant = 1635
WHERE iata = 'EMB';

UPDATE planes
SET nb_de_sieges = 44,
  vitesse_de_croisiere = 834,
  autonomie = 3019,
  carburant = 6420
WHERE iata = 'ERD';


UPDATE planes
SET
  vitesse_de_croisiere = 795,
  carburant = 3821
WHERE icao = 'C56X';

UPDATE planes
SET
  vitesse_de_croisiere = 905
WHERE iata = 'D10';

UPDATE planes
SET
  vitesse_de_croisiere = 371,
  carburant = 2356
WHERE iata = 'D28';

UPDATE planes
SET
  vitesse_de_croisiere = 295,
  carburant = 410,
  autonomie= 1700
WHERE iata = 'PN6';


UPDATE planes
SET
  carburant = 16739
WHERE iata = 'A58';

UPDATE planes
SET
  carburant = 16250
  --autonomie= 2500
WHERE iata = 'AN7';

UPDATE planes
SET
  carburant = 11728,
  autonomie= 3467
WHERE iata = '146';

UPDATE planes
SET
  carburant = 11728,
  autonomie= 3467,
  vitesse_de_croisiere = 784
WHERE iata = '141';

UPDATE planes
SET
  carburant = 11728,
  autonomie= 3467,
  vitesse_de_croisiere = 784
WHERE iata = '142';

UPDATE planes
SET
  carburant = 11728,
  autonomie= 3467,
  vitesse_de_croisiere = 784
WHERE iata = '143';

UPDATE planes
SET
  carburant = 2527
WHERE iata = 'BEH';

UPDATE planes
SET
  carburant = 1020,
  autonomie = 1745
WHERE icao = 'BE58';

UPDATE planes
SET
  carburant = 61100,
  autonomie = 8428
WHERE iata = 'B72';

UPDATE planes
SET
  carburant = 25941
WHERE iata = '7M8';


UPDATE planes
SET
  carburant = 18090,
  autonomie = 1353
WHERE iata = '732';

UPDATE planes
SET
  carburant = 43495
WHERE iata = '753';

UPDATE planes
SET
  carburant = 43495
WHERE iata = '753';
select * from planes where carburant is null;