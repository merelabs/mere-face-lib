QT += core

TARGET = mere-face
TEMPLATE = lib

CONFIG += c++11
CONFIG += shared

DEFINES += QT_DEPRECATED_WARNINGS MERE_FACE_LIB

SOURCES += \
    src/asset.cpp \
    src/assets.cpp \
    src/contents.cpp \
    src/creator.cpp \
    src/face.cpp \
    src/info.cpp \
    src/install.cpp \
    src/list.cpp \
    src/manifest.cpp \
    src/remove.cpp \
    src/service.cpp \
    src/utils.cpp

HEADERS += \
    src/asset.h \
    src/assets.h \
    src/contents.h \
    src/creator.h \
    src/face.h \
    src/info.h \
    src/install.h \
    src/list.h \
    src/manifest.h \
    src/remove.h\
    src/global.h \
    src/service.h \
    src/utils.h

RESOURCES += \
    res/face.qrc

INCLUDEPATH += /usr/local/include

LIBS += -lmere-xdg -lmere-utils


#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/face
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
