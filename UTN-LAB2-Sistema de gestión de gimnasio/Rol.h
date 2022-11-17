#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "Persona.h"
#include "Fecha.h"

/* 	-ID
    -cargo(rol)
    -Sueldo
    -Fecha de ingreso */

class Rol : public Persona {
private:
    int _id;
    char _cargo[30];
    float _sueldo;
    int _turnoId;
	Fecha _fechaIngreso;
	Fecha _fechaEgreso;
public:
    Rol(int id = 0, std::string cargo="", float sueldo = 0, int turnoId = 0, Fecha fechaIngreso=Fecha());
    int getId() { return _id; }
    std::string getCargo() { std::string cargo(_cargo); return cargo; }
    float getSueldo() { return _sueldo; }
    int getTurno() { return _turnoId; }
	Fecha getFechaIngreso() { return _fechaIngreso; }
	Fecha getFechaEgreso() { return _fechaEgreso; }
	
    void setId(int id) { _id=id; }
    void setCargo(std::string cargo) { strcpy(_cargo, cargo.c_str()); }
    void setSueldo(float s) { _sueldo = s; }
	void setTurno(int turno) { _turnoId = turno; }
	void setFechaIngreso(Fecha fechaIngreso) { _fechaIngreso = fechaIngreso; }
	void setFechaEgreso(Fecha fechaEgreso) { _fechaEgreso = fechaEgreso; }

    void MostrarRol();
    void CargarRol();
};
