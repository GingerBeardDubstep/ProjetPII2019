LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/airlines.csv'

INTO TABLE airline
fields terminated by ","
trailing nullcols
(
    airline_id,
    name,
    alias,
    IATA,
    ICAO,
    callsign,
    country,
    active
)
