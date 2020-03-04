package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationCity extends Specification {

    // renvoie true si un critère est spécifié
    private boolean specifiedCity_id = false;
    private boolean specifiedName = false;
    private boolean specifiedLatitude = false;
    private boolean specifiedLongitude = false;
    private boolean specifiedCountry = false;

    // critères de recherche
    private List<Integer> city_id = new ArrayList<>();
    private List<String> name = new ArrayList<>();
    private List<Double> latitude = new ArrayList<>();
    private List<Double> longitude = new ArrayList<>();
    private List<String> country = new ArrayList<>();

    public void reinitialiserSpec() {
	this.specifiedCity_id = false;
	this.specifiedName = false;
	this.specifiedLatitude = false;
	this.specifiedLongitude = false;
	this.specifiedCountry = false;
	this.city_id.clear();
	this.name.clear();
	this.latitude.clear();
	this.longitude.clear();
	this.country.clear();

    }

    // si une ville a été spécifié, renvoie true
    public boolean specifiedCityId() {
	return specifiedCity_id;
    }

    public boolean specifiedName() {
	return specifiedName;
    }

    public boolean specifiedLatitude() {
	return specifiedLatitude;
    }

    public boolean specifiedLongitude() {
	return specifiedLongitude;
    }

    public boolean specifiedCountry() {
	return specifiedCountry;
    }

    public void findByCityId(Integer id) {
	this.specifiedCity_id = true;
	this.city_id.add(id);
    }

    public void findByName(String m) {
	this.specifiedName = true;
	this.name.add(m);
    }

    public void findByLatitude(Double l) {
	this.specifiedLatitude = true;
	this.latitude.add(l);
    }

    public void findByLongitude(Double l) {
	this.specifiedLongitude = true;
	this.longitude.add(l);
    }

    public void findByCountry(String c) {
	this.specifiedCountry = true;
	this.country.add(c);
    }

    public List<Integer> getCityId() {
	return city_id;
    }

    public List<String> getName() {
	return name;
    }

    public List<Double> getLatitude() {
	return latitude;
    }

    public List<Double> getLongitude() {
	return longitude;
    }

    public List<String> getCountry() {
	return country;
    }
}
