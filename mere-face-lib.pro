QT += core

TARGET = mere-face
TEMPLATE = lib

CONFIG += c++11
CONFIG += shared

DEFINES += QT_DEPRECATED_WARNINGS MERE_FACE_LIB

SOURCES += \
    src/model/face.cpp \
    src/model/manifest.cpp \
    src/model/contents.cpp \
    src/model/assets.cpp \
    src/model/asset.cpp \
    src/creator.cpp \
    src/info.cpp \
    src/installer.cpp \
    src/lister.cpp \
    src/remover.cpp \
    src/service.cpp \
    src/utils.cpp

HEADERS += \
    src/model/face.h \
    src/model/manifest.h \
    src/model/contents.h \
    src/model/assets.h \
    src/model/asset.h \
    src/creator.h \
    src/info.h \
    src/installer.h \
    src/lister.h \
    src/global.h \
    src/remover.h \
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
