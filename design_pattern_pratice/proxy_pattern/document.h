#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

// Subject
class Document
{
public:
    virtual ~Document() = default;
    virtual void read() = 0;
    virtual void write(const std::string &content) = 0;
};

// RealSubject
class RealDocument : public Document
{
public:
    explicit RealDocument(std::string title) : title_(std::move(title)) {}

    void read() override
    {
        std::cout << "  Reading document \"" << title_
                  << "\": " << content_ << std::endl;
    }

    void write(const std::string &content) override
    {
        content_ = content;
        std::cout << "  Written to \"" << title_ << "\"" << std::endl;
    }

private:
    std::string title_;
    std::string content_ = "(empty)";
};

#endif // DOCUMENT_H
