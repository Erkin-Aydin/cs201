//Erkin Aydın 22002956

#ifndef ASSIGNMENT_4_ALGEBRAICEXPRESSION_H
#define ASSIGNMENT_4_ALGEBRAICEXPRESSION_H

#include <string>
using namespace std;

string infix2prefix( const string exp);
string infix2postfix( const string exp);
string prefix2infix( const string exp);
string prefix2postfix( const string exp);
string postfix2infix( const string exp);
string postfix2prefix( const string exp);
double evaluateInfix( const string exp);
double evaluatePrefix( const string exp);
double evaluatePostfix( const string exp);
int precedence(const string c);
string deleteExtraSpace(string exp);
string reverseString(string toBeReversed);

#endif //ASSIGNMENT_4_ALGEBRAICEXPRESSION_H
