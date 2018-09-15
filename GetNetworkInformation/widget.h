#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void getHostInformation();

public slots:
    void slotDetails();

private:
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QPushButton *detailsPushButton;
    QGridLayout *mainLayout;
};

#endif // WIDGET_H
