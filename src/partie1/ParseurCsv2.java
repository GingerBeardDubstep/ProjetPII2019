package src.partie1;
import java.io.*;

public class ParseurCsv2{
	public static boolean testFlightnumber(String[] t){
		boolean tst=true;
		if(t.length!=3){
			tst=false;
		}else{
			if(t[0].length()!=3&&t[0].length()!=2){ //test si IATA ou ICAO pour Airline
				tst=false;
			}
			if(t[1]==""){
				tst=false;
			}
			String[] tabArrets = t[2].split("-");
			for(int i=0;i<tabArrets.length;i++){
				if(tabArrets[i].length()!=4&&tabArrets[i].length()!=3){ //Test si IATA ou ICAO pour route
					tst=false;
				}
			}
		}
		return(tst);
	}
	public static String[] nettoyage(String line){ //Sert à enlever les ""
		String[] tab = line.split(",");			   //et à mettre à  quand : ,,  ,"", ,\N,
		for(int i=0;i<tab.length;i++){
			String val="";
			for(int j=0;j<tab[i].length();j++){
				boolean test = true;
				switch(tab[i].charAt(j)){
					case '"' :
						break;
					case '\\' :
						val="";
						j++;
						break;
					case 'N' :
						if(j==0&&tab[i].length()==4){
							if(tab[i].charAt(j+1)=='U'||tab[i].charAt(j+1)=='u'){
								if(tab[i].charAt(j+2)=='L'||tab[i].charAt(j+2)=='l'){
									if(tab[i].charAt(j+3)=='L'||tab[i].charAt(j+3)=='l'){
										val="";
										j=4;
										test=false;
									}
								}
							}
						}
						if(test){
							val+=tab[i].charAt(j);
						}
						
						break;

					case 'n' :
						if(j==0&&tab[i].length()==4){
							if(tab[i].charAt(j+1)=='U'||tab[i].charAt(j+1)=='u'){
								if(tab[i].charAt(j+2)=='L'||tab[i].charAt(j+2)=='l'){
									if(tab[i].charAt(j+3)=='L'||tab[i].charAt(j+3)=='l'){
										val="";
										j=4;
										test=false;
									}
								}
							}
						}
						if(test){
							val+=tab[i].charAt(j);
						}
						break;

					default :
						val+=tab[i].charAt(j);
				}
			}
			tab[i]=val;
		}
		return(tab);
	}
	//Parseur pour flightnumbers
	public static void parseCleanFN(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/flightnumbers.csv","UTF-8"); //Pour flighnumbers.csv
		PrintWriter writerRoute = new PrintWriter("cleaned_data/escales.csv","UTF-8"); //Pour flightnumber_route.csv
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int cpt=0;
		int idVol = 0; //identifiant pour les vols de flight_number (clé primaire)
		int idEscales = 0; //identifiant pour les escales de Escales (clé primaire)
		while(line!=null){
			String[] tab = nettoyage(line);
			boolean tst=testFlightnumber(tab);
			if(tst){
				String[] tabRoute = tab[2].split("-");

				String tot = Integer.toString(idVol) + "," + tab[1] + "," + tab[0] + "," + Integer.toString(tabRoute.length - 2);
				writer.println(tot);

				for(int i=0;i<tabRoute.length;i++){
						if (i< tabRoute.length-1){
						String totRoute = Integer.toString(idEscales) + "," + Integer.toString(idVol) + "," +tab[1]+","+tabRoute[i]+","+tabRoute[i+1]+","+ Integer.toString(i+1);
						writerRoute.println(totRoute); //On met dans flightnumber_route.csv toutes les routes possibles avec ce chemin en indiquant le nombre d'arrets
						idEscales++;

						}
						
				}
			}else{
				cpt++;
			}
			line=lecteur.readLine();
			idVol++;
		}
		writer.close(); 
		writerRoute.close();//Fermeture des writer
		System.out.println(cpt+" données non valides supprimées dans flightnumbers et 0 modifiées");
	}

