package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationFlight_number extends Specification {
	
    // renvoie true si un critère est spécifié
    private boolean specifiedID = false;

    // critères de recherche
	private List<Long> ID = new ArrayList<>();

    // si un code a été spécifié, renvoie true
    public boolean specifiedId() {
	return specifiedID;
    }

	public void findById(long id) {
		this.specifiedID = true;
		this.ID.add(id);
	}

	public List<Long> getId() {
		return ID;
	}

}
