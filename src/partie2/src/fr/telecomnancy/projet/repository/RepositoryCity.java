package fr.telecomnancy.projet.repository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import fr.telecomnancy.projet.db.ConnectionUtil;
import fr.telecomnancy.projet.dto.City;
import fr.telecomnancy.projet.specification.SpecificationCity;

public class RepositoryCity implements Repository<City, SpecificationCity> {

    public RepositoryCity() {

    }

    @Override
    public boolean add(City city) throws SQLException {
	String sql = "INSERT INTO CITY (CITYID, NAME, LATITUDE, LONGITUDE, COUNTRY) VALUES (?,?,?,?,?)";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, city.getCityId());
	state.setString(2, city.getName());
	state.setDouble(3, city.getLatitude());
	state.setDouble(4, city.getLongitude());
	state.setString(5, city.getCountry());

	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean update(City city) throws SQLException {
	String sql = "UPDATE CITY SET NAME = ?, LATITUDE = ?, LONGITUDE = ?, COUNTRY = ?";
	sql += "WHERE CITYID = ?";
	boolean inserted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(5, city.getCityId());
	state.setString(1, city.getName());
	state.setDouble(2, city.getLatitude());
	state.setDouble(3, city.getLongitude());
	state.setString(4, city.getCountry());

	inserted = state.executeUpdate() > 0;

	return inserted;
    }

    @Override
    public boolean remove(City city) throws SQLException {
	String sql = "DELETE FROM CITY WHERE CITYID = ?";
	boolean deleted = false;

	Connection conn = ConnectionUtil.getConnection();
	PreparedStatement state = conn.prepareStatement(sql);
	state.setInt(1, city.getCityId());
	deleted = state.executeUpdate() > 0;

	return deleted;
    }

    @Override
    public List<City> query(SpecificationCity specification) throws SQLException {
	Connection conn = ConnectionUtil.getConnection();
	List<City> listCity = new ArrayList<>();
	String sql = specificationsSQL(specification);

	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int cityid = resultSet.getInt("CITYID");
		    String name = resultSet.getString("NAME");
		    double latitude = resultSet.getDouble("LATITUDE");
		    double longitude = resultSet.getDouble("LONGITUDE");
		    String country = resultSet.getString("COUNTRY");

		    City city = new City(cityid, name, latitude, longitude, country);
		    listCity.add(city);

		}
	    }
	}
	return listCity;

    }

    // if there is multiple conditions AND or OR
    public String specificationsSQL(SpecificationCity specification) {
	List<String> sql = new ArrayList<>();
	sql.add("SELECT * FROM CITY WHERE");

	if (specification.specifiedCityId()) {
	    for (Integer id : specification.getCityId()) {
		sql.add("UPPER(CITYID) =" + id);
	    }
	}

	if (specification.specifiedName()) {
	    for (String name : specification.getName()) {
		sql.add("UPPER(NAME) = UPPER('" + name + "')");
	    }
	}

	if (specification.specifiedLatitude()) {
	    for (Double latitude : specification.getLatitude()) {
		sql.add("UPPER(LATITUDE) = " + latitude);
	    }
	}

	if (specification.specifiedLongitude()) {
	    for (Double longitude : specification.getLongitude()) {
		sql.add("UPPER(LONGITUDE) = " + longitude);
	    }
	}

	if (specification.specifiedCountry()) {
	    for (String country : specification.getCountry()) {
		sql.add("UPPER(COUNTRY) = UPPER('" + country + "')");
	    }
	}

	// if more than 1 spec is chosen
	for (int i = 2; i < sql.size(); i++) {
	    sql.set(i, specification.getConnector() + " " + sql.get(i));
	}

	return String.join(" ", sql);
    }

    @Override
    public List<City> findAll() throws SQLException {
	List<City> listCity = new ArrayList<>();
	String sql = "SELECT CITYID, NAME, LATITUDE, LONGITUDE, COUNTRY FROM CITY ORDER BY CITYID";

	Connection conn = ConnectionUtil.getConnection();
	try (Statement state = conn.createStatement()) {
	    try (ResultSet resultSet = state.executeQuery(sql)) {

		while (resultSet.next()) {
		    int cityid = resultSet.getInt("CITYID");
		    String name = resultSet.getString("NAME");
		    double latitude = resultSet.getDouble("LATITUDE");
		    double longitude = resultSet.getDouble("LONGITUDE");
		    String country = resultSet.getString("COUNTRY");

		    City city = new City(cityid, name, latitude, longitude, country);
		    listCity.add(city);
		}
	    }
	}
	return listCity;
    }

}
