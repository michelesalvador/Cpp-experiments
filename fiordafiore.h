// laboratorio di ricerca dei comandi basilari C++ per output, input, inserire testo in variabili e altre semplici operazioni
// il C/C++ pare un linguaggio in cui nel tempo si sono accumulati vari modi per fare le stesse cose


// carrellata di alcuni notabili metodi per scrivere in C/C++ direttamente testo a video
void scriviTesto() {
	/* "virgolette" e 'apici' non sono equivalenti in in Cuesto linCuaCCio
	 * "string literal" sono le sequenze di caratteri racchiusi tra virgolette
	 * 'a' pici contengono un singolo carattere anche escapato '\n'
	 */ 
	// cout
	cout << 'a'  << endl;	// 'a'
	cout << 61  << endl;	// '61'
	cout << 0x61  << endl;	// esadecimale scrive '97' cioè l'int di 'a'
	//cout << 'è'  << endl;	// avviso che è un carattere multi-character, e poi scrive '50088'
	cout << '\x61' << '\x82' << endl;	// ok char esadecimali 'aé'	invece Lubuntu 'a�'

	cout << "a" << endl; 	// ok scrive 'a'
	cout << "\x61" << endl;	// ok esadecimale escapato scrive 'a'

	cout << "è" << endl;	// no scrive '├¿'
				// INVECE ok in Lubuntu 'è' l'unico tra questi metodi che scrive un carattere 128+
	cout << static_cast<char>(138) << endl;	// ok scrive 'è'	invece 
						
	//cout << static_cast<int>('è');	// avviso che è un carattere multi-character, e poi scrive '50088'
	//cout << static_cast<unsigned int>('è');	// idem
	//cout << char 138;	// errori di compila
	cout << "\x8a" << endl;	// ok scrive 'è'  invece in Lubuntu '�'
	//cout << "\x686578" << endl;		// avviso giallo sequenza scapata hex fuori limiti
	cout << "\x85\x8A\x8d" << endl;		// ok scrive sequenza scapata hex 'àèì'
	
	//	cout << "testo " << 123 << txtstr;
	cout << endl;

	//  putchar scrive in output (stdout) char o int
	//  putchar non ha la sintassi c++ con i <<
	putchar(20);	// scrive ¶
	//putchar('¶');	// avviso di char multi-carattere.  scrive 'Â'
	putchar(10);	// inserisce un acapo
	putchar('a');	// ok
	puts ("cazzo scrive questo testo a video");	// puts aggiunge in automatico un \n alla fine
}


