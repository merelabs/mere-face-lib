#ifndef MERE_FACE_CREATOR_H
#define MERE_FACE_CREATOR_H

#include <QObject>

namespace Mere
{
namespace Face
{


class Creator : public QObject
{
    Q_OBJECT
public:
    explicit Creator(QObject *parent = nullptr);
    int create(const std::string &bundle);

signals:
};

}
}

#endif // MERE_FACE_CREATOR_H
