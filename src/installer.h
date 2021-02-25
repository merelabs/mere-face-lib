#ifndef MERE_FACE_INSTALL_H
#define MERE_FACE_INSTALL_H

#include "global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Installer : public QObject
{
    Q_OBJECT
public:
    explicit Installer(QObject *parent = nullptr);
    int install(const std::string &bundle, const bool &system = false);

signals:

};

}
}
#endif // MERE_FACE_INSTALL_H
