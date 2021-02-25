#ifndef MERE_FACE_INSTALL_H
#define MERE_FACE_INSTALL_H

#include "global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Install : public QObject
{
    Q_OBJECT
public:
    explicit Install(QObject *parent = nullptr);

signals:

};

}
}
#endif // MERE_FACE_INSTALL_H
