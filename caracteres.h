#include<iostream>
#include<conio.h>
using namespace std;
char caracter;
/* eliminar un caracter de un string*/
void delchar(string& word, char character){
	string new_word;
	for(int i = 0; i < word.length(); i++){
		if(word[i] != character && word[i] != toupper(character)){
			new_word+=word[i];
		}
	}
	word=new_word;
}

void takeDNI(string& DNI){
	char caracter;
	DNI="";
	do{
		caracter=getch();
		if(caracter!=8){
			if(caracter>47&&caracter<58){
				if(DNI.length()==2||DNI.length()==6){
					cout<<".";
					DNI+=".";
				}
				DNI.push_back(caracter);
				cout<<caracter;
			} else if(caracter==13&&DNI.length()==10){
				break;
			}
		} else{
			if(DNI.length()==3||DNI.length()==7){
				cout<<"\b \b"<<"\b \b";
				DNI=DNI.substr(0, DNI.length() - 2);
			}else if(DNI.length()>0){
				DNI=DNI.substr(0, DNI.length() - 1);
				cout<<"\b \b";
			}
		}
	} while(DNI.length()<10);
}

void takeCUIL(string& cuil, string DNI){
	delchar(DNI, '.');
	do{
		caracter=getch();
		if(caracter!=8){
			if(caracter>47&&caracter<58){
				cout<<caracter;
				cuil.push_back(caracter);
				if(cuil.length()==2){
					cout<<"-"<<DNI<<"-";
					cuil=cuil+"-"+DNI+"-";
				}
			}
		} else if(cuil.length() > 0){
			if(cuil.length()==12){
				while(cuil.length()!=1){
					cout<<"\b \b";
					cuil=cuil.substr(0, cuil.length() - 1);
				}
			} else{
				cuil=cuil.substr(0, cuil.length() - 1);
				cout<<"\b \b";
			}
		}
	} while(cuil.length()<=12);
	
}

int rec_typenum(string& word){
	int detect=1;	// int
	if(word.length()>0){
		for(int i=0; i<word.length();i++){
			if(word[i]=='.'){
				if(i+4<=word.length()) detect=2;	//float
				if(i+4>word.length()) detect=3;		//double
				break;
			}
		}
	} else{
		detect=0;
	}
	return detect;
}
/* detectar si un caracter esta en un string */
bool detchar(string& word, char character){
	int detect=false;
	for(int i=0; i<word.length();i++){
		if(word[i]==character){
			detect=true;
			break;
		}
	}
	return detect;
}
/* reemplazar un caracter */
void replchar(string& word, char replaced_char, char new_char){
	for (int i = 0; i < word.length(); i++) {
		if(word[i]!=replaced_char&&word[i]!=toupper(replaced_char)){
			word[i] = word[i];
		} else if(word[i] == replaced_char){
			word[i] = new_char;
		} else if( word[i] == toupper(replaced_char) ){
			word[i] = toupper(new_char);
		}
	}
}
	/* pasar a mayuscula */
void uppstr(string& word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=toupper(word[i]);
	}
}

void uppchar(char& word){
	word=toupper(word);
}
	/* pasar a minuscula*/
void lowstr(string& word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=tolower(word[i]);
	}
}

void lowchar(char& word){
	word=tolower(word);
}

	/*
	leer sin bloquear caracteres
	*/

void take(string& word){
	word="";
	do{
		caracter=getch();
		if(caracter!=8){
			word.push_back(caracter);
			cout<<caracter;
		}else if( word.length()>0){
			cout<<"\b \b";
			word = word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

void take(string& word, int max_digits){
	word="";
	do{
		caracter=getch();
		if(caracter!=8&& (max_digits > word.length() || max_digits==0)){
			cout<<caracter;
			word.push_back(caracter);
		}else if(word.length()>0&&caracter==8){
			cout<<"\b \b";
			word = word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

void take(string& word, int max_digits, bool mayus){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && (max_digits > word.length() || max_digits==0) ){
			if(mayus){
				caracter=toupper(caracter);
				word.push_back(caracter);
				cout<<caracter;	
			} else{
				caracter=tolower(caracter);
				word.push_back(caracter);
				cout<<caracter;
			}
		} else if(word.length()>0&&caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

void take(string& word, int max_digits, bool mayus, bool space){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && ((caracter==32&&space)||caracter!=32) && (max_digits>word.length() || max_digits==0)){
			if(mayus){
				caracter=toupper(caracter);
				word.push_back(caracter);
				cout<<caracter;	
			} else{
				caracter=tolower(caracter);
				word.push_back(caracter);
				cout<<caracter;
			}
		} else if( word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

	/*
	leer solo numeros
	*/
	
template <class Number>
void takenum(Number& num, int max_digits){
	string NUM;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=48 && caracter<=57) || caracter==46){
				cout<<caracter;
				NUM.push_back(caracter);	
			}
		} else if(NUM.length()>0){
			cout<<"\b \b";
			NUM=NUM.substr(0, NUM.length() - 1);
		}
	} while( caracter!=13 && (NUM.length()<max_digits || max_digits==0));
	switch( rec_typenum(NUM) ){
		case 0: num=0;
		break;
		case 1: num=stoi(NUM);
		break;
		case 2: num=stof(NUM);
		break;
		case 3: num=stod(NUM);
		break;
	}
}

template<class Number>
void takenum(Number& num){
	string NUM;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=48 && caracter<=57) || caracter==46){
				cout<<caracter;
				NUM.push_back(caracter);	
			}
		} else{
			if( NUM.length()>0 ){
				cout<<"\b \b";
				NUM=NUM.substr(0, NUM.length() - 1);
			}
		}
	} while(caracter!=13);
	switch( rec_typenum(NUM) ){
		case 0: num=0;
		break;
		case 1: num=stoi(NUM);
		break;
		case 2: num=stof(NUM);
		break;
		case 3: num=stod(NUM);
		break;
	}
}

	/*
	leer solo letras
	*/