// collezione dei principali metodi per stoccare i caratteri in stringhe e ricavarne la dimensione ecc.
void testoInStringhe() {
	/* puntatori (char*), c-string (char[]) e string attingono tutti alle string literal (se ho ben comprì)
	 * ma le trattano in modi diversi
	 * una string literal solitamente viene salvata in memoria di sola lettura
	 * un puntatore char* potrebbe modificarla direttamente ma è illegale e porta a risultati indefiniti
	 * la c-string è una copia (?) della string literal in un array di char
	 * string ... bho
	 */
	
	int carint;	// in un numero intero ci sta il numero ASCII di un carattere come 97 'a'
	carint = 97;
	cout << "int\t" << carint << endl;
	if ( carint == 'a' ) {	// dimostra che il l'int è uguale al carattere 'a'
		char car(carint);
		cout << "\t" << car << endl;
	}
	cout << endl;

	// singolo char
	//char carattere = "a";	// conversione invalida da const char*  char
	char carat = 'a';	// ok
	//static const char EOT(0x04); ??


	//char carattere = 'à';	// avviso di multi-carattere, non viene salvato ok
	cout << "char	" << carat << endl;
	//cout << "	strlen(carat)	" << strlen(carat) << endl;	// conversione invalida da char a const char
	cout << "	sizeof(char)	" << sizeof(carat) << " byte" << endl;	// numero dei bytes, un char occupa un byte
	cout << "	sizeof(&char)	" << sizeof(&carat) << " byte" << endl;	// 4 bytes del puntatore al primo carattere
									// sizeof ritorna un numero di tipo 'size_t' (unsigned integral type)

	// puntatore a un carattere
	//char * punto = 'a';	// conversione invalida da char a char*
	//char * punto;	// pointer 'punto' non inizializzato, cioè non punta a nessuno spazio in memoria, compare avviso giallo
	char * punto = 0;	// ok pointer 'punto' è inizializzato
/*	punto[0] = 'a';*/		// ok? ?????????????????????	errore SIGSEGV che ??? ma se prima funzionava!
	cout << "	sizeof(char*)	" << sizeof(punto) << " byte" << endl;
	cout << endl;


	/* array di caratteri
	 * anche detta c-string ovvero stringa in stile C, distinta dalla string del C++ (vedi poi)
	 * è definita nell'header <cstring>
	 * in pratica poi si usa il puntatore al suo primo carattere, ad esempio in cin.getline(ciccio,10)
	 * 'ciccio' non rappresenta tutto l'array, ma solo il puntatore (char*) al 1° carattere dell'array
	 */
	//char arrai[];	//	no. dimensione sconosciuta
	//char arrai[6];	// ok array di 6 posti non inizializzato quindi accupati da spazzatura
	//char arrai[] = "";	// ok
	//char arrai[] = {};	// ok
	char arrai[] = "abcde";	// ok
	//char arrai[] = { 'a','b','c','d','e',0 };	// equivalente. NUL alla fine, altrimenti spesso aggiunge caratteri a cacchio
	//char arrai[6] = { 'a','b','c','d','e',0 };	// ok. necessario specificare il NUL
	//char arrai[1] = "a";	// no. stringa troppo lunga non c'è spazio per il carattere null
	//char arrai[2] = "a";	// ok: 'a' + NUL
	//char arrai[2] = 'a';	// no gli apici da soli non vanno
	//char arrai[2147483647]; // ok dimensione massima di un array sembra questa 2³¹ bytes (che dovrebbero essere 2 gigaByte)
	                         // anche se poi compilatore lamenta che la funzione richiede troppa memoria
	//char arrai[256] = "abcde";	// ok. spazio allocato di 256 bytes anche se occupato da soli 5
	//char arrai[6] = {0}; 	// ok crea un array di 6 caratteri nulli
	//char arrai[6] = {'\0'}; 	// idem equivalente
	cout << "array	" << arrai << endl;
	cout << "	strlen(array)	" << strlen(arrai) << " caratteri" << endl;	// necessita di <cstring>
	cout << "	sizeof(array)	" << sizeof(arrai) << " bytes" << endl;	// numero di bytes
	cout << "	sizeof(&array)	" << sizeof(&arrai) << " bytes" << endl;	// 4 bytes del puntatore al primo carattere
	//cout << arrai.size();	// errore. char[] non è una classe quindi non ha funzioni membro (se ho ben capito)
	cout << "	decimali	";
	for(unsigned int i = 0; i <= strlen(arrai); ++i)
		cout << static_cast<unsigned int>(arrai[i]) << " ";
	cout << endl;
	arrai[0] = 'A';	// ok sostituisce il primo carattere
	arrai[5] = 'f';	// ok rimpiazza il \0 finale
	arrai[6] = 0;  	// NON aggiunge un altro elemento all'array
	// non so come modificare la lunghezza di un array !!!!!!	arrai.resize(7)	non va
	cout << "	modificata	" << arrai << endl;
	cout << endl;


	/* puntatore a una "string literal"
	 * la variabile 'pointer' contine l'INDIRIZZO di un singolo carattere che è il primo di un sequenza terminata da NUL
	 * assomiglia alla c-string ma la gran differenza è che la stringa è salvata in memoria di sola lettura
	 * cercare di modificarla è illegale e porta a risultati indefiniti
	 * 
	 * Dichiarazione: */
	//char * pointer;	// ok dichiara un puntatore con l'indirizzo di qualcuno e lo tratta come 'const char'
					// senza inizializzarlo, ovvero contiene spazzatura casuale
	//int * pointer;	// no. così il byte puntato è definito 'int' ma le funzioni seguenti si aspettano un 'const char'
	//char * pointer = new char;	// ok. dichiara e inizializza indirizzo a c-string di un carattere che è sempre il 12 '♀' (non so quanto voluto) + NUL finale
	//char * pointer = new char[6];	// ok idem inizializza una c-string col solo carattere 12'♀' + NUL finale
	char * pointer = new char();	// ok. inizializza il char con un carattere NUL, pare il metodo più "corretto"
				// pare che 'new' alloca un nuovo spazio in memoria, a differenza di una string literal che è di sola lettura
	//char * pointer = 0;	// no. in teoria equivalente al precedente, compilazione ok ma poi programma inchioda
	//char * pointer = '\0';	// idem programma inchioda, strano, non capisco
	//char * pointer = new char(97);	// ok dichiara un puntatore con l'indirizzo di un carattere inizializzato come 'a'
	//char * pointer = 'a';	// errore sintassi: non valida conversione da char a char*
	//char * pointer = "a"; 	// avviso conversione deprecata da costante string a char*
	//char *pointer = "abcde";	// ovunque lo suggeriscono ok, ma avvisa conversione deprecata da stringa a char
	//cout <<"ok\n"; 
	cout << "pointer	" << pointer << endl;
	cout << "	strlen(pointer)	" << strlen(pointer) << " caratteri" << endl;
	cout << "	sizeof(pointer)	" << sizeof(pointer) << " bytes" << endl;	// 4 bytes
	cout << "	char_traits<char>::length(pointer) " << char_traits<char>::length(pointer) << " caratteri" << endl;
	//cout << length(pointer); 	// no. length è funzione membro di char_traits
	cout << "	decimali	";
	for(size_t i=0; i <= strlen(pointer); ++i)
		cout << static_cast<unsigned int>(pointer[i]) << " "; cout<<endl;
	cout << "	&pointer	" << &pointer << " indirizzo di pointer" <<endl;
	cout << "	*pointer	" << *pointer << "	char a cui punta" << endl;
	cout << "	(int)pointer	" << (int)pointer << " decimali, indirizzo a cui punta" << endl;	// indirizzo a cui punta pointer
	/* 
	 * Inizializzazione (o modifica della stringa pointer già inizializzato) */
	//pointer = 'A';	// errore di sintassi: *pointer contiene un INDIRIZZO non un carattere
	//pointer = "abcde";	// avviso: conversione deprecata da string constant a char*
	pointer[0] = 'A';	// ok ma solo se è stato già inizializzato con uno dei 'new char...', altrimenti programma inchioda
	//*pointer = 'A';	// ok assegna 'A' all'indirizzo contenuto in *pointer
	//*pointer = "ABCDE";	// non valida conversione da const char* a char
	//pointer[0] = "ABCDE";	// idem non valido
		// non so come assegnare una STRINGA all'indirizzo del puntatore !!
	cout << "	modificato	" << pointer <<endl;
	cout << endl;


	// puntatore COSTANTE a una c-string
	// ma COSA è constante? il nome del puntatore, il suo indirizzo, l'indirizzo che contiene, l'indirizzo a cui punta, o ciò che ivi si trova???
	//const char * constPtr;	// ok lo dichiara senza inizializzarlo quindi contiene caratteri casuali in numero casuale (fino al primo NUL)
	//const char * constPtr = "a";	// ok puntatore a una stringa
	const char * constPtr = "abcde";	// idem ok uguale
	//const char * constPtr = { 'a','b','c', 0 };	// errore sintassi: scalar object richiede initializer
	cout << "const pointer	" << constPtr << endl;
	cout << "	strlen(cnt pointer)	" << strlen(constPtr) << " caratteri" << endl;
	cout << "	sizeof(cnt pointer)	" << sizeof(constPtr) << " bytes" << endl;	// 4 bytes
	cout << "	decimali	";
	for(size_t i=0; i <= strlen(constPtr); ++i)
		cout << static_cast<unsigned int>(constPtr[i]) << " ";
	cout << endl << endl;
	// modifica
	//constPtr[0] = 'A';	// non si può assegnare all'indirizzo *constPtr che è di sola lettura
	//cout << "	modificato	" << constPtr <<endl; cout << endl;

	
	// std::string
	//std::string stringa; // ok definisce una stringa vuota il cui primo carattere è NUL \0
	//stringa = 'a';	// ok stringa di un carattere
	//stringa = "abcde";	// ok inizia la stringa con 5 caratteri
	//stringa = {'a'};	// avviso iniziatore esteso di lista solo in c++11
	//stringa = {"a"};	// idem
	string stringa ("abcde");
	//string stringa = "abcde";	// ok definisce e inizia insieme
	//string stringa = "abcde\0";	// ok uguale, il '\0' finale verrebbe comunque aggiunto in automatico
	//string stringa = 0;	// compila ma poi programma crash
	//string stringa = "\0";	// sembra ok, inizializza una stringa di 0 caratteri
	cout << "string	" << stringa << endl;
	cout << "	string.size()	" << stringa.size() << " caratteri" << endl;
	cout << "	string.length()	" << stringa.length() << " caratteri" << endl; // sinonimo di stringa.size()
	cout << "	sizeof(string)	" << sizeof(stringa) << " bytes" << endl ;	// 4 bytes è il puntatore al primo carattere, non la stringa
	//cout << "strlen(stringa)	" << strlen(stringa) << endl ;	// no, lunghezza di un C string, ma qui non compila
	cout << "	decimali	" ;
	for ( size_t i=0; i<=stringa.size(); i++ )
		cout << static_cast<unsigned int>(stringa[i]) << " " ;
	cout << endl;
	// sostituire i caratteri nella stringa
	//stringa[0] = 0;	// in qualche modo annulla un carattere ma con segnali di errore
	stringa[0] = '\0'; // ok meglio annulla il primo carattere 
					  // ma non basta per scorciare la stringa la cui lunghezza è gestita da ???
	//	//stringa[0] = "A";	// conversione invalida da const char* a char
	stringa[0] = 'A';	// ok modifica il primo carattere
	stringa.resize (stringa.size()+1,'f');	// ok modifica la lunghezza di una stringa, secondo parametro è il riempimento in aumento
	//stringa[6] = 'g';	// lo aggiunge in coda ma string non sa di essere aumentata di un carattere quindi poi cout non lo mostra
	//stringa[7] = 0;  	// necessario per terminare la stringa ma non basta per far comparire 'g' aggiunto
	stringa.resize(7);	// aumenta lunghezza ma cancella il carattere 'g' appena aggiunto
	stringa[6] = 'g';	// ok è aggiunto alla string
	cout << "	modificata	" << stringa << endl;
	cout << "	string.size()	" << stringa.size() << " caratteri" << endl;
	//string corta = stringa(2);	// no. speravo per accorciarla, forse esiste qualcosa come copystr() ma non so
	cout << endl;


	// C string non ho capito bene cosa sia
	// necessita libreria <cstring>
	char szInput[256] = "abcde";
	cout << "The sentence entered is characters long.\n" << (unsigned)strlen(szInput);


	// wide char
	wchar_t wtext[] = L"abcde" ;
	cout << "wtext           : " << wtext << endl;
	cout << "wtext	 : UNABLE TO CONVERT NATIVELY." << endl;
	cout << L"wtext          : " << wtext << endl;
	cout << "sizeof(wtext)   : " << sizeof(wtext) << endl;
	cout << "wcslen(wtext)   : " << wcslen(wtext) << endl;
	cout << "wtext(binary)   :" ;
	for(size_t i = 0, iMax = wcslen(wtext); i < iMax; ++i)
      cout << " " << static_cast<unsigned int>(static_cast<unsigned short>(wtext[i])) ;
	cout << endl;
}


