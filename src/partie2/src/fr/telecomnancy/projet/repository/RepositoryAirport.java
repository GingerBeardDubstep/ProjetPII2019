package fr.telecomnancy.projet.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Airport;
import fr.telecomnancy.projet.specification.SpecificationAirport;

public class RepositoryAirport implements Repository<Airport, SpecificationAirport> {

    public RepositoryAirport() {

    }

    @Override
    public boolean add(Airport airport) throws SQLException {
	String sql = "INSERT INTO AIRPORTS (AIRPORTID, NAME, LATITUDE,LONGITUDE, IATA, ICAO, TYPE, DATASOURCE) VALUES (?,?,?,?,?,?,?,?)";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, airport.getAirportID());
	state.setString(2, airport.getName());
	state.setDouble(3, airport.getLatitude());
	state.setDouble(4, airport.getLongitude());
	state.setString(5, airport.getIata());
	state.setString(6, airport.getIcao());
	state.setString(7, airport.getType());
	state.setString(8, airport.getDatasource());
	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean update(Airport airport) throws SQLException {
	String sql = "UPDATE AIRPORTS SET NAME = ?, LATITUDE = ?,LONGITUDE = ?, IATA = ?, ICAO = ?, TYPE = ?, DATASOURCE = ?";
	sql += "WHERE AIRPORTID = ?";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(8, airport.getAirportID());
	state.setString(1, airport.getName());
	state.setDouble(2, airport.getLatitude());
	state.setDouble(3, airport.getLongitude());
	state.setString(4, airport.getIata());
	state.setString(5, airport.getIcao());
	state.setString(6, airport.getType());
	state.setString(7, airport.getDatasource());
	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean remove(Airport airport) throws SQLException {
	String sql = "DELETE FROM AIRPORTS WHERE AIRPORTID = ?";
	boolean deleted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, airport.getAirportID());
	deleted = state.executeUpdate() > 0;

	return deleted;
    }

    @Override
    public List<Airport> query(SpecificationAirport specification) throws SQLException {
	Connection conn = ConnectionUtil.getConnection();
	List<Airport> listAirport = new ArrayList<>();
	String sql = specificationsSQL(specification);

	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int airportID = resultSet.getInt("AIRPORTID");
		    String name = resultSet.getString("NAME");
		    Double latitude = resultSet.getDouble("LATITUDE");
		    Double longitude = resultSet.getDouble("LONGITUDE");
		    String iata = resultSet.getString("IATA");
		    String icao = resultSet.getString("ICAO");
		    String type = resultSet.getString("TYPE");
		    String datasource = resultSet.getString("DATASOURCE");

		    Airport airport = new Airport(airportID, name, latitude, longitude, iata, icao, type, datasource);
		    listAirport.add(airport);

		}
	    }
	}
	return listAirport;

    }

    // if there is multiple conditions AND or OR
    public String specificationsSQL(SpecificationAirport specification) {
	List<String> sql = new ArrayList<>();
	sql.add("SELECT * FROM AIRPORTS WHERE");

	if (specification.specifiedName()) {
	    for (String name : specification.getName()) {
		sql.add("UPPER(NAME) = UPPER(\'" + name + "\')");
	    }
	}
	if (specification.specifiedId()) {
	    for (long id : specification.getId()) {
		sql.add("AIRPORTID = " + id + " ");
	    }
	}
	if (specification.specifiedLatitude()) {
	    for (double lat : specification.getLatitude()) {
		sql.add("LATITUDE = " + lat + " ");
	    }
	}
	if (specification.specifiedLongitude()) {
	    for (double lon : specification.getLongitude()) {
		sql.add("LONGITUDE = " + lon + " ");
	    }
	}
	// if more than 1 spec is chosen
	for (int i = 2; i < sql.size(); i++) {
	    sql.set(i, specification.getConnector() + " " + sql.get(i));
	}

	return String.join(" ", sql);
    }

    @Override
    public List<Airport> findAll() throws SQLException {
	List<Airport> listairport = new ArrayList<>();
	String sql = "SELECT AIRPORTID, NAME, LATITUDE,LONGITUDE, IATA, ICAO, TYPE, DATASOURCE FROM AIRPORTS ORDER BY AIRPORTID";

	Connection conn = ConnectionUtil.getConnection();
	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int airportID = resultSet.getInt("AIRPORTID");
		    String name = resultSet.getString("NAME");
		    Double latitude = resultSet.getDouble("LATITUDE");
		    Double longitude = resultSet.getDouble("LONGITUDE");
		    String iata = resultSet.getString("IATA");
		    String icao = resultSet.getString("ICAO");
		    String type = resultSet.getString("TYPE");
		    String datasource = resultSet.getString("DATASOURCE");

		    Airport airport = new Airport(airportID, name, latitude, longitude, iata, icao, type, datasource);
		    listairport.add(airport);

		}
	    }
	}
	return listairport;
    }

}
