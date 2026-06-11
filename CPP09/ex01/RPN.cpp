#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void) other;
    return *this;
}

RPN::~RPN(){};

bool RPN::isOpr(char c)
{
    return (
        c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/'
    );
}

int RPN::performOpr(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
        {
            if (b == 0)
                throw std::runtime_error("Error");

            return a / b;
        }
    }

    throw std::runtime_error("Error");
}

bool RPN::isDigitToken(const std::string& token)
{
    return (
        token.length() == 1 &&
        std::isdigit(token[0])
    );
}

int RPN::evaluate(const std::string& str)
{
    std::stack<int> st;
    std::stringstream ss(str);
    std::string token;

    while (ss >> token)
    {
        if (isDigitToken(token))
        {
            st.push(token[0] - '0');
        }
        else if (token.size() == 1 && isOpr(token[0]))
        {
            if (st.size() < 2)
                throw std::runtime_error("Error");

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            st.push(performOpr(a, b, token[0]));
        }
        else
        {
            throw std::runtime_error("Error");
        } 
    }
     if (st.size() != 1)
        throw std::runtime_error("Error");

    return st.top();
}