// vari modi per estrarre testo da input utente
void prendeTestoInserito() {

	char carat = 0;     	// un carattere da adoprare
	string strng = "";    	// una stringa da riempire
	unsigned int ind = 0;	// un intero da usare ad esempio come contatore per i while (azzerandolo prima)
							// unsigned per stoccarvici strlen

	//goto cingetlinearray;	// ok ma non si può dichiarare nulla tra goto e la label
	
	cout<< "cin >> int 	                                                     	\n\
   estrae da input buffer solo i numeri 0-9 convertendoli in int           	\n\
   spazi, tabulazioni e acapi iniziali e finali sono estratti e ignorati   	\n\
   altri caratteri non 0-9 interrompono estrazione e RIMANGONO in buffer  	\n";
	cin >> ind;
	cout << " int\t" << ind <<endl;
	cout << " resto\t'";
	ind=0;
	do { cin.get(carat);
		cout << svela(carat,1);
		ind++;
	} while ( carat!='\n' && carat!=0 );
	cout << "'\n";
	cout << '\t' << ind << " caratteri" <<endl;
	cout << endl;


	// cin >> char
	cout<< "cin >> char 	                                                 	\n\
   ferma il programma in attesa input, utente scrive caratteri + Invio    		\n\
   cin estrae solo il primo carattere inserito dall'utente e gli altri incluso \\n finale rimangono in buffer                    	\n\
   nel caso trova in input evantuali spazi, tabulazioni e acapi li ESTRAE dall'input (eliminandoli) ma poi li scarta (ignorandoli)	\n\
   finché trova un carattere 'valido', se non lo trova rimane in atesa input            	\n\
   quindi se in buffer è avanzato un '\\n', lo estrae lo ignora e rimane in attesa input 	\n";
	cin >> carat;
	cout << " char	'"<< svela(carat,1) <<"'"<<endl;	// ok scrive primo carattere inserito (ignorando spaz tab acap)
 	cout << " scarto	'";
	ind=0;
	/* tentativo di estrazione scarti con cin>>char in un while
	 * inefficace per ripulire buffer ma utile per capire funzionamento di cin>>char
	do { cin >> carat;	// ok, ma estratti i caratteri avanzati rimane in attesa input
		//if(!(cin>>carat)) break;	// inutile, estratto ultimo carattere si ferma in attesa input
		cout << svela(carat,1);
		ind++;
	} //while (carat!='\n');	// non funziona perché estrae l'acapo ma non lo considera un carattere
	while (!cin.eof());	// ok Ctrd+C esce dal while ma poi c'è da gestire cin in stato "fine dela mondo", forse con cin.clear()
	*/
	// estrazione scarti con cin.get(char). ok?
	do { cin.get(carat);
		cout << svela(carat,1);
		ind++;
	} while (carat!='\n');
	cout << "' " << ind << " char" << endl<<endl;


	// cin >> char[]
	cout<< "cin >> char[] 	\n\
   cin pretende almeno un carattere che non sia spazio tabulazione o invio	\n\
   ignora spazi e tab iniziali ed estrae solo la prima parola, cioè fino al primo spazio tab o acapo LF '\\n' 	\n\
   e la mette in un array di char (che non è una c-string!)              	\n\
   i restanti caratteri inclusi spazi, tab e anche l'acapo sono tutti lasciati in input buffer  \n\
   estrae caratteri 127+ 													\n";
	//cin >> char arraic[]; 	// non si può iniziare dopo cin>>
	char arraic[] = ""; 	// ok
	cin >> arraic;      	// funziona ok
	cout << "char[]	'" << arraic << "'" << endl;
	cout << "\t" << strlen(arraic) << " caratteri" << endl;
	// recupero scarto
	cout << "scarto	'";
	do { carat=cin.get();	// ok cattura anche il carattere acapo
		cout << svela(carat);
		ind++;
	} while (carat!='\n');
	cout << "'" << endl;
	cout << "\t" << ind << " caratteri" << endl<<endl;

	
	// cin >> string
// da solo funziona benissimo, 
// ma se prima c'è cin>>char[] anche un paio di caratteri senza accenti produce errore SISEGV e programma termina
//cin.clear();	cin.ignore(INT_MAX,'\n');	// non risolvono, occorre ricerca web di cos'è SISEGV
	cout<< "cin >> string                                                        	\n\
   come sopra pretende almeno un carattere che non sia spazio tabulazione o invio 	\n\
   ignora spazi e tab iniziali ed estrae solo la prima parola                   	\n\
   cioè fino al primo spazio, tabulazione o acapo                                 	\n\
   dal quale limite incluso rimane tutto in buffer.                              	\n\
   estrae egregiamente anche caratteri accentati 127+                           	\n";
	cin >> strng;
	cout << "string	'" << strng << "'" << endl;
	cout << "\t" << strng.size() << " caratteri" << endl;	
	// recupero scarto anche del carattere delimite \n
	cout << "scarto	'";
	ind=0;
	do { carat = cin.get();
		cout << svela(carat);
		ind++;
	} while (carat!='\n');
	cout << "'" << endl;
	cout << "\t" << ind << " caratteri" << endl<<endl;
	

	// getchar()
	cout<< "getchar() 	\n\
   estrae il primo carattere che trova nello standard input (stdin) e lo elimina dal buffer	\n\
   a differenza di cin>>string ammette anche un solo acapo, spazio o tabulazione. 	\n\
   il carattere estratto viene immagazzinato come numero int o carattere char	\n\
   estrae egregiamente i caratteri oltre 128 	\n";
   // nella libreria <stdio.h>  e funzione di C più che C++       
	int i = 0;	// ok il carattere viene poi mostrato con il corrispondente numero intero
	//getchar(); 	// se c'è qualcosa in input buffer estrae il primo carattere eliminandolo (anche un solo '\n') e passa via
					// altrimenti si ferma in attesa di input
	//if (getchar());	// idem estrae se c'è almeno un carattere anche \n, altrimenti ferma in attesa input
	//cout << getchar();	// scrive l'intero del carattere che ha appena estratto. anche qui aspetta input
	
	// prima prende un char, poi nel do-while gli eventuali altri avanzati
	carat = i = getchar();
	cout << "char int" << endl;
	cout << setw(3);
	cout << svela(carat,1) <<"  "<< i << endl;
	//while ( (carat = i = getchar()) ) { 	// attende invio poi estrae un carattere alla volta dall'input ma NON esce dal loop
	//while ( (carat = getchar()) && c != '\n' ) {	// estrae tutto e si interrompe quando trova \n, che però non viene mostrato
												// se è vuoto ATTENDE input, quindi inadatto per ripulire il buffer
	if ( carat!='\n' ) {	// se non ha già esaurito l'estrazione linea, cioè se ci sono eventuali scarti, altrimenti getchar() si ferma in attesa input
		cout << "scarto" << endl;
		do { carat = i = getchar();
			cout << setw(3);
			//if((carat=getchar())=='\n')	// inutile, si ferma comunque in attesa input
			cout << svela(carat,1);	// acapo compare sempre alla fine di ogni invio, NUL non compare mai
			cout <<"  "<< i;
			cout << endl;
		} while ( carat != '\n' );	// do-while è meglio di while perché anche se c'è un solo \n lo mostra
	}
	//cout << "alla fine int "<<i <<"  char "<<carat << endl;	// alla fine int e char hanno l'ultimo valore estratto cioè 10 '\n'
	cout << endl;

	//get(s, count, widen('\n'))
	
	

	// cin.get()
	cout << 
	"cin.get(char) \nchar = cin.get()	\n\
   senza altri parametri prende un solo carattere incluso acapo, spazio o tabulazione\n\
   gli altri se ce ne sono rimangono nello scarto \n";
	//cin.get(); // così da solo si ferma in attesa input, estrae il primo carattere battuto, lo mette forse da qualche parte ma non ho idea dove
				// i restanti caratteri rimangono nell'input buffer a disposizione dell'eventuale prossimo estrattore di input
	cin.get(carat);	// ok. se poi il char non è usato niente avviso giallo
	//carat = cin.get();   // ok equivalente ma se poi non è usato avviso giallo
	//cin.get(ind);    	// errore sintassi: non può stoccare input in un int ma solo in char
	cout << "char	'" << svela(carat) << "'" << endl;
	// mostra i caratteri avanzati
	if(carat!='\n') {	// utente prima dell'acapo ha inserito anche altri caratteri 
		cout << "scarto	'";
		do { carat=cin.get();	// altrimenti con input buffer vuoto qui si fermerebbe in attesa input
			cout << svela(carat);
			ind++;
		} while (carat!='\n');
		cout << "'" << endl;
		cout << "\t" << ind << " char" << endl;
	}
	cout <<endl;
	

	// istream& get ( char* s, streamsize n, char delim )
	cout << 
	"cin.get(char[],int)\ncin.get(char[],10,'\\n') \n\
   mette i caratteri inclusi tutti gli spazi nell'array char[10] terminati da NUL (\\0)\n\
   il carattere limite default è '\\n' \n\
   che non viene inserito in arrai ed è invece lasciato in input stream 'cin' \n\
   un solo invio inserisce in array stringa vuota (NUL) e \\n rimane in buffer \n\
   caratteri oltre a dimensione array (in questo caso 10) rimangono in input buffer	\n";
	char arrai[10]; 	// qui c'è spazio solo per 9 caratteri + il NUL
	//cin.get(arrai);	// non c'è funzione corrispondente con un solo argomento per un array[1+]
	cin.get(arrai,10);	// ok. sottointeso terzo argomento '\n'
	//cin.get(arrai,10,' ');	// ok tronca prima dello spazio. 
							// Ma se nell'input non c'è uno spazio l'invio mica fa proseguire!
							// aspetta finché non c'è almeno uno spazio e poi invio
	//getline(cin,arrai);		// errori compilazione: getline non funziona con un char array
	//cout << arrai;	// ok. dopo un solo invio 'arrai' contiene una stringa vuota, o meglio un solo NUL
	//cout << svela(arrai[0]);	// ok. mostra il NUL di una stringa vuota
	cout << "char[]	'" << arrai << svela(arrai[strlen(arrai)]) << "'" << endl;
	cout << '\t' << cin.gcount()+1 << " caratteri" <<endl;	// ok conta i caratteri estratti con cin.get, cin.getline.. (unformatted)
	// recupero scarto
	//if(cin.get(arrai,10)) cout << arrai;	// inoperoso
	//cout << getline(cin,strng);  	// recepisce cin ovvero svuota il buffer, ma scrive a video '0x48...'
	//if(getline(cin,strng)) cout << strng; 	// estrae ed elimina il \n e scrive una stringa vuota di nessun carattere
	cout << "scarto	'";
	cin.clear();	// risistema input buffer così cin.get() seguente riesce a estrarre \n avanzato da singolo Invio
	ind=0;
	do { //cout << svela(cin.get(carat));	// piacerebbe tutto in uno, ma non valida conversione da istream<char> a char
		cin.get(carat);     	// cattura il '\n' avanzato sopra e lo rivela al pubblico
		cout << svela(carat);
		ind++;
	} while (carat!='\n');	// ok lo mostra.  c'ho il dubbio se il while prende il \n anche se non è il primo ... bho
	cout << "'" << endl;
	cout << "\t" << ind << " char" << endl;
	cout << endl;

	
	/* cin.getline( char[], 10, '\n' )
	 * prototipo: istream& getline(char *buffer, int length, char terminal_char);
	 */ //cingetlinearray:	// label del goto
	cout << 
	"cin.getline( char*, int, char )\n"
	"cin.getline( array, 10 )\n\
   estrae input e lo mette in un array di caratteri char (c-string)\n\
   char* è il puntatore al primo carattere di un array che ha dimensione di 10 byte (caratteri)\n\
   estrae anche tutti gli spazi iniziali e finali inseriti dall'utente\n\
   se non specificato il limite è LF '\\n'\n\
   unica differenza dal precedente è che scarta il carattere limite dall'input stream\n";
	//cin.getline();	// no errore sintassi
	//cin.getline(carat);	// non funziona con singolo char
	//cin.getline(carat,1);	// non valida conversione da char a istream<char>
	//cin.getline(char str[10],10);	// no str[] deve essere dichiarato prima
	char str[10];	// ok 10 posti di cui l'ultimo riservato a NUL quindi 9 caratteri
	//char * str = new char();	// OK uguale! dichiare il puntatore che contiene l'indirizzo di un carattere (inizializzato con NUL) che può essere il primo di una c-string
	cin.getline(str,10);  	// ok funziona, prende anche caratteri 128+ che occupano anche loro 1 posto (stanno in un byte, diamine)
							// prende massimo 9 caratteri, se sono di più dal 10 vengono estratti e scartati e cin messo in stato EOF quindi disastro coi seguenti cin
	//cin.getline(str,10,'\n');	// ok uguale
	//cout << str;	// ok scrive la stringa ma ovviamente non il caratteri nullo
	cout << "char[]\t'";
	for ( ind=0; ind<strlen(str)+1; ind++ ) 
		cout << svela(str[ind]); // ok anche carattere nullo finale \0
	cout <<"'"<< endl;
	cout << "\t" << strlen(str)+1 << " caratteri" << endl<<endl;


	// getline(cin,string)
	// std::getline( istream, std::string&, char delim )
cout << "getline(cin,string,'\\n') \n\
   unica differenza dal precedente è che opera su std::string anziché su char array       	\n\
   estrae caratteri da input stream 'cin' e li mette in 'string' fino al carattere limite 	\n\
   se non specificato il carattere limite è '\\n'                                       	\n\
   il carattere limite viene estratto e scartato, quindi poi NON è più presente in 'cin' 	\n";
	getline ( cin, strng ) ;	// forse ogni tanto sembra produrre errore SIGSEGV, magari vuole un cin.clear()
	//cout << strng;	// ok modo standard di scrivere string
	cout << "string	'";
	for ( ind=0; ind<strng.size()+1; ind++ ) 
		cout << svela(strng[ind]);	// ok anche carattere nullo finale \0
	cout << "'" << endl;
	cout << "\t" << strng.size()+1 << " caratteri" << endl;
/**/	
		getline ( cin, strng ) ;
		cout <<"\naltra "<< strng;
	//CString cstr; // non dichiarato in questo scopo
}

