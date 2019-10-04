QT += core qml

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/QQmlAutoPropertyHelpers.h \
    $$PWD/QQmlConstRefPropertyHelpers.h \
    $$PWD/QQmlPropertyHelpers.h \
    $$PWD/QQmlPtrPropertyHelpers.h \
    $$PWD/QQmlEnumClassHelper.h \
    $$PWD/QQmlListPropertyHelper.h \
    $$PWD/QQmlHelpersCommon.h \
    $$PWD/QQmlSingletonHelper.h

SOURCES += \
    $$PWD/QQmlHelpers.cpp

DISTFILES += \
    $$PWD/README.md \
    $$PWD/LICENSE.md

