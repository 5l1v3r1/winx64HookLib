// HookLibR3.cpp : �������̨Ӧ�ó������ڵ㡣
//

//��� ��װ��x64Hook �� 2019/09/13

#include "stdafx.h"
#include <Windows.h>
#include "HookEngine.h"

ULONG64 callback(Hook * hook, PRegisterContext pRegisterContext)
{
	printf("-------------------------------\r\n");
	return 0;
}

int main()
{
	//����0x000007FEFD913360 ��ַ �������Լ��޸�
	ULONG64 addr  = (ULONG64)0x000007FEFD913360;
	//HOOKǰ
	ULONG64 x = (ULONG64)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtOpenProcess");
	auto engine = HookEngine::GetInstance();
	Hook * hook = new Hook(addr, callback, 15, addr+15, HOOK_E9);
	engine->AddHook(hook);

	//Hook��
	ULONG64 y = (ULONG64)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtOpenProcess");
	HookEngine::DestoryInstance();

	//Hook�ͷź� �Ƿ�����
	ULONG64 z = (ULONG64)GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtOpenProcess");
	/*
	//HWND hwnd = FindWindowA("#32770", "ע��С����   By:С_�� QQ:471194425");
	//HWND hwnd = FindWindowA("Chrome_WidgetWin_1", "�±�ǩҳ - Google Chrome");
	HWND hwnd = FindWindowA("Q360SafeMainClass", "360��ȫ��ʿ ");
	//0x0000000000210744
	SendMessageA(hwnd, WM_CLOSE, 0, 0);
	*/
	getchar();
	return 0;
}

