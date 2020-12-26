#ifndef CTURNTABLETHREAD_H
#define CTURNTABLETHREAD_H

#include <QThread>
#include <Windows.h>
#include <QList>
#include <QMutex>

enum TTWM {
    TT_HOME = 0,     // 0 Home
    TT_SPEED ,       // 1 Speed Mode
    TT_POS,          // 2 Postion Mode
    TT_SETACC,       // 3 set Acc
    TT_SETDEC,       // 4 set Dec
    TT_SETMAX,        // 5 set MaxSpeed
	TT_HALT,		 // 6 Halt
	TT_STOP
};

struct _TurnTableWorkCmd_ST {
    TTWM workMode;  // SEE TTWM
	uint16_t Axis;      // 0 1 2
    qint32 speed;
    qint32 acc;
    qint32 dec;
    qint32 pos;
    qint32 relativestep;
};

struct TurnTableStatus_ST {
    qint32 pos[3];
    qint32 acc[3];
    qint32 dec[3];
	qint32 speed[3];
    qint32 maxspeed[3];
    quint8 workmode[3];
    quint8 direction[3];
    quint8 zero[3];
    quint8 neglimit[3];
    quint8 poslimit[3];
    quint8 runningstatus[3];
};


class CTurnTableThread : public QThread
{
    Q_OBJECT
public:
    explicit CTurnTableThread(QObject * parent = nullptr);
    ~CTurnTableThread();

    void try_quit();
    void addCmd(_TurnTableWorkCmd_ST & cmd);

Q_SIGNALS:
    void TurnTableStatus(TurnTableStatus_ST);
	void info(QString);

protected:
    void run() override;

protected slots:
    int sltConnect();
    void sltDisconnect();
    /*void sltGoPosition();
    void sltPosStop();*/

private:
    bool m_bQuit;
    QMutex cmdLock;
    QList<_TurnTableWorkCmd_ST> m_cmds;
	_TurnTableWorkCmd_ST m_lastHomeCmds[3];
	TTWM m_lastCmds[3];
};

#endif // CTURNTABLETHREAD_H
