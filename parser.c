/** 
This file handles expression organization. Checks that lookaheads are the type that they are supposed to be. 
Diplays error if not. 

Author: Kenya Holland
Course: Programming Languages
File: parser.c

*/

#include "parser.h"

void assignStmt(){
	
	while(p.lookahead != DONE){
		match(ID);
		if(p.lookahead != (int) '='){
			printf("Line %i contains error, expecting '='\n\n", a.lineNo);
			exit(1);
		}
		else{
			match(p.lookahead);
			expression();
			match((int) ';');
		}
		
		if(p.lookahead == END){
			match(END);
			if(p.lookahead != DONE){
				printf("Line %i contains error, expecting '.'\n\n", a.lineNo);
				exit(1);
			}
		}
	}
}

void expression(){
	term();
	while(p.lookahead == (int) '+' || p.lookahead == (int) '-'){
		match(p.lookahead);
		term();
	}
}

void term(){
	factor();
	while(p.lookahead == (int) '*' || p.lookahead == (int) '/'){
		match(p.lookahead);
		factor();
	}
}

void factor(){
	if(p.lookahead == ID){ 
		match(ID);
	}
	else if(p.lookahead == NUM){ 
		match(NUM);
	}
	else if(p.lookahead == (int) '('){
		match((int) '(');
		expression();
		match((int) ')');
	}
	else{
		printf("Line %i contains error in factor\n\n", a.lineNo);
		exit(1);
	}
}

void match(int t){
	if(p.lookahead == t){
		p.lookahead = lexan();
	}
	else{
		printf("Line %i contains error, expecting '%c'\n\n", a.lineNo, (char) t);
		exit(1);
	}
}