package fr.telecomnancy.projet.dto;

public abstract class Dto {

    // https://www.baeldung.com/java-pad-string
    public String padRight(String inputString, int length) {
	if (inputString == null) {
	    return inputString;
	}
	if (inputString.length() >= length) {
	    return inputString;
	}

	StringBuilder sb = new StringBuilder();
	sb.append(inputString);
	while (sb.length() < length) {
	    sb.append(' ');
	}
	return sb.toString();
    }

    public abstract String afficher();
}