	//Parseur pour la table des villes
		public static void parseCleanCT(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/city.csv","UTF-8"); //Pour flighnumbers.csv
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int id = -1; //identifiant pour les villes même si il semble y en avoir un (on est sûrs que celui que m'on crée est unique)
		while(line!=null){
			String[] tab = nettoyage(line);
			String tot = Integer.toString(id) + "," + tab[0] + "," + tab[2] + "," + tab[3] + "," + tab[4];
			writer.println(tot);
			line=lecteur.readLine();
			id++;
		}
		writer.close(); 
	}
	//Parseur pour plane
	public static void parseCleanP(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/planes.csv","UTF-8");
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int cpt1=0; //Compteur de suppressions
		int cpt2=0; //Compteur de modifications
		while(line!=null){
			String[] tab = nettoyage(line);
			boolean tst=true;
			if(tab.length!=3){
				tst=false;
			}else{
				if(tab[0]==""){ //Test sur nom 
					tst=false;
				}
				if(tab[1].length()!=3&&tab[1]!=""){
					tab[1]="";		//mise à  si IATA incorrect
					cpt2++;
				}
				if(tab[2].length()!=4){ //mise à  si ICAO incorrect
					tab[2]="";
					cpt2++;
				}
				if(tab[1]==""&&tab[2]==""){
					tst=false;			//Suppression de la donnée si les deux codes sont à 
				}
			}
			String tot=String.join(",",tab);
			if(tst){
				writer.println(tot);
			}else{
				cpt1++;
			}
			line=lecteur.readLine();
		}
		writer.close(); //Fermeture du writer
		System.out.println(cpt1+" données non valides supprimées dans planes et "+cpt2+" données modifiées");
	}
	//Parseur pour routes
	public static void parseCleanR(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/routes.csv","UTF-8");// Pour routes.csv
		PrintWriter writerEqu = new PrintWriter("cleaned_data/equipements.csv","UTF-8");// Pour equipements.csv
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int cpt1=0;
		int cpt2=0;
		int increment = 0; //incrément reprensente l'idRoute
		int idEquip = 0; //sert d'id pour la table equipement

		while(line!=null){
			String[] tab = nettoyage(line);
			boolean tst=true;
			
			
			if(tab.length!=9){ //Test sur la taille de la donnée
				tst=false;
			}else{
			if(tab[0].length()!=2&&tab[0].length()!=3){
				tst=false; //Test si airline est IATA ou ICAO
			}
			try{
				if(tab[1]!=""){
					Integer.parseInt(tab[1]);
				}
				if(tab[3]!=""){
					Integer.parseInt(tab[3]);
				}
				if(tab[5]!=""){
					Integer.parseInt(tab[5]);
				}
				Integer.parseInt(tab[7]);
			}catch(NumberFormatException ex){
				tst=false;
				//Test airlineID,airport_destID, airport_depID, arrets sont bien des entier
			}
			if(tab[2].length()!=4&&tab[2].length()!=3){
				tst=false;
				//Test si airport_dep est IATA ou ICAO
			}
			if(tab[4].length()!=4&&tab[4].length()!=3){
				tst=false;
				//Test si airport_dest est IATA ou ICAO
			}
			if(tab[6]!=""){
				if(tab[6].charAt(0)!='Y'){
					tst=false;
				}
			}

			String[] tabEquip=tab[8].split(" ");
			for(int i=0;i<tabEquip.length;i++){
				if(tabEquip[i].length()!=3){//Test sur Equipement
					if(tabEquip[i].length()==0){//Tentative de modifier les données
						String[] temp=new String[tabEquip.length-1];
						for(int j=0;j<tabEquip.length;j++){
							if(j<i){
								temp[j]=tabEquip[j];
								
							}else if(j>i){
								temp[j-1]=tabEquip[j];
							}
						}
						tabEquip=temp;
						cpt2++;
					}else{
						tst=false;
					}
					tab[8]=String.join(" ",tabEquip);
										
				}
				if(tst){
					String totEqu=Integer.toString(idEquip) + "," +Integer.toString(increment) +","+tab[0]+","+tab[2]+","+tab[4]+","+tabEquip[i];
					writerEqu.println(totEqu);
					idEquip++;
				}
			}
			
			
			}
			if(tst){
				String tot=Integer.toString(increment) +","+tab[0]+","+tab[1]+","+tab[2]+","+tab[3]+","+tab[4]+","+tab[5]+","+tab[6]+","+tab[7];
				writer.println(tot); //Print dans routes.csv
			}else{
				cpt1++;
			}
			line=lecteur.readLine();
			increment++;

		}
		writer.close();
		writerEqu.close();
		System.out.println(cpt1+" données non valides supprimées dans routes et "+cpt2+" données modifiées");
	}

