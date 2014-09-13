#include "StrUtils.h"
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static const char rstr[128] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62,    0, 0, 0, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0,
	0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 0, 0, 0, 0
};

void U2G(const char* pUtf8, char* pGb2312)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, pUtf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_UTF8, 0, pUtf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	memset(pGb2312, 0, sizeof(pGb2312));
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, pGb2312, len, NULL, NULL);
	if(wstr) delete[] wstr;
}

void G2U(const char* gb2312, char* utf8)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	memset(utf8, 0, sizeof(utf8));
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8, len, NULL, NULL);
	if(wstr) delete[] wstr;
}

std::string ws2s(const std::wstring& strWs)
{
	std::string curLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = strWs.c_str();
	size_t _Dsize = 2 * strWs.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest,0,_Dsize);
	wcstombs(_Dest,_Source,_Dsize);
	std::string result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

std::wstring s2ws(const std::string& str)
{
	setlocale(LC_ALL, "chs"); 
	const char* _Source = str.c_str();
	size_t _Dsize = str.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest,_Source,_Dsize);
	std::wstring result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, "C");
	return result;
}

void lTrim(char *pStr)
{
	char *pTmp = pStr;
	while(*pTmp == ' ' || *pTmp == '\t'){*pTmp++;}
	strcpy(pStr,pTmp);
}

void rTrim(char *pStr)
{
	int iLen = strlen(pStr)-1;
	while((pStr[iLen] == ' ' || pStr[iLen] == '\t') && iLen >= 0){iLen--;}
	pStr[iLen+1] = '\0';
}

std::string Trim(const char *pStr)
{
	if (NULL == pStr || 0 == strlen(pStr))
	{
		return std::string("");
	}

	int iLen = strlen(pStr) + 1;
	char* pTmp = (char*)malloc(sizeof(char) * iLen);
	memset(pTmp, 0, iLen);
	strncpy(pTmp, pStr, iLen-1);
	lTrim(pTmp);
	rTrim(pTmp);
	std::string strRet = std::string(pTmp);
	free(pTmp);
	return strRet;
}

bool SplitString(const std::string &strSrc,
				 const std::string &strSplit,
				 std::vector<std::string> &vecDest)
{
	if(strSrc.size()==0)
	{   
		return false;
	}   

	size_t oldPos,newPos;
	oldPos=0;
	newPos=0;
	std::string tempData;
	while(1)
	{   
		newPos=strSrc.find(strSplit,oldPos);
		if(newPos!=std::string::npos)
		{   
			tempData = strSrc.substr(oldPos,newPos-oldPos);
			vecDest.push_back(tempData);
			oldPos=newPos+strSplit.size();
		}   
		else if(oldPos<=strSrc.size())
		{   
			tempData= strSrc.substr(oldPos);
			vecDest.push_back(tempData);
			break;
		}   
		else
		{   
			break;
		}   
	}   

	return true;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) 
	{
		elems.push_back(item);
	}
	return elems;
}

void ToUpperString(std::string &str)
{  
	transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);  
}

void ToLowerString(std::string &str)
{  
	transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);  
}

std::string Base64Decode(const std::string& input)
{
	unsigned int i = 0, l = static_cast<unsigned int>(input.length());
	std::string output;
	output.resize((l / 4 + 1) * 3);
	output = "";
	while (i < l)
	{
		while (i < l && (input[i] == 13 || input[i] == 10))
			i++;
		if (i < l)
		{
			if(i + 3 >= l)return "";

			if(input[i] < 0 || input[i + 1] < 0 || input[i + 2] < 0 || input[i + 3] < 0)return "";
			char b1 = (char)((rstr[(int)input[i]] << 2 & 0xfc) + (rstr[(int)input[i + 1]] >> 4 & 0x03));
			output += b1;

			if (input[i + 2] != '=')
			{
				char b2 = (char)((rstr[(int)input[i + 1]] << 4 & 0xf0) + (rstr[(int)input[i + 2]] >> 2 & 0x0f));
				output += b2;
			}

			if (input[i + 3] != '=')
			{
				char b3 = (char)((rstr[(int)input[i + 2]] << 6 & 0xc0) + rstr[(int)input[i + 3]]);
				output += b3;
			}
			i += 4;
		}
	}
	return output;
}

void RandChars(char *pRndChars, int iLen)
{
	char chs[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int iRnd=0;
	static int iSRnd=0;
	iSRnd++;
	if(iSRnd>100000) iSRnd=0;
	srand((unsigned)time(NULL)+ iSRnd);
	for(int i = 0; i < iLen; i++){
		iRnd = rand() % 36;
		pRndChars[i] = chs[iRnd];
	}
}

#if _LINUX_

int ValidateIpFormat(char *pIp)
{
	int iLen = strlen(pIp);
	int iIpV6Flag = 0;
	int iDotCnt = 0;

	for (int i=0; i<iLen; i++)
	{
		if ( ! ( (pIp[i]<='9' && pIp[i]>='0') 
			|| (pIp[i]=='.') 
			|| (pIp[i]==':') 
			|| (pIp[i]<='f' && pIp[i]>='a') 
			|| (pIp[i]<='F' && pIp[i]>='A') ) )
		{
			return 1;
		}

		if (pIp[i]==':')
		{
			iIpV6Flag = 1;
		}
		else if (pIp[i]=='.')
		{
			iDotCnt ++;
		}
	}
	if (! iIpV6Flag && iDotCnt != 3)
	{
		return 2;
	}

	struct addrinfo hints;
	struct addrinfo *res;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	res = NULL;
	int intRet = getaddrinfo(pIp, NULL, &hints, &res);
	if (res)
	{
		freeaddrinfo(res);
	}

	return intRet;
}

#endif

bool IsNumString(char * pIn)
{
	int iLen;
	iLen=strlen(pIn);

	for(int i=0;i<iLen;i++)
	{
		if(*(pIn+i)<0x30||*(pIn+i)>0x39)
		{
			return false;
		}
	}
	return true;
}

template<typename T>
string toString(T value)
{
	ostringstream ss;
	ss << value;
	return ss.str();
}

string format(const char* fmt, ...)
{
// 	va_list args;
// 	char* buffer = NULL;
// 	va_start(args, fmt);
// 	int rc = vasprintf(&buffer, fmt, args);
// 	va_end(args);
// 	string result;
// 	if (rc >= 0) {
// 		result = buffer;
// 	}
// 	if (buffer != NULL) {
// 		free(buffer);
// 	}
// 	return result;
	return "";
}

string& replaceAll(string &str,const string &old_value,const string &new_value)  
{   
	while(true)   
	{   
		string::size_type pos(0); 

		if( (pos = str.find(old_value)) != string::npos ) 
		{
			str.replace(pos,old_value.length(),new_value);   
		}
		else   
		{
			break;   
		}
	}   

	return str;   
}   

string& replaceAllDistinct(string &str,const string &old_value,const string &new_value)   
{   
	for(string::size_type pos = 0; pos != string::npos; pos += new_value.length())   
	{   
		if( (pos = str.find(old_value,pos)) != string::npos )   
		{
			str.replace(pos,old_value.length(),new_value);   
		}
		else   
		{
			break;   
		}
	}   

	return   str;   
}   