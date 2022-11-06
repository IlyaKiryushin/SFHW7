#pragma once
#include <exception>
#include <iostream>
class bad_length : public std::exception
{
public:
	virtual const char* what() const noexcept override { return "ERROR: length < 0"; }
};
