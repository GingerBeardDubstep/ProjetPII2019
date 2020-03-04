package fr.telecomnancy.projet.IO;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

import fr.telecomnancy.projet.dto.Dto;

public class WriteCsv<T extends Dto> {

    public WriteCsv() {

    }

    public void write(List<T> o, String filename) throws IOException {

	try (BufferedWriter fos = new BufferedWriter(new FileWriter("../../communication/" + filename + ".csv"))) {
	    for (T attribute : o) {
		String line = attribute.toString();
		fos.write(line);
		fos.newLine();
	    }
	    System.out.println(o.get(0).getClass().getSimpleName() + " : done");
	}
    }

}