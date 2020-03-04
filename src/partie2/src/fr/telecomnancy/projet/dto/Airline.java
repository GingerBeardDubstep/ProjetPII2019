package fr.telecomnancy.projet.dto;

public class Airline extends Dto {
    private int airlineID;
    private String name;
    private String alias;
    private String iata;
    private String icao;
    private String callsign;
    private String country;
    private String active;

    public Airline(int id, String nom, String alias, String iata, String icao, String callsign, String pays,
	    String active) {
	this.airlineID = id;
	this.name = nom;
	this.alias = alias;
	this.iata = iata;
	this.icao = icao;
	this.callsign = callsign;
	this.country = pays;
	this.active = active;
    }

    @Override
    public String toString() {
	return getAirlineID() + "," + getName() + "," + getAlias() + "," + getIata() + "," + getIcao() + ","
		+ getCallsign() + "," + getCountry() + "," + getActive();
    }

    public String afficher() {
	String res = padRight(Integer.toString(getAirlineID()), 8);
	res += padRight(getName(), 50);
	res += padRight(getAlias(), 33);
	res += padRight(getIata(), 6);
	res += padRight(getIcao(), 8);
	res += padRight(getCallsign(), 50);
	res += padRight(getCountry(), 37);
	res += padRight(getActive(), 1);

	return res;
    }

    public int getAirlineID() {
	return airlineID;
    }

    public void setAirlineID(int airlineID) {
	this.airlineID = airlineID;
    }

    public String getName() {
	return name;
    }

    public void setName(String name) {
	this.name = name;
    }

    public String getIata() {
	return iata;
    }

    public void setIata(String iata) {
	this.iata = iata;
    }

    public String getIcao() {
	return icao;
    }

    public void setIcao(String icao) {
	this.icao = icao;
    }

    public String getCountry() {
	return country;
    }

    public void setCountry(String country) {
	this.country = country;
    }

    public String getAlias() {
	return alias;
    }

    public void setAlias(String alias) {
	this.alias = alias;
    }

    public String getCallsign() {
	return callsign;
    }

    public void setCallsign(String callsign) {
	this.callsign = callsign;
    }

    public String getActive() {
	return active;
    }

    public void setActive(String active) {
	this.active = active;
    }

}
