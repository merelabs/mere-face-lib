#ifndef MERE_FACE_GLOBAL_H
#define MERE_FACE_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined MERE_FACE_LIB
 #define MERE_FACE_LIB_SPEC Q_DECL_EXPORT
#else
 #define MERE_FACE_LIB_SPEC Q_DECL_IMPORT
#endif

#endif // MERE_FACE_GLOBAL_H
