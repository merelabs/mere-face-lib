#include "remover.h"

#include "mere/xdg/basedirectoryspec.h"

#include <fstream>
#include <iostream>

#include <QDir>

Mere::Face::Remover::Remover(QObject *parent) : QObject(parent)
{

}

int Mere::Face::Remover::remove(const std::string &bundle, const bool &system)
{
    // validate bundle structure not the content
    if (bundle.empty())
    {
        std::cout << "bundle name can not be empty." << std::endl;
        return 1;
    }

    auto slash = bundle.find("/");
    if (slash != std::string::npos)
    {
        std::cout << "bundle name sould not contain path." << std::endl;
        return 2;
    }

    // check the extension of the bundle name
    auto ext = bundle.find(".face");
    if (ext != (bundle.length() - 5))
    {
        std::cout << "bundle name extension missing." << std::endl;
        return 3;
    }

    std::string target = system ? Mere::XDG::BaseDirectorySpec::dataDirectories().at(0)
                                : Mere::XDG::BaseDirectorySpec::dataHome();

    target.append("mere/faces/");
    target.append(bundle);

    if(!std::ifstream(target).good())
    {
        std::cout << "bundle does not installed " << (system ? "globally." : "locally." ) << std::endl;
        return 4;
    }

    bool ok = QDir(target.c_str()).removeRecursively();

    return !ok;
}
