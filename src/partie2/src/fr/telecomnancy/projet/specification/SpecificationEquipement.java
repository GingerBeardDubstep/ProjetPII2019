package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationEquipement extends Specification{

    // renvoie true si un critere est specifie
    private boolean specifiedCode = false;

    // criteres de recherche
	private List<String> code = new ArrayList<>();

    // si un code a ete specifie, renvoie true
    public boolean specifiedCode() {
	return specifiedCode;
    }

	public void findByCode(String code) {
		this.specifiedCode = true;
		this.code.add(code);
	}

	public List<String> getCode() {
		return code;
	}

}
