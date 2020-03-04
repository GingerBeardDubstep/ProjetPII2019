package fr.telecomnancy.projet.dto;

public class Plane extends Dto {

    private String nom;
    private String iata;
    private String icao;
    private int nbsieges;
    private int vitesse;
    private int autonomie;
    private int carburant;

    public Plane(String name, String iata, String icao, int sieges, int speed, int aut, int ker) {
	this.nom = name;
	this.iata = iata;
	this.icao = icao;
	this.nbsieges = sieges;
	this.vitesse = speed;
	this.autonomie = aut;
	this.carburant = ker;
    }

    @Override
    public String toString() {
	return getNom() + "," + getIata() + "," + getIcao() + "," + getNbsieges() + "," + getVitesse() + ","
		+ getAutonomie() + "," + getCarburant();
    }

    @Override
    public String afficher() {
	String res = padRight(getNom(), 48);
	res += padRight(getIata(), 6);
	res += padRight(getIcao(), 9);
	res += padRight(Integer.toString(getNbsieges()), 3);
	res += padRight(Integer.toString(getVitesse()), 6);
	res += padRight(Integer.toString(getAutonomie()), 7);
	res += padRight(Integer.toString(getCarburant()), 8);

	return res;
    }

    public String getNom() {
	return nom;
    }

    public void setNom(String nom) {
	this.nom = nom;
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

    public int getNbsieges() {
	return nbsieges;
    }

    public void setNbsieges(int nbsieges) {
	this.nbsieges = nbsieges;
    }

    public int getVitesse() {
	return vitesse;
    }

    public void setVitesse(int vitesse) {
	this.vitesse = vitesse;
    }

    public int getAutonomie() {
	return autonomie;
    }

    public void setAutonomie(int autonomie) {
	this.autonomie = autonomie;
    }

    public int getCarburant() {
	return carburant;
    }

    public void setCarburant(int carburant) {
	this.carburant = carburant;
    }

}