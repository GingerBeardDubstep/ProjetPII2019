package fr.telecomnancy.projet.dto;

public class Flight_number extends Dto {
    private int flightid;
    private String flightnumber;
    private String airline_code;
    private int stops;

    public Flight_number(int id, String number, String code, int stops) {
	this.flightid = id;
	this.flightnumber = number;
	this.airline_code = code;
	this.stops = stops;
    }

    @Override
    public String toString() {
	return getFlightid() + "," + getFlightnumber() + "," + getAirline_code() + "," + getStops();
    }

    @Override
    public String afficher() {
	String res = padRight(Integer.toString(getFlightid()), 7);
	res += padRight(getFlightnumber(), 7);
	res += padRight(getAirline_code(), 5);
	res += padRight(Integer.toString(getStops()), 4);

	return res;
    }

    public int getFlightid() {
	return flightid;
    }

    public void setFlightid(int flightid) {
	this.flightid = flightid;
    }

    public String getFlightnumber() {
	return flightnumber;
    }

    public void setFlightnumber(String flightnumber) {
	this.flightnumber = flightnumber;
    }

    public String getAirline_code() {
	return airline_code;
    }

    public void setAirline_code(String airline_code) {
	this.airline_code = airline_code;
    }

    public int getStops() {
	return stops;
    }

    public void setStops(int stops) {
	this.stops = stops;
    }

}