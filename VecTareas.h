#pragma once
#include <vector>
#include "Tarea.h"

class VecTareas {
private:
	vector<Tarea*>* LTarea;
public:
	VecTareas() { LTarea = new vector<Tarea*>(); };
	~VecTareas() {
		for (Tarea* TIndividual : *LTarea)
			delete TIndividual;
		delete LTarea;
	}

	void agregar(Tarea* t) { this->LTarea->push_back(t); }

	unsigned int size() { return LTarea->size(); }


	int getOrden(int n) { return LTarea->at(n)->getOrden(); }
	void setOrden(int n, int nOrden) { LTarea->at(n)->setOrden(nOrden); }
	unsigned int getNivel(int n) { return LTarea->at(n)->getNivel(); }
	void setNivel(int n, int nNivel){
		if (n > 2) {
			LTarea->at(n - 1)->setNivel(nNivel);
		}
		else cout << endl << "El nivel de las dos primeras tareas no pueden ser modificadas." << endl;
	}

	int getHoras(int n) { return LTarea->at(n)->getHoras(); }
	void setHoras(int n, int nHoras) { LTarea->at(n)->setHoras(nHoras); }
	void genHoras(int n) { LTarea->at(n)->genHoras(); }
};