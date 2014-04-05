// basilare teoria informatica in particolare signed-unsigned int
void signedUnsigned() {
	cout<<"unsigned int di un byte  	\n"
	" binario 00000000→11111111 decimale 0→255 esadecimale 00→FF  	\n"
	"signed int arrivato a metà ( hex 50 = dec 128 ) diventa negativo  -128→-1 anziché 128→255	\n"
	"00001111→11111111";
	// perché a che serve?
}

// confronta 2 numeri
void confrontoNumeri() {
	int number1;
	int number2;

	cout << "scrivi due numeri:\r\n";
	cin >> number1 >> number2;

	if(number1 == number2)
		cout << number1 << " == " << number2 << endl;
		
	if(number1 != number2)
		cout << number1 << " != " << number2 << endl;

	if(number1 < number2)
		cout << number1 << " < " << number2 << endl;

	if(number1 > number2)
		cout << number1 << " > " << number2 << endl;
		
	cout << "modulo e': " << number1 % number2 << endl;
	
	/*int resto;	// x risolvere un dubbio. tutto ok
	resto = number1 % 16;
	cout << "resto esadecimale " << resto << endl;
	resto = number1 % number2;
	cout << "resto esadecimale " << resto << endl;*/
	cout << endl;
}

// scompone le 5 cifre di un numero
void scomponeNumero() {
	int valore;
	cout << "entra un numero di 5 cifre ";	// ad es 12345
	 	// il problema è che se input lettere va subito in loop
	cin >> valore;	// come verificare che sono solo numeri?
	//if ( (valore = cin.get()) > 0) { // no prende troppa roba
	//if (valore > 0 && valore < 100000) {	// questa condizione non lo preserva, il loop parte prima
	cout << valore/10000 << " ";
	cout << valore/1000 % 10 << " ";
	cout << valore/100 % 10 << " ";
	cout << valore/10 % 10 << " ";
	cout << valore % 10 << " ";
	cout << endl;
	//}
}

// confronta while e do-while
void confrontaWhileDoWhile() {
	// while gira finché la condizione è vera, se all'inizio del loop è diventata falsa il loop non riparte
	int i = 0;
	cout << "while ";
	while ( i < 0 ) {
		i++;
		cout << i;  	// non scrive niente
	}
	cout << "	";
	char car;
	while ( car != '\n' ) {
		car = cin.get();
		cout << svela(car);	// scrive il '\n' finale
	}
	cout << endl;
	
	// anche do-while verifica la condizione all'inizio del loop
	// TRANNE che al primo loop, il quale parte anche se la condizione è falsa
	// quindi do-while gira sempre ALMENO UNA volta
	i = 0;
	cout << "do-while ";
	do {
		i++;
		cout << i;   	// scrive '1'
	} while ( i < 0 );
	cout << "	";
	do {
		car = cin.get();
		cout << svela(car);	// idem scrive una volta il '\n' finale
	} while ( car != '\n' );
}


// in uno switch il return interrompe la funzione oppure occorre anche il break?
string switchReturnBreak() {
	switch(1){	// è vero il caso 1
		case 0: cout << "zero";
		case 1: cout << "primo ";	// in chiamaSwitchReturnBreak() ritorna questo
		case 2: return "secondo\n";	// e questo.
		case 3: cout << "terzo";	// questo no
}	}
void chiamaSwitchReturnBreak() {
	cout << switchReturnBreak();	// scrive 'primo secondo' quindi dopo return non occorre break
}


// confronta for e while con dentro continue
void confrontaForWhile() {
	for (int i=1; i<=10; i++) {
		if (i==5)
			continue;
		cout << i << " ";
	}
	cout << "\n";
	
	int i=1;
	while ( i<=10 ) {
		if (i==5) {
			//continue;	// qui il programma va in loop con cursore lampeggiante e non entri più niente
			cout << "[qui il programma va in loop]" << endl;	break;	// alternativa eseguibile
		}
		cout << i << " ";
		i++;
	}
}


