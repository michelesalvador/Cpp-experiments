/* ASCII 7 bit (0→127)
 * così appare la tabella in Lubuntu
 * 
 * 
 * "Extended ASCII" sono  le varianti a 8 bit in genere
 * 
 *  Code page 437
 * l'originale di MS DOS, caratteri di controllo 1→31 e 127 diventano stampabili in contesti di output
 * 
 *  Code page 850 (simile a 437)
 * quasi perfettamente quello del prompt attuale
 * 
 *  Code page 858 
 * identico a 850 tranne aggiunge € al posto di ı
 * 
 *  ANSI c'è controversia su cosa sia esattamente
 * 
 *  ISO 8859-1 (Latin 1)
 * 128→159 riservati a caratteri di controllo 
 * 160→255 quasi tutti stampabili caratteri accentati europa occidentale ± ¶ »
 * I primi 256 caratteri Unicode sono questi stessi identici
 * 
 *  Windows-1252
 * il più comune codepage. 
 * identico a 8859-1 con in più anche 128→159 quasi tutti stampabili (accentati € …)
 */
 
/* come appare la tabella di 256 caratteri nel prompt dei comandi cmd.exe
 * 'chcp' setta il codepage, cioè quale carattere mostrare di uno stesso int
 * 
 * 437   ♦Ç░α	OEM statuniti del primo MS DOS. quasi tutti 256 come carattere stampabili, anche i primi 16
 *  			  ☺ ☻ ♥ ♦ ♣ ♠         ♂ ♀   ♫ ☼
 *  			► ◄ ↕ ‼ ¶ § ▬ ↨ ↑ ↓ → ← ∟ ↔ ▲ ▼
 *           	molte cornicette, alcuni caratteri greci
 * 850   ♦Ç░Ó	Latin 1, simile al 437, meno cornicette e greci e più caratteri accentati
 * 	     		è il codepage di defaut nella console Windows (prompt dei comandi) attuale
 *          	si può modificare nel registro di sistema
 * 855   ♦ђ░Я 	cirillico
 * 1252  €°à	Latin 1. la più sensata
 *          	0→31 tutti '' che celano i caratteri controllo
 *          	128→255 quasi tutti caratteri accentati ben ordinati, nessuna cornicetta
 * 1250  €°ŕ	Latin 2 (europa centrale)
 * 65001 	in teoria sarebbe UTF-8
 * 	        	fa comparire corretti i caratteri unicode delle string literal
 *          	della tabella 256 ci sono solo gli ASCII, 0→31 e 128→255 sono '' e non si lasciano copiare!
 * 	         	inoltre dà diversi problemi all'esecuzione del programma...
 * 28591 °à	codepage Windows corrispondente a ISO 8859-1
 *           	e infatti tabella 256 appare come atteso
 */

// semplice stringa con caratteri unicode
void caratteri256() {
	cout << "abcd\nàèìòù\nQ.ᵗᵒ ḝ il teſto no͠v:ᵒ\n";
	/* in cmd.exe 
	 * font Consolas	ok ha tutti i caratteri unicode
	 * 'chcp 65001' 	ok setta output utf8
	 * ma dopo averla outputtata cursore aspetta nel limbo... 
	 * credo per mala interpretazione della lunghezza della stringa
	 * 
	 * 'type tabellacaratteri.h' (che stampa a video tutto il file) caratteri unicode tutti ok
	 */
}
 
/* tabella con i 256 caratteri ASCII esteso
 * il risultato dipende dal codepage inpostato: in cmd.exe il codpage di default è 850
 * Lubuntu invece pare ASCII: i primi 16 perlopiù quadratini col numero esadecimale, 128→255 quasi tutti '�' tranne un paio vuoti	*/
void listaCaratteri() {
	// riga intestazione
	cout << setw(4);
	for (int e=0; e<16; e++)
		cout << Esadecimi[e] << " ";
	cout << endl;
	
	int n = 0;
	for ( int y=0; y<16; y++ ) {
		cout << endl << Esadecimi[y] << setw(3);
		for (int x=0; x<16; x++) {
			char c = n;
			cout << svela(c,2) << " ";	// ok
			n++;	// 0-255
	}	}
	cout << endl;
}

