package fr.telecomnancy.projet.dto;

public class Route extends Dto {
    private String airline;
    private int airlineID;
    private String airportdep;
    private int airportdepID;
    private String airportdest;
    private int airportdestID;
    private String codeshare;
    private int arrets;
    private int routeId;

    public Route(String airline, int aid, String dep, int depid, String dest, int destid, String cdshare, int arrets,
	    int rid) {
	this.airline = airline;
	this.airlineID = aid;
	this.airportdep = dep;
	this.airportdepID = depid;
	this.airportdest = dest;
	this.airportdestID = destid;
	this.codeshare = cdshare;
	this.arrets = arrets;
	this.routeId = rid;
    }

    @Override
    public String toString() {
	return getAirline() + "," + getAirlineID() + "," + getAirportdep() + "," + getAirportdepID() + ","
		+ getAirportdest() + "," + getAirportdestID() + "," + getCodeshare() + "," + getArrets() + ","
		+ getRouteId();
    }

    @Override
    public String afficher() {
	String res = padRight(getAirline(), 7);
	res += padRight(Integer.toString(getAirlineID()), 7);

	res += padRight(getAirportdep(), 7);
	res += padRight(Integer.toString(getAirportdepID()), 7);
	res += padRight(getAirportdest(), 7);
	res += padRight(Integer.toString(getAirportdestID()), 7);
	res += padRight(getCodeshare(), 7);
	res += padRight(Integer.toString(getArrets()), 7);
	res += padRight(Integer.toString(getRouteId()), 3);

	return res;
    }

    public String getAirline() {
	return airline;
    }

    public void setAirline(String airline) {
	this.airline = airline;
    }

    public int getAirlineID() {
	return airlineID;
    }

    public void setAirlineID(int airlineID) {
	this.airlineID = airlineID;
    }

    public String getAirportdep() {
	return airportdep;
    }

    public void setAirportdep(String airportdep) {
	this.airportdep = airportdep;
    }

    public int getAirportdepID() {
	return airportdepID;
    }

    public void setAirportdepID(int airportdepID) {
	this.airportdepID = airportdepID;
    }

    public String getAirportdest() {
	return airportdest;
    }

    public void setAirportdest(String airportdest) {
	this.airportdest = airportdest;
    }

    public int getAirportdestID() {
	return airportdestID;
    }

    public void setAirportdestID(int airportdestID) {
	this.airportdestID = airportdestID;
    }

    public String getCodeshare() {
	return codeshare;
    }

    public void setCodeshare(String codeshare) {
	this.codeshare = codeshare;
    }

    public int getArrets() {
	return arrets;
    }

    public void setArrets(int arrets) {
	this.arrets = arrets;
    }

    public int getRouteId() {
	return routeId;
    }

    public void setRouteId(int routeId) {
	this.routeId = routeId;
    }

}