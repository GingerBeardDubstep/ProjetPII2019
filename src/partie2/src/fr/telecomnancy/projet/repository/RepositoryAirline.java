package fr.telecomnancy.projet.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Airline;
import fr.telecomnancy.projet.specification.SpecificationAirline;

public class RepositoryAirline implements Repository<Airline, SpecificationAirline> {

	public RepositoryAirline() {

	}

	@Override
	public boolean add(Airline airline) throws SQLException {
		String sql = "INSERT INTO AIRLINES (AIRLINEID, NAME, ALIAS, IATA, ICAO, CALLSIGN, COUNTRY, ACTIVE) VALUES (?,?,?,?,?,?,?,?)";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setInt(1, airline.getAirlineID());
		state.setString(2, airline.getName());
		state.setString(3, airline.getAlias());
		state.setString(4, airline.getIata());
		state.setString(5, airline.getIcao());
		state.setString(6, airline.getCallsign());
		state.setString(7, airline.getCountry());
		state.setString(8, airline.getActive());
		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean update(Airline airline) throws SQLException {
		String sql = "UPDATE AIRLINES SET NAME = ?, ALIAS = ?, IATA = ?, ICAO = ?, CALLSIGN = ?, COUNTRY = ?, ACTIVE = ?";
		sql += "WHERE AIRLINEID = ?";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setInt(8, airline.getAirlineID());
		state.setString(1, airline.getName());
		state.setString(2, airline.getAlias());
		state.setString(3, airline.getIata());
		state.setString(4, airline.getIcao());
		state.setString(5, airline.getCallsign());
		state.setString(6, airline.getCountry());
		state.setString(7, airline.getActive());
		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean remove(Airline airline) throws SQLException {
		String sql = "DELETE FROM AIRLINES WHERE AIRLINEID = ?";
		boolean deleted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setInt(1, airline.getAirlineID());
		deleted = state.executeUpdate() > 0;

		return deleted;
	}

	@Override
	public List<Airline> query(SpecificationAirline specification) throws SQLException {
		List<Airline> listAirline = new ArrayList<>();
		Connection conn = ConnectionUtil.getConnection();
		try (Statement state = conn.createStatement()) {

			String sql = specificationsSQL(specification);

			try (ResultSet resultSet = state.executeQuery(sql)) {

				while (resultSet.next()) {
					int airlineID = resultSet.getInt("AIRLINEID");
					String name = resultSet.getString("NAME");
					String alias = resultSet.getString("ALIAS");
					String iata = resultSet.getString("IATA");
					String icao = resultSet.getString("ICAO");
					String callsign = resultSet.getString("CALLSIGN");
					String country = resultSet.getString("COUNTRY");
					String active = resultSet.getString("ACTIVE");

					Airline airline = new Airline(airlineID, name, alias, iata, icao, callsign, country, active);
					listAirline.add(airline);
				}
			}
		}

		return listAirline;
	}

	// if there is multiple conditions AND or OR
	public String specificationsSQL(SpecificationAirline specification) {

		List<String> sql = new ArrayList<>();
		sql.add("SELECT * FROM AIRLINES WHERE");

		if (specification.specifiedName()) {
			for(String name : specification.getName()) {
				sql.add("UPPER(NAME) = UPPER(\'" + name + "\')");
			}
		}
		if (specification.specifiedId()) {
			for(long id : specification.getId()) {
				sql.add("AIRLINEID = " + id + " ");
			}
		}
		// if more than 1 spec is chosen
		for (int i = 2; i < sql.size(); i++) {
			sql.set(i, specification.getConnector() + " " + sql.get(i));
		}

		return String.join(" ", sql);
	}

	@Override
	public List<Airline> findAll() throws SQLException {
		List<Airline> listAirline = new ArrayList<>();
		String sql = "SELECT AIRLINEID,NAME,ALIAS,IATA,ICAO,CALLSIGN,COUNTRY,ACTIVE FROM AIRLINES ORDER BY AIRLINEID";

		Connection conn = ConnectionUtil.getConnection();
		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					int airlineID = resultSet.getInt("AIRLINEID");
					String name = resultSet.getString("NAME");
					String alias = resultSet.getString("ALIAS");
					String iata = resultSet.getString("IATA");
					String icao = resultSet.getString("ICAO");
					String callsign = resultSet.getString("CALLSIGN");
					String country = resultSet.getString("COUNTRY");
					String active = resultSet.getString("ACTIVE");

					Airline airline = new Airline(airlineID, name, alias, iata, icao, callsign, country, active);
					listAirline.add(airline);

				}
			}		return listAirline;
		}
	}
}
