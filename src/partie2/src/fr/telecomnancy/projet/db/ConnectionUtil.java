package fr.telecomnancy.projet.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionUtil {

	private static Connection con = null;

	private ConnectionUtil() {

	}

	public static Connection getConnection() throws SQLException {
		if (con == null || con.isClosed()) {
			String url = "jdbc:oracle:thin:@//oracle.telecomnancy.univ-lorraine.fr:1521/TNCY";
			String user = "grp10";
			String passwd = "TPOracle";
			con = DriverManager.getConnection(url, user, passwd);
		}
		return con;
	}


}