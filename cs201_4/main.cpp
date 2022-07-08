//Erkin Aydın 22002956
#include <iostream>
#include "AlgebraicExpression.h"
using namespace std;

int main() {

    cout << "Infix Testbench starts here..." << endl;

    cout << "=====================================================" << endl;
    cout << "Infix expression: 15 + 6 * 2 - 90 / 3" << endl;
    cout << infix2prefix("15 + 6 * 2 - 90 / 3") << endl;
    cout << infix2postfix("15 + 6 * 2 - 90 / 3") << endl;
    cout << evaluateInfix("15 + 6 * 2 - 90 / 3") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Infix expression: ( 5 + 6 ) * 2 - 9 / 3" << endl;
    cout << infix2prefix("( 5 + 6 ) * 2 - 9 / 3") << endl;
    cout << infix2postfix("( 5 + 6 ) * 2 - 9 / 3") << endl;
    cout << evaluateInfix("( 5 + 6 ) * 2 - 9 / 3") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Infix expression: ( 5 + 6 ) * ( 2 - 9 / 3 )" << endl;
    cout << infix2prefix("( 5 + 6 ) * ( 2 - 9 / 3 )") << endl;
    cout << infix2postfix("( 5 + 6 ) * ( 2 - 9 / 3 )") << endl;
    cout << evaluateInfix("( 5 + 6 ) * ( 2 - 9 / 3 )") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Infix expression: ( 5 + 6 ) * ( 2 - 12 / 3 )" << endl;
    cout << infix2prefix("( 5 + 6 ) * ( 2 - 12 / 3 )") << endl;
    cout << infix2postfix("( 5 + 6 ) * ( 2 - 12 / 3 )") << endl;
    cout << evaluateInfix("( 5 + 6 ) * ( 2 - 12 / 3 )") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Infix expression: ( 5 + 6 ) * ( 2 - 11 ) / 3" << endl;
    cout << infix2prefix("( 5 + 6 ) * ( 2 - 11 ) / 3") << endl;
    cout << infix2postfix("( 5 + 6 ) * ( 2 - 11 ) / 3") << endl;
    cout << evaluateInfix("( 5 + 6 ) * ( 2 - 11 ) / 3") << endl;
    cout << "=====================================================" << endl;


    //prefix
    cout << endl;
    cout << endl;
    cout << "Prefix Testbench starts here..." << endl;
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Prefix expression: - + 8 3 * 5 11" << endl;
    cout << prefix2postfix("- + 8 3 * 5 11") << endl;
    cout << prefix2infix("- + 8 3 * 5 11") << endl;
    cout << evaluatePrefix("- + 8 3 * 5 11") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Prefix expression: - * / + 6 11 12 8 - 5 1" << endl;
    cout << prefix2postfix("- * / + 6 11 12 8 - 5 1") << endl;
    cout << prefix2infix("- * / + 6 11 12 8 - 5 1") << endl;
    cout << evaluatePrefix("- * / + 6 11 12 8 - 5 1") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Prefix expression: + - * 7 16 * 6 111 91" << endl;
    cout << prefix2postfix("+ - * 7 16 * 6 111 91") << endl;
    cout << prefix2infix("+ - * 7 16 * 6 111 91") << endl;
    cout << evaluatePrefix("+ - * 7 16 * 6 111 91") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Prefix expression: + - - 42 * 31 411 225 2" << endl;
    cout << prefix2postfix("+ - - 42 * 31 411 225 2") << endl;
    cout << prefix2infix("+ - - 42 * 31 411 225 2") << endl;
    cout << evaluatePrefix("+ - - 42 * 31 411 225 2") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Prefix expression: + / 171 * 11 3 899" << endl;
    cout << prefix2postfix("+ / 171 * 11 3 899") << endl;
    cout << prefix2infix("+ / 171 * 11 3 899") << endl;
    cout << evaluatePrefix("+ / 171 * 11 3 899") << endl;
    cout << "=====================================================" << endl;

    cout << endl;
    cout << endl;
    cout << "Postfix Testbench starts here..." << endl;
    cout << endl;

    cout << "=====================================================" << endl;
    cout << "Postfix expression: 81 9 / 3 2 4 2 / + * +" << endl;
    cout << postfix2infix("81 9 / 3 2 4 2 / + * +") << endl;
    cout << postfix2prefix("81 9 / 3 2 4 2 / + * +") << endl;
    cout << evaluatePostfix("81 9 / 3 2 4 2 / + * +") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Postfix expression: 90 2 * 150 - 5 - 5 /" << endl;
    cout << postfix2infix("90 2 * 150 - 5 - 5 /") << endl;
    cout << postfix2prefix("90 2 * 150 - 5 - 5 /") << endl;
    cout << evaluatePostfix("90 2 * 150 - 5 - 5 /") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Postfix expression: 12 6 3 / 2 * / 19 +" << endl;
    cout << postfix2infix("12 6 3 / 2 * / 19 +") << endl;
    cout << postfix2prefix("12 6 3 / 2 * / 19 +") << endl;
    cout << evaluatePostfix("12 6 3 / 2 * / 19 +") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Postfix expression: 15 2 3 * - 4 2 / * 6 3 / * 3 3 - -" << endl;
    cout << postfix2infix("15 2 3 * - 4 2 / * 6 3 / * 3 3 - -") << endl;
    cout << postfix2prefix("15 2 3 * - 4 2 / * 6 3 / * 3 3 - -") << endl;
    cout << evaluatePostfix("15 2 3 * - 4 2 / * 6 3 / * 3 3 - -") << endl;
    cout << "=====================================================" << endl;

    cout << "=====================================================" << endl;
    cout << "Postfix expression: 88 11 / 2 * 20 -" << endl;
    cout << postfix2infix("88 11 / 2 * 20 -") << endl;
    cout << postfix2prefix("88 11 / 2 * 20 -") << endl;
    cout << evaluatePostfix("88 11 / 2 * 20 -") << endl;
    cout << "=====================================================" << endl;


    return 0;
}
