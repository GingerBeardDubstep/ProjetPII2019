LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/airports.csv'
  
INTO TABLE airports
fields terminated by ","
trailing nullcols

(
    airport_id,
    nom,
    latitude "translate(:latitude, '.', ',' ) ",
    longitude "translate(:longitude, '.', ',' ) ",
    IATA,
    ICAO,
    type,
    dataSource
)
