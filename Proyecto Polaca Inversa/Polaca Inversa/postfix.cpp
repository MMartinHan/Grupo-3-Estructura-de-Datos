/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Grupo 3
* @date 11/1/2021
* @brief Programa principal
*/
#pragma once
#include "stack.h"
#include "postfix.h"
#include "Arbol.h"

//! evaluates postfix expression.
float eval_postfix(char* postfix){
    stack<string> operands; 
    istringstream stin;
    float evaluated;
    string character;	
    string expression(postfix); 
    stin.str(expression);
	Arbol bTree;	

    while(stin >> character){
        if(character == "+" || character == "-" || character == "*" || character == "/" || character == "^"|| character == ">" || character == "<"||character == "=" || character == "!"|| character == "s"|| character == "c"|| character == "t"|| character == "e"|| character == "x"|| character == "g"){
		bTree.insertar(character);
            	compute(character, operands);
        }
        else{
		bTree.insertar(character);
            	operands.push(character);
        }
    }
    evaluated = atof(operands.topAndPop().c_str());
	bTree.inorder(bTree.getRaiz());
    return evaluated;
}


//! computes binary operations for eval_postfix function.
void compute(string operation, stack<string>& operands){
    
    float first, second, solved;
    bool solution;
    second = atof(operands.topAndPop().c_str());
    first = atof(operands.topAndPop().c_str());
    ostringstream output;
    string result;
    
    if(operation == "+"){
        solved = first + second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "-"){
        solved = first - second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "*"){
        solved = first * second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "/"){
        solved = first / second;
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "^"){
        solved = pow(first, second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "s"){
        solved = sin(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "c"){
        solved = cos(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "t"){
        solved = tan(first*second);
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "e"){
        solved = 1/(cos(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "x"){
        solved = 1/(sin(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "g"){
        solved = 1/(tan(first*second));
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == ">"){
        if(first > second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "<"){
        if(first < second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "="){
        if(first == second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
    else if(operation == "!"){
        if(first != second){
            solved = 1;
        }
        else{
            solved = 0;
        }
        output << solved;
        result = output.str();
        operands.push(result);
    }
}

