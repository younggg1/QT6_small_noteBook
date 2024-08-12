#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>

class MyTextEdit : public QTextEdit
{
public:
    MyTextEdit(QWidget *parent);
protected:
    void wheelEvent(QWheelEvent *e)override;
    void keyPressEvent(QKeyEvent *e)override;
    void keyReleaseEvent(QKeyEvent *e)override;
private:
    bool ctrlKeyPressed = 0;

};

#endif // MYTEXTEDIT_H
