#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    hostLabel = new QLabel(tr("Hostname:"));
    hostLineEdit = new QLineEdit;
    ipLabel = new QLabel;
    ipLabel->setText("Ip:");
    ipLineEdit = new QLineEdit;
    detailsPushButton = new QPushButton;
    detailsPushButton->setText("Detials");
    mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel,0,0);
    mainLayout->addWidget(hostLineEdit,0,1);
    mainLayout->addWidget(ipLabel,1,0);
    mainLayout->addWidget(ipLineEdit,1,1);
    mainLayout->addWidget(detailsPushButton,2,0,1,2);
    setLayout(mainLayout);

    getHostInformation();
    connect(detailsPushButton,SIGNAL(clicked(bool)),this,SLOT(slotDetails()));

}

Widget::~Widget()
{

}


void Widget::getHostInformation()
{
    QString hostname =QHostInfo:: localHostName();
    hostLineEdit->setText(hostname);
    QHostInfo hostInfo =QHostInfo:: fromName(hostname);
    QList<QHostAddress> listAddress = hostInfo.addresses();
     if(!listAddress.empty())
     {
         ipLineEdit->setText(listAddress.at(2).toString());
     }
}

void Widget::slotDetails()
{
    QString  det = "";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for(int i = 0;i<list.count();++i)
    {
        QNetworkInterface interface = list.at(i);
        det = det + tr("dev:") + interface.name()+"\n";
        det = det + tr("dev address:") + interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for(int j =1;j<entryList.count();++j)
        {
            QNetworkAddressEntry entry = entryList.at(j);
            det = det +"\t"+tr("ip adress:")+entry.ip().toString()+"\n";
            det = det+"\t" +tr("subnet mask:")+entry.netmask().toString()+"\n";
            det = det+"\t"+tr("broadcast address:") + entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,tr("details"),det);
}
