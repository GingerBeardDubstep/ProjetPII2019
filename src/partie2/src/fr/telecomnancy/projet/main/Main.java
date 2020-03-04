package fr.telecomnancy.projet.main;

import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import fr.telecomnancy.projet.IO.*;
import fr.telecomnancy.projet.dto.*;
import fr.telecomnancy.projet.repository.*;
import fr.telecomnancy.projet.specification.*;

public class Main {

    private static <T extends Dto, U extends Specification> void modification(Repository<T, U> table, List<T> lines,
	    String choixModif) throws SQLException {
	int count = 1;
	if (choixModif.toUpperCase().equals("AJOUTER")) {
	    for (T line : lines) {
		System.out.print("line " + count + " : ");
		System.out.println(table.add(line));
		count++;
	    }
	} else if (choixModif.toUpperCase().equals("SUPPRIMER")) {
	    for (T line : lines) {
		System.out.print("line " + count + " : ");
		System.out.println(table.remove(line));
		count++;
	    }
	} else if (choixModif.toUpperCase().equals("MAJ")) {
	    for (T line : lines) {
		System.out.print("line " + count + " : ");
		System.out.println(table.update(line));
		count++;
	    }
	} else {
	    System.out.println("ok");
	}
    }

    private static void trouverFlight_number(List<String> listICAO) throws SQLException {
	System.out.println("Voici le numero des vols :");
	if (listICAO.isEmpty() || listICAO.size() == 1) {
	    System.out.println("\taucun numero de vol trouve");
	    System.exit(0);
	}

	List<Stops> listStops = new ArrayList<Stops>();
	RepositoryStops repStops = new RepositoryStops();
	SpecificationStops specStops = new SpecificationStops();
	String icaoDepart = listICAO.get(0);

	System.out.print("\tdepart -> ");
	for (int i = 1; i < listICAO.size(); i++) {
	    String icaoArrive = listICAO.get(i);
	    specStops.findByAirport_dep(icaoDepart);
	    specStops.findByAirport_dest(icaoArrive);
	    specStops.setConnector("AND");

	    listStops = repStops.query(specStops);
	    specStops.reinitialiserSpec();
	    if (listStops.isEmpty()) {
		System.out.print("flightnumber introuvable -> ");
	    }
	    for (Stops stop : listStops) {
		System.out.print(stop.getFlightnumber() + " -> ");
	    }
	    icaoDepart = icaoArrive;
	    listStops.clear();
	}
	System.out.println("arrivee");

    }

    public static String[] parseRetourAeroport(){
    	String[] tab = new String[5];
    	return(tab);
    }