// uscire da un while con Ctrl+D 'End Of Transmission'
void EOTesceWhile() {
	// char 4 EOT (end of transmission)
	// si ottiene digitando Crtl+D che a video scrive '^D' + un acapo
	// in Lubuntu Ctrl+D non scrive niente ma ugualmente inserisce il carattere EOT che fa uscire dal programma
	// in Windows è mostrato '♦' e incollandolo+acapo si ottiene lo stesso EOT int 4

	// in un char
	char chr;
	while ( chr != 4 ) {	// ok. loop nell'input stream finchè trova un EOT
		chr = cin.get();
		cout << " char '" << svela(chr,1) << "'" << endl;	// ok scrive '♦' un'ultima volta poi esce dal loop 
	}
	cout << "uscito dal while" <<endl<<endl;

	// in un char seconda possibilità, meglio del precedente evita il cout restante dopo il break
	while (1) {	// loop infinito
		chr = cin.get();
		if ( chr == 4 ) break; 	// ok interrompe loop appena trova EOF
		cout << " char '" << svela(chr,1) << "'" << endl;	// questo non viene mostrato dopo il break
	}
	cout << "fine secondo while" <<endl<<endl;


	// con string
	int i=0;
	string coord;
	while ( coord!="♦" ) {	// finché non scrive exit
		coord.clear(); i=0;
		do {
			chr = cin.get();
			coord.resize(i+1);
			coord[i] = chr;
			i++;
		} while (chr!='\n');
		if(i>1) coord.resize(i-1);	// toglie \n finale a meno che è l'unico
		cout << " '" << coord << "' " << " char\n";	// ok

		//if (coord=="exit") break; 	// ok esce dal while;
		
		// 4 '♦' EOT= end of transmission. si ottiene digitando Crtl+D 
		if ( coord[0] == 4 ) break; 	// ok con Ctrl+D scrive '^D' che sarebbe int 4
		
		//if ( coord[0] == 'EOT' )	// ho trovato questa formula ma mostra avviso multi-caracter
	}
}

// chiudi applicazione con carattere EOF End-Of-File int 3 inserito con Ctrl+C
// In Windows appare '♥'
// anche in Lubuntu Ctrl+C scrive '^C' probab inserisce EOF e il programma termina
void endOfFile() {
	char c;
	c = cin.get();    	// premendo Ctrl+C inserisce EOF e va a capo
	cout << svela(c,1) << endl;  	// il carattere EOF inserito ha int -1
	if(cin.eof()) 	// ok! valuta se da qualche parte nel cin c'è EOF, anche dopo ad altri caratteri avanzati in buffer
		cout << "cin.eof() ha trovato EOF" << endl;	// ok lo scrive e basta
	cout << "dopo fine " << endl;
	c = cin.get();		// il programma prosegue ma non si ferma in attesa input
	cout << svela(c,1) << endl;  // scrive '-1'
	c = cin.get();		// 
	cout << svela(c,1) << endl;  // scrive '-1'
	c = cin.get();		// anche questo estrae da cin -1
	cout << svela(c,1) << endl;	// scrive '-1'
	string finale;  	/**/
	getline(cin,finale); 	// anche questo estrae EOF da cin immagazzinandolo come una stringa vuota
	cout << svela(finale[0],1) << endl;	// scrive '\0'
							// MA getline() a differenza di cin.get reinposta input rendendolo disponibile a nuovo input
	c = getchar();     	// QUI di nuovo programma attende input utente
	cout << svela(c,1) << endl;
}


