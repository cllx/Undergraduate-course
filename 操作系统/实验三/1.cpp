#include <stdio.h>
#include <windows.h>
#define MaxCount 9000000  // 循环次数要很大，可多次尝试一些值
int i = 0;
CRITICAL_SECTION cs;
DWORD __stdcall fun1( LPVOID p1)
{
	for( int j =0 ;j < MaxCount;j++){
		::EnterCriticalSection(&cs);
		i++;
		::LeaveCriticalSection(&cs);
	}
	return 0;
}

DWORD __stdcall  fun2( LPVOID p1)
{
	for( int j =0 ;j < MaxCount;j++){
		::EnterCriticalSection(&cs);
		i--;
		::LeaveCriticalSection(&cs);
	}
	return 0;
}


int main()
{
	DWORD id1,id2;
	HANDLE hThread[2];
	::InitializeCriticalSection(&cs);
	hThread[0] = ::CreateThread(0,0,fun1,0,0,&id1);
	hThread[1] = ::CreateThread(0,0,fun2,0,0,&id2);
	::WaitForMultipleObjects(2,hThread,1,INFINITE);
	printf("i = %d\n",i);
	::DeleteCriticalSection(&cs);
	getchar();
	return 0;
}
