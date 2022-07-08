//Erkin Aydın 22002956

#include <cstdlib>
#include "AlgebraicExpression.h"
#include "Stack.h"

string infix2prefix( const string exp) {
    // For the sake of simplicity, infix2postfix and postfix2prefix will be used.
    return postfix2prefix(infix2postfix(exp));
}

//In this function, infix2postfix, following video was useful, especially in precedence issue: https://www.youtube.com/watch?v=xsXNeysHd9w&t=402s
//Another video that was helpful is this: https://www.youtube.com/watch?v=J3Ps-e52pKQ
//Lastly, this video was useful in terms of algorithm: https://www.youtube.com/watch?v=fRCHGu320lo&t=1213s
//Additionally, slides were used to implement this function. ( 15 + 6 ) * 4 / 2
string infix2postfix( const string exp) {
    Stack<string> thatStack;
    string postfixVersion = "";
    for(int i = 0; i < exp.length(); i++) {
        string currentString = "";
        // Getting the next operand or operator, with an empty space at the end
        while(exp[i] != ' ' && i != exp.length()) {
            currentString += exp[i];
            i++;
        }
        currentString += " ";
        if(currentString == "( ") {
            thatStack.push(currentString);
        }
        else if(currentString == ") ") {
            string top;
            while(thatStack.pop(top)) {
                if(top == "( ") break;
                postfixVersion += top;
                postfixVersion += " ";//Unnecessary??? It does not matter since unnecessary spaces will be deleted later
            }
        }
        else if(currentString == "+ " || currentString == "- " || currentString == "* " || currentString == "/ " ){
            while(!thatStack.isEmpty()) {
                string top = "";
                thatStack.getTop(top);
                if(top == "( ") break;
                if(precedence(currentString) <= precedence(top)) {
                    thatStack.pop(top);
                    postfixVersion += top;
                }
                else break;
            }
            thatStack.push(currentString);
        }
        else {
            postfixVersion += currentString;
        }
    }
    string toAdd;
    while(thatStack.pop(toAdd)) {
        postfixVersion += " ";
        postfixVersion += toAdd;
    }
    return deleteExtraSpace(postfixVersion);
}

string prefix2infix( const string exp) {
    // For the sake of simplicity, prefix2postfix and postfix2infix will be used.
    return postfix2infix(prefix2postfix(exp));
}

//In this part, this video was quite helpful: https://www.youtube.com/watch?v=jZxII0guwUo
//The idea of reversing the string came from here.
string prefix2postfix( const string exp) {

    Stack<string> thatStack;
    string toAdd = "";
    string expReversed = reverseString(exp);
    for(int i = 0; i < expReversed.length(); i++) {
        if (expReversed[i] == '+' || expReversed[i] == '-' || expReversed[i] == '*' || expReversed[i] == '/') {
            string op2;
            string op1;
            thatStack.pop(op2);
            thatStack.pop(op1);
            while (expReversed[i] != ' ' && i != expReversed.length() - 1) {
                toAdd += expReversed[i];
                i++;
            }
            toAdd += " " + op1 + op2 + " ";
            toAdd += expReversed[i];
            thatStack.push(toAdd);
        } else {
            while (expReversed[i] != ' ' && i != expReversed.length() - 1) {
                toAdd += expReversed[i];
                i++;
            }
            toAdd += expReversed[i];
            thatStack.push(toAdd);
        }
        toAdd = "";
    }
    thatStack.pop(toAdd);
    toAdd = reverseString(toAdd);
    return deleteExtraSpace(toAdd);
}

//This video was very helpful here: https://www.youtube.com/watch?v=UikLQldGV_0&t=186s
//Additionally, slides were used here.
string postfix2infix( const string exp) {
    Stack<string> thatStack;
    string toAdd = "";
    for(int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            char curOperator = exp[i];
            string op2;
            string op1;
            thatStack.pop(op2);
            thatStack.pop(op1);
            while (exp[i] != ' ' && i != exp.length() - 1) {
                toAdd += exp[i];
                i++;
            }
            toAdd += exp[i];
            if(curOperator == '-' || curOperator == '+') {
                toAdd = "( " + op1 + " " + toAdd + " " + op2 + " )";
            }
            else {
                toAdd = op1 + " " + toAdd + " " + op2;
            }
            thatStack.push(toAdd);
        } else {
            while (exp[i] != ' ' && i != exp.length() - 1) {
                toAdd += exp[i];
                i++;
            }
            toAdd += exp[i];
            thatStack.push(toAdd);
        }
        toAdd = "";
    }
    thatStack.pop(toAdd);
    return deleteExtraSpace(toAdd);
}

