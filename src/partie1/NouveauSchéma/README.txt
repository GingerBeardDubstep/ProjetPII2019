Apres passage en 3NF on à 9 tables :


AIRPORTS
-airportID PRIMARY KEY
-latitude
-longitude
-type
-source (je ne crois pas que ça soit utile)

ALTER TABLE AIRPORTS
ADD CONSTRAINT FK_AIRPORTS_LATITUDE_LONGITUDE
FOREIGN KEN (LATITUDE, LONGITUDE) REFERENCES LOCALISATION(LATITUDE, LONGITUDE);

AIRPORT_ID
-airportID
-IATA
-ICAO

ALTER TABLE AIRPORT_ID
ADD CONSTRAINT FK_AIRPORTS_ID_AIRPORTID
FOREIGN KEY (AIRPORTID) REFERENCES AIRPORTS(AIRPORTID);


AIRLINE
-AirlineID PRIMARY KEY
-Name
-country
-alias
-callsign
-active


AIRLINE_ID
-AirlineID
-IATA
-ICAO


ALTER TABLE AIRLINE_ID
ADD CONSTRAINT FK_AIRLINE_ID_AIRLINEID
FOREIGN KEY (AIRLINEID) REFERENCES AIRLINE(AIRLINEID);

EQUIPEMENT

-IDairportdep
-IDairportdest
-stops
-plane.IATA
-plane.ICAO

ALTER TABLE EQUIPEMENT
ADD CONSTRAINT FK_FLIGHT_NUMBER_EQUIPEMENT
FOREIGN KEY (IDAIRPORTDEP, IDAIRPORTDEST, STOPS) REFERENCES ROUTE (IDAIRPORTDEP, IDAIRPORTDEST, STOPS)

PLANE
-IATA
-ICAO
-NAME
-PLACES
-SPEED
-Autonomy
-kerosen

ALTER TABLE PLANE
ADD CONSTRAINT PLANE_PK
PRIMARY KEY (IATA, ICAO)


ROUTE
-IDairportdep
-IDairportdest
-stops
-AirlineID

//Ici je veux mettre le couple (IDairportdep, IDairportdest) comme clé primaire (une route est definie par son point de départ et son point d'arrivé quoique je me demande si il ne faut pas rajouter égalemetn le nombre de stop dans la clé primaire car en fonction de où on s'arrete ce n'est pas la même route...) mais comme une même compagnie exploite plusieurs routes il ne va pas être unique. je me posais la question de créer une autre table pour dire quelles compagnies exploite quelles routes mais comme c'est une relation N-N je ne suis pas sûre de comment faire


LOCALISATION
-latitude
-longitude
-Altitude
-country
-city
-timezone
-dst
-TZ database time zone
ALTER TABLE LOCALISATION
ADD CONSTRAINT LOCALISATION_PK
PRIMARY KEY (LATITUDE, LONGITUDE)


FLIGHT_NUMBER
-IDFlight (c'est flightNumber) PRIMARY KEY
-IDAirline
-IDairportdep
-IDairportdest
-stops

ALTER TABLE FLIGHT_NUMBER
ADD CONSTRAINT FK_FLIGHT_NULBER_AIRLINEID
FOREIGN KEY (IDAIRLINE) REFERENCES AIRLINE (ID_AIRLINE);

ALTER TABLE FLIGHT_NUMBER
ADD CONSTRAINT FK_FLIGHT_NUMBER_ROUTE
FOREIGN KEY (IDAIRPORTDEP, IDAIRPORTDEST, STOPS) REFERENCES ROUTE (IDAIRPORTDEP, IDAIRPORTDEST, STOPS)




J'ai crée les tables AIRPORTID et AIRLINEID pour la 3NF mais je ne vois pas trop l'interêt de ses tables...