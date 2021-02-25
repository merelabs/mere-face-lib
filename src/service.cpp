#include "service.h"

//#include "mere/face/installer.h"

#include <stdlib.h>
#include <fstream>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSettings>

Mere::Face::Service::Service(QObject *parent) : QObject(parent)
{

}

int Mere::Face::Service::install(const std::string &fqfn, bool system)
{
    QFileInfo info(fqfn.c_str());
    if (!info.exists()) return 1;
    if (!info.isDir()) return 2;

    // check for /manifest
    std::string manifest = fqfn;
    manifest = manifest.append("/manifest");
    QFileInfo minfo(manifest.c_str());
    if (!minfo.exists()) return 3;
    if (!minfo.isFile()) return 4;

    // check for /contents
    std::string contents = fqfn;
    contents = contents.append("/contents");
    QFileInfo cinfo(contents.c_str());
    if (!cinfo.exists()) return 5;
    if (!cinfo.isDir()) return 6;

    // check for /contents/index.html
    std::string index = contents;
    index = index.append("/index.html");
    QFileInfo iinfo(index.c_str());
    if (!iinfo.exists()) return 7;
    if (!iinfo.isFile()) return 8;

    std::string destination;
    if (system)
        destination = "/usr/local/share/mere/faces/";
    else
        destination = "/home/iklash/.local/share/mere/faces/";

    QFileInfo dinfo(destination.c_str());
    if (!dinfo.exists() && !QDir().mkpath(destination.c_str()))
        return 9;

    std::string file(destination);
    file = file.append(info.fileName().toStdString());
    QFileInfo finfo(file.c_str());
    if (finfo.exists()) return 10;

    int err = ::system(std::string("cp -fRnp ").append(fqfn).append(" ").append(destination).c_str());;

    return err;
}

std::vector<Mere::Face::Face> Mere::Face::Service::faces() const
{
    std::vector<Face> faces;

    Face face("abc");
    face.uuid("123e4567-e89b-12d3-a456-426614174000");
    face.name("Mere Default Face v1.0");
    face.path("/usr/local/share/mere/faces/abc.face");


    faces.push_back(face);

    return faces;
}
