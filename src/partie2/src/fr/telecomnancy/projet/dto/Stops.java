package fr.telecomnancy.projet.dto;

public class Stops extends Dto {
    private int stopid;
    private int idflight;
    private String airport_dep;
    private String airport_dest;
    private String flightnumber;
    private int stoporder;

    public Stops(int stpid, int idfl, String dep, String dest, String fln, int stp) {
	this.stopid = stpid;
	this.idflight = idfl;
	this.airport_dep = dep;
	this.airport_dest = dest;
	this.flightnumber = fln;
	this.stoporder = stp;
    }

    @Override
    public String toString() {
	return getStopid() + "," + getIdflight() + "," + getAirport_dep() + "," + getAirport_dest() + ","
		+ getFlightnumber() + "," + getStoporder();
    }

    @Override
    public String afficher() {
	String res = padRight(Integer.toString(getStopid()), 8);
	res += padRight(Integer.toString(getIdflight()), 8);
	res += padRight(getAirport_dep(), 7);
	res += padRight(getAirport_dest(), 6);
	res += padRight(getFlightnumber(), 6);
	res += padRight(Integer.toString(getStoporder()), 4);

	return res;
    }

    public int getStopid() {
	return stopid;
    }

    public void setStopid(int stopid) {
	this.stopid = stopid;
    }

    public int getIdflight() {
	return idflight;
    }

    public void setIdflight(int idflight) {
	this.idflight = idflight;
    }

    public String getAirport_dep() {
	return airport_dep;
    }

    public void setAirport_dep(String airport_dep) {
	this.airport_dep = airport_dep;
    }

    public String getAirport_dest() {
	return airport_dest;
    }

    public void setAirport_dest(String airport_dest) {
	this.airport_dest = airport_dest;
    }

    public String getFlightnumber() {
	return flightnumber;
    }

    public void setFlightnumber(String flightnumber) {
	this.flightnumber = flightnumber;
    }

    public int getStoporder() {
	return stoporder;
    }

    public void setStoporder(int stoporder) {
	this.stoporder = stoporder;
    }

}