	public static void parseCleanAirp(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/airports.csv","UTF-8"); //Pour airports.csv
		PrintWriter writerLoc = new PrintWriter("cleaned_data/localisations.csv","UTF-8"); //Pour localisations.csv
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int cpt1=0;
		int cpt2=0;
		while(line!=null){
			String[] tab = nettoyage(line);
			boolean tst=true;
			if(tab.length==14){
				try{
					Integer.parseInt(tab[0]);
					Integer.parseInt(tab[8]);
					Double.parseDouble(tab[6]);
					Double.parseDouble(tab[7]);
					if(tab[9]!=""){
						Double.parseDouble(tab[9]);
					}
				}catch(NumberFormatException ex){
					//Test airportID et décalage horaire entier, lat long et alt doubles
					tst=false;
				}
				if(tab[1]==""){
					//Test Nom,Ville,Pays non 
					tst=false;
				}
				if(tab[4].length()!=3&&tab[4]!=""){ //Test IATA
					tab[4]="";
					cpt2++;
				}
				if(tab[5].length()!=4){ //Test IACO
					tab[5]="";
					cpt2++;
				}
				switch(tab[10]){ //test DST
					case "E":
						break;
					case "e":
						tab[10]="E";
						cpt2++;
						break;
					case "A":
						break;
					case "a":
						tab[10]="A";
						cpt2++;
						break;
					case "S":
						break;
					case "s":
						tab[10]="S";
						cpt2++;
						break;
					case "O":
						break;
					case "o":
						tab[10]="O";
						cpt2++;
						break;
					case "Z":
						break;
					case "z":
						tab[10]="Z";
						cpt2++;
						break;
					case "N":
						break;
					case "n":
						tab[10]="N";
						cpt2++;
						break;
					case "U":
						break;
					default :
						tab[10]="U";
						cpt2++;
						break;
				}
				switch(tab[12]){ //Test type
					case "airport":
						break;
					case "station":
						break;
					case "port":
						break;
					case "unknown":
						break;
					default :
						tab[12]="unknown";
						cpt2++;
				}
			}else{
				tst=false;
			}
			if(tst){
				String tot=tab[0]+","+tab[1]+","+tab[6]+","+tab[7]+","+tab[4]+","+tab[5]+","+tab[12]+","+tab[13];
				String totLoc=tab[6]+","+tab[7]+","+tab[2]+","+tab[3]+","+tab[8]+","+tab[9]+","+tab[10]+","+tab[11];
				writer.println(tot); //On écrit la partie de airports
				writerLoc.println(totLoc); //On écrit la partie localisations
			}else{
				cpt1++;
			}
			line=lecteur.readLine();
		}
		writer.close();
		writerLoc.close(); //Fermeture des writers
		System.out.println(cpt1+" données non valides supprimées dans airports et "+cpt2+" données modifiées");
	}

	public static void parseCleanAirl(String source) throws Exception{
		BufferedReader lecteur = null;
		PrintWriter writer = new PrintWriter("cleaned_data/airlines.csv","UTF-8");
		lecteur = new BufferedReader(new FileReader(source));
		String line = lecteur.readLine();
		int cpt1=0;
		int cpt2=0;
		while(line!=null){
			String[] tab = nettoyage(line);
			boolean tst=true;
			if(tab.length==8){//Test sur la longueur de la donnée
				try{
					Integer.parseInt(tab[0]);
				}catch(NumberFormatException ex){
					tst=false;
					//Test airlineID est entier
				}
				if(tab[1]==""){
					tst=false;
					//Test nom n'est pas 
				}
				if(tab[3].length()!=2&&tab[3]!=""){
					tab[3]="";
					cpt2++;
					//Modification si pas IATA
				}
				if(tab[4].length()!=3&&tab[4]!=""){
					tab[4]="";
					cpt2++;
					//Modification si pas ICAO
				}
				switch(tab[7]){ //Test sur Active
					case "Y" :
						break;
					case "y" :
						tab[7]="Y";
						cpt2++;
						//Modification si minuscule
						break;
					case "n" :
						tab[7]="N";
						cpt2++;
						//Modification si minuscule
						break;
					case "N" :
						break;
					case "" :
						break;
					default :
						tst=false;
						break;
				}
			}else{
				tst=false;
			}			
			String tot=String.join(",",tab);
			if(tst){
				writer.println(tot);
			}else{
				cpt1++;
			}
			line=lecteur.readLine();
		}
		writer.close(); //Fermeture du writer
		System.out.println(cpt1+" données non valides supprimées dans airlines et "+cpt2+" données modifiées");
	}

	public static void main(String[] argv) throws Exception{
		parseCleanFN("provided_data/flightnumbers.csv");
		parseCleanP("provided_data/planes.dat");
		parseCleanR("provided_data/routes.dat");
		parseCleanAirp("provided_data/airports.dat");
		parseCleanAirl("provided_data/airlines.dat");
		parseCleanCT("provided_data/worldcities.csv");
	}
}
