#include "utils.h"

#include <QFile>
#include <QTextStream>

//static
bool Mere::Face::Utils::valid(const std::string &bundle)
{

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
        stream << "mere.face.hash=" << manifest.hash().c_str() << Qt::endl;

        file.close();
    }

    return 0;
}
