#ifndef MERE_FACE_ASSETS_H
#define MERE_FACE_ASSETS_H

#include "global.h"
#include "asset.h"
#include <QObject>

namespace Mere
{
namespace Face
{

class MERE_FACE_LIB_SPEC Assets : public QObject
{
    Q_OBJECT
public:
    explicit Assets(QObject *parent = nullptr);

signals:

private:
    std::vector<Asset> m_assets;

};

}
}
#endif // MERE_FACE_ASSETS_H
