package fr.telecomnancy.projet.IO;
import fr.telecomnancy.projet.IO.*;
import fr.telecomnancy.projet.dto.*;
import fr.telecomnancy.projet.repository.*;
import fr.telecomnancy.projet.specification.*;
import java.sql.SQLException;
import java.util.*;
import java.io.*;
public class Test{
	public static void main(String[] argv) throws Exception{
		List<Airport> retAirp1 = new ArrayList<Airport>();
		ReadCsv read = new ReadCsv();
		retAirp1=read.readAirport("plusProche.csv");
		System.out.println(retAirp1.get(0).getName());
	}
}