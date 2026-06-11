#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <sstream>

class RPN
{
    private:
        static bool isOpr(char c);
        static bool isDigitToken(const std::string& token);
        static int performOpr(int a, int b, char op);
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        static int evaluate(const std::string& str);
};


#endif