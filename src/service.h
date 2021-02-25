#ifndef MERE_FACE_FACESERVICE_H
#define MERE_FACE_FACESERVICE_H

#include "global.h"
#include "face.h"
#include <QDebug>
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);

    int install(const std::string &fqfn, bool system = false);
    std::vector<Face> faces() const;

signals:

};

}
}
#endif // MERE_FACE_FACESERVICE_H
