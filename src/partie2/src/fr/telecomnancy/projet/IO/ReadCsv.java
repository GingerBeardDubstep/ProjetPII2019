package fr.telecomnancy.projet.IO;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.dto.Airline;
import fr.telecomnancy.projet.dto.Airport;
import fr.telecomnancy.projet.dto.City;
import fr.telecomnancy.projet.dto.Equipement;
import fr.telecomnancy.projet.dto.Flight_number;
import fr.telecomnancy.projet.dto.Localisation;
import fr.telecomnancy.projet.dto.Plane;
import fr.telecomnancy.projet.dto.Route;
import fr.telecomnancy.projet.dto.Stops;

public class ReadCsv {

    String chemin = "../../communication/";

    public ReadCsv() {

    }

    public List<Integer> readId(String filename) {

	List<Integer> ids = new ArrayList<>();

	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {
		ids.add(Integer.parseInt(line));
	    }
	} catch (FileNotFoundException e) {
	    System.out.println("Aucun vol n'a été trouvé");
	} catch (IOException e) {
	    System.err.println(e);
	}
	return ids;
    }

    public List<Airport> readAirport(String filename) throws FileNotFoundException, IOException {

	List<Airport> airports = new ArrayList<Airport>();

	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {

	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		int airportID = Integer.parseInt(attributes[0]);
		String name = attributes[1];
		double latitude = Double.parseDouble(attributes[2]);
		double longitude = Double.parseDouble(attributes[3]);
		String iata = attributes[4];
		String icao = attributes[5];
		String type = attributes[6];
		String datasource = attributes[7];

		Airport airport = new Airport(airportID, name, latitude, longitude, iata, icao, type, datasource);
		airports.add(airport);
	    }
	}
	return airports;

    }

    public List<Airline> readAirline(String filename) throws IOException {

	List<Airline> airlines = new ArrayList<Airline>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		int airlineID = Integer.parseInt(attributes[0]);
		String name = attributes[1];
		String alias = attributes[2];
		String iata = attributes[3];
		String icao = attributes[4];
		String callsign = attributes[5];
		String country = attributes[6];
		String active = attributes[7];

		Airline airline = new Airline(airlineID, name, alias, iata, icao, callsign, country, active);
		airlines.add(airline);
	    }
	}

	return airlines;

    }

    public List<City> readCity(String filename) throws IOException {

	List<City> listDto = new ArrayList<City>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		int cityId = Integer.parseInt(attributes[0]);
		String name = attributes[1];
		Double latitude = Double.parseDouble(attributes[2]);
		Double longitude = Double.parseDouble(attributes[3]);
		String country = attributes[4];

		City airport = new City(cityId, name, latitude, longitude, country);
		listDto.add(airport);
	    }
	}

	return listDto;
    }

    public List<Equipement> readEquipement(String filename) throws IOException {

	List<Equipement> equipement = new ArrayList<Equipement>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		String airline = attributes[0];
		String airport_dep = attributes[1];
		String airport_dest = attributes[2];
		String code = attributes[3];
		int routeId = Integer.parseInt(attributes[4]);
		int equid = Integer.parseInt(attributes[5]);
		Equipement airport = new Equipement(airline, airport_dep, airport_dest, code, routeId, equid);
		equipement.add(airport);
	    }
	}

	return equipement;

    }

    public List<Flight_number> readFlight_number(String filename) throws IOException {

	List<Flight_number> listDto = new ArrayList<Flight_number>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		int flightid = Integer.parseInt(attributes[0]);
		String flightnumber = attributes[1];
		String airline_code = attributes[2];
		int stops = Integer.parseInt(attributes[3]);

		Flight_number flight_number = new Flight_number(flightid, flightnumber, airline_code, stops);
		listDto.add(flight_number);
	    }
	}
	return listDto;
    }

    public List<Localisation> readLocalisation(String filename) throws IOException {

	List<Localisation> localisations = new ArrayList<Localisation>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		double latitude = Double.parseDouble(attributes[0]);
		double longitude = Double.parseDouble(attributes[1]);
		String ville = attributes[2];
		String pays = attributes[3];
		int altitude = Integer.parseInt(attributes[4]);
		int decalage_horaire = Integer.parseInt(attributes[5]);
		String dst = attributes[6];
		String tzdata = attributes[7];

		Localisation localisation = new Localisation(latitude, longitude, ville, pays, altitude,
			decalage_horaire, dst, tzdata);
		localisations.add(localisation);
	    }
	}
	return localisations;
    }

    public List<Plane> readPlane(String filename) throws IOException {

	List<Plane> planes = new ArrayList<Plane>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		String nom = attributes[0];
		String iata = attributes[1];
		String icao = attributes[2];
		int nbsieges = Integer.parseInt(attributes[3]);
		int vitesse = Integer.parseInt(attributes[4]);
		int autonomie = Integer.parseInt(attributes[5]);
		int carburant = Integer.parseInt(attributes[6]);

		Plane plane = new Plane(nom, iata, icao, nbsieges, vitesse, autonomie, carburant);
		planes.add(plane);
	    }
	}
	return planes;
    }

    public List<Route> readRoute(String filename) throws IOException {

	List<Route> routes = new ArrayList<Route>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		String airline = attributes[0];
		int airlineID = Integer.parseInt(attributes[1]);
		String airportdep = attributes[2];
		int airportdepID = Integer.parseInt(attributes[3]);
		String airportdest = attributes[4];
		int airportdestID = Integer.parseInt(attributes[5]);
		String codeshare = attributes[6];
		int arrets = Integer.parseInt(attributes[7]);
		int routeId = Integer.parseInt(attributes[8]);

		Route route = new Route(airline, airlineID, airportdep, airportdepID, airportdest, airportdestID,
			codeshare, arrets, routeId);
		routes.add(route);
	    }
	}
	return routes;
    }

    public List<Stops> readStops(String filename) throws IOException {

	List<Stops> stops = new ArrayList<Stops>();
	try (BufferedReader reader = new BufferedReader(new FileReader(chemin + filename))) {
	    String line;
	    while ((line = reader.readLine()) != null) {

		String[] attributes = line.split(",",-1);
		int stopid = Integer.parseInt(attributes[0]);
		int idflight = Integer.parseInt(attributes[1]);
		String airport_dep = attributes[2];
		String airport_dest = attributes[3];
		String flightnumber = attributes[4];
		int stoporder = Integer.parseInt(attributes[5]);

		Stops stop = new Stops(stopid, idflight, airport_dep, airport_dest, flightnumber, stoporder);
		stops.add(stop);
	    }
	}

	return stops;

    }

}
