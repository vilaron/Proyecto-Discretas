#include "Tarea.h"
#include "VecTareas.h"
#include <conio.h>
#include <string.h>

void main() {
	
	auto c = [](char* a) {cout << a; };
	auto e = []() {cout << endl; };
	float n = 0.0;
	c("Ingrese un numero del 8 al 12: ");
	while (n != -1) {
		while (1) {
			cin >> n;
			if (n >= 8.0 && n <= 12.0) break;
			c("El valor ingresado no se encuentra en el rango de 8-12. Intente nuevamente."), e(), e();
			c("Ingrese un numero del 8 al 12: ");
		}

		VecTareas* ListaT = new VecTareas();
		for (int i = 1; i <= n; i++) {
			Tarea* aux = new Tarea(i);
			ListaT->agregar(aux);
			unsigned int maxNivel = 2;
			if (i > 2) {
				if (ListaT->getNivel(i - 2) > maxNivel)maxNivel = ListaT->getNivel(i - 2);
				ListaT->setNivel(i, maxNivel);
			}
		}
		//ListaT->genCon();
		//Tarea* t1 = new Tarea(n);
		cout << "\t| Tarea |\t| Orden |\t| Nivel |\t| Horas |", e();
		for (int i = 0; i < ListaT->size(); i++) {
			ListaT->genHoras(i);
			e();
			cout << "\t\t"<< i+1 << "\t\t" << ListaT->getOrden(i) << "\t\t" << ListaT->getNivel(i) << "\t\t" << ListaT->getHoras(i), e();
		}
	}
	/*while (n != 0) {
		c("Introduzca el orden deseado: "), cin >> n, ListaT->setOrden(n);
		for (int i = 0; i < 1; i++) {
			t1->genHoras();

			e();
			cout << "\t| Tarea |\t| Orden |\t| Nivel |\t| Horas |", e();
			cout << "\t\t" << i + 1 << "\t\t" << t1->getOrden() << "\t\t" << t1->getNivel() << "\t\t" << t1->getHoras(), e();
		}
	}*/
	_getch();
}