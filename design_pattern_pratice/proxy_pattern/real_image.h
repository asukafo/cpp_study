#ifndef REAL_IMAGE_H
#define REAL_IMAGE_H

#include <string>
#include <thread>

#include "image.h"

// RealSubject — the expensive object that does the actual work
class RealImage : public Image
{
public:
    explicit RealImage(std::string filename)
        : filename_(std::move(filename))
    {
        loadFromDisk();
    }

    void display() override
    {
        std::cout << "  Displaying " << filename_ << std::endl;
    }

    std::string getFilename() const override { return filename_; }

private:
    void loadFromDisk()
    {
        std::cout << "  [Loading " << filename_
                  << " from disk... heavy I/O]"
                  << std::endl;
    }

    std::string filename_;
};

#endif // REAL_IMAGE_H
