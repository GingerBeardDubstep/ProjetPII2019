package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationRoute extends Specification{

	// renvoie true si un critère est spécifié
	private boolean specifiedAirport_dep = false;
	private boolean specifiedAirport_dest = false;

	// critères de recherche
	private List<String> airport_dep = new ArrayList<>();
	private List<String> airport_dest = new ArrayList<>();

	
	
	// si une ville a été spécifié, renvoie true
	public boolean specifiedAirport_dep() {
		return specifiedAirport_dep;
	}

	public boolean specifiedAirport_dest() {
		return specifiedAirport_dest;
	}
	
	
	public void findByAirport_dep(String a) {
		this.specifiedAirport_dep = true;
		this.airport_dep.add(a);
	}

	public void findByAirport_dest(String a) {
		this.specifiedAirport_dest = true;
		this.airport_dest.add(a);
	}
	
	
	public List<String> getAirport_dep() {
		return airport_dep;
	}
	
	public List<String> getAirport_dest() {
		return airport_dest;
	}

}
