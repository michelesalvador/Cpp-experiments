// vari esperimenti intorno alla questione ALLUCINANTE degli avanzi di input buffer che non si può sapere se ci sono o no


// alcuni oggetti che estraggono caratteri dall'input buffer lasciano lì dei caratteri in sospeso ad esempio il carattere di fine linea LF (\n)
// poi i successivi estrattori di input ritrovano questi caratteri e li prendono come fossero input
// questa funzione mostra il problema
// POI studio per scoprire come intercettare questi EVENTUALI caratteri avanzati
void scartiBuffer() {
	char arr[2];
	cout << "scrivi 1 carattere oppure batti solo Invio: ";
	cin.get(arr,2);	// estrae il primo carattere
					// quindi se inserito un carattere poi l'acapo (LF 10 '\n') rimane in input buffer
					// ma se è stato battuto solo un Invio non rimane niente in buffer
	cout << "char[] = " << arr << endl;

	// mostra contenuto dell'array incluso il NUL finale
	for (int i=0; i<2; i++)
		cout << svela(arr[i],1); // se è stato dato solo un Invio l'array è una stringa vuota con il solo carattere terminale NUL '\0'
	 cout << endl;

	// mostra gli scarti incluso l'acapo
	// mostrare gli scarti vuol dire anche svuotare il buffer
	cout << "scarti = '";
	char c=4;
	do { cin.get(c);
		cout << svela(c,1);
	} while ( c!='\n' && c!=4 );
	cout << "'" << endl;

	
	cout << "riesci a batterne un altro? ";
	cin >> arr;               	// se sono stati inseriti 2 caratteri questo 'cin' estrae il secondo
	cout << "hai inserito " << arr << endl;

	
	// a questo punto c'è ancora il '\0' avanzato dopo il 'char', perciò while riparte
		//cin.clear();	// non svuota il cin come mi aspettavo. il \0 è ancora qui
	
	//if (cin=='\0')	// completamente ignorato
	//if (cin=="\0") cout << "cin ha dentro solo un \\0 !" << endl;

	/*cout << "[ante clear]";
	//comando.clear(); 	// forse svuota la stringa, ma non è qui che stanno i caratteri avanzati
	cin.clear();   	// da solo non fa niente. setta la flag di iostate in buono, cattivo ecc.
	//cin.clear(ios_base::eofbit); 	// no. setta lo stato di input in raggiunto End-of-File, infatti poi il programma termina
	cout << "[tra i 2]";
	cin.ignore(INT_MAX);	// no. ignora tutti i comandi fino a EOF. non è questo che voglio
	//cin.ignore(INT_MAX,'\0');	// idem. cin si ferma qui qualsiasi cosa inserisco finché EOF
	//cin.ignore();	// aspetta il carattere '\n' o dallo stream buffer, o altrimenti occorre battere un Invio, che non è ciò che voglio
	//cin.ignore(INT_MAX,'\n');	// idem: input si ferma qui fino a un invio. idem se prima c'è cin.clear()
								// però svuota solo se nel buffere c'è un '\n' (ad esempio come avanzo di 'cin >> char')
								// invece se non trova '\n' (ad esempio dopo getline(cin,string) che svuota tutto il buffer) allora rimane in ATTESA finché arriva un Invio (='\n')
	//cin.ignore(INT_MAX,'h');	// puoi continuare a scrivere anche acapi finché inserisci 'h' e invio, è tutto ignorato
	//cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	// sembra uguale a INT_MAX
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');	// idem ripulito
	//cin.ignore(INT_MAX,"\n");	// non valida conversione da char a int
	//cin.ignore(INT_MAX,static_cast<int>('\n'));	// peggio, aspetta sempre invio
	cout << "[dopo ignore]";*/
	
	//fflush(cin);	// non so cosa mettere tra le parentesi
	//cin.flush();	// no questo comando non esiste
	//cout.flush();	// non ho capito sua funzione ma comunque non svuota l'input buffer, semmai l'output
	//cout << cout.flush();	// scrive sempre solo 0x483864
	
/*	cout << "[ante sync]";
	cin.sync();	// fa esattamente giusto!!!! elimina input buffer SE ce n'è, altrimenti passa via!
				// però funziona solo in Windows, in Lubuntu è del tutto inefficace come non esistesse
	cout << "[dopo sync]";*/
}

