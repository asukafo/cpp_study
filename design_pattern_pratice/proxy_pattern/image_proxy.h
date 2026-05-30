#ifndef IMAGE_PROXY_H
#define IMAGE_PROXY_H

#include <string>

#include "image.h"
#include "real_image.h"

// Virtual Proxy — lazy-loads the real image only when needed
class ImageProxy : public Image
{
public:
    explicit ImageProxy(std::string filename)
        : filename_(std::move(filename)), real_image_(nullptr) {}

    ~ImageProxy() { delete real_image_; }

    void display() override
    {
        // Virtual proxy: only create the expensive object on first access
        if (!real_image_)
        {
            std::cout << "  [Proxy: instantiating RealImage now]" << std::endl;
            real_image_ = new RealImage(filename_);
        }
        real_image_->display();
    }

    std::string getFilename() const override { return filename_; }

private:
    std::string filename_;
    RealImage *real_image_;
};

#endif // IMAGE_PROXY_H
