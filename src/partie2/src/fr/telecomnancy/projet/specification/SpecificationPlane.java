package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationPlane extends Specification{

	// renvoie true si un critère est spécifié
	private boolean specifiedName = false;
	private boolean specifiedSieges = false;
	private boolean specifiedVitesse = false;
	private boolean specifiedAutonomie = false;
	private boolean specifiedCarburant = false;

	// critères de recherche
	private List<String> name = new ArrayList<>();
	private List<Integer> sieges = new ArrayList<>();
	private List<Integer> vitesse = new ArrayList<>();
	private List<Integer> autonomie = new ArrayList<>();
	private List<Integer> carburant = new ArrayList<>();

	
	
	// si une ville a été spécifié, renvoie true
	public boolean specifiedName() {
		return specifiedName;
	}

	public boolean specifiedSieges() {
		return specifiedSieges;
	}
	
	public boolean specifiedVitesse() {
		return specifiedVitesse;
	}
	
	public boolean specifiedAutonomie() {
		return specifiedAutonomie;
	}
	
	public boolean specifiedCarburant() {
		return specifiedCarburant;
	}
	
	
	public void findByName(String n) {
		this.specifiedName = true;
		this.name.add(n);
	}

	public void findByNbSieges(Integer s) {
		this.specifiedSieges = true;
		this.sieges.add(s);
	}
	
	public void findByVitesse(Integer v) {
		this.specifiedVitesse = true;
		this.vitesse.add(v);
	}

	public void findByAutonomie(Integer a) {
		this.specifiedAutonomie = true;
		this.autonomie.add(a);
	}
	
	public void findByCarburant(Integer c) {
		this.specifiedCarburant= true;
		this.carburant.add(c);
	}
	
	public List<String> getName() {
		return name;
	}

	public List<Integer> getSieges() {
		return sieges;
	}
	
	public List<Integer> getVitesse() {
		return vitesse;
	}
	
	public List<Integer> getAutonomie() {
		return autonomie;
	}
	
	public List<Integer> getCarburant() {
		return carburant;
	}
}