    public static void main(String[] args) throws InterruptedException,SQLException, IOException {

	int choix = 0;
	String choixDto = "";
	String choixModif = "";
	String choixVille = "";
	String choixAeroport1 = "";
	String choixAeroport2 = "";
	String choixPays = "";

	RepositoryAirline repAirline = new RepositoryAirline();
	RepositoryAirport repAirport = new RepositoryAirport();
	RepositoryCity repCity = new RepositoryCity();
	RepositoryEquipement repEquipement = new RepositoryEquipement();
	RepositoryFlight_number repFlight_number = new RepositoryFlight_number();
	RepositoryLocalisation repLocalisation = new RepositoryLocalisation();
	RepositoryPlane repPlane = new RepositoryPlane();
	RepositoryRoute repRoute = new RepositoryRoute();
	RepositoryStops repStops = new RepositoryStops();

	SpecificationAirport specAirport = new SpecificationAirport();
	SpecificationCity specCity = new SpecificationCity();
	SpecificationLocalisation specLocalisation = new SpecificationLocalisation();
	SpecificationStops specStops = new SpecificationStops();

	List<Airline> listAirline = new ArrayList<Airline>();
	List<Airport> listAirport = new ArrayList<Airport>();
	List<City> listCity = new ArrayList<City>();
	List<Equipement> listEquipement = new ArrayList<Equipement>();
	List<Flight_number> listFlight_number = new ArrayList<Flight_number>();
	List<Localisation> listLocalisation = new ArrayList<Localisation>();
	List<Plane> listPlane = new ArrayList<Plane>();
	List<Route> listRoute = new ArrayList<Route>();
	List<Stops> listStops = new ArrayList<Stops>();
	List<Integer> listId = new ArrayList<>();
	List<String> listICAO = new ArrayList<>();
	List<Airport> retAirp1 = new ArrayList<Airport>();
	List<Airport> retAirp2 = new ArrayList<Airport>();

	WriteCsv<City> writeCity = new WriteCsv<>();

	WriteCsv<Airport> wAirports = new WriteCsv<>();
	wAirports.write(repAirport.findAll(), "Airport");
	specAirport.reinitialiserSpec();

	// WriteCsv<Route> wRoutes = new WriteCsv<>();
	// wRoutes.write(repRoute.findAll(), "routes");
	//specRoute.reinitialiserSpec();



	ReadCsv read = new ReadCsv();

	//writeEquipement.write(repEquipement.findAll(), "Equipement");

	try (Scanner sc = new Scanner(System.in)) {

	    while (choix < 1 || choix > 2) {
		System.out.println("Voulez vous chercher un trajet (1) ou modifier la base de donnee (2)");
		choix = sc.nextInt();
	    }
	    sc.nextLine();

	    // Si l'utilisateur recherche un trajet
	    if (choix == 1) {
		// Choix de la ville de depart
		System.out.print("De quelle ville voulez vous partir ? ");
		choixVille = sc.nextLine();

		specLocalisation.findByVille(choixVille);
		listLocalisation = repLocalisation.query(specLocalisation);

		// Si localisation a trouve la ville de depart, on enumere la liste des aerports

		if (!listLocalisation.isEmpty()) {

		    System.out.println("Voici les aeroports disponibles :");
		    for (Localisation l : listLocalisation) {
			specAirport.findByLatitude(l.getLatitude());
			specAirport.findByLongitude(l.getLongitude());
			specAirport.setConnector("AND");

			listAirport = repAirport.query(specAirport);
			for (Airport ap : listAirport) {
			    System.out.println("\t" + ap.getName());
			}
			specAirport.reinitialiserSpec();
		    }
		    specLocalisation.reinitialiserSpec();

		    // on propose à l utilisateur de choisir un aeroport parmi la liste proposee

		    System.out.print("De quel aeroport voulez-vous partir : ");
		    choixAeroport1 = sc.nextLine();

		    listLocalisation.clear();
		    listAirport.clear();
		    // sinon si ville n'a pas ete trouvee dans localisation, on fait une recherche
		    // dans city, en demandant un pays.
		} else if (listLocalisation.isEmpty()) {
		    System.out.println(
			    "Il n'y a pas d'aeroports dans cette ville, recherche de l'aeroport le plus proche...");
		    System.out.print("Selectionnez un pays : ");
		    choixPays = sc.nextLine();

		    specCity.findByName(choixVille);
		    specCity.findByCountry(choixPays);
		    specCity.setConnector("AND");

		    listCity = repCity.query(specCity);
		    specCity.reinitialiserSpec();
		    if (listCity.isEmpty()) {
			System.out.println("pas de resultat");
			System.exit(0);
		    } else {
			writeCity.write(listCity, "City");
			Process p1 = Runtime.getRuntime().exec("make plusProche");
			p1.waitFor();
			retAirp1=read.readAirport("plusProche.csv");
			if(retAirp1.size()>0){
				choixAeroport1 = retAirp1.get(0).getName();
			}else{
				System.out.println("La recherche pa perimetre n'a pas fonctionné");
			}
			
			retAirp1.clear();
			listCity.clear();
		    }

		}

		// Choix de la ville d'arrive
		System.out.print("A quelle ville voulez vous arriver ? ");
		choixVille = sc.nextLine();

		specLocalisation.findByVille(choixVille);
		listLocalisation = repLocalisation.query(specLocalisation);

		// Si localisation a trouvé la ville de départ, on enumere la liste des aerports
		if (!listLocalisation.isEmpty()) {

		    System.out.println("Voici les aeroports disponibles :");
		    for (Localisation l : listLocalisation) {
			specAirport.findByLatitude(l.getLatitude());
			specAirport.findByLongitude(l.getLongitude());
			specAirport.setConnector("AND");

			listAirport = repAirport.query(specAirport);
			for (Airport ap : listAirport) {
			    System.out.println("\t" + ap.getName());
			}
			specAirport.reinitialiserSpec();
		    }
		    specLocalisation.reinitialiserSpec();

		    // on propose à l utilisateur de choisir un aeroport parmi la liste proposee
		    System.out.print("A quel aeroport voulez vous arriver : ");
		    choixAeroport2 = sc.nextLine();

		    listLocalisation.clear();
		    listAirport.clear();

		    // sinon si ville n'a pas ete trouvee dans localisation, on fait une recherche
		    // dans city, en demandant un pays.
		} else if (listLocalisation.isEmpty()) {
		    System.out.println(
			    "Il n'y a pas d'aeroports dans cette ville, recherche de l'aeroport le plus proche...");
		    System.out.print("Selectionnez un pays : ");
		    choixPays = sc.nextLine();

		    specCity.findByName(choixVille);
		    specCity.findByCountry(choixPays);

		    listCity = repCity.query(specCity);
		    specCity.reinitialiserSpec();

		    if (listCity.isEmpty()) {
			System.out.println("pas de resultat");
			System.exit(0);
		    } else {
			writeCity.write(listCity, "City");
			Process p2 = Runtime.getRuntime().exec("make plusProche");
			p2.waitFor();
			
			retAirp2=read.readAirport("plusProche.csv");
			if(retAirp2.size()>0){
				choixAeroport2 = retAirp2.get(0).getName();
			}else{
				System.out.println("La recherche pa perimetre n'a pas fonctionné");
			}
			
			retAirp1.clear();
			listCity.clear();
		    }

		}

		specAirport.findByName(choixAeroport1);
		specAirport.findByName(choixAeroport2);
		specAirport.setConnector("OR");

		WriteCsv<Airport> writeAirports = new WriteCsv<>();
		writeAirports.write(repAirport.query(specAirport), "Trajet");
		specAirport.reinitialiserSpec();

		try {

			Process p = Runtime.getRuntime().exec("make astar");
			p.waitFor();

		}
		catch(Exception e) {
			System.out.println("Ca n'a pas marche");
		}

		listId = read.readId("sortie.txt");

		System.out.println("Voici le chemin a suivre :");
		System.out.print("\tdepart -> ");
		for (Integer id : listId) {
		    specAirport.findById(id);
		    listAirport = repAirport.query(specAirport);
		    for (Airport aip : listAirport) {
			System.out.print(aip.getName() + " -> ");
			listICAO.add(aip.getIcao());
		    }
		    specAirport.reinitialiserSpec();
		}
		System.out.println("arrivee");

		listId.clear();
		System.out.println(listICAO);
		trouverFlight_number(listICAO);

		// Si l'utilisateur veut modifier la base de donnee
	    } else if (choix == 2) {
		System.out.println("Ajouter dans communication/modifBD.txt les tuples à modifier");
		System.out.println("Quelle table voulez vous modifier ?");
		System.out.println(
			"\t-airport\n\t-airline\n\t-city\n\t-equipement\n\t-flight_number\n\t-localisation\n\t-plane\n\t-route\n\t-stops");
		System.out.print("choix : ");
		choixDto = sc.nextLine();

		System.out.println("Quelle modification voulez vous faire (ajouter,supprimer,maj) ?");
		choixModif = sc.nextLine();

		switch (choixDto.toUpperCase()) {

		case "AIRPORT":
		    listAirport = read.readAirport("modifBD.txt");

		    modification(repAirport, listAirport, choixModif);
		    break;
		case "AIRLINE":
		    listAirline = read.readAirline("modifBD.txt");

		    modification(repAirline, listAirline, choixModif);

		    break;
		case "CITY":
		    listCity = read.readCity("modifBD.txt");

		    modification(repCity, listCity, choixModif);

		    break;
		case "EQUIPEMENT":
		    listEquipement = read.readEquipement("modifBD.txt");

		    modification(repEquipement, listEquipement, choixModif);

		    break;
		case "FLIGHT_NUMBER":
		    listFlight_number = read.readFlight_number("modifBD.txt");

		    modification(repFlight_number, listFlight_number, choixModif);

		    break;
		case "LOCALISATION":
		    listLocalisation = read.readLocalisation("modifBD.txt");

		    modification(repLocalisation, listLocalisation, choixModif);

		    break;
		case "PLANE":
		    listPlane = read.readPlane("modifBD.txt");

		    modification(repPlane, listPlane, choixModif);

		    break;
		case "ROUTE":
		    listRoute = read.readRoute("modifBD.txt");

		    modification(repRoute, listRoute, choixModif);

		    break;
		case "STOPS":
		    listStops = read.readStops("modifBD.txt");

		    modification(repStops, listStops, choixModif);

		    break;
		}

	    }
	}
    }
}
