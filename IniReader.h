#ifndef INIREADER_H
#define INIREADER_H
class CIniReader
{
public:
	CIniReader(LPCWSTR szFileName);	
	int ReadInteger(LPCWSTR szSection, LPCWSTR szKey, int iDefaultValue);
	float ReadFloat(LPCWSTR szSection, LPCWSTR szKey, float fltDefaultValue);
	bool ReadBoolean(LPCWSTR szSection, LPCWSTR szKey, bool bolDefaultValue);
	LPCWSTR ReadString(LPCWSTR szSection, LPCWSTR szKey, const LPCWSTR szDefaultValue);
private:
	LPCWSTR m_szFileName;
};
#endif//INIREADER_H
