LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/flightnumbers.csv'

INTO TABLE flight_number
fields terminated by ","
trailing nullcols
(
    flightid,
    airline_code,
    flightnumber,
    stops
)
