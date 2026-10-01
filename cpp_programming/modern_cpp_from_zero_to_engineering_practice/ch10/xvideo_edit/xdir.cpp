#include "xdir.h"

#include <filesystem>
#include <system_error>

namespace fs = std::filesystem;

bool XDir::IsDir(const std::string& path)
{
    std::error_code ec;
    return fs::is_directory(path, ec);
}

void XDir::Create(const std::string& path)
{
    std::error_code ec;
    fs::create_directories(path, ec);
}

std::vector<XDir::File> XDir::GetFiles(const std::string& dir)
{
    std::vector<File> files;
    std::error_code ec;
    if (!fs::is_directory(dir, ec))
        return files;

    for (auto& entry : fs::directory_iterator(dir, ec))
    {
        File f;
        f.name = entry.path().filename().string();
        f.path = entry.path().string();
        files.push_back(f);
    }
    return files;
}
