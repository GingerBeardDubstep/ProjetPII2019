package fr.telecomnancy.projet.specification;

import java.util.ArrayList;
import java.util.List;

public class SpecificationAirport extends Specification {

	private boolean specifiedName = false;
	private boolean specifiedID = false;
	private boolean specifiedLatitude = false;
	private boolean specifiedLongitude = false;

	private List<String> name = new ArrayList<>();
	private List<Long> ID = new ArrayList<>();
	private List<Double> latitude = new ArrayList<>();
	private List<Double> longitude = new ArrayList<>();

	public void reinitialiserSpec() {
		this.specifiedName = false;
		this.specifiedID = false;
		this.specifiedLatitude = false;
		this.specifiedLongitude = false;
		this.name.clear();
		this.ID.clear();
		this.latitude.clear();
		this.longitude.clear();
	}

	public boolean specifiedName() {
		return specifiedName;
	}

	public boolean specifiedId() {
		return specifiedID;
	}

	public boolean specifiedLatitude() {
		return specifiedLatitude;
	}

	public boolean specifiedLongitude() {
		return specifiedLongitude;
	}

	public void findByName(String name) {
		this.specifiedName = true;
		this.name.add(name);
	}

	public void findById(long id) {
		this.specifiedID = true;
		this.ID.add(id);
	}

	public void findByLatitude(Double lat) {
		this.specifiedLatitude = true;
		this.latitude.add(lat);
	}

	public void findByLongitude(Double lon) {
		this.specifiedLongitude = true;
		this.longitude.add(lon);
	}

	public List<String> getName() {
		return name;
	}

	public List<Long> getId() {
		return ID;
	}

	public List<Double> getLatitude() {
		return latitude;
	}

	public List<Double> getLongitude() {
		return longitude;
	}

}