// disegna lista dei caratteri 0-31 con il corrispondente Ctrl+ABC
void listaCaratteriCtrl() {
	char ABC;
	cout << "Ctrl+ ";
	for (int i=65; i<=90; i++) {
		ABC = i;
		cout << ABC << " ";
	}
	cout << "? ? ? " << endl << setw(7);;
	
	for (int i=1; i<32; i++ ) {
		ABC = i;
		cout << svela(ABC,2) << " ";
	}
	cout << endl;
}


// riceve stringa e scrive dati sul carattere
void profiloCarattere(string coord) {
	string eventuale = coord;	// di passaggio per valutare cosa contiene coord
	int decim;     	// numero decimale -128→255

	// almeno 3 caratteri valuta se sono un numero decimale 
	if (coord.size()>=3) {
		eventuale.resize(3);
		if ( (decim=stringaNumero(eventuale))!=-1 && decim<256 ) {	// intero tra 0 e 255
			cout << "   decimale " << decim;
			if (decim>127) cout << " " << decim-0x100;	// aggiunge eventuale signed -128→-1
			cout << endl;
			cout << "  carattere '"<< static_cast<char>(decim) <<"'" << endl;
			cout << "esadecimale " << decimaleEsadecimale(decim) << endl;
			return;
	}	}
	// almeno 2 caratteri valuta se i primi 2 sono un esadecimale 
	if (coord.size()>=2) {
		eventuale.resize(2);
		if ( (decim=esadecimaleDecimale(eventuale)) != -1 )	{ // inserito un esadecimale di 2 cifre e valido
			cout << "esadecimale " << maiscolo(eventuale) << endl;	// ok
			cout << "   decimale " << decim;
			if (decim>127) cout << " " << decim-256;	// eventuale signed
			cout << endl;
			cout << "  carattere '"<< static_cast<char>(decim) <<"'" << endl;   // ok anche 128+
			return;
	}	}
	// altrimenti considera il primo carattere inserito
		cout << "  carattere '" << svela(coord[0]) << "'" << endl;
		/*decim = coord[0];  	// ricava il SIGNED int del carattere ANSI
		cout << "   decimale ";
		if (decim<0) cout << decim+256 << " ";	// se è signed negativo -128→-1 infila l'unsigned 128→255
		cout << decim << endl;	         	// e signed si sposta a destra*/
		
		decim = coord[0]<0 ? coord[0]+256 : coord[0];  	// ricava unsigned int 0-256 del carattere
		cout << "   decimale " << decim;		
		if (decim>127) cout << " " << decim-256;	// eventuale signed -128→-1
		cout << endl;
		cout << "esadecimale " << decimaleEsadecimale(decim) << endl;
}


void esploraCaratteri() {	
	cout << "inserisci carattere (a) esadecimale (61) o decimale (097)\n";
	string coord;
	char car;
	int i;
	//while ( !cin.eof() ) {	// ok! interrompe loop se trova EOF in cin
	while (1) { // non valuta niente, solo loop
		// riceve input utente
		coord.clear(); i=0;
		do {
			car = cin.get();
			if (car==4) break;	 	// EOT interrompe questo loop e il superiore
			if (cin.eof()) break;	// EOF interrompe questo loop, il superiore e il macroprogramma
			//cout << car ;
			coord.resize(i+1);
			coord[i] = car;
			i++;
		} while (car!='\n');	// '\n' è l'ultimo carattere che estrae
		if(i>1) coord.resize(i-1);	// toglie \n finale a meno che è l'unico
		//cout << " '" << coord << "' " << coord.size() << " char\n";	// ok

		// elaborazione comandi
		if ( coord=="exit" || car==4 || cin.eof() ) 
			break;	// "exit" e EOT escono da questo sottoprogramma, EOF anche dal macroprogramma
		else if (coord=="t1"||coord=="tab")
			listaCaratteri();	// ok ridisegna char table di 256 caratteri
		else if (coord=="t2") 
			listaCaratteriCtrl();	// ok
		else 
			profiloCarattere(coord);
	}
}
