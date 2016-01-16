#ifndef __THREAD_H__
#define __THREAD_H__
#include "Global.h"
class Thread
{
private:
	DWORD	m_ThredID; ///< ������ ���̵� ���� ����
	DWORD	m_ExitCode; ///<  �����ڵ� ����
	HANDLE	m_hThred;	///<  ������ �ڵ�

public:
	Thread(void);
	virtual ~Thread(void);

	bool SetUp(PTHREAD_START_ROUTINE pFunc, LPVOID pFuncPrameter); ///<  �¾�
	bool Start();				///< ����
	bool Stop();				//�Ͻ� ����
	bool IsGo();				//���������� �˻�
	bool CompulsionFinish();	///< ������ �۾������� ����
private:
	void Release();				///< ����
// 	inline HANDLE GetThread()
// 	{
// 		return m_hThred; ///< ������ �ڵ���
// 	}
	
};

#endif