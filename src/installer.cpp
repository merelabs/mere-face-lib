#include "installer.h"

#include "mere/xdg/basedirectoryspec.h"
#include "mere/utils/folderutils.h"

#include <fstream>
#include <iostream>

Mere::Face::Installer::Installer(QObject *parent) : QObject(parent)
{

}

int Mere::Face::Installer::install(const std::string &bundle, const bool &system)
{
    // validate bundle structure not the content

    if (bundle.empty())
    {
        std::cout << "bundle name can not be empty." << std::endl;
        return 1;
    }

    auto slash = bundle.find_last_of("/");
    if (slash == bundle.length() - 1 )
    {
        std::cout << "bundle name can not be empty. got trailing slash" << std::endl;
        return 2;
    }

    // check the extension of the bundle name
    auto ext = bundle.find(".face");
    if (ext != (bundle.length() - 5))
    {
        std::cout << "bundle name extension missing." << std::endl;
        return 3;
    }

    if(std::fstream(bundle).good())
    {
        std::cout << "bundle not found." << std::endl;
        return 4;
    }

    std::string target = system ? Mere::XDG::BaseDirectorySpec::dataDirectories().at(0)
                                : Mere::XDG::BaseDirectorySpec::dataHome();

    target.append("mere/faces/");
    target.append(bundle.substr(slash+1));

    if(std::ifstream(target).good())
    {
        std::cout << "bundle with same name already installed " << (system ? "globally." : "locally." ) << std::endl;
        return 5;
    }

    int err = Mere::Utils::FolderUtils::copy(bundle, target);

    return err;
}

