#ifndef MERE_FACE_ASSET_H
#define MERE_FACE_ASSET_H

#include "../global.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Asset : public QObject
{
    Q_OBJECT
public:
    explicit Asset(QObject *parent = nullptr);

signals:
private:
    std::string m_name;
    std::string m_mime;
    std::string m_path;
    std::string m_size;
};

}
}

#endif // MERE_FACE_ASSET_H
