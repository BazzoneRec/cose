#include <iostream>
#include "dati.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tcoda* impiantiRisalita = new Tcoda(DIM); 
	Timpianto imp;
	
	for (int i=0; i<5; i++) {
		newImpianto(&imp);
		imp.stampa();
	 	addImpianto(impiantiRisalita, imp);
	}
	stampaImpianti(impiantiRisalita);
	cout << cancellaEConta (impiantiRisalita, NERA);
	return 0;
}
