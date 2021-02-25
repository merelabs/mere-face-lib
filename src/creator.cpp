#include "creator.h"
#include "model/manifest.h"
#include "utils.h"

#include "mere/utils/folderutils.h"

#include <fstream>
#include <iostream>

#include <QUuid>
#include <QDateTime>
#include <QFile>

Mere::Face::Creator::Creator()
{

}

int Mere::Face::Creator::create(const std::string &bundle)
{
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

    std::string file(bundle);

    // check path
    slash = bundle.find("/");
    if (slash != 0)
    {
        slash = bundle.find("./");
        if (slash != 0)
        {
            file.insert(0, "./");
        }
    }

    // check the extension of the bundle name
    auto ext = bundle.find(".face");
    if (ext == std::string::npos)
        file.append(".face");


    if(std::ifstream(file).good())
    {
        std::cout << "another face is already in place." << std::endl;
        return 3;
    }

    int err = Mere::Utils::FolderUtils::copy(":/face/skel.face", file.c_str());
    if (!err)
    {
        Manifest manifest(std::string(file.c_str()).append("/manifest"));
        manifest.uuid(QUuid::createUuid().toString().toStdString());
        manifest.name(bundle);
        manifest.note("copied from skel.face from the lib bundle.");
        manifest.when(QDateTime::currentDateTime().toString().toStdString());
        manifest.site("https://face.merelabs.io");


        err = Utils::update(manifest);
        if (!err)
        {
            std::cout << "face " << bundle << " is created." << std::endl;
        }
    }
    return err;
}
