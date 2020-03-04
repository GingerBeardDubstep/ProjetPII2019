package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationLocalisation extends Specification {

	// renvoie true si un critère est spécifié
	private boolean specifiedVille = false;
	private boolean specifiedPays = false;

	// critères de recherche
	private List<String> ville = new ArrayList<>();
	private List<String> pays = new ArrayList<>();

	public void reinitialiserSpec() {
		this.specifiedVille = false;
		this.specifiedPays = false;
		this.ville.clear();
		this.pays.clear();
	}

	// si une ville a été spécifié, renvoie true
	public boolean specifiedVille() {
		return specifiedVille;
	}

	public boolean specifiedPays() {
		return specifiedPays;
	}

	public void findByVille(String v) {
		this.specifiedVille = true;
		this.ville.add(v);
	}

	public void findByPays(String p) {
		this.specifiedPays = true;
		this.pays.add(p);
	}

	public List<String> getVille() {
		return ville;
	}

	public List<String> getPays() {
		return pays;
	}

}
