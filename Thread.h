#ifndef __THREAD_H__
#define __THREAD_H__
#include "Global.h"
class Thread
{
private:
	DWORD	m_ThredID; ///< 스레드 아이디 저장 변수
	DWORD	m_ExitCode; ///<  종료코드 저장
	HANDLE	m_hThred;	///<  스레드 핸들

public:
	Thread(void);
	virtual ~Thread(void);

	bool SetUp(PTHREAD_START_ROUTINE pFunc, LPVOID pFuncPrameter); ///<  셋업
	bool Start();				///< 시작
	bool Stop();				//일시 정지
	bool IsGo();				//실행중인지 검사
	bool CompulsionFinish();	///< 강제로 작업스레드 종료
private:
	void Release();				///< 해제
// 	inline HANDLE GetThread()
// 	{
// 		return m_hThred; ///< 스레드 핸들얻기
// 	}
	
};

#endif