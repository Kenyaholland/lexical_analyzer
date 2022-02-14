/** 
This file is the header file for Parser struct and its related functions. 

Author: Kenya Holland
Course: Programming Languages
File: parser.h

*/

#ifndef PARSER_H
#define PARSER_H

#include<stdlib.h>
#include<stdio.h>

#include "analyzer.h"

typedef struct Parser{
	int lookahead;
} ParserStruct;

ParserStruct p;

void assignStmt();
void expression();
void term();
void factor();
void match(int t);

#endif