#include <iostream>

#include "image.h"
#include "image_proxy.h"
#include "real_image.h"
#include "document.h"
#include "protection_proxy.h"

int main()
{
    std::cout << "The Proxy Pattern provides a surrogate or\n"
              << "placeholder for another object to control\n"
              << "access to it.\n"
              << std::endl;

    // ========== Virtual Proxy ==========
    std::cout << "=== Proxy Pattern: Virtual Proxy (Lazy Loading) ===" << std::endl;

    // ImageProxy does NOT load the image until display() is called
    ImageProxy img1("photo1.jpg");
    ImageProxy img2("photo2.jpg");

    std::cout << "\nImages created, but not yet loaded...\n";
    std::cout << "Now displaying:\n";

    img1.display(); // RealImage created here
    img1.display(); // Already cached — uses existing RealImage

    std::cout << "\n(photo2.jpg was never loaded — never called display)\n";

    // ========== Protection Proxy ==========
    std::cout << "\n=== Proxy Pattern: Protection Proxy (Access Control) ===" << std::endl;

    RealDocument doc("Top Secret Report");
    ProtectionDocumentProxy user_proxy(&doc, "user");
    ProtectionDocumentProxy admin_proxy(&doc, "admin");

    std::cout << "\n--- As 'user' ---\n";
    user_proxy.read();
    user_proxy.write("leak this");

    std::cout << "\n--- As 'admin' ---\n";
    admin_proxy.read();
    admin_proxy.write("classified content here");

    std::cout << "\n--- Final read ---\n";
    user_proxy.read();

    return 0;
}
