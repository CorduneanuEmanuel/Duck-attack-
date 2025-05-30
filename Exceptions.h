#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class CustomException : public std::exception {
protected:
    std::string m_message;

public:
    CustomException(const std::string& message) : m_message(message) {}
    const char* what() const noexcept override {
        return m_message.c_str();
    }
};


class FileException : public CustomException {
public:
    FileException(const std::string& message) :
	    CustomException("FileException: " + message) {}
};

//daca sunt prea multe entitati
/*class MemoryManagment : std::bad_alloc {
public:
    MemoryManagment(const std::string& message)
        : bad_alloc("MemoryManagment: " + message) {}
}*/;


class RenderException : public CustomException {
public:
    RenderException(const std::string& message)
        : CustomException("RenderException: " + message) {}
};

class Memory: public std::bad_alloc {
public:
	const char* what() const override {
		return "MemoryException: Nu-i destula memorie";
	}
};


#endif