
#include <QObject>

class _QmlVarProperty_ : public QObject {
  Q_OBJECT
 protected:
  Q_PROPERTY(int var1 READ get_var1 WRITE set_var1 NOTIFY var1Changed) private : int m_var1;

 public:
  int get_var1(void) const { return m_var1; }

 public:
  void set_var1(int var1) {
    if (m_var1 != var1) {
      m_var1 = var1;
      emit var1Changed();
    }
  }
 Q_SIGNALS:
  void var1Changed(void);
};
