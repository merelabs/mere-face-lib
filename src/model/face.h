#ifndef MERE_FACE_FACE_H
#define MERE_FACE_FACE_H

#include "../global.h"
#include <QObject>


namespace Mere
{
namespace Face
{

class Manifest;
class Contents;

class MERE_FACE_LIB_SPEC Face
{
public:
    explicit Face(const std::string &name);

    std::string uuid() const;
    void uuid(const std::string &uuid);

    std::string name() const;
    void name(const std::string &name);

    std::string path() const;
    void path(const std::string &path);

signals:

private:
    std::string m_uuid;
    std::string m_name;
    std::string m_path;
//    std::string m_size;

    Manifest *m_manifest;
    Contents *m_contents;
};

}
}
#endif // MERE_FACE_FACE_H
