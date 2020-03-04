LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/routes.csv'

INTO TABLE routes
fields terminated by ","
trailing nullcols
(
    routeID,
    airline,
    airlineID,
    airport_dep,
    airport_depID,
    airport_dest,
    airport_destID,
    codeshare,
    arrets	
)
