#ifndef MERE_FACE_UTILS_H
#define MERE_FACE_UTILS_H

#include "manifest.h"

namespace Mere
{
namespace Face
{

class Utils
{
    Utils() = default;
public:
    static int update(const Manifest &manifest);
};

}
}

#endif // MERE_FACE_UTILS_H
