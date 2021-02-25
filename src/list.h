#ifndef MERE_FACE_LIST_H
#define MERE_FACE_LIST_H

#include "global.h"
#include "face.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC List : public QObject
{
    Q_OBJECT
public:
    explicit List(QObject *parent = nullptr);

    std::vector<Face> list() const;

signals:

};

}
}
#endif // MERE_FACE_LIST_H
