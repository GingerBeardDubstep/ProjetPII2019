package fr.telecomnancy.projet.dto;

public class City extends Dto {
    private int cityId;
    private String name;
    private Double latitude;
    private Double longitude;
    private String country;

    public City(int cityid, String name, Double latitude, Double longitude, String country) {
	super();
	this.cityId = cityid;
	this.name = name;
	this.latitude = latitude;
	this.longitude = longitude;
	this.country = country;
    }

    @Override
    public String toString() {
	return getCityId() + "," + getName() + "," + getLatitude() + "," + getLongitude() + "," + getCountry();
    }

    public String afficher() {
	String res = padRight(Integer.toString(getCityId()), 7);
	res += padRight(getName(), 36);
	res += padRight(Double.toString(getLatitude()), 10);
	res += padRight(Double.toString(getLongitude()), 11);
	res += padRight(getCountry(), 42);

	return res;
    }

    public int getCityId() {
	return cityId;
    }

    public void setCityId(int cityid) {
	this.cityId = cityid;
    }

    public String getName() {
	return name;
    }

    public void setName(String name) {
	this.name = name;
    }

    public Double getLatitude() {
	return latitude;
    }

    public void setLatitude(Double latitude) {
	this.latitude = latitude;
    }

    public Double getLongitude() {
	return longitude;
    }

    public void setLongitude(Double longitude) {
	this.longitude = longitude;
    }

    public String getCountry() {
	return country;
    }

    public void setCountry(String country) {
	this.country = country;
    }

}
