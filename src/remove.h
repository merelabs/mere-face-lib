#ifndef MERE_FACE_REMOVE_H
#define MERE_FACE_REMOVE_H

#include "global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Remove : public QObject
{
    Q_OBJECT
public:
    explicit Remove(QObject *parent = nullptr);

signals:

};

}
}
#endif // MERE_FACE_REMOVE_H
