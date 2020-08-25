#define DIM 3
#include <cstring>

using namespace std;

typedef enum Tpista { NERA, ROSSA, BIANCA } Tpista;

typedef struct Timpianto{
 	char nomeImpianto[20]; 
	unsigned int lunghezza;
 	float costo;
 	Tpista tipoPista;
 	Timpianto () { 
 		lunghezza = 0;
 		costo = 0.0;
 		tipoPista = NERA;
	}
	
 	void stampa() { 
 		cout << nomeImpianto << "(NERA) LUN = " << lunghezza << " costo = " << costo << endl;
	}
} Timpianto;

typedef struct Tcoda {
	Timpianto* is; // array con allocazione dinamica
 	int head, tail; int dim, n;
 	// Inizializza la coda
 	Tcoda (int _dim) { 
 		head = 0;
 		tail = 0;
 		n = 0;
 		dim = _dim+1; //?;
 		is = new Timpianto[dim];
 		// cout << "head = " << head << " tail " << tail << "n = " << n << " dim = " << dim << " is = " << is << endl;
	}
	
	// Stampa un elemento alla volta finchè i non arriva a tail
	// chiamando la funzione stampa di ogni elemento nell'array
	void stampa() {
		cout << "STAMPA CODA METODO " << endl;
		cout << "head = " << head << " tail = " << tail << " n = " << n << endl;
		int a = head;
		while (a != tail) {
			cout << "a = " << a << "  ";
			is[a].stampa();
			a = (a+1)%dim;
		}
	}
	
	// Inserisce un impianto nella coda
 	void put(Timpianto d) { 
 		cout << "Sto chiamando il put "<< endl;
 		if (!isFull()) {
 			strcpy(is[tail].nomeImpianto,d.nomeImpianto);
 			is[tail].costo = d.costo;
 			is[tail].lunghezza = d.lunghezza;
 			is[tail].tipoPista = d.tipoPista;
 			tail = (tail+1)%dim;
 			n++;
		}
	}
	
	// GET PRENDE IL PRIMO ELEMENTO 
 	Timpianto get(){
 		// funziona se la coda ha dentro qualcosa se no ritorniamo null?
 		if (!isEmpty()) {
 			Timpianto nodo;
 			strcpy(nodo.nomeImpianto, is[head].nomeImpianto);
 			nodo.costo = is[head].costo;
 			nodo.lunghezza = is[head].lunghezza;
 			nodo.tipoPista = is[head].tipoPista;
 			// aumenta la head
 			// MB quella del cancellare era delle liste
 			head = (head+1)%dim;
 			n = n-1;
 			return nodo;
		}
		// Non so se va l'else
	}
 	
 	bool isFull(){
 		if ((tail+1)%dim == head) {
 			return true;
		}
		else {
			return false;
		} 
	}
	
 	bool isEmpty(){
 		// Oppure n = 0 i guess
 		if (head == tail) {
 			return true;
		}
		else {
			return false;
		}
	}
} Tcoda; // CODA realizzata con array

// Funzione newImpianto
// Non so come si usa il random
void newImpianto(Timpianto *imp) {
	cout << "Nome impianto = ";
	cin >> imp->nomeImpianto;
	imp->tipoPista = NERA;
	imp->lunghezza = 500;
	imp->costo = 20.0;
}

// Funzione addImpianto
void addImpianto(Tcoda* cod, Timpianto imp) {
	// Se la coda è piena non lo faccio perchè di no i tuoi FILE sono magia nerda
	if (!(cod->isFull())) {
		cod->put(imp);
	}
	else {
		cout << "La coda e piena" << endl;
		cout << "n = " << cod->n << endl;
	}
}


void stampaImpianti(Tcoda *cod) {
	cout << endl <<"ENTRATO NELLA STAMPA IMPIANTI" << endl,
	cod->stampa();
}

int cancellaEConta(Tcoda *cod, Tpista tp) {
	int c = 0;
	while (!cod->isEmpty()){
		Timpianto imp = cod->get();
		if (imp.tipoPista == tp) {
			c++;
		}
	}
	return c;
}