// esperimenti per allineare testo e numeri left o right con setw()
void allineaTestoNumeri() {
	cout << "setw(7)" << endl;
	cout << "<< 0" << endl;
	setw(7);
	cout << 0 << endl;
	
	cout << "<< setw(7) << 1" << endl;
	cout << setw(7) << 1 << endl;	// di default si allinea a destra nella 7a casella
	
	cout << "<< right << 12" << endl;
	cout << right << 12 << endl;	// il setw si perde se non viene più esplicitato
	
	cout << "<< setw(7)" << endl;
	cout << "<< 123" << endl;
	cout << setw(7);		// però può essere dichiarato in un cout precedente, è proprio come mettere una tabulazione
	cout << 123 << endl;	//	123 è allineato a destra
	
	cout << endl;
	
	// cout << left;		// esplicitando left tutti i seguenti si allineano a sinistra
	cout << "<< setw(7) << \"a\"" << endl;
	cout << setw(7) << 'a' << endl;     	// anche il testo di default si allinea a destra!
	
	cout << "<< setw(7)" << endl;
	cout << "<< \"abc\"" << endl;
	cout << setw(7);			// anche se il setw sta nella riga prima
	cout << "abc" << endl;		// abc è allineato a destra

	cout << "<< setw(7) << left << \"ab\"" << endl;
	cout << setw(7) << left << "ab" << endl;
	
	cout << "<< setw(7) << \"cd\"" << endl;
	cout << setw(7) << "cd" << endl;		// mantiene il left impostato prima anche senza più esplicitarlo

	cout << "<< right" << endl;	
	cout << "<< setw(7) << \"a\"" << endl;
	cout << right;            		 	// right impostato da solo
	cout << setw(7) << "a" << endl; 	// a  è allineata a destra
	
	cout << "<< setw(7) << \"bc\"" << endl;
	cout << setw(7) << "bc" << endl;       	// mantiene il right impostato prima
	
	cout << endl;

	cout << "<< setw(7) << \"a\" << 1" << endl;	
	cout << setw(7) << "a" << 1 << endl;		// a1  insieme a destra perchè ricorda il right dichiarato prima

	cout << "<< left" << endl;	
	cout << "<< setw(7) << \"a\" << 1" << endl;	
	cout << left;								// dopo dichiarare il left...
	cout << setw(7) << "a" << 1 << endl;		// a	1  sono separati anche se il setw è all'inizio !

	cout << "<< setw(7) << 2 << \"b\" " << endl;
	cout << setw(7) << 2 << "b" << endl;		// 1	a  separati! anche se il primo è un numero?!?!?

	cout << "<< setw(7) << 2 << \"b\" " << endl;
	cout << setw(7);
	cout << left << "c" << left << 3 << endl;  	// c	3  inutile, ormai il 3 è DOPO la tabulazione di 7
				// l'operatore di inserimento nello stream << NON concatena stringhe, ma semplicemente aggiunge output a video

	//string d4 = concat("d", 4) ;      	// COME CONCATENARE UNA STRINGA E UN NUMERO IN C++ ? non vanno: + .
	string d4 = "d4" ;
	cout << setw(7);
	cout << left << d4 << endl;  	// c	3  inutile, ormai il 3 è DOPO la tabulazione di 7

	cout << "<< right << \"bc\" << 23" << endl;
	cout << right << "bc" << 23 << endl;		// anche qui il valore di setw() si perde se non è esplicitato
	
	cout << "<< \"bc\" << 23" << endl;
	cout << "bc" << 23 << endl;        		// idem per ulteriore conferma
	
	cout << "<< setw(7) << right << \"a\" << 1" << endl;
	cout << setw(7) << right << "a" << 1 << endl;		// a1 insieme a destra
	
	cout << "<< \"a\" << setw(7) << 1" << endl;
	cout << "a" << setw(7) << 1 << endl;        	// a	1  separati
	
	cout << "<< left << \"a\" << setw(7) << 1" << endl;
	cout << left << "a" << setw(7) << 1 << endl;     	// a1  insieme a sinistra
	
	cout << "<< left << \"a\" << setw(7) << right << 1" << endl;
	cout << left << "a" << setw(7) << right << 1 << endl;  	// a	1  separati
}


