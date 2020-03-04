package fr.telecomnancy.projet.specification;
public abstract class Specification {

	protected String connector = "AND";

	// si plus de deux specifications, permet de mettre un connecteur AND ou OR
	public void setConnector(String s) {
		if (s.toUpperCase() == "OR") {
			this.connector = "OR";
		}
	}

	public String getConnector() {
		return connector;
	}

}