// metodi ulteriori per catturare testo input
void prendeTestoInseritoExra() {
	unsigned int i;	// contatore
	
	cout << "cin.get() estrae un carattere alla volta e lo infila direttamente in una string 	\n"
			"se inserito un solo acapo LF diventa l'unico carattere della stringa, altrimenti acapo è eliminato \n"
			"gestisce bene anche caratteri 127+            	\n"
			"exit per smettere 	\n";
	string streng;	// una stringa vuota
	while ( streng!="exit" ) {	// finché non scrive exit
		//for (i=0; i<streng.size(); i++) streng[i]='\0';	// brutale per annullarla
		streng.clear();	// ok svuota string a zero caratteri
		i=0;
		do { streng.resize(i+1);	// fa posto al carattere che arriva
			streng[i] = cin.get();	// ok estrae uno alla volta tutti i caratteri battuti incluso LF
			//cout << svela(streng[i]);	// ok mostra anche ultimo \n
			i++;
		} while (streng[i-1]!='\n');
		if (i>1) streng.resize(i-1);	// ok elimina l'ultimo acapo a meno che sia l'unico carattere della string
		if(i==1) streng = svela(streng[0],2);	// mostra carattere acapo invisibile
		cout << " '" << streng << "'" <<endl;
		cout << " "<< streng.size() <<" char" <<endl;
	}
	cout << endl;


	// screvere un numero 0-9 e avere int uguale 0-9
	

	// non completata
	cout << "cin.get() estrae un carattere alla volta, lo infila in un char che lo passa a una string 	\n"
			"exit per smettere 	\n";
	//char coord[5]={0}; // ok ma uso una std::string
	string strng = "1234";	// una stringa di 4 caratteri
	char car;
	while ( strng!="exit" ) {	// finché non scrive exit
		strng[0]='\0'; i=0;
		do { //strng[i] = cin.get();	// ok ma poi l'indice aumenta e mi perdo il carattere attuale
			car = cin.get();
			cout << i << " | " << svela(car) << " | ";
			if(car=='\n') strng[i] = 0;	// carattere terminazione della string
			else strng[i] = car;
			i++;
			//strng[i] = 0;
			cout  << strng << endl;
		} while (car!='\n');
		cout << "fin do " << strng << endl;
	}

}

