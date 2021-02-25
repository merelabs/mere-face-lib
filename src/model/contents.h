#ifndef MERE_FACE_CONTENTS_H
#define MERE_FACE_CONTENTS_H

#include "../global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Contents : public QObject
{
    Q_OBJECT
public:
    explicit Contents(QObject *parent = nullptr);

signals:
private:
    std::string m_index;


};

}
}
#endif // MERE_FACE_CONTENTS_H
