#include<iostream>
#include<conio.h>
using namespace std;
string delchar(string word, char character){
	string new_word;
	for(int i = 0; i < word.length(); i++) {
		if( word[i] != character && word[i] != toupper(character)){
			new_word+=word[i];
		}
	}
	return new_word;
}
string rpchar(string word, char replaced_char, char new_char){
	for (int i = 0; i < word.length(); i++) {
		if( word[i] != replaced_char && word[i] != toupper(replaced_char)){
			word[i] = word[i];
		} else if(word[i] == replaced_char){
			word[i] = new_char;
		} else if( word[i] == toupper(replaced_char) ){
			word[i] = toupper(new_char);
		}
	}
	return word;
}
string uppstr(string word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=toupper(word[i]);
	}
	return word;
}

string lowstr(string word){
	for (int i = 0; i < word.length(); i++) {
		word[i]=tolower(word[i]);
	}
	return word;
}

int readnum(int max_digits){
	string NUM;
	char caracter;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=48&&caracter<=57)){
				cout<<caracter;
				NUM.push_back(caracter);	
			}
		} else{
			if(NUM.length()>0){
				cout<<"\b \b";
				NUM=NUM.substr(0, NUM.length() - 1);
			}
		}
	} while(caracter!=13 && (NUM.length()<max_digits||max_digits==0));
	if(NUM!=""){
		int z=stoi(NUM);
		return z;
	} else{
		return 0;
	}
}

string readstr(int max_digits){
	string WORD;
	char caracter;
	do{
		caracter=getch();
		if(caracter!=8){
			if((caracter>=65&&caracter<=90)||(caracter>=97&&caracter<=122)){
				cout<<caracter;
				WORD.push_back(caracter);	
			}
		} else{
			if(WORD.length()>0){
				cout<<"\b \b";
				WORD=WORD.substr(0, WORD.length() - 1);
			}
		}
	} while((caracter!=13 && (WORD.length()<max_digits||max_digits==0)) || WORD.length()==0);
	return WORD;
}