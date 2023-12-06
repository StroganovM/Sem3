#ifndef _STRING_PARSER_H_
#define _STRING_PARSER_H_
#include <iostream>
#include "../StackOnList/StackOnList.h"
#include"../Stack/Stack.h"
struct Variable {
    std::string val; //1 // 1.0 // 0.1
    std::string name;// a b c d e A B C D E
};
class Parser {
    std::string expression;
public:
    int CorrectInputSkobochki(const std::string& str) {//скобочки 
        StackOnList<char> stack;
        int count = 0;
        for (char c : str) {
            switch (c) {

            case '(': stack.push(')'); break;
            case '[': stack.push(']'); break;
            case '{': stack.push('}'); break;
            case '<': stack.push('>'); break;

            case ')':
            case ']':
            case '}':
            case '>':

                if (stack.isEmpty() || stack.top() != c) {
                    return count = str.find(c) + 1;
                }
                stack.pop();
                break;
            default:
                break;
            }

        }

        if (stack.isEmpty()) {
            return 0;
        }
        else {
            int c = stack.top();
            if (c == 41) { c = 40; }
            else if (c == 93) { c = 91; }
            else if (c == 125) { c = 123; }
            return count = str.find(c) + 1;
        }
    }
    void EraseSpace(std::string& st) {
        while (st.find(' ') != std::string::npos) {
            st.erase(st.find(' '), 1);
        }
    }
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    bool isSkobochki(char c) {
        return(c == '(' || c == ')' || c == '{' || c == '}' || c == '<' || c == '>' || c == '[' || c == ']');
    }

    TList<std::string> splitExpression(const std::string& expression) {//разделение на лексемы
        TList<std::string> tokens;
        std::string currentToken;

        for (char c : expression) {
            if (isOperator(c) || isSkobochki(c)) {
                if (!currentToken.empty()) {
                    tokens.push_back_(currentToken);
                    currentToken.clear();
                }
                tokens.push_back_(std::string(1, c));
            }
            else {
                currentToken += c;
            }
        }

        if (!currentToken.empty()) {
            tokens.push_back_(currentToken);
        }

        return tokens;
    }
};


#endif //_STRING_PARSER_H_
