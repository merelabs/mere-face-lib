#ifndef MERE_FACE_REMOVE_H
#define MERE_FACE_REMOVE_H

#include "global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Remover : public QObject
{
    Q_OBJECT
public:
    explicit Remover(QObject *parent = nullptr);
    int remove(const std::string &bundle, const bool &system = false);


signals:

};

}
}
#endif // MERE_FACE_REMOVE_H
