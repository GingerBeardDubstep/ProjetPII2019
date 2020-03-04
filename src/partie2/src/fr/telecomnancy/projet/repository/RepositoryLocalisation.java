package fr.telecomnancy.projet.repository;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Localisation;
import fr.telecomnancy.projet.specification.SpecificationLocalisation;

public class RepositoryLocalisation implements Repository<Localisation, SpecificationLocalisation> {

	public RepositoryLocalisation() {

	}

	@Override
	public boolean add(Localisation localisation) throws SQLException {
		String sql = "INSERT INTO LOCALISATION (LATITUDE, LONGITUDE, VILLE,PAYS,ALTITUDE,DECALAGE_HORAIRE,DST,TZDATA) VALUES (?,?,?,?,?,?,?,?)";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setDouble(1, localisation.getLatitude());
		state.setDouble(2, localisation.getLongitude());
		state.setString(3, localisation.getVille());
		state.setString(4, localisation.getPays());
		state.setInt(5, localisation.getAltitude());
		state.setInt(6, localisation.getDecalage_horaire());
		state.setString(7, localisation.getDst());
		state.setString(8, localisation.getTzdata());

		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean update(Localisation localisation) throws SQLException {
		String sql = "UPDATE LOCALISATION SET VILLE = ?,PAYS = ?,ALTITUDE = ?,DECALAGE_HORAIRE = ?, DST = ?,TZDATA = ? ";
		sql += "WHERE LATITUDE = ? AND LONGITUDE = ?";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setDouble(7, localisation.getLatitude());
		state.setDouble(8, localisation.getLongitude());
		state.setString(1, localisation.getVille());
		state.setString(2, localisation.getPays());
		state.setInt(3, localisation.getAltitude());
		state.setInt(4, localisation.getDecalage_horaire());
		state.setString(5, localisation.getDst());
		state.setString(6, localisation.getTzdata());
		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean remove(Localisation localisation) throws SQLException {
		String sql = "DELETE FROM LOCALISATION WHERE LATITUDE = ? AND LONGITUDE = ?";
		boolean deleted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setDouble(1, localisation.getLatitude());
		state.setDouble(2, localisation.getLongitude());
		deleted = state.executeUpdate() > 0;

		return deleted;
	}

	@Override
	public List<Localisation> query(SpecificationLocalisation specification) throws SQLException {
		Connection conn = ConnectionUtil.getConnection();
		List<Localisation> listLocalisation = new ArrayList<>();
		String sql = specificationsSQL(specification);

		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					double latitude = resultSet.getDouble("LATITUDE");
					double longitude = resultSet.getDouble("LONGITUDE");
					String ville = resultSet.getString("VILLE");
					String pays = resultSet.getString("PAYS");
					int altitude = resultSet.getInt("ALTITUDE");
					int decalage_horaire = resultSet.getInt("DECALAGE_HORAIRE");
					String dst = resultSet.getString("DST");
					String tzdata = resultSet.getString("TZDATA");

					Localisation localisation = new Localisation(latitude, longitude, ville,pays,altitude,decalage_horaire,dst,tzdata);
	 				listLocalisation.add(localisation);

				}
			}
		}
		return listLocalisation;

	}


	// if there is multiple conditions AND or OR
	public String specificationsSQL(SpecificationLocalisation specification) {
		List<String> sql = new ArrayList<>();
		sql.add("SELECT * FROM LOCALISATION WHERE");

		if (specification.specifiedVille()) {
			for(String ville : specification.getVille()) {
				sql.add("UPPER(VILLE) = UPPER('" + ville + "')");
			}
		}

		if (specification.specifiedPays()) {
			for(String pays : specification.getPays()) {
				sql.add("UPPER(PAYS) = UPPER('" + pays + "')");
			}
		}
		
		// if more than 1 spec is chosen
		for (int i = 2; i < sql.size(); i++) {
			sql.set(i, specification.getConnector() + " " + sql.get(i));
		}

		return String.join(" ", sql);
	}

	@Override
	public List<Localisation> findAll() throws SQLException {
		List<Localisation> listlocalisation = new ArrayList<>();
		String sql = "SELECT LATITUDE, LONGITUDE, VILLE,PAYS,ALTITUDE,DECALAGE_HORAIRE,DST,TZDATA FROM LOCALISATION ORDER BY VILLE";

		Connection conn = ConnectionUtil.getConnection();
		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					double latitude = resultSet.getDouble("LATITUDE");
					double longitude = resultSet.getDouble("LONGITUDE");
					String ville = resultSet.getString("VILLE");
					String pays = resultSet.getString("PAYS");
					int altitude = resultSet.getInt("ALTITUDE");
					int decalage_horaire = resultSet.getInt("DECALAGE_HORAIRE");
					String dst = resultSet.getString("DST");
					String tzdata = resultSet.getString("TZDATA");

					Localisation localisation = new Localisation(latitude, longitude, ville,pays,altitude,decalage_horaire,dst,tzdata);
	 				listlocalisation.add(localisation);

				}
			}
		}
		return listlocalisation;
	}


}
