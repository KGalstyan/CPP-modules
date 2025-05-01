#include "RPN.hpp"

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN& obj) : _stack(obj._stack)
{
}

RPN& RPN::operator=(const RPN& obj)
{
	if (this != &obj)
		_stack = obj._stack;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) const
{
	return token.length() == 1 && std::isdigit(token[0]);
}

int RPN::applyOperator(int a, int b, const std::string& op) const
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
    {
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	}
	throw std::runtime_error("Invalid operator");
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
    {
		if (isNumber(token))
			_stack.push(std::atoi(token.c_str()));
        else if (isOperator(token))
        {
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			int result = applyOperator(a, b, token);
			_stack.push(result);
		}
        else
			throw std::runtime_error("Invalid token");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");

	return _stack.top();
}