//This video was very helpful here: https://www.youtube.com/watch?v=smQ88h1qzQY&t=198s
//Additionally, slides were slightly helpful here.
string postfix2prefix( const string exp) {
    Stack<string> thatStack;
    string toAdd = "";
    for(int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            string op2;
            string op1;
            thatStack.pop(op2);
            thatStack.pop(op1);
            while (exp[i] != ' ' && i != exp.length() - 1) {
                toAdd += exp[i];
                i++;
            }
            toAdd += exp[i];
            toAdd += " ";
            toAdd += op1 + op2;
            thatStack.push(toAdd);
        } else {
            while (exp[i] != ' ' && i != exp.length() - 1) {
                toAdd += exp[i];
                i++;
            }
            toAdd += exp[i];
            thatStack.push(toAdd);
        }
        toAdd = "";
    }
    thatStack.pop(toAdd);
    return deleteExtraSpace(toAdd);
}

//For the sake of simplicity, I used infix2postfix and evaluatePostfix functions here.
double evaluateInfix( const string exp) {
    string postfixVersion = infix2postfix(exp);
    return evaluatePostfix(postfixVersion);
}

//For the sake of simplicity, I used prefix2postfix and evaluatePostfix functions here.
double evaluatePrefix( const string exp) {
    string postfixVersion = prefix2postfix(exp);
    return evaluatePostfix(postfixVersion);
}

//Evaluating postfix is easy and sufficient. Thus, in evaluateInfix and evaluatePrefix, evaluatePostfix is used.
double evaluatePostfix( const string exp) {
    Stack<double> numberStack;
    string toAdd = "";
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            char curOperator = exp[i];
            i++;
            double op2;
            double op1;
            numberStack.pop(op2);
            numberStack.pop(op1);
            if(curOperator == '+') numberStack.push(op1 + op2);
            else if(curOperator == '-') numberStack.push(op1 - op2);
            else if(curOperator == '*') numberStack.push(op1 * op2);
            else if(curOperator == '/') numberStack.push(op1 / op2);
            double numToPrint;
            numberStack.getTop(numToPrint);
        }
        else {
            while (exp[i] != ' ' && i != exp.length()) {
                toAdd += exp[i];
                i++;
            }
            char* end;
            char charArray[toAdd.length()];
            for(int j = 0; j < toAdd.length(); j++) {
                charArray[j] = toAdd[j];
            }
            numberStack.push(strtod(charArray, &end));
        }
        toAdd = "";
    }
    double numToReturn;
    numberStack.pop(numToReturn);
    return numToReturn;
}

//Here, this site was quite helpful fo me to understand how precedence worked: https://www.free-online-calculator-use.com/infix-to-postfix-converter.html
int precedence(const string a) {
    if( a == "+ " || a == "- ") return 0;
    else if(a == "* " || a == "/ ") return 1;
    else return -1;
}

//I use this function to delete extra spaces in an expression, so that each operand and operator has only and only 1 empty
//space between them, not less or more.
string deleteExtraSpace(string exp) {
    string modified = "";
    bool prev = false;
    for(int j = 0; j < exp.length(); j++) {
        if( prev && exp[j] == ' ') {
            modified += exp[j];
            prev = false;
        }
        else if(exp[j] != ' '){
            modified += exp[j];
            prev = true;
        }
    }
    return modified;
}

//This function is used in prefix to postfix, twice.
string reverseString(string toBeReversed) {
    Stack<string> stackForReversing;
    string toAdd = "";
    string reversed = "";
    for(int i = 0; i < toBeReversed.length(); i++) {
        while (toBeReversed[i] != ' ' && i != toBeReversed.length()) {
            toAdd += toBeReversed[i];
            i++;
        }
        toAdd += " ";
        stackForReversing.push(toAdd);
        toAdd = " ";
    }
    while(!stackForReversing.isEmpty()) {
        stackForReversing.pop(toAdd);
        reversed += toAdd;
    }
    reversed = deleteExtraSpace(reversed);
    return reversed;
}