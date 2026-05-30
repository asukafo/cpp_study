#ifndef PROTECTION_PROXY_H
#define PROTECTION_PROXY_H

#include <string>

#include "document.h"

// Protection Proxy — controls access based on role/permission
class ProtectionDocumentProxy : public Document
{
public:
    ProtectionDocumentProxy(Document *doc, std::string role)
        : doc_(doc), role_(std::move(role)) {}

    void read() override
    {
        // Anyone can read
        doc_->read();
    }

    void write(const std::string &content) override
    {
        // Only admin can write
        if (role_ != "admin")
        {
            std::cout << "  [ACCESS DENIED] \"" << role_
                      << "\" may not write this document." << std::endl;
            return;
        }
        doc_->write(content);
    }

private:
    Document *doc_;
    std::string role_;
};

#endif // PROTECTION_PROXY_H
