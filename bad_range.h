#pragma once
#include <exception>
#include <iostream>
class bad_range : public std::exception
{
public:
	virtual const char* what()const noexcept override { return "ERROR: Incorrect index"; }
};