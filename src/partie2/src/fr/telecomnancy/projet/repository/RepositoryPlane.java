package fr.telecomnancy.projet.repository;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Plane;
import fr.telecomnancy.projet.specification.SpecificationPlane;

public class RepositoryPlane implements Repository<Plane, SpecificationPlane> {

	public RepositoryPlane() {

	}

	@Override
	public boolean add(Plane plane) throws SQLException {
		String sql = "INSERT INTO PLANES (NOM, IATA, ICAO, NB_DE_SIEGES, VITESSE_DE_CROISIERE, AUTONOMIE, CARBURANT) VALUES (?,?,?,?,?,?,?)";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setString(1, plane.getNom());
		state.setString(2, plane.getIata());
		state.setString(3, plane.getIcao());
		state.setInt(4, plane.getNbsieges());
		state.setInt(5, plane.getVitesse());
		state.setInt(6, plane.getAutonomie());
		state.setInt(7, plane.getCarburant());

		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean update(Plane plane) throws SQLException {
		String sql = "UPDATE PLANES SET IATA = ?, ICAO = ?, NB_DE_SIEGES = ?, VITESSE_DE_CROISIERE = ?, AUTONOMIE = ?, CARBURANT = ?";
		sql += "WHERE NOM = ?";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setString(7, plane.getNom());
		state.setString(1, plane.getIata());
		state.setString(2, plane.getIcao());
		state.setInt(3, plane.getNbsieges());
		state.setInt(4, plane.getVitesse());
		state.setInt(5, plane.getAutonomie());
		state.setInt(6, plane.getCarburant());
		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean remove(Plane plane) throws SQLException {
		String sql = "DELETE FROM PLANES WHERE NOM = ?";
		boolean deleted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setString(1, plane.getNom());
		deleted = state.executeUpdate() > 0;

		return deleted;
	}

	@Override
	public List<Plane> query(SpecificationPlane specification) throws SQLException {
		Connection conn = ConnectionUtil.getConnection();
		List<Plane> listPlane = new ArrayList<>();
		String sql = specificationsSQL(specification);

		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					String nom = resultSet.getString("NOM");
					String iata = resultSet.getString("IATA");
					String icao = resultSet.getString("ICAO");
					int nb_sieges = resultSet.getInt("NB_DE_SIEGES");
					int vitesse = resultSet.getInt("VITESSE_DE_CROISIERE");
					int autonome = resultSet.getInt("AUTONOMIE");
					int carburant = resultSet.getInt("CARBURANT");

					Plane plane = new Plane(nom, iata, icao,nb_sieges,vitesse,autonome,carburant);
	 				listPlane.add(plane);

				}
			}
		}
		return listPlane;

	}


	// if there is multiple conditions AND or OR
	public String specificationsSQL(SpecificationPlane specification) {
		List<String> sql = new ArrayList<>();
		sql.add("SELECT * FROM PLANES WHERE");

		if (specification.specifiedName()) {
			for(String name : specification.getName()) {
				sql.add("UPPER(NOM) = UPPER('" + name + "')");
			}
		}

		if (specification.specifiedSieges()) {
			for(Integer sieges : specification.getSieges()) {
				sql.add("UPPER(NB_DE_SIEGES) = UPPER('" + sieges + "')");
			}
		}
		
		if (specification.specifiedVitesse()) {
			for(Integer vitesse : specification.getVitesse()) {
				sql.add("UPPER(VITESSE_DE_CROISIERE) = UPPER('" + vitesse + "')");
			}
		}
		
		if (specification.specifiedAutonomie()) {
			for(Integer autonomie : specification.getAutonomie()) {
				sql.add("UPPER(AUTONOMIE) = UPPER('" + autonomie + "')");
			}
		}
		
		if (specification.specifiedCarburant()) {
			for(Integer carbu : specification.getCarburant()) {
				sql.add("UPPER(CARBURANT) = UPPER('" + carbu + "')");
			}
		}
		
		// if more than 1 spec is chosen
		for (int i = 2; i < sql.size(); i++) {
			sql.set(i, specification.getConnector() + " " + sql.get(i));
		}

		return String.join(" ", sql);
	}

	@Override
	public List<Plane> findAll() throws SQLException {
		List<Plane> listPlane = new ArrayList<>();
		String sql = "SELECT NOM, IATA, ICAO, NB_DE_SIEGES, VITESSE_DE_CROISIERE, AUTONOMIE, CARBURANT FROM PLANES ORDER BY NOM";

		Connection conn = ConnectionUtil.getConnection();
		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					String nom = resultSet.getString("NOM");
					String iata = resultSet.getString("IATA");
					String icao = resultSet.getString("ICAO");
					int nb_sieges = resultSet.getInt("NB_DE_SIEGES");
					int vitesse = resultSet.getInt("VITESSE_DE_CROISIERE");
					int autonome = resultSet.getInt("AUTONOMIE");
					int carburant = resultSet.getInt("CARBURANT");

					Plane plane = new Plane(nom, iata, icao,nb_sieges,vitesse,autonome,carburant);
	 				listPlane.add(plane);
				}
			}
		}
		return listPlane;
	}

}
