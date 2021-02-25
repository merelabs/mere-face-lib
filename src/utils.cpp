#include "utils.h"

#include <fstream>
#include <iostream>

#include <QFile>
#include <QTextStream>

//static
bool Mere::Face::Utils::valid(const std::string &bundle)
{
    if (bundle.empty())
    {
        std::cout << "bundle name can't be empty." << std::endl;
        return false;
    }

    auto ext = bundle.find(".face");
    if (ext == std::string::npos || ext != (bundle.length() - 5))
    {
        std::cout << "bundle name extension must be .face." << std::endl;
        return false;
    }

    if(!std::ifstream(bundle).good())
    {
        std::cout << "bundle not found in path." << std::endl;
        return false;
    }

    std::string manifest(bundle);
    manifest.append("/manifest");
    if(!std::ifstream(manifest).good())
    {
        std::cout << "bundle does not contain manifest." << std::endl;
        return false;
    }
    // validate manifest file content

    std::string contents(bundle);
    contents.append("/contents");
    if(!std::ifstream(contents).good())
    {
        std::cout << "bundle does not contain contents." << std::endl;
        return false;
    }

    contents.append("/index.html");
    if(!std::ifstream(contents).good())
    {
        std::cout << "bundle's contents does not contain face file (index.html)." << std::endl;
        return false;
    }

    return true;
}

//static
int Mere::Face::Utils::update(const Manifest &manifest)
{
    QFile file(manifest.file().c_str());
    if(file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << "mere.face.uuid=" << manifest.uuid().c_str() << Qt::endl;
        stream << "mere.face.name=" << manifest.name().c_str() << Qt::endl;
        stream << "mere.face.note=" << manifest.note().c_str() << Qt::endl;
        stream << "mere.face.when=" << manifest.when().c_str() << Qt::endl;
        stream << "mere.face.site=" << manifest.site().c_str() << Qt::endl;
        stream << "mere.face.author=" << "your name" << Qt::endl;
        stream << "mere.face.version=" << "1.0" << Qt::endl;
        stream << "mere.face.hash=" << manifest.hash().c_str() << Qt::endl;

        file.close();
    }

    return 0;
}
