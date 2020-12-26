#ifndef QTURNTABLEDLG_H
#define QTURNTABLEDLG_H

#include <QDialog>
#include "CTurnTableThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QTurnTableDlg; }
QT_END_NAMESPACE



class QTurnTableDlg : public QDialog
{
    Q_OBJECT

public:
    QTurnTableDlg(QWidget *parent = nullptr);
    ~QTurnTableDlg();


protected slots:
    void sltHS1ValueChanged(int);
    void sltGoPosition1();
    void sltPosStop1();
	void sltHS2ValueChanged(int);
	void sltGoPosition2();
	void sltPosStop2();
	void sltHS3ValueChanged(int);
	void sltGoPosition3();
	void sltPosStop3();
	void sltHalt();
	void sltGoZero();

	void sltInfo(QString);

    void sltGetTurnTableStatus(TurnTableStatus_ST tts);

private:
    Ui::QTurnTableDlg *ui;
    CTurnTableThread turnTable;
};
#endif // QTURNTABLEDLG_H
