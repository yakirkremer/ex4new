#ifndef EXCEPTION_H 
#define EXCEPTION_H
#include <stdexcept>

class DeckFileNotFound:public std::exception
{
    public:
    const char* what()const throw() override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError:public std::invalid_argument
{
    //unsigned long m_index;
    public:
    explicit DeckFileFormatError(int index):std::invalid_argument("Deck File Error: File format error in line "
    + std::to_string(index)){}
};

class DeckFileInvalidSize:public std::exception
{
    public:
    const char* what()const throw() override
    {
        return "Deck File Error: Deck size is invalid";
    }
};
#endif





