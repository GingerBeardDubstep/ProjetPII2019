package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationAirline extends Specification {

	// renvoie true si un critère est spécifié
	private boolean specifiedName = false;
	private boolean specifiedID = false;

	// critères de recherche
	private List<String> name = new ArrayList<>();
	private List<Long> ID = new ArrayList<>();

	// si un nom a été spécifié, renvoie true
	public boolean specifiedName() {
		return specifiedName;
	}

	// si un ID a été spécifié, renvoie true
	public boolean specifiedId() {
		return specifiedID;
	}

	public void findByName(String name) {
		this.specifiedName = true;
		this.name.add(name);
	}

	public void findById(long id) {
		this.specifiedID = true;
		this.ID.add(id);
	}

	public List<String> getName() {
		return name;
	}

	public List<Long> getId() {
		return ID;
	}

}
