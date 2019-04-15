#pragma once
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
class Tarea {
protected:
	unsigned int orden;
	unsigned int nivel;
	unsigned int* t;
	unsigned int horas;
public:
	Tarea(unsigned int n): orden(n)  {
		srand(time(0));
		if (n == 1 || n == 2) nivel = n;
		else {
			do {
				nivel = (rand() % n + 1);
			} while (nivel == 1);
		}
		t = new unsigned int(n-1);
	};

	int getOrden() { return orden; };
	void setOrden(int n) { orden = n;
	if (n == 1||n==2) nivel = n;
	else { 
		do {
			nivel = rand() % n + 1;
		} while (nivel == 1);
	}
	};

	int getNivel() { return nivel; };
	void setNivel(int n){
		srand(n*time(NULL));
		do {
			nivel = (rand() % orden + 1) % (n + 1);
			if (nivel == 0 || nivel == 1) nivel = n;
		} while (nivel == 1);
		if (rand() % 10) nivel++;
	};

	int getHoras() { return horas; };
	void setHoras(unsigned int n) {	horas = n; };
	void genHoras() { horas = rand() % 8 + 1; };

};
