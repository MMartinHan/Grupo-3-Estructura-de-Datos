/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Grupo 3
* @date 11/1/2021
* @brief Programa principal
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "postfix.h"
#include "postfix.cpp"
#include "infix.h"
#include "infix.cpp"
#include "Menu.h"
#include "Menu.cpp"
#include "Arbol.h"
#include "Arbol.cpp"
#include "Console.h"
#include "Console.cpp"

void format_input(string input, string &output);

int main(void)
{
	
	Menu menu;
	int option;	
	Arbol bArbol();//revisado listo
	string in, out, expression;
	char *infix; 	
	char *postfix;
	double x = 0;
	do {
		option = menu.makeMenu(4,"Ingresar Expresion","Ver Infija","Ver Posfija","Salir");
		system("cls");
		switch (option) {
		case 1:{
			Console screen;
			screen.hideCursor(true);
			in = "";
			expression = "";
			x = 0;
			infix,postfix = NULL;

			cout << "Ingrese una expresion: ";
			getline(cin, in);
			format_input(in, expression);
			out.resize(expression.length() * 100);
			cout<<"Expresion ingresada-> "<<expression<<endl;
			infix = &expression[0];
			postfix = &out[0];
			infix2postfix(infix, postfix);
			x = eval_postfix(postfix);
			cout << "Resulatado: " << x << endl;
			system("pause");
			break;
		}
		case 2:{
			cout << "\nInfija: " << infix << endl;
			system("pause");
			break;
		}
		case 3:{
			infix2postfix(infix, postfix);
	
			cout << "\nPostfija: " <<  out << endl;
			system("pause");
			break;
		}
		default:
		break;

	}


	}while (option != 4);


	return EXIT_SUCCESS;
}

void format_input(string input, string &output){
	for(unsigned int i = 0; i < input.length(); i++){
		if(input[i] != ' '){
            if(input[i] == '^' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '+'|| input[i] == '>'|| input[i] == '<'|| input[i] == '='|| input[i] == '!'|| input[i] == 's'|| input[i] == 'c'|| input[i] == 't'|| input[i] == 'e'|| input[i] == 'x'|| input[i] == 'g'){
				output.push_back(' ');
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == '-'){
				if((i != 0) && (*output.rbegin() != 's' && *output.rbegin() != 'c' && *output.rbegin() != 't' && *output.rbegin() != 'e' && *output.rbegin() != 'x' && *output.rbegin() != 'g' && *output.rbegin() != '(' && *output.rbegin() != ' '&& *output.rbegin() != '^' && *output.rbegin() != '*' && *output.rbegin() != '/' && *output.rbegin() != '%' && *output.rbegin() != '+' && *output.rbegin() != '-'&& *output.rbegin() != '>'&& *output.rbegin() != '<'&& *output.rbegin() != '='&& *output.rbegin() != '!')){
					output.push_back(' ');
					output.push_back(input[i]);
					output.push_back(' ');
				}
				else{
					output.push_back(input[i]);
				}	
			}
			else if(input[i] == '('){
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == ')'){
				output.push_back(' ');
				output.push_back(input[i]);
			}
			else
			{
				output.push_back(input[i]);
			}
		}
	}
}
