#pragma once

#include <QtWidgets/QWidget>
#include "ui_qkey.h"

class QKey : public QWidget
{
	Q_OBJECT

public:
	QKey(QWidget *parent = Q_NULLPTR);
	~QKey();

private slots:
	void on_keyButton_clicked();

private:
	Ui::QKeyClass *ui;
};
