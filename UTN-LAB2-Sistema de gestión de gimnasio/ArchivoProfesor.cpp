#include "ArchivoProfesor.h"

bool ArchivoProfesor::guardarProfesor(Profesor& profesor)
{
	FILE* p = fopen("profesores.dat", "ab");
	if (p == nullptr) return false;
	bool ok = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return ok;
}

Profesor ArchivoProfesor::leerProfesor(int nRegistro)
{
	Profesor profesor;
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	bool leyo = fread(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return profesor;
}

bool ArchivoProfesor::leerTodos(Profesor* profesor, int cantidad)
{
	FILE* p = fopen("profesores.dat", "rb");
	if (p == nullptr) return false;
	bool leyo = fread(&profesor, sizeof(Profesor), cantidad, p);
	fclose(p);
	return leyo;
}

bool ArchivoProfesor::modificarProfesor(Profesor& profesor, int nRegistro)
{
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), SEEK_SET);
	bool ok = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return ok;
}



int ArchivoProfesor::getCantidad()
{
	int cant = 0;
	FILE* p = fopen("profesores.dat", "rb");
	fseek(p, 0, 2);
	cant = ftell(p) / sizeof(Profesor);
	fclose(p);
	return cant;
}

int ArchivoProfesor::buscarRegPorDni(std::string dni)
{
	int cant = getCantidad();
	Profesor profesor;
	for (int x = 0;x < cant;x++) {
		profesor = leerProfesor(x);
		if (profesor.getDni() == dni) return x;
	}
	return -1;
}

bool ArchivoProfesor::bajaLogica(int nRegistro)
{
	Profesor profesor;
	Fecha fecha;
	fecha.establecerFechaHoy();
	profesor = leerProfesor(nRegistro);
	bool flag;
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	profesor.setEstado(false);
	profesor.setFechaEgreso(fecha);
	flag = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return flag;
}

bool ArchivoProfesor::altaLogica(int nRegistro)
{
	Profesor profesor;
	profesor = leerProfesor(nRegistro);
	Fecha fecha;
	fecha.establecerFechaHoy();
	bool flag;
	FILE* p = fopen("profesores.dat", "rb+");
	if (p == nullptr) return false;
	fseek(p, nRegistro * sizeof(Profesor), 0);
	profesor.setEstado(true);
	profesor.setFechaIngreso(fecha);
	flag = fwrite(&profesor, sizeof(Profesor), 1, p);
	fclose(p);
	return flag;
}
