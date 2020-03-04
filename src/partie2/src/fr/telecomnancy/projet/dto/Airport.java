package fr.telecomnancy.projet.dto;

public class Airport extends Dto {

    private int airportID;
    private String name;
    private double latitude;
    private double longitude;
    private String iata;
    private String icao;
    private String type;
    private String datasource;

    public Airport(int id, String nom, double lat, double longi, String iata, String icao, String type,
	    String datasource) {
	this.airportID = id;
	this.name = nom;
	this.latitude = lat;
	this.longitude = longi;
	this.iata = iata;
	this.icao = icao;
	this.type = type;
	this.datasource = datasource;

    }

    @Override
    public String toString() {
	return getAirportID() + "," + getName() + "," + getLatitude() + "," + getLongitude() + "," + getIata() + ","
		+ getIcao() + "," + getType() + "," + getDatasource();
    }

    @Override
    public String afficher() {
	String res = padRight(Integer.toString(getAirportID()), 7);
	res += padRight(getName(), 68);
	res += padRight(Double.toString(getLatitude()), 22);
	res += padRight(Double.toString(getLongitude()), 23);
	res += padRight(getIata(), 6);
	res += padRight(getIcao(), 6);
	res += padRight(getType(), 9);
	res += padRight(getDatasource(), 13);

	return res;
    }

    public int getAirportID() {
	return airportID;
    }

    public void setAirportID(int airportID) {
	this.airportID = airportID;
    }

    public String getName() {
	return name;
    }

    public void setName(String name) {
	this.name = name;
    }

    public double getLatitude() {
	return latitude;
    }

    public void setLatitude(double latitude) {
	this.latitude = latitude;
    }

    public double getLongitude() {
	return longitude;
    }

    public void setLongitude(double longitude) {
	this.longitude = longitude;
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

    public String getType() {
	return type;
    }

    public void setType(String type) {
	this.type = type;
    }

    public String getDatasource() {
	return datasource;
    }

    public void setDatasource(String datasource) {
	this.datasource = datasource;
    }

}