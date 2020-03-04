LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/equipements.csv'

INTO TABLE equipement
fields terminated by ","
trailing nullcols
(
    equid,
    routeid,
    airline,
    airport_dep,
    airport_dest,
    code
)
