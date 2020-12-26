#include "CTurnTableThread.h"
#include <QDebug>
#include <QSettings>
#include "MT_API.h"
#include "commontools.h"

CTurnTableThread::CTurnTableThread(QObject * parent)
    :QThread(parent)
    ,m_bQuit(false)
{
    qRegisterMetaType<TurnTableStatus_ST>("TurnTableStatus_ST");
    MT_Init();
}

CTurnTableThread::~CTurnTableThread()
{
    MT_DeInit();
}

int CTurnTableThread::sltConnect()
{
    QSettings configIni(PROJECT_INI_NAME, QSettings::IniFormat);
    QString turntableAddress = configIni.value("Config/TurnTableAddress").toString();
    QStringList addrip = turntableAddress.split(".");
    quint8 ip[4] = {192u,168u,1,7};
    for(int i = 0;i<addrip.count();i++){
        ip[i] = addrip.at(i).toUInt() & 0xff;
    }
    return MT_Open_Net(ip[0],ip[1],ip[2],ip[3],8888);

}

void CTurnTableThread::sltDisconnect()
{
    MT_Close_Net();
}

void CTurnTableThread::try_quit()
{
    m_bQuit = true;
}

void CTurnTableThread::addCmd(_TurnTableWorkCmd_ST & cmd)
{
    cmdLock.lock();
    m_cmds.append(cmd);
    cmdLock.unlock();
}

void CTurnTableThread::run()
{
    TurnTableStatus_ST tts;
	int ret = sltConnect();
	if (ret != 0) {
		emit info(tr("Connect Failed"));
	}
    while(!m_bQuit){
        quint16 AObj = 0;
        for(AObj = 0; !m_bQuit && AObj < 3;AObj++){
			MT_Get_Axis_Software_P_Now(AObj,&(tts.pos[AObj]));
            MT_Get_Axis_Acc(AObj,&(tts.acc[AObj]));
            MT_Get_Axis_Dec(AObj,&(tts.dec[AObj]));
            MT_Get_Axis_Position_V_Max(AObj,&(tts.maxspeed[AObj]));
            //MT_Get_Axis_Mode(AObj,&(tts.workmode[AObj]));
			MT_Get_Axis_V_Now(AObj, &(tts.speed[AObj]));
            MT_Get_Axis_Status(AObj,&(tts.runningstatus[AObj])
                               ,&(tts.direction[AObj])
                               ,&(tts.neglimit[AObj])
                               ,&(tts.poslimit[AObj])
                               ,&(tts.zero[AObj])
                               ,&(tts.workmode[AObj]));


        }
        if(!m_bQuit && AObj>=3){
            emit TurnTableStatus(tts);
        }
		cmdLock.lock();
		for (int i = 0; i < m_cmds.size(); i++) {
			_TurnTableWorkCmd_ST cmd =  m_cmds.at(i);
			AObj = cmd.Axis;
			if (AObj < 3) {
				m_lastCmds[AObj] = cmd.workMode;
			}
			else {
				continue;
			}
			switch (cmd.workMode) {
			case TT_STOP:
			{
				MT_Set_Axis_Position_Stop(AObj);
				break;
			}
			case TT_HOME:     // 0 Home
			{
				m_lastHomeCmds[AObj] = cmd;
				MT_Set_Axis_Mode_Home(AObj);
				MT_Set_Axis_Home_Acc(AObj, cmd.acc);
				MT_Set_Axis_Home_Dec(AObj, cmd.dec);
				MT_Set_Axis_Home_V(AObj, cmd.speed);
				break;
			}
			case TT_SPEED:       // 1 Speed Mode
			{
				break;
			}
			case TT_POS:          // 2 Postion Mode
			{
				MT_Set_Axis_Mode_Position(AObj);
				MT_Set_Axis_Position_V_Max(AObj, cmd.speed);
				MT_Set_Axis_Position_Acc(AObj, cmd.acc);
				MT_Set_Axis_Position_Dec(AObj, cmd.dec);
				MT_Set_Axis_Position_P_Target_Abs(AObj, cmd.pos);
				break;
			}
			case TT_SETACC:       // 3 set Acc
			{
				break;
			}
			case TT_SETDEC:       // 4 set Dec
			{
				break;
			}
			case TT_SETMAX:        // 5 set MaxSpeed
			{
				break;
			}
			case TT_HALT:			 // 6 Halt
			{
				MT_Set_Axis_Halt(AObj);
				break;
			}
			}
		}
		m_cmds.clear();
		cmdLock.unlock();
		QThread::msleep(100);

    }
	sltDisconnect();
}
