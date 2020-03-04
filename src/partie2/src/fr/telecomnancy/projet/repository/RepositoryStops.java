package fr.telecomnancy.projet.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Stops;
import fr.telecomnancy.projet.specification.SpecificationStops;

public class RepositoryStops implements Repository<Stops, SpecificationStops> {

    public RepositoryStops() {

    }

    @Override
    public boolean add(Stops stops) throws SQLException {
	String sql = "INSERT INTO STOPS (STOPID, IDFLIGHT, AIRPORT_DEP, AIRPORT_DEST, FLIGHTNUMBER, STOPORDER) VALUES (?,?,?,?,?,?)";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, stops.getStopid());
	state.setInt(2, stops.getIdflight());
	state.setString(3, stops.getAirport_dep());
	state.setString(4, stops.getAirport_dest());
	state.setString(5, stops.getFlightnumber());
	state.setInt(6, stops.getStoporder());

	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean update(Stops stops) throws SQLException {
	String sql = "UPDATE STOPS SET IDFLIGHT =? , AIRPORT_DEP = ? , AIRPORT_DEST = ?, FLIGHTNUMBER = ?, STOPORDER = ?";
	sql += "WHERE STOPID = ?";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(6, stops.getStopid());
	state.setInt(1, stops.getIdflight());
	state.setString(2, stops.getAirport_dep());
	state.setString(3, stops.getAirport_dest());
	state.setString(4, stops.getFlightnumber());
	state.setInt(5, stops.getStoporder());

	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean remove(Stops stops) throws SQLException {
	String sql = "DELETE FROM STOPS WHERE STOPID = ?";
	boolean deleted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, stops.getStopid());
	deleted = state.executeUpdate() > 0;

	return deleted;
    }

    @Override
    public List<Stops> query(SpecificationStops specification) throws SQLException {
	Connection conn = ConnectionUtil.getConnection();
	List<Stops> listStops = new ArrayList<>();
	String sql = specificationsSQL(specification);

	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int stopid = resultSet.getInt("STOPID");
		    int idflight = resultSet.getInt("IDFLIGHT");
		    String airport_dep = resultSet.getString("AIRPORT_DEP");
		    String airport_dest = resultSet.getString("AIRPORT_DEST");
		    String flightnumber = resultSet.getString("FLIGHTNUMBER");
		    int stoporder = resultSet.getInt("STOPORDER");

		    Stops stops = new Stops(stopid, idflight, airport_dep, airport_dest, flightnumber, stoporder);
		    listStops.add(stops);

		}
	    }
	}
	return listStops;

    }

    // if there is multiple conditions AND or OR
    public String specificationsSQL(SpecificationStops specification) {
	List<String> sql = new ArrayList<>();
	sql.add("SELECT * FROM STOPS WHERE");

	if (specification.specifiedAirport_dep()) {
	    for (String airport : specification.getAirport_dep()) {
		sql.add("UPPER(AIRPORT_DEP) = UPPER('" + airport + "')");
	    }
	}

	if (specification.specifiedAirport_dest()) {
	    for (String airport : specification.getAirport_dest()) {
		sql.add("UPPER(AIRPORT_DEST) = UPPER('" + airport + "')");
	    }
	}

	if (specification.specifiedStop_id()) {
	    for (Integer id : specification.getStopId()) {
		sql.add("UPPER(STOPID) = " + id);
	    }
	}

	// if more than 1 spec is chosen
	for (int i = 2; i < sql.size(); i++) {
	    sql.set(i, specification.getConnector() + " " + sql.get(i));
	}

	return String.join(" ", sql);
    }

    @Override
    public List<Stops> findAll() throws SQLException {
	List<Stops> listStops = new ArrayList<>();
	String sql = "SELECT STOPID, IDFLIGHT, AIRPORT_DEP, AIRPORT_DEST, FLIGHTNUMBER, STOPORDER FROM STOPS ORDER BY STOPID";

	Connection conn = ConnectionUtil.getConnection();
	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int stopid = resultSet.getInt("STOPID");
		    int idflight = resultSet.getInt("IDFLIGHT");
		    String airport_dep = resultSet.getString("AIRPORT_DEP");
		    String airport_dest = resultSet.getString("AIRPORT_DEST");
		    String flightnumber = resultSet.getString("FLIGHTNUMBER");
		    int stoporder = resultSet.getInt("STOPORDER");

		    Stops stops = new Stops(stopid, idflight, airport_dep, airport_dest, flightnumber, stoporder);
		    listStops.add(stops);
		}
	    }
	}
	return listStops;
    }

}
