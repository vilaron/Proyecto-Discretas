#pragma once
#include <vector>
#include "Tarea.h"

class VecTareas {
protected:
	vector<Tarea*>* LTarea;
	int* imm=new int;
public:
	VecTareas() { LTarea = new vector<Tarea*>(), imm[0]=0; };
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

	/*unsigned int nNivel(unsigned int n) {
		int cont=0;
		for (int i = 1; i < LTarea->size(); i++) {
			if (getNivel(i) == n) cont++;
		}
		return cont;
	}
	unsigned int* cNivel(unsigned int n) {
		unsigned int* niveles=new unsigned int;
		for (int i = 0; i < LTarea->size(); i++) {
			if (getNivel(i) == n) niveles[i] = i;
		}
		return niveles;
	}*/

	/*void genCon() {
		for (int i = 1; i < LTarea->size(); i++) {
			if (getNivel(i) == 2) LTarea->at(i)->setPrecedentes(0, 1);
			else {
				for (int j = 0; j < nNivel(getNivel(i)); j++) {
					LTarea->at(i)->setPrecedentes(j, cNivel(i)[j]);
				}
			}
		}
	}
	void imprimirPrecedentes(int n) {
		for (int i = 0; i < nNivel(n); i++) {
			if(LTarea->at(n)->getPrecedentes(i)<12&& LTarea->at(n)->getPrecedentes(i)>0)	cout << LTarea->at(n)->getPrecedentes(i)<<" ";
		}
	}*/
};