
//string nomeFileTxt = "esempio.txt"; 	// no fstream non è previsto che riceva una string
char nomeFileTxt[] = "esempio.txt";	// ok così funziona


// apre un file txt e scrive a video il contenuto
void apriFile() {
	// apre il file
	ifstream file_da_aprire (nomeFileTxt);
	if (file_da_aprire.is_open()) {
		// tutto il testo insieme con getline(), NON mostra BOM utf8
		string testo_aperto;
		getline(file_da_aprire,testo_aperto);	// come si mette EOF???
		cout << testo_aperto <<endl; // ok stampa a video tutto il testo (al solito caratteri utf8 mojibake)
		cout << testo_aperto.size() << " caratteri" <<endl;	// ok conta esattamente i caratteri inclusi gli acapi
		
		// una linea alla volta
		/*while (getline(file_da_aprire,testo_aperto)) // ok
			cout << testo_aperto << '\n';	// ok, tranne che nel Prompt non riconosce i caratteri utf8 e li mostra sballati

		// metodo per avere tutto il testo insieme gestito da un puntatore. mostra il BOM utf8
		// forse non è buon metodo inquanto accede alla ROM per scrivere, non ho capito se accade anche con 'new char'
		char * testo_aperto = new char;	// puntatore a un indirizzo in memoria dove si trova un carattere a sorpresa
		file_da_aprire.getline(testo_aperto,INT_MAX,EOF); // sìì! funziona! estrae tutto il contenuto del file
		cout << strlen(testo_aperto) << " caratteri" <<endl;	// ok conta esattamente i caratteri inclusi gli acapi
		*/
		
	// se non lo trova
	} else
		cout << "Non trovo il file " << nomeFileTxt <<endl;
	file_da_aprire.close();
	
}

// crea un file txt e gli scrive dentro un paio di righe
// i caratteri unicode risultano corretti (anche se in prompt appaiono mojibake)
// aprendo file con blocco note parrebbe che se nella stringa c'è un carattere 128+ 'è' il txt risulta utf8
// però poi riaprendo il testo da prompt non appare il BOM, se invece da notapad risalvato utf8 appare il BOM
void creaFile() {
	ofstream nuovofile;
	nuovofile.open (nomeFileTxt);
	// scritura nel file: se il file esiste già SOVRASCRIVE il contenuto senza complimenti
	cout << "1 ASCII\n2 ASCII esteso\n3 Unicode\n";
	int n;
	cin >> n;
	switch (n) {
		case 1:	nuovofile << "Solo caratteri ASCII\ne questo file txt viene codificato ANSI e non utf8";
				// ok scrive nel txt stringa di caratteri ASCII, percui il txt viene codificato ANSI
			break;
		case 2:	nuovofile << "Una strìnga di caràtteri che potrebbero essere ANSI\nStò txt è codificato utf-8 o ANSI o cosa? bho";
				// ok stringa di caratteri ANSI (entro il 256) salvati corretti nel txt che poi risulta codificato UTF8
			break;
		case 3:	nuovofile << "Q.ᵗᵒ è il teſto nùov:ᵒ \nſicché è un doc͞to in utf⁸\nb͠no pei caratterᶖ ♡";
				// ok nella stringa ci sono caratteri unicode, vengono scritti correttamente e idem txt risulta codificato UTF8
	}
	cout << "creato file " << nomeFileTxt <<endl;
	nuovofile.close();
}


// salva testo inserito da utente in file txt
void scriviSalvaTesto() {
	ofstream file_da_riempire;
	file_da_riempire.open(nomeFileTxt);
	if (file_da_riempire.is_open()) {
		/* così il file txt diventa ANSI e eventuali caratteri accentati risultano sono cambiati ma di egual numero!
		 * ad esempio àèéìòù diventa …Š‚•—	(in mezzo c'è il beep)
		 * MA interessante è che se file è ricaricato da apriFile() in Prompt ritorna àèéìòù
		 * quindi è solo una questione di interpretazione della mappa caratteri che questo programma fa diverso dal sistema 
		 * operativo */
		cout << "scrivi una riga che vuoi salvare: ";	
		string testo;
		getline(cin,testo); 
		cout << "nel file '" << nomeFileTxt << "' scriverai '" << testo << "'" << endl;
		file_da_riempire << testo;	// eventuale testo presistente viene sovrascritto
	} else
		cout << "Non trovo " << nomeFileTxt <<endl;
	file_da_riempire.close();
}


// apre file e aggiunge una riga al contenuto esistente
void scriviDentroFile() {
	ifstream file_scritto(nomeFileTxt);
	if (file_scritto.is_open()) {
		char * tuttotesto = new char;
		file_scritto.getline(tuttotesto,INT_MAX,EOF);
		cout << tuttotesto <<endl;
	} else cout << "Non trovo " << nomeFileTxt <<endl;
	//tuttotesto[strlen(tuttotesto)] = 
}

