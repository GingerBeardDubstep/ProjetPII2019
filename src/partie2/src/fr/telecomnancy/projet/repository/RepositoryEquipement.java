package fr.telecomnancy.projet.repository;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Equipement;
import fr.telecomnancy.projet.specification.SpecificationEquipement;

public class RepositoryEquipement implements Repository<Equipement, SpecificationEquipement> {

		public RepositoryEquipement() {

		}
		@Override
		public boolean add(Equipement equipement) throws SQLException {
			String sql = "INSERT INTO EQUIPEMENT (AIRLINE, AIRPORT_DEP, AIRPORT_DEST,CODE, ROUTEID, EQUID) VALUES (?,?,?,?,?,?)";
			boolean inserted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setString(1, equipement.getAirline());
			state.setString(2, equipement.getAirportdep());
			state.setString(3, equipement.getAirportdest());
			state.setString(4, equipement.getCode());
			state.setInt(5, equipement.getRouteId());
			state.setInt(6, equipement.getEquid());
			inserted = state.executeUpdate() > 0;

			return inserted;
		}

		@Override
		public boolean update(Equipement equipement) throws SQLException {
			String sql = "UPDATE EQUIPEMENT SET AIRLINE = ?, AIRPORT_DEP = ?,AIRPORT_DEST = ?, CODE = ?, ROUTEID = ?";
			sql += "WHERE EQUID = ?";
			boolean inserted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setString(1, equipement.getAirline());
			state.setString(2, equipement.getAirportdep());
			state.setString(3, equipement.getAirportdest());
			state.setString(4, equipement.getCode());
			state.setInt(5, equipement.getRouteId());
			state.setInt(6, equipement.getEquid());
			inserted = state.executeUpdate() > 0;

			return inserted;
		}

		@Override
		public boolean remove(Equipement equipement) throws SQLException {
			String sql = "DELETE FROM EQUIPEMENT WHERE EQUID = ?";
			boolean deleted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setInt(1, equipement.getEquid());
			deleted = state.executeUpdate() > 0;

			return deleted;
		}
		
		@Override
		public List<Equipement> query(SpecificationEquipement specification) throws SQLException {
			Connection conn = ConnectionUtil.getConnection();
			List<Equipement> listEquipement = new ArrayList<>();
			String sql = specificationsSQL(specification);

			try(Statement state = conn.createStatement()){
				try(ResultSet resultSet = state.executeQuery(sql)){

					while (resultSet.next()) {
						String airline = resultSet.getString("AIRLINE");
						String airport_dep = resultSet.getString("AIRPORT_DEP");
						String airport_dest = resultSet.getString("AIRPORT_DEST");
						String code = resultSet.getString("CODE");
						int routeid = resultSet.getInt("ROUTEID");
						int equid = resultSet.getInt("EQUID");
						
						Equipement equipement = new Equipement(airline, airport_dep, airport_dest,code, routeid, equid);
						listEquipement.add(equipement);

					}
				}
			}
			return listEquipement;

		}


		// if there is multiple conditions AND or OR
		public String specificationsSQL(SpecificationEquipement specification) {
			List<String> sql = new ArrayList<>();
			sql.add("SELECT * FROM EQUIPEMENT WHERE");

			if (specification.specifiedCode()) {
				for(String code : specification.getCode()) {
					sql.add("UPPER(CODE) = UPPER(\'" + code + "\')");
				}
			}

			// if more than 1 spec is chosen
			for (int i = 2; i < sql.size(); i++) {
				sql.set(i, specification.getConnector() + " " + sql.get(i));
			}

			return String.join(" ", sql);
		}

		@Override
		public List<Equipement> findAll() throws SQLException {
			List<Equipement> listequipement = new ArrayList<>();
			String sql = "SELECT AIRLINE, AIRPORT_DEP, AIRPORT_DEST,CODE, ROUTEID, EQUID FROM EQUIPEMENT ORDER BY EQUID";

			Connection conn = ConnectionUtil.getConnection();
			try(Statement state = conn.createStatement()){
				try(ResultSet resultSet = state.executeQuery(sql)){

					while (resultSet.next()) {
						String airline = resultSet.getString("AIRLINE");
						String airport_dep = resultSet.getString("AIRPORT_DEP");
						String airport_dest = resultSet.getString("AIRPORT_DEST");
						String code = resultSet.getString("CODE");
						int routeid = resultSet.getInt("ROUTEID");
						int equid = resultSet.getInt("EQUID");
						
						Equipement equipement = new Equipement(airline, airport_dep, airport_dest,code, routeid, equid);
						listequipement.add(equipement);

					}
				}
			}
			return listequipement;
		}

	}
