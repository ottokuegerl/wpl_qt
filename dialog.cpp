#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);  // Sets up the user interface for the specified widget

    m_types.insert("Graz", 8710);
    m_types.insert("Wien", 1010);
    m_types.insert("Knittelfeld", 8720);
    m_types.insert("Wolfpassing", 3424);
    m_types.insert("Goesing", 3221);

    ui->comboBox_city->addItems(m_types.keys());
    ui->comboBox_city->setCurrentIndex(3);   // Wien selected from map

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_city_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    int m = m_types.value(ui->comboBox_city->currentText());  // get plz from combobox
    ui->label_city->setText(QString::number(m));

}


void Dialog::on_pushButton_clickme_clicked()
{
    bool ok = false;

    int value = ui->lineEdit_age->text().toInt(&ok);

    if(!ok) ui->lineEdit_age->setText("0");

    int returnvalue = value * 365 * 24;

    ui->label_age2hours->setText(QString::number(returnvalue));

}

