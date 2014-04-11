void mostraAiuto() {
	cout <<
	"    b	vedi la tabella dei numeri da 1 a 100 elevati fino alla 10a potenza\n"
	"    f	apri (gestore) file\n"
	"    g	prova con variabili globali e locali\n"
	"    l	la funzione su cui sto lavorando al momento\n"
	"    h	questo aiuto\n"
	"    s	selezione dei migliori metori x le operazioni + semplici\n"
	"    t	esplorare i caratteri \n"	
	"    t1	tabella di 256 caratteri\n"
	"    t2	32 caratteri Ctrl\n"
	"    w	prove di allineamento testo e numeri con setw()\n"
	"    x	esci\n";
}

void benvenuto() {
	string comando;
	cout << "Comanda o re!" << endl;
	cout << ">";
	/*getline( cin, comando ); // ok funziona ma poi il while va all'infinito
	while ( (comando != "exit" || comando != "x") && comando != "") {*/
	int scelta; // per gli array di puntatori a funzioni, o altro 
	
	while ( getline(cin,comando) && comando[0]!='x' && comando!="exit" && comando[0]!=4 ) {
		//cout << "comando inserito: " << comando << endl;
		/*if (comando=="\r" || comando=="\n")
			cout << "[acapo]";	// nn compare mai
		else if (comando=="\0")	// carattere nullo in una stringa vuota prodotta da un solo acapo \n 
			cout << "[NUL]";  	// o dopo un solo invio senza altri caratteri, o avanzato nell'input buffer
		else if (comando=="");
			cout << "una stringa vuota" << endl;	// ad ogni invio senza caratteri inseriti
		else*/ 
		if (comando=="b")
			tabellaPotenze();
		else if (comando=="f") {
			cout << "1 apri txt esistente\n2 crea txt predefinito\n3 scrivi e salva\n4 aggiungi una riga\n";
			void (*funzipunti[])() ={0,apriFile,creaFile,scriviSalvaTesto,scriviDentroFile};
			cin >> scelta;
			cin.get();	// prende acapo di scarto
			funzipunti[scelta](); }
		else if (comando=="g")			
			localiGlobali();
		else if (comando=="h" || comando=="help")
			mostraAiuto();
		else if (comando=="l") {
		// fior da fiore
			//testoInStringhe();
			//prendeTestoInserito();
			//prendeTestoInseritoExra();
			//conversioneCarattere();
		// funzioni
			//calcolaQuadrato();
			//arrayFunzioni();
		// varie
			//confrontaWhileDoWhile();
			//tuttoCin();
			//EOTesceWhile();	
			//endOfFile();
			//cinNonSincronizzatoConStdin();
			//chiamaSwitchReturnBreak();
		// tabella caratteri
			caratteri256();
		// problemi
			//ignoreNonIgnora();
			//cingetNonAttendeInput();
			//potenzaSottraeUno();
		// inputbuffer
			//scartiBuffer();
			//ignoraScarti();	// ok
			//contaInputBuffer();
		// gestionefile
			//scriviSalvaTesto();
			//scriviDentroFile();
		}	
		else if (comando=="p")		
			prendeTestoInserito();
		else if (comando=="s") {	// selezion
			cout << "	0  testo direttamente a video"
			        "\n	1  testo in char array string..."
			        "\n	2  prende testo inserito"
			        "\n	3  prende testo inserito Exra"
			        "\n	4  conversione tra tipi di variabili"
			        "\n	5  array con un elenco di funzioni"
				"\n";
			void (*funzioni[6])() = { scriviTesto,
				testoInStringhe, 
				prendeTestoInserito, prendeTestoInseritoExra, 
				conversioneCarattere, arrayFunzioni };
			cin >> scelta;	// \n residuo rimane in buffer ciclando 2 volte il while 
			funzioni[scelta]();
		}
		else if (comando=="t")
			esploraCaratteri();
		else if (comando=="t1")
			listaCaratteri();
		else if (comando=="t2")
			listaCaratteriCtrl();
		else if (comando=="v") {	// vecchie funzioni di studio
			void (*vecchie[])() = {
				confrontoNumeri,	
				carattereNumero,
				scomponeNumero,
				prendiUnCarattere, 
				dichiaraVariabili	};
			cout<<
			"0	confronti due numeri                                    	\n"
			"1  chiede un carattere e restituisce il numero ASCII       	\n"
			"2	scomponi un numero di 5 cifre                             	\n"
			"3  inserisci un carattere                                    	\n"
			"4  dimostra che variabili dichiarate con la virgola funzionano \n";
			int f = cin.get();
			vecchie[f]();
		}
		else if (comando=="w")
			allineaTestoNumeri();
		else
			cout << "Enter \"h\" for help" << endl;
		stringaNumero(comando);

		//comando();	// tentativo di fare eseguire una funzione inserendo il suo nome nel prompt, non va
		//cout << "comando alla fine: " << comando << endl;
		cin.sync();
		cout << ">";

		// COME USARE switch con una stringa di testo?!?!?!!? non è così semplice
/*		switch (comando) {	
			case "1":	// il numero ASCII del carattere '1'
				allineaTestoNumeri();
				break;
			case "c":
				carattereNumero();
				break;
			case 'f':	
				confrontaForWhile();
				break;
			case 'i':	
				stringaTesto();
				break;				
			case 'n':
				confrontoNumeri();
				break;
			case 's': 
				scompone();
				break;
			case 't':
				tabellaPotenze();
				break;
			case "help":
			case 'h':
				mostraAiuto();
				break;
			case '\n':
				cout << "> ";
				break;
			case ' ':
			case '\t':
				break;
			default:
				cout << "Enter \"h\" for help" << endl;
		}*/
	}
}
