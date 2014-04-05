// problemi specifici di alcuni comandi C++ e possibili soluzioni


// cin.ignore() si blocca se non c'è input
// non risolto
void ignoreNonIgnora() {
	// il primo argomento è il numero di caratteri MASSIMO da ignorare, default è 1
	// se è maggiore 
	cout << "ante clear" << endl;
	//cin.clear(); 
	cout << "tra clear e ignore" << endl;
	//  si ferma in attesa di un invio
	//cin.ignore();	// ignore si ferma in attesa di un invio
	cin.ignore(0);	// passa via
	//cin.ignore(INT_MAX,'\n');	// da solo senza che ci sia stato input blocca l'output ???
	cout << "dopo ignore" << endl;
}


// cin.get(char[]*) prende i caratteri e lascia SEMPRE in input il separatore '\n'
// infatti i cin.get() seguenti lo estraggono
// dopo un solo Invio inserisce stringa vuota in *char[] e dovrebbe lasciare in buffer il '\n'
// problema: invece i cin.get() seguenti anche NUMEROSI non estraggono alcun '\n' né arrestano il programma in attesa di input.
// cin.clear() consente ai seguenti cin.get(char) di estrarre '\n' anche dopo questo caso particolare dell'Invio senza altri caratteri
// ma non basta per i seguenti cin.get(char[])
// ecco dunque che cin.clear() + cin.ignore(INT_MAX,'\n') risolvono per entrambi, anche se così nota bene il \n è eliminato dal buffer
void cingetNonAttendeInput() {
	// basic_istream::get di cui 
	
	/*char arrai[256];
	cin.get(arrai,256);	// ok. sottointeso terzo argomento '\n'
	cout << "arrai	'" << arrai << svela(arrai[strlen(arrai)]) << "'" << endl;

	//char arrai[1];
	//cin.get(arrai,1);	// non estrae alcun carattere dall'input e mette solo un NUL /0 nell'unico posto
						// però i caratteri avanzati non si ritrovano estratti dai seguenti cin.get()*/
	
	char arrai[3];
	cin.get(arrai,3);	// prende solo il primo carattere e nel secondo posto mette /0
						// i restanti caratteri avanzati compreso '\n' sono estratti dai cin.get() seguenti
			// se dato solo un Invio, giustamente mette /0 al primo e tanto basta
			// STRANEZZA: ma in questo caso il cin.get seguente non cattura niente (a logica dovrebbe estrarre solo un '\n')
			// e neanche tre cin.get() posti in fila consecutiva si fermano più in attesa input.
	for(size_t i=0; i<strlen(arrai)+10; i++)
		cout << svela(arrai[i]) << " ";
	cout << endl;

	// questo fenomeno dei seguenti cin.get ignoranti non sembra accadere se invece di char[] è un semplice char
	/*char c;
	cin.get(c); 
	cout << "char '" << svela(c) << "'" << endl;*/ // poi i seguenti scorrono giusti rispetto a quanti caratteri avanzati

	// questi risolvono pare (leggi sopra)
	cin.clear();
	//cin.ignore(INT_MAX,'\n');	// però in Lubuntu: INT_MAX non è dichiarato in questo scope
	
	char arrai2[7] = {7};
	cin.get(arrai2,5);
	cout << "arrai2 ";
	for(size_t i=0; i<strlen(arrai2)+5; i++)
		cout << svela(arrai2[i]) << " ";
	cout << endl;
	char arrai3[3] = {3};
	cin.get(arrai3,3);	// quando dovrebbe estrarre il solo '\n' avanzato in buffer riempie l'array di '\0' ma non si ferma
		for(size_t i=0; i<strlen(arrai3)+3; i++)
		cout << svela(arrai3[i]) << " ";
	cout << endl;
	char arrai4[3] = {4};
	cin.get(arrai4,3);
		for(size_t i=0; i<strlen(arrai4)+3; i++)
		cout << svela(arrai4[i]) << " ";
	cout << endl;/**/
	
	cin.clear();
	
	char caruccio = 'W'; 	// ok
	cin.get(caruccio);  	// qui NON si ferma in attesa di input, neanche se all'apparenza non prende alcun '\n' avanzato dal prim cin.get
	//caruccio = cin.get();	// idem non si ferma
	cout << "secondo " << svela(caruccio) << endl;
	//cin.get(caruccio); 		// neanche qui si ferma se è stato dato SOLO un INVIO, ma sì se inserito almeno un carattere + invio
	caruccio = cin.get();	// idem non si ferma dopo un solo invio, ma sì se inserito uno o più caratteri + invio
	cout << "terzo " << svela(caruccio) << endl;
	char caruccio4 = '4'; 
	caruccio4 = cin.get();	// idem non si ferma dopo un solo invio ??
	cout << "quarto " << svela(caruccio4) << endl;
	
	// scoperto che forse questo interrompe il 
	char c=4;	// proprio con 4 EOT non con altri, quindi forse anche 3 EOF
	do { cin.get(c);
		cout << svela(c,1);
	} while ( c!='\n' && c!=4 );
	
	// da stackovfw
	// .get(char*,int) will never remove the '\n' from the buffer
	// inoltre il tentativo di leggere char* (?) mette cin in stato di tristezza tanto che non legge più niente, 
	// a meno di .clear() questo stato di depressione di cin
}


// potenza di 10 perde una unità con esponenti '2' e '4'
// risolto arrotondando il risultato con round() o floor()
void potenzaSottraeUno() {
	// il fatto è che pow() calcola con virgola mobile, e a volte il risultato è 99.99999 che int diventa 99
	int num = pow(10,2); 	// qui dentro c'è l'errore
	cout << num << endl;	// scrive '99' anziché '100'
	num = pow(10,3);
	cout << num << endl;	// ok '1000'
	num = pow(10,4);
	cout << num << endl;	// '999' invece di '10000'
	num = pow(10,5);
	cout << num << endl;	// ok '100000'
	num = pow(10,6);
	cout << num << endl;	// ok '1000000'
	
	// occorre arrotondare il risultato della potenza con round() o floor() in questo caso equivalenti
	num = round(pow(10,2));	// arrotonda il risultato di tipo double
	cout << num << endl;	// ok! scrive '100'
	num = floor(pow(10,4));	// idem arrotonda il risultato
	cout << num << endl;	// ok! scrive '10000'
}

