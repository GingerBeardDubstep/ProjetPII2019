package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationStops extends Specification {

    // renvoie true si un critère est spécifié
    private boolean specifiedAirport_dep = false;
    private boolean specifiedAirport_dest = false;
    private boolean specifiedStop_id = false;

    // critères de recherche
    private List<String> airport_dep = new ArrayList<>();
    private List<String> airport_dest = new ArrayList<>();
    private List<Integer> stop_id = new ArrayList<>();

    public void reinitialiserSpec() {
	this.specifiedAirport_dep = false;
	this.specifiedAirport_dest = false;
	this.specifiedStop_id = false;
	this.airport_dep.clear();
	this.airport_dest.clear();
	this.stop_id.clear();
    }

    // si une ville a été spécifié, renvoie true
    public boolean specifiedAirport_dep() {
	return specifiedAirport_dep;
    }

    public boolean specifiedAirport_dest() {
	return specifiedAirport_dest;
    }

    public boolean specifiedStop_id() {
	return specifiedStop_id;
    }

    public void findByAirport_dep(String a) {
	this.specifiedAirport_dep = true;
	this.airport_dep.add(a);
    }

    public void findByAirport_dest(String a) {
	this.specifiedAirport_dest = true;
	this.airport_dest.add(a);
    }

    public void findByStopId(Integer s) {
	this.specifiedStop_id = true;
	this.stop_id.add(s);
    }

    public List<String> getAirport_dep() {
	return airport_dep;
    }

    public List<String> getAirport_dest() {
	return airport_dest;
    }

    public List<Integer> getStopId() {
	return stop_id;
    }
}