// converte tra i diversi tipi: int char string
void conversioneCarattere() {
	// convertire un char in string
	char peppa = 'a'; 	// un semplicissimo char
	
	//string stringola = peppa;	// conversione invalida da char a const char*
	//string stringola[0] = peppa;	// output anziché 'b' scrive 0x22fef8
	//string stringola = static_cast<string>(peppa);	// non valida conversione da char a const char*
	//char arr[1];  arr[0] = peppa; //	quasi ok, ma senza il NUL finale spesso aggiunge fuffa in coda
	//string stringola(peppa); 	// non valida conversione da char a const char*
	//string stringola(peppa,0);   // non segnala errori ma produce una stringa inconsistente \0\0
	//string stringola({peppa,0});   // no molti avvisi gialli
	//string stringola{peppa,0};   // no errori vari
	//string stringola([peppa,0]);  	// no gragnuola di errori
	//string stringola(char arr[peppa,0]);  // proprio no
	//string stringola(char arr[2]={peppa,0});  // tentativo di crearla in una stringa unica ma non funziona
	
	// stranissima ma funziona, necessita <sstream>
	stringstream ss;
	ss << peppa;
	string stringola1;
	ss >> stringola1;
	cout << "char '" << peppa << "'  string \"" << stringola1 << "\"  ";
	cout << "ovvero \"" << stringola1[0] << svela(stringola1[1]) << "\"" <<endl;
	
	// la più semplice soluzione funzionanante che ho trovato
	char arr[2] = { peppa, 0 };  //	necessario il NUL finale per terminare correttamente la stringa
	string stringola(arr);      	
	cout << "char '" << peppa << "'   string \"" << stringola << "\"  ";
	cout << "composta da " << stringola[0] << svela(stringola[1]) << endl;
	cout << endl;
	

	//---------------------------
	// convertire un int in testo: int 3 diventa char '3'	NON SO COME FARE
	int ineto = 3;	
	peppa = ineto;	// diventa il char corrispondente a int 3 cioè '♥'
	cout << "char " << peppa << endl;
	peppa = static_cast<char>(ineto);	// idem diventa ♥
	cout << "char " << peppa << endl;
	cout << endl;


	// da un char ricavare il corrispondente int ASCII
	cout << static_cast<int>('a') << endl;      	// ok scrive '97'
	cout << static_cast<unsigned int>('a') << endl;	// idem scrive '97'

	
	// da string[char] a corrispondente int ASCII anche per i 128+
	string strunga("1"); // stringa di 1 carattere
	
	strunga[0] = 97;	// ovvero 'a'
	cout << static_cast<int>(strunga[0]) << endl;     	// ok in output a video scrive '97'
	int charint = strunga[0];       // ok. un char in un int diventa il corrispondente numero
		cout << charint << endl;	// scrive '97'
	cout << 0 + strunga[0] << endl; 	// ok scrive '97'. in un contesto di numeri è trattato come numero
	
	strunga[0] = 138;	// ovvero 'è'
	cout << static_cast<int>(strunga[0]) << endl;       	// quasi: scrive '-118'	cioè signed int
	cout << static_cast<unsigned int>(strunga[0]) << endl;	// no. scrive '4294967178'
	cout << static_cast<size_t>(strunga[0]) << endl;     	// no. scrive '4294967178'
	cout << 256+static_cast<int>(strunga[0]) << endl;    	// ok! scrive '138'
	charint = strunga[0];   	// ok
	cout << charint << endl; 	// scrive '-118' come static_cast


	cout << "indirizzo esadecimale → int decimale\n";
	int * puntatore;
	// questo metodo con le parentesi prima si chiama cast
	cout << &puntatore << " → " << (int)&puntatore <<endl;	// 0x22fe08 → 2293256
	cout <<endl;
	
	
	// da HINSTANCE a LPCSTR
	// ovvero da pointer void*? a const char*
	// il tipo HINSTANCE dovrebbe contenere un void qualcosa...
	//void * handle; 
	//const char * visibile = "eccomi qui";
	
}

