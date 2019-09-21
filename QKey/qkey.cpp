#include "qkey.h"


#include <QDebug>
//#include <QDateTime>


QKey::QKey(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::QKeyClass)
{
	ui->setupUi(this);	
	setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint);
	setFixedSize(this->width(), this->height());
}

QKey::~QKey()
{

}

void QKey::on_keyButton_clicked()
{
	QString strMac, strCPU;

	strMac = ui->macEdit->text().remove('\n');
	strMac = strMac.remove(':');
	strMac = strMac.remove(' ');

	strCPU = ui->cpuEdit->text().remove(' ');
	strCPU = strCPU.remove('\n');

	unsigned int m_mac = 0;
	for (size_t i = 0; i < strMac.length(); i++)
	{
		m_mac += (unsigned int)strMac.toUtf8().at(i)*pow(7, i);
	}

	unsigned int m_cpu = 0;
	for (size_t i = 0; i < strCPU.length(); i++)
	{
		m_cpu += (unsigned int)strCPU.toUtf8().at(i)*pow(3, i);
	}

	unsigned int m_date = 0;
	QString time = ui->timeEdit->text().remove('\n');
	time = time.remove(' ');
	unsigned int m_year = time.section('/', 0, 0).toUInt();
	unsigned int m_month = time.section('/', 1, 1).toUInt();
	unsigned int m_day = time.section('/', 2, 2).toUInt();

	m_date += m_year * 987;
	m_date += m_month * 65;
	m_date += m_day*7;

	unsigned int key = m_cpu ^ m_date * m_mac;

//	qDebug() << "Key" << QString::number(key);

	ui->keyEdit->setText(QString::number(key));
}
