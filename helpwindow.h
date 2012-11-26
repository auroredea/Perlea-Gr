#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class Helpwindow;
}

class Helpwindow : public QDialog
{
    Q_OBJECT
    
public:
    enum Texte {
             Manuel = 0x0,
             Apropos = 0x1
    };
    Q_DECLARE_FLAGS(Textes, Texte)

    explicit Helpwindow(QWidget *parent = 0);
    ~Helpwindow();

    void setType(int t);
    int getType();

protected slots:
    void accept();
    
private:
    Ui::Helpwindow *ui;
    Texte type;
    QString manuel;
    QString apropos;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Helpwindow::Textes)

#endif // HELPWINDOW_H