void takestr(string& WORD){
	if(WORD!="") WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>='a'&&caracter<='z')||(caracter>='A'&&caracter<='Z')||caracter==' '){
				cout<<caracter;
				WORD.push_back(caracter);	
			}
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while(caracter!=13 || WORD.length()==0);
}
	
void takestr(string& WORD, int max_digits){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if((WORD.length()<max_digits||max_digits==0)&&((caracter>='a'&&caracter<='z')||(caracter>='A'&&caracter<='Z')||caracter==' ')){
				cout<<caracter;
				WORD.push_back(caracter);	
			}
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while(caracter!=13 || WORD.length()==0);
}

void takestr(string& WORD, int max_digits, bool space){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if((WORD.length()<max_digits||max_digits==0)&&((caracter>='a'&&caracter<='z')||(caracter>='A'&&caracter<='Z')||(caracter==' '&&space))){
				cout<<caracter;
				WORD.push_back(caracter);	
			}
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while(caracter!=13 || WORD.length()==0);
}

void takestr(string& WORD, int max_digits, bool space, bool mayus){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if((WORD.length()<max_digits||max_digits==0)&&((caracter>='a'&&caracter<='z')||(caracter>='A'&&caracter<='Z')||(caracter==' '&&space))){
				if(mayus){
					caracter=toupper(caracter);
					word.push_back(caracter);
					cout<<caracter;	
				} else{
					caracter=tolower(caracter);
					word.push_back(caracter);
					cout<<caracter;
				}
				cout<<caracter;
				WORD.push_back(caracter);
			}
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while(caracter!=13 || WORD.length()==0);
}

	/*
	leer una palabra bloaqueando el mensaje
	*/

void takepasw(string& WORD){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			cout<<"*";
			WORD.push_back(caracter);
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while(caracter!=13);
}
	
void takepasw(string& WORD, int max_digits){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			cout<<"*";
			WORD.push_back(caracter);
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while((caracter!=13 && (WORD.length()<max_digits||max_digits==0)) || WORD.length()==0);
}

void takepasw(string& WORD, int max_digits, bool mayus){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if(mayus) caracter=toupper(caracter);
			cout<<"*";
			WORD.push_back(caracter);
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while((caracter!=13 && (WORD.length()<max_digits||max_digits==0)) || WORD.length()==0);
}

	/*
	leer solo 's' o 'n' 
	*/
	
void takesn(char& WORD){
	do{
		WORD=getch();
	} while(caracter!='s'&&caracter!='S'&&caracter!='n'&&caracter!='N');
	uppchar(WORD);
}

void takesn(string& WORD){
	WORD="";
	do{
		caracter=getch();
		if(caracter=='s'||caracter=='S'||caracter=='n'||caracter=='N'){
			WORD.push_back(toupper(caracter));
		}
	} while(WORD.length() == 0);
}

/*
leer bloqueando unos caracteres en especifico
*/

void takenot(string& word, char char1){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && caracter!=char1){
			cout<<caracter;
			word.push_back(caracter);
		}else if(word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

void takenot(string& word, char char1, char char2){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && (caracter!=char1 && caracter!=char2)){
			cout<<caracter;
			word.push_back(caracter);
		}else if(word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

void takenot(string& word, char char1, char char2, char char3){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && (caracter!=char1 && caracter!=char2 && caracter!=char3)){
			cout<<caracter;
			word.push_back(caracter);
		}else if(word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}
