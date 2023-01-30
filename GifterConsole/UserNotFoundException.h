#pragma once
#include <iostream>
#include <exception>

struct UserNotFoundException : public std::exception
{
    const char* what() const throw ()
    {
        return "This user name was not found!";
    }
};