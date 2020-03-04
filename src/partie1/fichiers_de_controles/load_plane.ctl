LOAD DATA
CHARACTERSET UTF8
INFILE '../../cleaned_data/planes.csv'

INTO TABLE planes
fields terminated by ","
trailing nullcols
(
    nom,
    IATA,
    ICAO,
    nb_de_sieges,
    vitesse_de_croisiere,
    autonomie,
    carburant
)
