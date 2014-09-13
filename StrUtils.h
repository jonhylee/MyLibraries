/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		StrUtils.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-6
  *Description:		�ַ���������
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-6
       Author:		zhiqli
       Modification:�����ļ�
***********************************************/

#ifndef __STR_UTILS_HH__
#define __STR_UTILS_HH__

#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

/**********************************************
  *Summary: UTF-8ת��ΪGB2312
  *Parameters:
       in pUtf8 ����UTF-8�ַ���
       out pGb2312 ����GB2312�ַ���
  *Return : no
***********************************************/
void U2G(const char* pUtf8, char* pGb2312);

/**********************************************
  *Summary: GB2312ת��ΪUTF-8
  *Parameters:
       in pGb2312 ����GB2312�ַ���
       out pUtf8 ����UTF-8�ַ���
  *Return : no
***********************************************/
void G2U(const char* pGb2312, char* pUtf8);

/**********************************************
  *Summary: wstring תΪ string
  *Parameters:
       in strWs wstring�ַ���
       out no
  *Return : ת���ɹ���string�ַ���
***********************************************/
std::string ws2s(const std::wstring& strWs);

/**********************************************
  *Summary: string תΪ wstring
  *Parameters:
       in strWs string�ַ���
       out no
  *Return : ת���ɹ���wstring�ַ���
***********************************************/
std::wstring s2ws(const std::string& str);

/**********************************************
  *Summary: ȥ���ַ����е���ո�
  *Parameters:
       in pStr�������ַ���
       out pStr����ɹ����ص��ַ���
  *Return : תno
***********************************************/
void lTrim(char *pStr);

/**********************************************
  *Summary: ȥ���ַ����е��ҿո�
  *Parameters:
       in pStr�������ַ���
       out pStr����ɹ����ص��ַ���
  *Return : תno
***********************************************/
void rTrim(char *pStr);

/**********************************************
  *Summary: ȥ���ַ����е����ҿո�
  *Parameters:
       in pStr�������ַ���
       out no
  *Return : ����ɹ��ַ���
***********************************************/
std::string Trim(const char* pStr);

/**********************************************
  *Summary: �ַ����ָ�
  *Parameters:
       in strSrc ԭ�ַ���
	      strSplit �ָ���
       out vecDest �ָ�����ַ����б�
  *Return : �ɹ�true ����false
***********************************************/
bool SplitString(const std::string &strSrc,const std::string &strSplit, std::vector<std::string> &vecDest);

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

/**********************************************
  *Summary: ���ַ���ת���ɴ�д
  *Parameters:
       in str ԭ�ַ���
       out no
  *Return : no
***********************************************/
void ToUpperString(std::string &str);

/**********************************************
  *Summary: ���ַ���ת����Сд
  *Parameters:
       in str ԭ�ַ���
       out no
  *Return : no
***********************************************/
void ToLowerString(std::string &str);

/**********************************************
  *Summary: base64����
  *Parameters:
       in str base64�ַ���
       out no
  *Return : �������ַ���
***********************************************/
std::string Base64Decode(const std::string& input);

/**********************************************
  *Summary: ��ȡһ������ַ���
  *Parameters:
       in iLen �ַ������� 
       out pRndChars ����ַ���
  *Return : no
***********************************************/
void RandChars(char *pRndChars, int iLen);

/**********************************************
  *Summary: �ж�IP��ַ�Ƿ�Ϸ�
  *Parameters:
       in pIp IP��ַ 
       out no
  *Return : �ɹ�����0
***********************************************/
int ValidateIpFormat(char *pIp);

/**********************************************
  *Summary: �ж��ַ����Ƿ�Ϊ����
  *Parameters:
       in pIn �����ַ���
       out no
  *Return : �ɹ�����true
***********************************************/
bool IsNumString(char * pIn);

/**********************************************
  *Summary: ��������ת����string
  *Parameters:
       in value ����ֵ
       out no
  *Return : ת�����ַ���
***********************************************/
template<typename T>
string toString(T value);

/**********************************************
  *Summary: ��ʽ��Ϊ�ַ���
  *Parameters:
       in fmt ����ֵ
       out no
  *Return : ��ʽ�����ַ���
***********************************************/
string format(const char* fmt, ...); 

/**********************************************
  *Summary: �滻�ַ��������е��ض��ַ�����ѭ���滻������"12212"��"12�嶼�滻��"21"�����Ϊ"22211"��
  *Parameters:
       in str �����ַ���
	      old_value ��Ҫ�滻���ַ���
		  new_value ���滻���ַ���
       out no
  *Return : �滻����ַ���
***********************************************/
string& replaceAll(string &str,const string &old_value,const string &new_value);

/**********************************************
  *Summary: �滻�ַ��������е��ض��ַ�����ѭ���滻������"12212"��"12�嶼�滻��"21"�����Ϊ"21221"��
  *Parameters:
       in str �����ַ���
	      old_value ��Ҫ�滻���ַ���
		  new_value ���滻���ַ���
       out no
  *Return : �滻����ַ���
***********************************************/
string& replaceAllDistinct(string &str,const string &old_value,const string &new_value);
#endif
