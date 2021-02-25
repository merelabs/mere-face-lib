#ifndef MERE_FACE_INFO_H
#define MERE_FACE_INFO_H

#include "global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Info : public QObject
{
    Q_OBJECT
public:
    explicit Info(QObject *parent = nullptr);

signals:

};

}
}
#endif // MERE_FACE_INFO_H
