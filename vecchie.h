// obsolete ma non ho il cuore di buttarle

// chiede un carattere e restituisce il numero ASCII
void carattereNumero() {
	char lettera;
	cout << "Batti un carattere qualsiasi: ";
	cin >> lettera;
	if (cin.fail()) {
			// da testare
	}
	int nume = static_cast<int>(lettera);
	if(lettera>0)
		cout << "\"" << lettera << "\" e' il carattere ASCII numero " << nume <<endl;
	else
		cout << "questo non è un carattere ASCII, comunque il numero e' " << nume <<endl;
}

// prende input con cin.get() e lo vaglia in un while
void prendiUnCarattere() {
	int carattere;	// in un numero intero ci sta il numero ASCII di un carattere ad es. 65 = 'A'
	// cin.get() prende un carattere alla volta di tutti quelli inseriti
	while ( ( carattere = cin.get() ) != 'x' ) {
		//cout << "comando al inizio: " << comando << endl;
		switch (carattere) {
			case 49:	// il numero ASCII del carattere '1'
				cout << "hai scritto 1" << endl;
				break;
			case 'a':
				cout << "hai scritto a" << endl;
				break;
			case 's': 
				cout << "hai scritto s" << endl;
				break;
			case 't':
				break;
			case '\n':
				cout << ": ";
				break;
			case ' ':
				cout << "uno spazio" << endl;
				break;
			default:
				cout << "Scrivi uno di questi: '1' 'a' 'x'" << endl;
		}
	}
}
