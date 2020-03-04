package fr.telecomnancy.projet.repository;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Route;
import fr.telecomnancy.projet.specification.SpecificationRoute;

public class RepositoryRoute implements Repository<Route, SpecificationRoute> {

	public RepositoryRoute() {

	}

	@Override
	public boolean add(Route route) throws SQLException {
		String sql = "INSERT INTO ROUTES (AIRLINE, AIRLINEID, AIRPORT_DEP, AIRPORT_DEPID, AIRPORT_DEST, AIRPORT_DESTID, CODESHARE,ARRETS,ROUTEID) VALUES (?,?,?,?,?,?,?,?,?)";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setString(1, route.getAirline());
		state.setInt(2, route.getAirlineID());
		state.setString(3, route.getAirportdep());
		state.setInt(4, route.getAirportdepID());
		state.setString(5, route.getAirportdest());
		state.setInt(6, route.getAirportdestID());
		state.setString(7, route.getCodeshare());
		state.setInt(8, route.getArrets());
		state.setInt(9, route.getRouteId());

		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean update(Route route) throws SQLException {
		String sql = "UPDATE ROUTES SET AIRLINE = ?, AIRLINEID = ?, AIRPORT_DEP = ?, AIRPORT_DEPID = ?, AIRPORT_DEST = ?, AIRPORT_DESTID = ?, CODESHARE = ?, ARRETS = ?";
		sql += "WHERE ROUTEID = ?";
		boolean inserted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setString(1, route.getAirline());
		state.setInt(2, route.getAirlineID());
		state.setString(3, route.getAirportdep());
		state.setInt(4, route.getAirportdepID());
		state.setString(5, route.getAirportdest());
		state.setInt(6, route.getAirportdestID());
		state.setString(7, route.getCodeshare());
		state.setInt(8, route.getArrets());
		state.setInt(9, route.getRouteId());
		
		inserted = state.executeUpdate() > 0;

		return inserted;
	}

	@Override
	public boolean remove(Route route) throws SQLException {
		String sql = "DELETE FROM ROUTES WHERE ROUTEID = ?";
		boolean deleted = false;

		Connection conn = ConnectionUtil.getConnection();
		PreparedStatement state = conn.prepareStatement(sql);
		state.setInt(1, route.getRouteId());
		deleted = state.executeUpdate() > 0;

		return deleted;
	}

	@Override
	public List<Route> query(SpecificationRoute specification) throws SQLException {
		Connection conn = ConnectionUtil.getConnection();
		List<Route> listRoute = new ArrayList<>();
		String sql = specificationsSQL(specification);

		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){

				while (resultSet.next()) {
					String airline = resultSet.getString("AIRLINE");
					int airlineid = resultSet.getInt("AIRLINEID");
					String airport_dep = resultSet.getString("AIRPORT_DEP");
					int airport_depid = resultSet.getInt("AIRPORT_DEPID");
					String airport_dest = resultSet.getString("AIRPORT_DEST");
					int airport_destid = resultSet.getInt("AIRPORT_DESTID");
					String codeshare = resultSet.getString("CODESHARE");
					int arret = resultSet.getInt("ARRETS");
					int routeid = resultSet.getInt("ROUTEID");

					Route route = new Route(airline, airlineid, airport_dep,airport_depid,airport_dest,airport_destid,codeshare,arret,routeid);
	 				listRoute.add(route);

				}
			}
		}
		return listRoute;

	}


	// if there is multiple conditions AND or OR
	public String specificationsSQL(SpecificationRoute specification) {
		List<String> sql = new ArrayList<>();
		sql.add("SELECT * FROM ROUTES WHERE");

		if (specification.specifiedAirport_dep()) {
			for(String airport : specification.getAirport_dep()) {
				sql.add("UPPER(AIRPORT_DEP) = UPPER('" + airport + "')");
			}
		}

		if (specification.specifiedAirport_dest()) {
			for(String airport : specification.getAirport_dest()) {
				sql.add("UPPER(AIRPORT_DEST) = UPPER('" + airport + "')");
			}
		}		
		
		//if more than 1 spec is chosen
		for (int i = 2; i < sql.size(); i++) {
			sql.set(i, specification.getConnector() + " " + sql.get(i));
		}

		return String.join(" ", sql);
	}

	@Override
	public List<Route> findAll() throws SQLException {
		List<Route> listRoute = new ArrayList<>();
		String sql = "SELECT AIRLINE, AIRLINEID, AIRPORT_DEP, AIRPORT_DEPID, AIRPORT_DEST, AIRPORT_DESTID, CODESHARE,ARRETS,ROUTEID FROM ROUTES ORDER BY ROUTEID";

		Connection conn = ConnectionUtil.getConnection();
		try(Statement state = conn.createStatement()){
			try(ResultSet resultSet = state.executeQuery(sql)){


				while (resultSet.next()) {
					String airline = resultSet.getString("AIRLINE");
					int airlineid = resultSet.getInt("AIRLINEID");
					String airport_dep = resultSet.getString("AIRPORT_DEP");
					int airport_depid = resultSet.getInt("AIRPORT_DEPID");
					String airport_dest = resultSet.getString("AIRPORT_DEST");
					int airport_destid = resultSet.getInt("AIRPORT_DESTID");
					String codeshare = resultSet.getString("CODESHARE");
					int arret = resultSet.getInt("ARRETS");
					int routeid = resultSet.getInt("ROUTEID");

					Route route = new Route(airline, airlineid, airport_dep,airport_depid,airport_dest,airport_destid,codeshare,arret,routeid);
	 				listRoute.add(route);
				}
			}
		}
		return listRoute;
	}

}
