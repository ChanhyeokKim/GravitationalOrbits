#include "Thread.h"

Thread::Thread(void)
{
}

Thread::~Thread(void)
{
	Release();
}

//SetUp(�Լ� ������,�Լ�����)
bool Thread::SetUp(PTHREAD_START_ROUTINE pFunc, LPVOID pFuncPrameter)
{
	m_hThred = CreateThread(NULL, 0, pFunc, pFuncPrameter, CREATE_SUSPENDED, &m_ThredID);
	if(m_hThred == NULL)
	{
		MessageBox(DXUTGetHWND(),L"Thread SetUp() function error",L"Error",MB_OK);
		return false;
	}
	return true;
}

//������ ����
bool Thread::Start()
{
	if (m_hThred != NULL)
	{
		ResumeThread(m_hThred);
	}
	return true;
}
//������ �Ͻ�����
bool Thread::Stop()
{
	if (m_hThred != NULL)
	{
		SuspendThread(m_hThred);
	}
	return true;
}
//������ ���������� �˻�
//�������̸� true �ƴϸ� false
bool Thread::IsGo()
{
	GetExitCodeThread(m_hThred, &m_ExitCode);
	if(m_ExitCode == STILL_ACTIVE)
	{
		return true;
	}
	return false;
}
//������ ���� ����
bool Thread::CompulsionFinish()
{
	if (m_hThred == NULL)
	{
		return false;
	}

	if(GetExitCodeThread(m_hThred, &m_ExitCode))
	{
		
		TerminateThread(m_hThred, m_ExitCode);
		Sleep(100);
		Release();
		return true;
	}

	return false;
}

void Thread::Release()
{
	if (m_hThred != NULL)
	{
		CloseHandle(m_hThred);
	}
}
	
