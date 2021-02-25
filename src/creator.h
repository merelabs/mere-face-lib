#ifndef MERE_FACE_CREATOR_H
#define MERE_FACE_CREATOR_H

#include <QObject>

namespace Mere
{
namespace Face
{

class Creator
{
public:
    Creator();
    int create(const std::string &bundle);
};

}
}
#endif // MERE_FACE_CREATOR_H
