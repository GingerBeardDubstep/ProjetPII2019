LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/stops.csv'

INTO TABLE stops
fields terminated by ","
trailing nullcols
(
    stopid,
    idflight,
    flightnumber,
    airport_dep,
    airport_dest,
    stoporder
)
