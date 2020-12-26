#ifndef COMMONTOOLS_H
#define COMMONTOOLS_H
#include <QObject>
#include <QString>
#include <Windows.h>
extern QString PROJECT_INI_NAME;

WORD CalcCRC16(BYTE *pbDataBuf, DWORD dwNumOfBytes);

#endif // COMMONTOOLS_H
