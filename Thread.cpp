#include "Thread.h"

Thread::Thread(void)
{
}

Thread::~Thread(void)
{
	Release();
}

//SetUp(함수 포인터,함수인자)
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

//쓰레드 시작
bool Thread::Start()
{
	if (m_hThred != NULL)
	{
		ResumeThread(m_hThred);
	}
	return true;
}
//쓰레드 일시정지
bool Thread::Stop()
{
	if (m_hThred != NULL)
	{
		SuspendThread(m_hThred);
	}
	return true;
}
//쓰레드 실행중인지 검사
//실행중이면 true 아니면 false
bool Thread::IsGo()
{
	GetExitCodeThread(m_hThred, &m_ExitCode);
	if(m_ExitCode == STILL_ACTIVE)
	{
		return true;
	}
	return false;
}
//쓰레드 강제 종료
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
	
