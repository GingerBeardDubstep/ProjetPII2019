package fr.telecomnancy.projet.repository;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.Flight_number;
import fr.telecomnancy.projet.specification.SpecificationFlight_number;

public class RepositoryFlight_number implements Repository<Flight_number, SpecificationFlight_number> {

		public RepositoryFlight_number() {

		}

		@Override
		public boolean add(Flight_number equipement) throws SQLException {
			String sql = "INSERT INTO FLIGHT_NUMBER (FLIGHTID, FLIGHTNUMBER, AIRLINE_CODE,STOPS) VALUES (?,?,?,?)";
			boolean inserted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setInt(1, equipement.getFlightid());
			state.setString(2, equipement.getFlightnumber());
			state.setString(3, equipement.getAirline_code());
			state.setInt(4, equipement.getStops());
			inserted = state.executeUpdate() > 0;

			return inserted;
		}

		@Override
		public boolean update(Flight_number equipement) throws SQLException {
			String sql = "UPDATE FLIGHT_NUMBER SET FLIGHTNUMBER = ?, AIRLINE_CODE = ?,STOPS = ?";
			sql += "WHERE FLIGHTID = ?";
			boolean inserted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setInt(4, equipement.getFlightid());
			state.setString(1, equipement.getFlightnumber());
			state.setString(2, equipement.getAirline_code());
			state.setInt(3, equipement.getStops());
			inserted = state.executeUpdate() > 0;
			
			return inserted;
		}

		@Override
		public boolean remove(Flight_number equipement) throws SQLException {
			String sql = "DELETE FROM FLIGHT_NUMBER WHERE FLIGHTID = ?";
			boolean deleted = false;

			Connection conn = ConnectionUtil.getConnection();
			PreparedStatement state = conn.prepareStatement(sql);
			state.setInt(1, equipement.getFlightid());
			deleted = state.executeUpdate() > 0;

			return deleted;
		}
		
		@Override
		public List<Flight_number> query(SpecificationFlight_number specification) throws SQLException {
			Connection conn = ConnectionUtil.getConnection();
			List<Flight_number> listFlight_number = new ArrayList<>();
			String sql = specificationsSQL(specification);

			try(Statement state = conn.createStatement()){
				try(ResultSet resultSet = state.executeQuery(sql)){

					while (resultSet.next()) {
						int flightid = resultSet.getInt("FLIGHTID");
						String flightnumber = resultSet.getString("FLIGHTNUMBER");
						String airline_code = resultSet.getString("AIRLINE_CODE");
						int stops = resultSet.getInt("STOPS");
						
						Flight_number equipement = new Flight_number(flightid, flightnumber, airline_code,stops);
						listFlight_number.add(equipement);

					}
				}
			}
			return listFlight_number;

		}


		// if there is multiple conditions AND or OR
		public String specificationsSQL(SpecificationFlight_number specification) {
			List<String> sql = new ArrayList<>();
			sql.add("SELECT * FROM FLIGHT_NUMBER WHERE");

			if (specification.specifiedId()) {
				for(long id : specification.getId()) {
					sql.add("FLIGHTID = " + id);
				}
			}

			// if more than 1 spec is chosen
			for (int i = 2; i < sql.size(); i++) {
				sql.set(i, specification.getConnector() + " " + sql.get(i));
			}

			return String.join(" ", sql);
		}

		@Override
		public List<Flight_number> findAll() throws SQLException {
			List<Flight_number> listequipement = new ArrayList<>();
			String sql = "SELECT FLIGHTID, FLIGHTNUMBER, AIRLINE_CODE,STOPS FROM FLIGHT_NUMBER ORDER BY FLIGHTID";

			Connection conn = ConnectionUtil.getConnection();
			try(Statement state = conn.createStatement()){
				try(ResultSet resultSet = state.executeQuery(sql)){
					
					while (resultSet.next()) {
						int flightid = resultSet.getInt("FLIGHTID");
						String flightnumber = resultSet.getString("FLIGHTNUMBER");
						String airline_code = resultSet.getString("AIRLINE_CODE");
						int stops = resultSet.getInt("STOPS");
						
						Flight_number equipement = new Flight_number(flightid, flightnumber, airline_code,stops);
						listequipement.add(equipement);

					}
				}
			}
			return listequipement;
		}

	}
