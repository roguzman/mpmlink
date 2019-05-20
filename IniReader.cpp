#include <iostream>
#include <Windows.h>
#include "IniReader.h"

CIniReader::CIniReader(LPCWSTR szFileName)
{
	// memset(m_szFileName, 0x00, 255);
	// memcpy(m_szFileName, szFileName, wcslen(szFileName));
	m_szFileName = szFileName;
}

int CIniReader::ReadInteger(LPCWSTR szSection, LPCWSTR szKey, int iDefaultValue)
{
	int iResult = GetPrivateProfileInt(szSection,  szKey, iDefaultValue, m_szFileName);	
	return iResult;
}

bool CIniReader::ReadBoolean(LPCWSTR szSection, LPCWSTR szKey, bool bolDefaultValue)
{
	LPWSTR szResult = L"";
	LPCWSTR szDefault = L"";
	bool bolResult;
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);	
	bolResult =  (wcscmp(szResult, L"True") == 0 || wcscmp(szResult, L"true") == 0) ? true : false;
	return bolResult;
}

LPCWSTR CIniReader::ReadString(LPCWSTR szSection, LPCWSTR szKey, const LPCWSTR szDefaultValue)
{
	LPWSTR szResult = new TCHAR[255];
	GetPrivateProfileString(szSection,  szKey, szDefaultValue, szResult, 255, m_szFileName);	
	return szResult;
}
