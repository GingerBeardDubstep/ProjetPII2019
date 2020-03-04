package fr.telecomnancy.projet.repository;

import java.sql.SQLException;
import java.util.List;

import fr.telecomnancy.projet.dto.Dto;
import fr.telecomnancy.projet.specification.Specification;

public interface Repository<T extends Dto, U extends Specification> {

    boolean add(T o) throws SQLException;

    boolean update(T o) throws SQLException;

    boolean remove(T o) throws SQLException;

    List<T> query(U specification) throws SQLException;

    List<T> findAll() throws SQLException;

}