// ripulisce l'input buffer rimasto in cin dopo che è stato preso il carattere che interessa
// così che il seguente cin non ha da prendersi gli inutili scarti avanzati
void ignoraScarti() {
	//char un_carattere;	// ok
	string una_stringa;	// ok
	cout << "Scrivi 1 o + caratteri:";
	// anche inserendo un solo carattere 'cin >> char' lascia '\n' nel buffer. 
	// '\n' è il delimitatore di default per il getline() che segue
	cin >> una_stringa;
	//getline(cin,una_stringa);
	if (cin.fail())	// non accade mai
		cout << "cin ha fallito" << endl;/**/
	cout << "ante clear = 	" << una_stringa << endl;
	// senza di questi due spazzini rimane un '\n' vacante che viene preso dal cin seguente
	cin.clear(); 
	cout << "tra clear e ignore = " << una_stringa << endl;
	// int o char viene preso un carattere e lascitato il \0, invece getline ELIMINA il '\n' finale, quindi ignore si ferma in attesa
	//cin.ignore(INT_MAX,'\n');	// da solo senza che ci sia stato input blocca l'output
	cin.ignore(0);
	cout << "dopo ignore = 	" << una_stringa << endl;

	string myString;
	cout << "Inserisci un'altra stringa:";
	getline (cin, myString);
	cout << "Hai scritto = '" << myString << "'" << endl;
}


// come sapere se nell'input buffer sono rimasti byte da estrarre?
void contaInputBuffer() {

//	cin.rdbuf() -> in_avail()
	// cin normalmente è sincronizzato con 'stdin', questo metodo prevede che non siano sincronizzati (qualunque cosa significhi ciò)
	// ios_base (il capostipite degli i/o stream) ha la funzione membro sync_with_stdio()
	// che commuta la sincronizzazione con lo strem di <cstdio> (cioè il stdin)
	// ma deve stare PRIMA che cin estrae i primi caratteri, dopo è inutile
	ios_base::sync_with_stdio(false);	// ok insispensabile altrimenti poi in_avail() restituisce solo '0'
	//sync_with_stdio(false);   	// errore funzione non dichiarata
	
	//streamsize quantiCaratteri;	// ok.  streamsize è praticamente un signed int
	// in questo caso input buffer è letto da std::cin
	// cin ha la funzione membro pubblica rdbuf() (ereditata dalla classe 'ios')
	// la quale ha? il metodo in_avail() membro della classe streambuf? 
	int quantiCaratteri = std::cin.rdbuf()->in_avail();	// ok. 'int' è equivalente a 'streamsize'
	cout << quantiCaratteri << endl;	// scrive '0' poiché qui all'inizio non ci sono byte avanzati in input buffer
	
	char c;
	cin.get(c);  	// ok. estrae un carattere e ne lascia in buffer
	//ios_base::sync_with_stdio(false);	// NO qui inefficace, poi in_avail() restituisce sempre '0', deve stare PRIMA che cin estrae
	cout << "primo carattere '" << svela(c,1) << "'" << endl;
	cout << "buffer avanzato " << cin.rdbuf()->in_avail() << " char\n\n";	// funziona! scrive '0' se battuto un solo Invio, altrimenti numero caratteri avanzati

	// in_avail() usato dentro cin.ignore()
	cin.clear();		// ripulisce cin da .. uhm qualcosa
	cin.ignore(cin.rdbuf()->in_avail()); // ok! ignora esattamente i caratteri rimasti in buffer non uno di più
										// e anche senza scarti programma prosegue tranquillo
	
	cin >> c;
	cout << "primo " << c << '\n';    	// ok
	quantiCaratteri = cin.rdbuf()->in_avail();   	// ok!
	cout << quantiCaratteri << " rimasti in buffer\n\n";

	// pausa(); non funziona come vorrei

/*	// uso all'interno di un ignore()
	if (!cin) { 	// non so questi 2 if a cosa servono
		cin.clear();
		if (cin) 
			cin.ignore(cin.rdbuf()->in_avail());
	}	*/
	
	// in questo caso input buffer è letto da std::ifstream anziché da std::cin 
	// in_avail() conta caratteri rimasti caricati da un file .txt in cui è scritto almeno un carattere
	std::ifstream ifs ("test.txt");
	//std::streambuf* pbuf = ifs.rdbuf();	// ok ma si può saltare
	ifs >> c;
	cout << "first character in file: " << c << '\n';
	streamsize size = ifs.rdbuf()->in_avail();          	// ok! trova quanti caratteri avanzano
	cout << size << " characters in buffer dopo di lui\n";
	ifs.close();
}


// esempio di cin non sincronizzato con stdin, dimostra come possono accedere a due input buffer distinti
// mostra il fenomeno anche se non funziona proprio come previsto
void cinNonSincronizzatoConStdin() {
	ios_base::sync_with_stdio(false);	// ok 
/* cin */
	cout << "scrivi due parole\n";
	string str;
	cin >> str;    	// cin estrae solo la prima e la seconda rimane in buffer
	cout << " primo cin\t" << str <<endl; 	// !!!!!!!!!! QUI si ferma in attesa di un altro Invio!  perché ???? non so
/* stdin */
	cout << "un numero o lettera\n";
	char c = getchar();
	cout << "   stdin\t'" << svela(c,1) << "'" << endl;	// qui si ferma in attesa input proprio perché getchar() non è legato a cin ma a stdin
/* di nuovo cin */
	getline(cin,str);
	cout << " buffer cin\t'" << str << "'\n";
}

