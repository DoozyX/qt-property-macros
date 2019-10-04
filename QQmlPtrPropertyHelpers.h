#pragma once

#include <QObject>

#include "QQmlHelpersCommon.h"

#define PTR_GETTER(type, name) \
 public:                       \
  type* MAKE_GETTER_NAME(name)(void) const { return m_##name; }

#define PTR_SETTER(type, name)  \
 public:                        \
  void set_##name(type* name) { \
    if (m_##name != name) {     \
      m_##name = name;          \
      emit name##Changed();     \
    }                           \
  }

#define W_PTR_PROPERTY(type, name)                                                         \
 protected:                                                                                \
  Q_PROPERTY(type* name READ MAKE_GETTER_NAME(name) WRITE set_##name NOTIFY name##Changed) \
                                                                                           \
  MEMBER(type*, name)                                                                      \
  PTR_GETTER(type, name)                                                                   \
  PTR_SETTER(type, name)                                                                   \
  NOTIFIER(name)                                                                           \
 private:

#define R_PTR_PROPERTY(type, name)                                        \
 protected:                                                               \
  Q_PROPERTY(type* name READ MAKE_GETTER_NAME(name) NOTIFY name##Changed) \
                                                                          \
  MEMBER(type*, name)                                                     \
  PTR_GETTER(type, name)                                                  \
  PTR_SETTER(type, name)                                                  \
  NOTIFIER(name)                                                          \
 private:

#define C_PTR_PROPERTY(type, name)                            \
 protected:                                                   \
  Q_PROPERTY(type* name READ MAKE_GETTER_NAME(name) CONSTANT) \
                                                              \
  MEMBER(type*, name)                                         \
  PTR_GETTER(type, name)                                      \
 private:

class _QmlPtrProperty_ : public QObject {
  Q_OBJECT

  W_PTR_PROPERTY(int, var1)
  R_PTR_PROPERTY(bool, var2)
  C_PTR_PROPERTY(QString, var3)
};
