--Séléctionne les iata et les icao des compagnie aérienne russes et française

SELECT IATA, ICAO from airlines where country = 'Russia';
SELECT IATA, ICAO from airlines where country = 'France';

--Sélectionne les aéroports à Moscou et à Paris

SELECT a.name, a.iata, a.icao from localisation l join airports a on a.latitude = l.latitude and a.longitude=l.longitude where ville='Moscow';
SELECT a.name, a.iata, a.icao from localisation l join airports a on a.latitude = l.latitude and a.longitude=l.longitude where ville='Paris';


--Sélectionne les routes 

SELECT airline from routes where airport_dep='CDG' and airport_dest='SVO'; --Il faut y mettre les IATA et ça renvoie les iata

--Sélectionne les numéro de vols

SELECT DISTINCT f.airline_code, s.stoporder, f.stops from flight_number f join stops s on f.flightid= s.idflight where s.airport_dep = 'LFPG' and s.airport_dest = 'UUEE'; --Il faut mettre les icao et ça renvoit les icao des airlines

--On recherche la correspondance en ICAO

SELECT ICAO from airlines where iata in (SELECT airline from routes where airport_dep='CDG' and airport_dest='SVO');

--On en trouve 2 qui correspondent (il y à donc 2 routes et bien plus de numéro de vol)


CREATE TABLE CITY (
    cityid int primary key,
    name VARCHAR2(100),
    latitude number(38,20),
    longitude number(38, 20),
    country varchar2(100)
);
    
