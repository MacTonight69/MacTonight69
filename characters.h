#include<iostream>
#include<conio.h>
using namespace std;
char caracter;

/* delete a caracter of a string var*/

void delchar(string& word, char character){
	string new_word;
	for(int i = 0; i < word.length(); i++){
		if(word[i] != character && word[i] != toupper(character)){
			new_word+=word[i];
		}
	}
	word=new_word;
}
	
int rec_typenum(string& word){
	int detect=1;	// int
	while(word[0]=='0'){
		for(int i=0; i<word.length(); i++){
			if(i+1!=word.length()){
				word[i]=word[i+1];
			} else{
				word[i]=' ';
			}
		}
	}
	if(word.length()>0){
		for(int i=0; i<word.length();i++){
			if(word[i]=='.'){
				if(i+4<=word.length()) detect=2;	//float
				if(i+4>word.length()) detect=3;		//double
				break;
			}
		}
	} else{
		detect=0; // it's void
	}
	return detect;
}

	/* detect a character in a string var*/

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

	/* replace a character */

void repchar(string& word, char replaced_char, char new_char){
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
	/* mayus */
void uppstr(string& word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=toupper(word[i]);
	}
}

void uppchar(char& word){
	word=toupper(word);
}
	/* pasar a minuscula */
void lowstr(string& word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=tolower(word[i]);
	}
}

void lowchar(char& word){
	word=tolower(word);
}

	/*
		read characters
	*/

void takechar(char& CT){	//take a character
	CT=getch();
}

char takechar(){		//take and return a character
	return getch();
}

void takeyn(char& WORD){	//read only 'Y' (yes) or 'N' (no) 
	do{
		WORD=getch();
	} while(toupper(WORD)!='Y'||toupper(WORD)!='N');
	uppchar(WORD);
}

char takeyn(){	//read and return 'Y' or 'N'
	do{
		caracter=getch();
	} while(toupper(caracter)!='Y'||toupper(caracter)!='N');
	return toupper(caracter);
}

void takeonly(char& ct, char ct1, char ct2){	//read only 2 specifics characters
	do{
		ct=toupper(getch());
	} while( ct != ct1 && ct != ct2);
}

char takeonly(char ct1, char ct2){	//read & return 2 specifics character
	do{
		caracter=toupper(getch());
	} while( caracter != ct1 && caracter != ct2);
	return caracter;
}

	/*
	read string var without limit characters
	*/
	
void take(string& word){
	word="";
	do{
		caracter=getche();
		if(caracter!=8){
			word.push_back(caracter);
		}else if( word.length()>0){
			cout<<" \b \b";
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
			if(mayus) caracter=toupper(caracter);
			else caracter=tolower(caracter);
			word.push_back(caracter);
			putch(caracter);
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
			if(mayus) caracter=toupper(caracter);
			else caracter=tolower(caracter);
			word.push_back(caracter);
			putch(caracter);
		} else if( word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}

	/*
	read only numbers
	*/
	
template <class Number>
void takenum(Number& num, int max_digits){
	string NUM;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=48 && caracter<=57) || caracter==46){
				putch(caracter);
				NUM.push_back(caracter);	
			}
		} else if(NUM.length()>0){
			cout<<"\b \b";
			NUM=NUM.substr(0, NUM.length() - 1);
		}
	} while( caracter!=13 && (NUM.length()<max_digits || max_digits==0));
	
	if(NUM=="0") num=0;
	else{
		switch( rec_typenum(NUM) ){
			case 1: num=stoi(NUM);break;
			case 2: num=stof(NUM);break;
			case 3: num=stod(NUM);break;
		}
	}
}

template<class Number>
void takenum(Number& num){
	string NUM;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=48 && caracter<=57) || caracter==46){
				putch(caracter);
				NUM.push_back(caracter);
			}
		} else{
			if( NUM.length()>0 ){
				cout<<"\b \b";
				NUM=NUM.substr(0, NUM.length() - 1);
			}
		}
	} while(caracter!=13);
	if(NUM=="0") num=0;
	else{
		switch( rec_typenum(NUM) ){
			case 1: num=stoi(NUM);break;
			case 2: num=stof(NUM);break;
			case 3: num=stod(NUM);break;
		}
	}
	
}

	/*
	read only letters and spaces
	*/

void takestr(string& WORD){
	if(WORD!="") WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>='a'&&caracter<='z')||(caracter>='A'&&caracter<='Z')||caracter==' '){
				putch(caracter);
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
				putch(caracter);
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
				putch(caracter);
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
				if(mayus) caracter=toupper(caracter);
				else caracter=tolower(caracter);
				putch(caracter);
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
	read a password
	*/

void takepasw(string& WORD){
	WORD="";
	do{
		caracter=getch();
		if(caracter!=8){
			putch('*');
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
			putch('*');
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
			putch('*');
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
	read blocking specifics characters
	*/

void takenot(string& word, char char1){
	word="";
	do{
		caracter=getch();
		if(caracter!=8 && caracter!=char1){
			putch(caracter);
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
			putch(caracter);
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
			putch(caracter);
			word.push_back(caracter);
		}else if(word.length()>0 && caracter==8){
			cout<<"\b \b";
			word=word.substr(0, word.length() - 1);
		}
	} while(caracter!=13);
}
