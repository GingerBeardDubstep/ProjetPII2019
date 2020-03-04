import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ValeurMaxAttributs {

    //permet de compter le nombre maximal de caractères de chaque attribut pour chaque fichier,
    //afin d'utiliser le moins d'espace possible quand on créé les tables sur Oracle.
    
    public static int[][] countMaxCollumnFromCsvs(String[] chFichiers) {

	int[][] res = new int[chFichiers.length][10];

	for (int j = 0; j < chFichiers.length; j++) {
	    try {
		BufferedReader fichier = new BufferedReader(new FileReader(chFichiers[j]));
		String chaine;
		int i = 1;
		while ((chaine = fichier.readLine()) != null) {
		    if (i > 1) {

			String[] tabChaine = chaine.split(",");

			for (int k = 0; k < tabChaine.length; k++) {
			    if (!tabChaine[k].equals("NULL") && res[j][k] < tabChaine[k].length()) {
				res[j][k] = tabChaine[k].length();
			    }
			}
		    }
		    i++;
		}
		fichier.close();
	    } catch (IOException e) {
		System.out.println("Le fichier est introuvable !");
		e.printStackTrace();
	    }
	}
	return res;
    }

    public static void printValues(String[] chFichiers, int[][] res, String[][] colonnes) {

	for (int j = 0; j < chFichiers.length; j++) {

	    String[] nomFichier = chFichiers[j].split("/");

	    System.out.println("fichier : " + nomFichier[nomFichier.length - 1]);

	    for (int index = 0; index < colonnes[j].length; index++) {
		System.out.println("  [" + colonnes[j][index] + "] : " + res[j][index]);
	    }
	    System.out.println("");
	}
    }

    public static void main(String[] args) {
	String Airports = "../../cleaned_data/airports.csv";
	String Airlines = "../../cleaned_data/airlines.csv";
	String Localisations = "../../cleaned_data/localisations.csv";
	String routes = "../../cleaned_data/routes.csv";
	String flightnumbers = "../../cleaned_data/flightnumbers.csv";
	String planes = "../../cleaned_data/planes.csv";
	String equipements = "../../cleaned_data/equipements.csv";
	String stops = "../../cleaned_data/stops.csv";

	String[][] colonnes = { { "airport_id", "name", "latitude", "longitude", "IATA", "ICAO", "type", "dataSource" },
		{ "airline_id", "name", "alias", "IATA", "ICAO", "Callsign", "Pays", "active" },
		{ "latitude", "longitude", "ville", "pays", "altitude", "decalage_horaire", "DST", "TzData" },
		{ "routeID","airline", "airlineID", "airport_dep", "airport_depID", "airport_dest", "airport_destID", "codeshare",
			"arrets" },
		{  "flightid","airline_code","flightnumber","stops" },
		{ "nom", "IATA", "ICAO", "nb de sièges", "vitesse de croisière", "autonomie", "carburant" },
		{ "equid","routeid","airline", "airport_dep", "airport_dest", "code"},
		{ "stopid", "idflight","flightnumber", "airport_dep", "airport_dest","stoporder" } };

	String[] chFichiers = { Airports, Airlines, Localisations, routes, flightnumbers, planes, equipements,
		stops };

	int[][] resultat = countMaxCollumnFromCsvs(chFichiers);
	printValues(chFichiers, resultat, colonnes);

    }
}