// i Deitel dicono che in c++ dichiarare due parametri "double x, y" è un errore di sintassi
// ma questa funzione dichiara delle variabili con la virgola e va benissimo
// infatti in alcuni esempi la usano anche loro!
void dichiaraVariabili() {
	double numerino1, numerino2;
	numerino1 = .01234;	
	numerino2 = 22.2345;
	cout << "numerino1 = " << numerino1 << endl;
	cout << "numerino2 = " << numerino2 << endl;
		
	string testino1, testino2;
	testino1 = "prima stringa";
	testino2 = "seconda stringa dichiarata dopo la virgola";
	cout << "testino1 = " << testino1 << endl;
	cout << "testino2 = " << testino2 << endl;
	
}

void timeManager() {	// magari si può chiamare solo secondi()
	cout << time(0) << " secondi dal 1 gennaio 1970 " << endl;
	
	// dichiarazione di costanti di enumerazione
	enum Mesi { GEN=1, FEB, MAR, APR, NOV, DIC };	// senza =1 corrispondono a 0 1 2 ...
	Mesi meseAttuale;
	meseAttuale = MAR;
	cout << meseAttuale << endl;	// 3
	//cout << Mesi;               	// errore
}


// crea una tabella con le potenze degli interi da 1 a 100
void tabellaPotenze() {

	int riga = 0,
		colonna,
		larga_min = 7,
		N;

	while (riga < 102) {
		colonna = 0;
		N = riga-1;	// la prima riga coi valori è la 2 e i numeri devono partire da 1
		
		while (colonna < 10) {
			// corpo della tabella
			if(riga>1) {
				// di default testo allineato a sinistra e numeri a destra
				// con left e right si può modificare
				//if (colonna==0 || colonna==7 )
				//if(colonna%2)	// alterna colonne pari e dispari
				/*if(riga%2)	// alterna le righe pari e dispari
					cout << right; 
				else cout << left;*/
				
				//N = N*riga;	// aumenta i valori di modo da renderli disomogenei
				//N *= 10;	
				cout << setw( larga_min + colonna );
				cout << left;	// allinea tutti a sinistra
				//cout << pow(N,colonna+1);		// numeri oltre 999999 scritti come decimali X potenze di 10
				cout << fixed << setprecision(0) << pow(N,colonna+1);	// numeri interi (senza potenze di 10)
																		// vanno ben oltre i 4 miliardi !
				
			// linea demarca
			} else if (riga==1) {	
				for (int i=0; i<larga_min + colonna;i++)
					cout << setw(0) << "-";
				cout << "+";
				
			// intestazione	
			} else {
				//cout << "N*" << left << pow(10,colonna);	// moltiplicato per 10 100 1000...
				//cout << setw(0) << left;	prima colonna a 0 e non capisco perché
				if (colonna>0)
					cout << "N^" << colonna+1 << setw(larga_min+colonna-2);	// COME CONCATENARE TESTO E NUMERO?
				else 	// solo per la prima
					cout << "N" << setw(larga_min);
				cout << "|";
				//cout << setw(larga_min+colonna);
			}
			
			if (riga>1) {	// solo per il corpo
				cout << "|";	// uguale per tutte
				/*if(riga%2)	// righe dispari e pari in alternanza
					cout << ":"; 
				else cout << "|";*/
			}
			
			colonna++;
		}
		cout << endl;
		riga++;
	}
	// l'allineamento rimane attivo poi per tutto il programma!
	// siccome l'ultimo dichiarato qui sopra è stato left poi si propaga altrove quindi moglio ristabilire right
	cout << right;	// forse basterebbe solo right; ?
}


