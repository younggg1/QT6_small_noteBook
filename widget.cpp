#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QDebug"

#include <QMessageBox>
#include <QShortcut>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //通过这行代码进行显示说明让窗口变化时，布局里的空间会随布局变化
    this->setLayout(ui->verticalLayout);
    ui->widgetBottom->setLayout(ui->horizontalLayout);
    connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(oncursorPositionChanged()));

    QShortcut *shortcutOpen = new QShortcut(QKeySequence(tr("Ctrl+O","File|Open")),this);
    QShortcut *shortcutSave = new QShortcut(QKeySequence(tr("Ctrl+S","File|Save")),this);
    QShortcut *shortcutClose = new QShortcut(QKeySequence(tr("Ctrl+W","File|Close")),this);
    QShortcut *shortcutZoomin = new QShortcut(QKeySequence(tr("Ctrl+shift+=","File|Save")),this);
    QShortcut *shortcutZoomout = new QShortcut(QKeySequence(tr("Ctrl+shift+-","File|Save")),this);
    connect(shortcutOpen,&QShortcut::activated,[=](){
        on_btnOpen_clicked();
    });
    connect(shortcutSave,&QShortcut::activated,[=](){
        on_btnSave_clicked();
    });
    connect(shortcutClose,&QShortcut::activated,[=](){
        on_btnClose_clicked();
    });
    connect(shortcutZoomin,&QShortcut::activated,[=](){
        zoomIn();
    });
    connect(shortcutZoomout,&QShortcut::activated,[=](){
        zoomOut();
    });
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"),"D:/QT/",tr("Text (*.txt)"));
    ui->textEdit->clear();

    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
        qDebug()<<"file open error";
    }
    this->setWindowTitle(fileName+"-YZH记事本");
    QTextStream in(&file);

    while(!in.atEnd()){
        QString context=in.readLine();
        //qDebug()<<qPrintable(context);
        //ui->textEdit->setText(context);
        ui->textEdit->append(context);
    }
}
void Widget::on_btnSave_clicked()
{
    if(!file.isOpen()){
        QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),"D:/QT/untitled.txt",tr("Text (*.txt *.doc)"));

        file.setFileName(fileName);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            qDebug()<<"file open error";
        }
        this->setWindowTitle(fileName+"-YZH记事本");

    }
    QTextStream out(&file);
    QString context = ui->textEdit->toPlainText();
    out<<context;


}
void Widget::on_btnClose_clicked()
{

    ui->textEdit->clear();
    QMessageBox msgBox;
    int ret = QMessageBox::warning(this, tr("MyNoteBook"),
                                   tr("文档已被修改\n"
                                      "你想保存更改吗?"),
                                   QMessageBox::Save | QMessageBox::Discard
                                       | QMessageBox::Cancel,
                                   QMessageBox::Save);
    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        break;
    default:
        // should never be reached
        break;
    }




    if(file.isOpen()){
        file.close();

        this->setWindowTitle("MyNoteBook");
    }
}

void Widget::oncursorPositionChanged()
{

    QTextCursor cursor = ui->textEdit->textCursor();
    //qDebug()<<cursor.blockNumber()+1<<cursor.columnNumber()+1;
    QString blockNum  = QString::number(cursor.blockNumber()+1);
    QString columnNum  = QString::number(cursor.columnNumber()+1);
    const QString labelMes= "第"+blockNum+"行,"+"第"+columnNum+"列";
    ui->labelPosition->setText(labelMes);

    //设置当前行高亮
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection ext;
    ext.cursor = ui->textEdit->textCursor();//获取当前行
    QBrush qBrush(Qt::yellow);
    ext.format.setBackground(qBrush);//设置背景色
    ext.format.setProperty(QTextFormat::FullWidthSelection,true);//整行设置
    extraSelections.append(ext);
    ui->textEdit->setExtraSelections(extraSelections);
}

void Widget::zoomIn()
{
    QFont font = ui->textEdit->font();
    int fontSize = font.pointSize();//获得当前字体大小
    if(fontSize==-1)return;
    //改变字体大小，设置字体大小
    fontSize++;
    font.setPointSize(fontSize);
    ui->textEdit->setFont(font);
}

void Widget::zoomOut()
{
    QFont font = ui->textEdit->font();
    int fontSize = font.pointSize();//获得当前字体大小
    if(fontSize==-1)return;
    //改变字体大小，设置字体大小
    fontSize--;
    font.setPointSize(fontSize);
    ui->textEdit->setFont(font);
}




