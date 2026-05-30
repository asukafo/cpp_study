#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <string>

// Subject — common interface for Real and Proxy
class Image
{
public:
    virtual ~Image() = default;
    virtual void display() = 0;
    virtual std::string getFilename() const = 0;
};

#endif // IMAGE_H
