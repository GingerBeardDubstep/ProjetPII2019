package fr.telecomnancy.projet.dto;

public class Localisation extends Dto {

    private double latitude;
    private double longitude;
    private String ville;
    private String pays;
    private int altitude;
    private int decalage_horaire;
    private String dst;
    private String tzdata;

    public Localisation(double latitude, double longitude, String ville, String pays, int altitude,
	    int decalage_horaire, String dst, String tzdata) {
	this.latitude = latitude;
	this.longitude = longitude;
	this.ville = ville;
	this.pays = pays;
	this.altitude = altitude;
	this.decalage_horaire = decalage_horaire;
	this.dst = dst;
	this.tzdata = tzdata;
    }

    @Override
    public String toString() {
	return getLatitude() + "," + getLongitude() + "," + getVille() + "," + getPays() + "," + getAltitude() + ","
		+ getDecalage_horaire() + "," + getDst() + "," + getTzdata();
    }

    @Override
    public String afficher() {
	String res = padRight(Double.toString(getLatitude()), 22);
	res += padRight(Double.toString(getLongitude()), 23);
	res += padRight(getVille(), 35);
	res += padRight(getPays(), 34);
	res += padRight(Integer.toString(getAltitude()), 7);
	res += padRight(Integer.toString(getDecalage_horaire()), 7);
	res += padRight(getDst(), 30);
	res += padRight(getTzdata(), 5);

	return res;
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

    public String getVille() {
	return ville;
    }

    public void setVille(String ville) {
	this.ville = ville;
    }

    public String getPays() {
	return pays;
    }

    public void setPays(String pays) {
	this.pays = pays;
    }

    public int getAltitude() {
	return altitude;
    }

    public void setAltitude(int altitude) {
	this.altitude = altitude;
    }

    public int getDecalage_horaire() {
	return decalage_horaire;
    }

    public void setDecalage_horaire(int decalage_horaire) {
	this.decalage_horaire = decalage_horaire;
    }

    public String getDst() {
	return dst;
    }

    public void setDst(String dst) {
	this.dst = dst;
    }

    public String getTzdata() {
	return tzdata;
    }

    public void setTzdata(String tzdata) {
	this.tzdata = tzdata;
    }

}