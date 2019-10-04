#pragma once

#include <QObject>

#include "QQmlHelpersCommon.h"

#define PROP_GETTER(type, name) \
 public:                        \
  type MAKE_GETTER_NAME(name)(void) const { return m_##name; }

#define PROP_SETTER(type, name) \
 public:                        \
  void set_##name(type name) {  \
    if (m_##name != name) {     \
      m_##name = name;          \
      emit name##Changed();     \
    }                           \
  }

#define W_PROPERTY(type, name)                                                            \
 protected:                                                                               \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) WRITE set_##name NOTIFY name##Changed) \
                                                                                          \
  MEMBER(type, name)                                                                      \
  PROP_GETTER(type, name)                                                                 \
  PROP_SETTER(type, name)                                                                 \
  NOTIFIER(name)                                                                          \
 private:

#define R_PROPERTY(type, name)                                           \
 protected:                                                              \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) NOTIFY name##Changed) \
                                                                         \
  MEMBER(type, name)                                                     \
  PROP_GETTER(type, name)                                                \
  PROP_SETTER(type, name)                                                \
  NOTIFIER(name)                                                         \
 private:

#define C_PROPERTY(type, name)                               \
 protected:                                                  \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) CONSTANT) \
                                                             \
  MEMBER(type, name)                                         \
  PROP_GETTER(type, name)                                    \
 private:

#define W_PROPERTY_DEFAULT(type, name, defaultValue)                                      \
 protected:                                                                               \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) WRITE set_##name NOTIFY name##Changed) \
                                                                                          \
  MEMBER_DEFAULT(type, name, defaultValue)                                                \
  PROP_GETTER(type, name)                                                                 \
  PROP_SETTER(type, name)                                                                 \
  NOTIFIER(name)                                                                          \
 private:

class _QmlVarProperty_ : public QObject {
  Q_OBJECT
  W_PROPERTY(int, var1)
  R_PROPERTY(bool, var2)
  C_PROPERTY(QString, var3)

  W_PROPERTY_DEFAULT(QString, var4, "test")
};
