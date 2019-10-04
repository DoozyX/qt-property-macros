#pragma once

#include <QObject>

#include "QQmlHelpersCommon.h"

#define CONST_SETTER(type, name)      \
 public:                              \
  void set_##name(const type& name) { \
    if (m_##name != name) {           \
      m_##name = name;                \
      emit name##Changed();           \
    }                                 \
  }

#define CONST_GETTER(type, name) \
 public:                         \
  const type& MAKE_GETTER_NAME(name)(void) const { return m_##name; }

#define W_CREF_PROPERTY(type, name)                                                       \
 protected:                                                                               \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) WRITE set_##name NOTIFY name##Changed) \
 private:                                                                                 \
  MEMBER(type, name)                                                                      \
  CONST_GETTER(type, name)                                                                \
  CONST_SETTER(type, name)                                                                \
  NOTIFIER(name)

#define R_CREF_PROPERTY(type, name)                                      \
 protected:                                                              \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) NOTIFY name##Changed) \
  MEMBER(type, name)                                                     \
  CONST_GETTER(type, name)                                               \
  CONST_SETTER(type, name)                                               \
  NOTIFIER(name)                                                         \
 private:

#define C_CREF_PROPERTY(type, name)                          \
 protected:                                                  \
  Q_PROPERTY(type name READ MAKE_GETTER_NAME(name) CONSTANT) \
  MEMBER(type, name)                                         \
  CONST_GETTER(type, name)                                   \
 private:

class Test : public QObject {
  Q_OBJECT
  W_CREF_PROPERTY(int, var1)
  R_CREF_PROPERTY(bool, var2)
  C_CREF_PROPERTY(QString, var3)
};
