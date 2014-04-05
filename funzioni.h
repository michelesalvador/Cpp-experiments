// il prototipo sta prima della funzione chiamante, periò quella chiamata può stare ovunque

// 'inline' il compilatore crea una copia della funzione là dove è chiamata, anziché richiamarla da qui
// funzioni inline possono stare PRIMA di essere chiamate, e non necessitano di prototipo
//inline 


// visibilità variabili locali e globali
int x = 1;	// variabile globale
void usaStaticLocale() {
	static int x = 50;
	cout << "static in funzione    " << x << endl;
	x++;
	cout << "static in funzione ++ " << x << endl;
}
void localiGlobali() {
	cout << "globale    " << x << endl;
	int x = 5;
	usaStaticLocale();
	cout << "locale in scopo esterno    " << x << endl;
	{	// un fighissimo cazzo di ambito privée in cui fai quel cazzo che vuoi figa
		int x = 7;
		cout << "altra locale in scopo interno    " << x << endl;
		x++;
		cout << "altra locale in scopo interno ++ " << x << endl;
	}
	x--;
	cout << "locale in scopo esterno -- " << x << endl;
	usaStaticLocale();
	
	::x++;
	cout << "globale ++ " << ::x << endl; // l'operatore unitario di risoluzione dello scope ::
}


// passaggio di argomenti a una funzione per RIFERIMENTO, anziché l'usuale "per valore"
void quadratoPerRiferimento (int &);
// chiamata per riferimento
void calcolaQuadrato() {
	int numero = 3;
	cout << "numero iniziale " << numero << endl;
	quadratoPerRiferimento(numero);
	cout << "la stessa variabile dopo aver calcolato il quadrato per riferimento " << numero << endl;
}
// definizione
void quadratoPerRiferimento(int& num) {	// int &num, int& num, int & num  sono equivalenti
	num *= num;	// nel corpo nn si usano gli & 
		// modifica la viariabile 'numero' direttamente nella funzione chiamante!
		
}

// array di puntatori a funzioni
void arrayFunzioni() {
	// array di funzioni non è possibile, ma bensì di puntatori a funzioni
	// l'operatore unitario * indica che 'funzi' è un array di puntatori anziché di valori
	// le funzioni puntate devono avere identica struttura: stesso tipo e numero di argomenti e stesso coso ritornato
	int scelta;
	
	// funzioni senza argomenti
	void (*funzi[4])() = { 0, usaStaticLocale, localiGlobali, calcolaQuadrato };
	cout << " 1 usaStaticLocale()\n 2 localiGlobali()\n 3 calcolaQuadrato()\n";
	cin >> scelta;
	funzi[scelta]();
	cout << endl;

	// funzioni con un argomento 'string'
	void (*funzi2[3])(string) = { 0, profiloCarattere, profiloCarattere };
	cout << " 1 o 2 chiamano la stessa profiloCarattere()\n altro esci\n";
	// loop per continuare a chiamarle
	while ((cin>>scelta)>0 && scelta<3) {
		cout << "argomento da passarle: ";
		string argomento;
		cin.ignore(1,10);	// ok qui funziona sto strnz
		getline(cin,argomento);
		funzi2[scelta](argomento);
	}
}
