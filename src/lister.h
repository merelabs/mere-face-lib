#ifndef MERE_FACE_LIST_H
#define MERE_FACE_LIST_H

#include "global.h"
#include "model/face.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Lister : public QObject
{
    Q_OBJECT
public:
    explicit Lister(QObject *parent = nullptr);

    std::vector<Face> list() const;

signals:

};

}
}
#endif // MERE_FACE_LIST_H
