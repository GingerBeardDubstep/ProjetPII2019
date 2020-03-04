package fr.telecomnancy.projet.dto;

public class Equipement extends Dto {
    private String airline;
    private String airport_dep;
    private String airport_dest;
    private String code;
    private int routeId;
    private int equid;

    public Equipement(String airline, String airportdep, String airportdest, String code, int routeId, int equid) {
	this.airline = airline;
	this.airport_dep = airportdep;
	this.airport_dest = airportdest;
	this.code = code;
	this.routeId = routeId;
	this.equid = equid;
    }

    @Override
    public String toString() {
	return getAirline() + "," + getAirportdep() + "," + getAirportdest() + "," + getCode() + "," + getRouteId()
		+ "," + getEquid();
    }

    public String afficher() {
	String res = padRight(getAirline(), 7);
	res += padRight(getAirportdep(), 7);
	res += padRight(getAirportdep(), 5);
	res += padRight(getCode(), 5);
	res += padRight(Integer.toString(getRouteId()), 5);
	res += padRight(Integer.toString(getEquid()), 5);

	return res;
    }

    public String getAirline() {
	return airline;
    }

    public void setAirline(String airline) {
	this.airline = airline;
    }

    public String getAirportdep() {
	return airport_dep;
    }

    public void setAirportdep(String airportdep) {
	this.airport_dep = airportdep;
    }

    public String getAirportdest() {
	return airport_dest;
    }

    public void setAirportdest(String airportdest) {
	this.airport_dest = airportdest;
    }

    public String getCode() {
	return code;
    }

    public void setCode(String code) {
	this.code = code;
    }

    public int getRouteId() {
	return routeId;
    }

    public void setRouteId(int routeId) {
	this.routeId = routeId;
    }

    public int getEquid() {
	return equid;
    }

    public void setEquid(int equid) {
	this.equid = equid;
    }

}