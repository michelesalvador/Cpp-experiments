// questa è l'unica vera libreria di funzioni utili 

const char Esadecimi[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
const char EsadecimiMinus[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	
// riceve un numero e restituisce il numero di cifre che lo compone
// int arriva max a 10 cifre, long idem. short dovrebbe essere tipo 65000
int contaCifre(long numero) {
	int cifre = 0;
	do{ numero /= 10;	// ogni divisione elimina l'ultima cifra fino a ridurre numero a zero
		cifre++;
		//cout << cifre << " " << numero << endl;
	} while (numero > 0);
	return cifre;
}


// restituisce il valore esadecimale di un intero o di un carattere
// arriva fino a 255=FF, poi 256=00 e ricomincia
string decimaleEsadecimale(int deci) {
//char decimaleEsadecimale(int deci) {	// non so come ritornare un char array
	//char hex[9] = {0};	// ok array di 9 caratteri nulli
	string hex = "00";
	//if ( contaCifre(deci)==1 ) {	// ok. decimale di una cifra 0-9 è uguale a esadecimale e morta lì
	/*if ( deci<16 ) {
		//return deci;	// non so come convertire int in testo
		hex[0] = Esadecimi[deci];	// ok funziona
		return hex;
	}*/
	//if ( deci==16 )	return "10"; ok
	//if ( deci==17 )	return "11"; ok
	//hex.resize(2);
	hex[1] = Esadecimi[deci % 16];	// unità inserite nella stringa in seconda posizione
	hex[0] = Esadecimi[deci/16];	// 16ine in prima
	//cout << " hex " << hex << endl;
	//for ( size_t pos=0; deci>0; pos++ ) {	// le posizioni delle cifre esadecimali	}
	return hex;
}


// restituisce il valore decimale di una string che contiene un intero esadecimale
// ritorna -1 se non è un esadecimale
int esadecimaleDecimale (string &esade) {
	int dec = 0;
	for( size_t pos=0; pos<esade.size(); pos++ ) {	// ciclo tra le posizioni della stringa
		int e = 0;	// indice nell'array Esadecimi
		while ( esade[pos]!=Esadecimi[e] && esade[pos]!=EsadecimiMinus[e] ) {
			e++;
			if(e>15)	// il carattere non è tra i 16 Esadecimi
				return -1;
		} 
		dec += e * pow( 16, esade.size()-pos-1 );		
	}
	return dec;
}


// riceve un caratter invisibile \n \t \0 spazio e ritorna sequenza escapata
/* secondo argomento: 
	0 essenziale     		\0	\n		 
	1 escapato      		\0	\n	\t	\ 
	2 monocarattere    	a	0	n	t	 
	3 monocarattereANSI	♫	0	¶	→	·	<--- non funziona bisogna usare gli esadecimi \x04 	*/
string svela(char tipino, int stile=0, string spazio=" ") {
	// per ora non va lo stile 2 utf8 ¶·→☻
	const string Stampabili[5][4] = { "\\0","\\0","0","☺", 	"\07","\07","a","\x0E",   "	","\\t","t","→", 	"\\n","\\n","n","¶", 	" ","\\ "," ","·" };
									// 0 NUL				7 alarm 				9 tabulazione			10 acapo 				 spazio				 
	switch (tipino) {
		case '\0':	// 0 NUL il carattere nullo
			return Stampabili[0][stile];
		case 4:  	// 4 EOF end of file
			return "\x04";		
		case 5: 	// 5 ?
			return "5";
		case 7:  	// 7 BEL alarm bip
			return Stampabili[1][stile];
		case 8:   	// 8 BS backspace
			return "b";
		case '\t':	// 9 HT tabulazione
			return Stampabili[2][stile];
		case '\n':	// 10 LF nuova linea
			return Stampabili[3][stile];
		case 11: 	// Windows '♂' 	in Lubuntu diventa una specie di acapo
			return "B";
		case 12: 	// Windows '♀' 	in Lubuntu si manifesta che va una riga sotto
			return "C";
		case '\r':  	// 13 CR ritorno di carrello
			return "r";	
		case ' ':	// spazio
			if (spazio!=" ") return spazio;	// ok! ritorna spazio personalizzato
			else return Stampabili[4][stile];
		/*case -10:
			return "-10";*/
		case -1: 	// restituito da cin.get(char) che non riesce a estrarre '\n'
			return "-1";	// in Lubuntu compare nella tabella al carattere FF cioè unsigned int -1
		 default: 	// ritorna stringa con il solo carattere
			char arr[2] = {tipino,0}; 
			string str(arr);
			return str;
	}
}
//string rivela(char, bool, string) = svela;	// non so come copiare una funzione in un'altra


//riceve una stringa e converte i caratteri a-z in A-Z
string maiscolo(string st) {
	int chint;
	for( size_t i=0; i<st.size(); i++ ) {
		chint = st[i];
		if ( chint>=97 && chint<=122 )
			st[i] = chint-32;	// ogni maiuscolo sta giusto 2 righe prima del corrispondente minuscolo
	}
	return st;
}


// se stringa composta solo di numeri 0-9 la restituisce come int altrimenti -1
int stringaNumero(string st) {
	int num = 0;
	for( size_t i=0; i<st.size(); i++ ) {
		if (st[i]<48||st[i]>57)	// carattere minore di 48 '0' e maggiore di 57 '9'
			return -1;
		else
			num += (st[i]-48) * round(pow(10,st.size()-i-1));	// inserisce il carattere nel numero
		//cout <<" "<< st[i] <<"  "<< num <<endl;
	}
	return num;
}

// mette una pausa nel programma
void pausa() {	// si può fare + semplice, ma per ora vediamo se funziona così
	ios_base::sync_with_stdio(false);	// troppo tardi! dovrebbe stare PRIMA che cin comincia a estrare da input
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());	// umh devo studiare meglio questo ignore
	ios_base::sync_with_stdio(true);
	cout << "...\n";
	char x[1];
	cin.getline(x,1);
}

// DOVREBBE restituisce il numero di caratteri avanzati nell'input buffer di cin
int altroInput() { // ma non funziona
	//ios_base::sync_with_stdio(false);	// troppo tardi! dovrebbe stare PRIMA che cin comincia a estrare da input
	int ss = cin.rdbuf()->in_avail();
	ios_base::sync_with_stdio(true);
	return ss;
}
