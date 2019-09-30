QT += core qml

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/QQmlVarPropertyHelpers.h \
    $$PWD/QQmlPtrPropertyHelpers.h \
    $$PWD/QQmlEnumClassHelper.h \
    $$PWD/QQmlConstRefPropertyHelpers.h \
    $$PWD/QQmlListPropertyHelper.h \
    $$PWD/QQmlAutoPropertyHelpers.h \
    $$PWD/QQmlHelpersCommon.h \
    $$PWD/QQmlSingletonHelper.h

SOURCES += \
    $$PWD/QQmlHelpers.cpp

DISTFILES += \
    $$PWD/README.md \
    $$PWD/LICENSE.md