/* tabella con i 256 caratteri ANSI (o si dice ASCII Extended?)
 * in Windows quasi tutti 256 come carattere stampabili, anche i primi 16 
	  ☺ ☻ ♥ ♦ ♣ ♠         ♂ ♀   ♫ ☼
	► ◄ ↕ ‼ ¶ § ▬ ↨ ↑ ↓ → ← ∟ ↔ ▲ ▼
 * e la seconda metà tutti i caratteri accentati di Europa occidentale
 * Lubuntu mostra solo gli ASCII da 0 a 127, i primi 16 perlopiù quadratini col numero esadecimale
 * la seconda metà quasi tutti '�' tranne un paio vuoti
 */
void profiloCarattere(string);
void listaCaratteriCtrl();
void listaCaratteri() {
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

		// uscita da questo sottoprogramma
		if ( coord=="exit" || car==4 || cin.eof() ) 
			break;	// "exit" e EOT escono da questo sottoprogramma, EOF anche dal macroprogramma

		if (coord=="tabella"||coord=="tab") {
			listaCaratteri();	// ridisegna char table
			break; 	// interrompe il while in caso di uscita
		}
		if (coord=="c2") listaCaratteriCtrl();	// ok ma andrebbe messa meglio da qualche parte
		
		profiloCarattere(coord);
		//cout << ":";
}	}

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
			if (decim>=127) cout << " " << decim-0x100;	// inserisce eventuale signed
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
	{	cout << "  carattere '" << svela(coord[0]) << "'" << endl;
		decim = coord[0];  	// ricava il SIGNED int del carattere ANSI
		cout << "   decimale ";
		if (decim<0) cout << decim+256 << " ";	// se è signed negativo -128→-1 infila l'unsigned 128→255
		cout << decim << endl;	         	// e signed si sposta a destra
		cout << "esadecimale " << decimaleEsadecimale(decim) << endl;
	}
}


// esploriamo insieme 'cin' importantissimo comando di C++
void tuttoCin() {
/*	// l'oggetto 'std::cin' estrae i caratteri da una fonte input, tastiera o file che sia
	cin;         	// avviso: da solo non ha effetto
	cout << cin;	// non si ferma in attesa input. sia con buffer pieno che vuoto scrive solo '0x483908' */

	cout << "scrivi una parola:";
	char c;
	cin >> c;	// cin ferma il programma in attesa dell'input utente. programma riparte dopo un Invio
	         	// cin estrae dall'input in relazione col tipo di variabile a destra dell'operatore '>>'
				// in questo caso è un char perciò cin estrae dall'input solo il primo carattere e lo scarta dal buffer (ma forse rimane)
	cout << "primo char " << svela(c,1) << endl;

	// ecco che arriva un second 'cin'... a questo punto ci sono 2 possibilità: 
	// 1: utente ha battuto 1 solo carattere che è stato estratto e scartato da primo cin, quindi non c'è più niente in input buffer
	// 2: utente ha battuto alcuni caratteri, il cin ha estratto il primo e gli altri sono ancora in input buffer
	string s;
	cin >> s;	// nel primo caso cin blocca il programma in attesa di ricevere altro input
				// nel secondo caso estrae i restanti caratteri e li mette tutti nella stringa
	cout << "resto string " << s << endl<<endl;


	// ho ipotizzato che dentro l'ambito di un'altro scope, come per le variabili ci fosse un altro livello di cin
	// invece no perché cin estrae dall'INPUT BUFFER che è unico per tutti gli scope
	{	string s2;
		cout << "inserisci 2 parole:";	// eventuali spazi spezzano la stringa che vengono prese separatamente dai due cin
		cin >> s2;
		cout << "dentro " << s << endl;
	}
	//cin >> s2;	// errore sintassi: 's2' non è stata dichiarata in questo scope
	cin >> s;	// ok dichiarata prima in questo stesso scope
	cout << "fuori  " << s << endl;

	// 'cin' è un oggetto della classe 'istream' e quindi ne eredita tutte le proprietà
}

