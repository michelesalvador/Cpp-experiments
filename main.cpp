#include <iostream>	// cin cout
#include <fstream>	// puts() getchar() putchar()  ifstream ofstream EOF
#include <cstring>	// strlen()
#include <cmath>	// pow() round() floor()
#include <iomanip>	// setw() setprecision()
#include <sstream>	// stringstream
#include <ctime>	// time()
#include <climits>	// ignore()  Lubuntu INT_MAX lo trova qui, Windows in qualche altro forse addirittura iostream
//#include <cstdlib>	// system("PAUSE")
using namespace std;
//#include <stdio.h>	// idem gli stessi puts() getchar() putchar()
//#include <string>	// std::char_traits
					// pare essere già incluso in <iostream>
					// torno a includerlo ogni volta che ho un problema con le stringhe di testo... ma non risolve mai niente
//#include <locale>	// forse serve per mostrare i caratteri accentati, lui solo non cabia nulla



// prototipi di alcune funzioni di utilità definite in "utilita.h"
int contaCifre(long);
int esadecimaleDecimale(string &);
string decimaleEsadecimale(int);
string svela(char,int,string);
string maiscolo(string);
int stringaNumero(string);
int altroInput();

// altri file di funzioni
#include "utilita.h"
#include "fiordafiore.h"
#include "varie.h"
#include "tabellacaratteri.h"
#include "gestionefile.h"
#include "inputbuffer.h"
#include "problemi.h"
#include "funzioni.h"
#include "vecchie.h"
#include "core.h"

// cout << "cout deve stare in main() o in altra funzione, non può stare qui fuori all'aria aperta";

int main() {
	//caratteri256();
	benvenuto();
	//prendeTestoInserito();
	//
	return 0;
}
