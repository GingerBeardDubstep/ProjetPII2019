LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/localisations.csv'

INTO TABLE localisation
fields terminated by ","
trailing nullcols

(
    latitude "translate(:latitude, '.', ',' ) ",
    longitude "translate(:longitude, '.', ',' ) ",
    ville,
    pays,
    altitude,
    decalage_horaire "translate(:decalage_horaire, '.', ',' ) " ,
    DST,
    TZDATA
)
