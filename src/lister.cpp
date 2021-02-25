#include "lister.h"
#include "mere/xdg/basedirectoryspec.h"

#include <QDir>
Mere::Face::Lister::Lister(QObject *parent) : QObject(parent)
{

}

std::vector<Mere::Face::Face> Mere::Face::Lister::list() const
{
    std::vector<Mere::Face::Face> faces;

    std::string home = Mere::XDG::BaseDirectorySpec::dataHome();

    std::vector<std::string> dirs = Mere::XDG::BaseDirectorySpec::dataDirectories();
    dirs.push_back(home);

    for(std::string &dir : dirs)
    {
        dir.append("mere/faces/");

        QStringList entries = QDir(dir.c_str()).entryList(QStringList() << "*.face", QDir::Dirs | QDir::NoDotAndDotDot);
        if (entries.isEmpty()) continue;

        for(QString entry : entries)
        {
            Face face(entry.toStdString());
            face.path(dir);

            faces.push_back(face);
        }
    }


    return faces;
}
