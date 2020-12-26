#include "QTurnTableDlg.h"
#include "ui_QTurnTableDlg.h"
#include "MT_API.h"
#include <QMessageBox>
#include <QTimer>

QString PROJECT_INI_NAME = "./TurnTableDlg.ini";

QTurnTableDlg::QTurnTableDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QTurnTableDlg)
{
    ui->setupUi(this);

	
	connect(&turnTable, SIGNAL(TurnTableStatus(TurnTableStatus_ST)), this, SLOT(sltGetTurnTableStatus(TurnTableStatus_ST)));
	connect(&turnTable, SIGNAL(info(QString)), this, SLOT(sltInfo(QString)));
	turnTable.start();
}

void QTurnTableDlg::sltInfo(QString str)
{
	ui->lbInfo->setText(str);
}

QTurnTableDlg::~QTurnTableDlg()
{
//    MT_DeInit();
	turnTable.try_quit();
	turnTable.wait();
    delete ui;
}



void QTurnTableDlg::sltGetTurnTableStatus(TurnTableStatus_ST tts)
{
    ui->lbAcc_1->setText(QString::number(tts.acc[0] / 1600));
    ui->lbDec_1->setText(QString::number(tts.dec[0] / 1600));
    ui->lbMax_1->setText(QString::number(tts.maxspeed[0] / 1600));
    ui->lbSpeed_1->setText(QString::number(tts.speed[0] / 1600));
    ui->lbPos_1->setText(QString::number(tts.pos[0] / 1600));
    ui->lbDirection_1->setText(QString::number(tts.direction[0]));
    ui->lbZero_1->setText(QString::number(tts.zero[0]));
    ui->lbPosLimit_1->setText(QString::number(tts.poslimit[0]));
    ui->lbNegLimit_1->setText(QString::number(tts.neglimit[0]));
    ui->lbStatus_1->setText(QString::number(tts.runningstatus[0]));
    ui->lbWorkMode_1->setText(QString::number(tts.workmode[0]));
	ui->pbAng_1->setValue(tts.pos[0] / 1600);

    ui->lbAcc_2->setText(QString::number(tts.acc[1] / 1600));
    ui->lbDec_2->setText(QString::number(tts.dec[1] / 1600));
    ui->lbMax_2->setText(QString::number(tts.maxspeed[1] / 1600));
    ui->lbSpeed_2->setText(QString::number(tts.speed[1] / 1600));
    ui->lbPos_2->setText(QString::number(tts.pos[1] / 1600));
    ui->lbDirection_2->setText(QString::number(tts.direction[1]));
    ui->lbZero_2->setText(QString::number(tts.zero[1]));
    ui->lbPosLimit_2->setText(QString::number(tts.poslimit[1]));
    ui->lbNegLimit_2->setText(QString::number(tts.neglimit[1]));
    ui->lbStatus_2->setText(QString::number(tts.runningstatus[1]));
    ui->lbWorkMode_2->setText(QString::number(tts.workmode[1]));
	ui->pbAng_2->setValue(tts.pos[1]/1600);

    ui->lbAcc_3->setText(QString::number(tts.acc[2] / 1600));
    ui->lbDec_3->setText(QString::number(tts.dec[2] / 1600));
    ui->lbMax_3->setText(QString::number(tts.maxspeed[2] / 1600));
    ui->lbSpeed_3->setText(QString::number(tts.speed[2] / 1600));
    ui->lbPos_3->setText(QString::number(tts.pos[2] / 1600));
    ui->lbDirection_3->setText(QString::number(tts.direction[2]));
    ui->lbZero_3->setText(QString::number(tts.zero[2]));
    ui->lbPosLimit_3->setText(QString::number(tts.poslimit[2]));
    ui->lbNegLimit_3->setText(QString::number(tts.neglimit[2]));
    ui->lbStatus_3->setText(QString::number(tts.runningstatus[2]));
    ui->lbWorkMode_3->setText(QString::number(tts.workmode[2]));
	ui->pbAng_3->setValue(tts.pos[2] / 1600);
}

void QTurnTableDlg::sltHS1ValueChanged(int value)
{
	ui->sbAxis_1->setValue(value);
}
void QTurnTableDlg::sltGoPosition1()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_POS;
	cmd.Axis = 0;
	cmd.pos = ui->sbAxis_1->value()* 1600;
	cmd.speed = ui->leMaxSpeed_1->text().toInt()*1600;
	cmd.acc = ui->leAcc_1->text().toInt() * 1600;
	cmd.dec = ui->leDec_1->text().toInt() * 1600;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltPosStop1()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_STOP;
	cmd.Axis = 0;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltHS2ValueChanged(int value)
{
	ui->sbAxis_2->setValue(value);
}
void QTurnTableDlg::sltGoPosition2()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_POS;
	cmd.Axis = 1;
	cmd.pos = ui->sbAxis_2->value() * 1600;
	cmd.speed = ui->leMaxSpeed_2->text().toInt() * 1600;
	cmd.acc = ui->leAcc_2->text().toInt() * 1600;
	cmd.dec = ui->leDec_2->text().toInt() * 1600;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltPosStop2()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_STOP;
	cmd.Axis = 1;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltHS3ValueChanged(int value)
{
	ui->sbAxis_3->setValue(value);
}


void QTurnTableDlg::sltHalt()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_HALT;
	cmd.Axis = 0;
	turnTable.addCmd(cmd);
	cmd.Axis = 1;
	turnTable.addCmd(cmd);
	cmd.Axis = 2;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltGoZero()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_HOME;
	cmd.Axis = 0;
	cmd.speed = ui->leMaxSpeed_1->text().toInt() * 1600;
	if (ui->lbPos_1->text().toInt() < 0)
		cmd.speed = abs(cmd.speed);
	else {
		cmd.speed = -abs(cmd.speed);
	}
	cmd.acc = ui->leAcc_1->text().toInt() * 1600;
	cmd.dec = ui->leDec_1->text().toInt() * 1600;
	turnTable.addCmd(cmd);

	cmd.Axis = 1;
	cmd.speed = ui->leMaxSpeed_2->text().toInt() * 1600;
	if (ui->lbPos_2->text().toInt() < 0)
		cmd.speed = abs(cmd.speed);
	else {
		cmd.speed = -abs(cmd.speed);
	}
	cmd.acc = ui->leAcc_2->text().toInt() * 1600;
	cmd.dec = ui->leDec_2->text().toInt() * 1600;
	turnTable.addCmd(cmd);

	cmd.Axis = 2;
	cmd.speed = ui->leMaxSpeed_3->text().toInt() * 1600;
	if (ui->lbPos_3->text().toInt() < 0)
		cmd.speed = abs(cmd.speed);
	else {
		cmd.speed = -abs(cmd.speed);
	}
	cmd.acc = ui->leAcc_3->text().toInt() * 1600;
	cmd.dec = ui->leDec_3->text().toInt() * 1600;
	turnTable.addCmd(cmd);
}


void QTurnTableDlg::sltGoPosition3()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_POS;
	cmd.Axis = 2;
	cmd.pos = ui->sbAxis_3->value() * 1600;
	cmd.speed = ui->leMaxSpeed_3->text().toInt() * 1600;
	cmd.acc = ui->leAcc_3->text().toInt() * 1600;
	cmd.dec = ui->leDec_3->text().toInt() * 1600;
	turnTable.addCmd(cmd);
}
void QTurnTableDlg::sltPosStop3()
{
	_TurnTableWorkCmd_ST cmd;
	cmd.workMode = TT_STOP;
	cmd.Axis = 2;
	turnTable.addCmd(cmd);
}



