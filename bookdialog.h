#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>

namespace Ui {
class BookDialog;
}

class BookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookDialog(QString type ,QWidget *parent = nullptr);
    ~BookDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BookDialog *ui;
    QString type;
};

#endif // BOOKDIALOG_H
