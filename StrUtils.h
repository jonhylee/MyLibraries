/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		StrUtils.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-6
  *Description:		字符串工具类
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-6
       Author:		zhiqli
       Modification:创建文件
***********************************************/

#ifndef __STR_UTILS_HH__
#define __STR_UTILS_HH__

#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

/**********************************************
  *Summary: UTF-8转换为GB2312
  *Parameters:
       in pUtf8 传入UTF-8字符串
       out pGb2312 传出GB2312字符串
  *Return : no
***********************************************/
void U2G(const char* pUtf8, char* pGb2312);

/**********************************************
  *Summary: GB2312转换为UTF-8
  *Parameters:
       in pGb2312 传出GB2312字符串
       out pUtf8 传入UTF-8字符串
  *Return : no
***********************************************/
void G2U(const char* pGb2312, char* pUtf8);

/**********************************************
  *Summary: wstring 转为 string
  *Parameters:
       in strWs wstring字符串
       out no
  *Return : 转换成功的string字符串
***********************************************/
std::string ws2s(const std::wstring& strWs);

/**********************************************
  *Summary: string 转为 wstring
  *Parameters:
       in strWs string字符串
       out no
  *Return : 转换成功的wstring字符串
***********************************************/
std::wstring s2ws(const std::string& str);

/**********************************************
  *Summary: 去掉字符串中的左空格
  *Parameters:
       in pStr待处理字符串
       out pStr处理成功返回的字符串
  *Return : 转no
***********************************************/
void lTrim(char *pStr);

/**********************************************
  *Summary: 去掉字符串中的右空格
  *Parameters:
       in pStr待处理字符串
       out pStr处理成功返回的字符串
  *Return : 转no
***********************************************/
void rTrim(char *pStr);

/**********************************************
  *Summary: 去掉字符串中的左右空格
  *Parameters:
       in pStr待处理字符串
       out no
  *Return : 处理成功字符串
***********************************************/
std::string Trim(const char* pStr);

/**********************************************
  *Summary: 字符串分隔
  *Parameters:
       in strSrc 原字符串
	      strSplit 分隔符
       out vecDest 分隔后的字符串列表
  *Return : 成功true 错误false
***********************************************/
bool SplitString(const std::string &strSrc,const std::string &strSplit, std::vector<std::string> &vecDest);

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

/**********************************************
  *Summary: 将字符串转换成大写
  *Parameters:
       in str 原字符串
       out no
  *Return : no
***********************************************/
void ToUpperString(std::string &str);

/**********************************************
  *Summary: 将字符串转换成小写
  *Parameters:
       in str 原字符串
       out no
  *Return : no
***********************************************/
void ToLowerString(std::string &str);

/**********************************************
  *Summary: base64解码
  *Parameters:
       in str base64字符串
       out no
  *Return : 解码后的字符串
***********************************************/
std::string Base64Decode(const std::string& input);

/**********************************************
  *Summary: 获取一个随机字符串
  *Parameters:
       in iLen 字符串长度 
       out pRndChars 随机字符串
  *Return : no
***********************************************/
void RandChars(char *pRndChars, int iLen);

/**********************************************
  *Summary: 判断IP地址是否合法
  *Parameters:
       in pIp IP地址 
       out no
  *Return : 成功返回0
***********************************************/
int ValidateIpFormat(char *pIp);

/**********************************************
  *Summary: 判断字符串是否为数字
  *Parameters:
       in pIn 输入字符串
       out no
  *Return : 成功返回true
***********************************************/
bool IsNumString(char * pIn);

/**********************************************
  *Summary: 其他类型转换成string
  *Parameters:
       in value 输入值
       out no
  *Return : 转换后字符串
***********************************************/
template<typename T>
string toString(T value);

/**********************************************
  *Summary: 格式化为字符串
  *Parameters:
       in fmt 输入值
       out no
  *Return : 格式化后字符串
***********************************************/
string format(const char* fmt, ...); 

/**********************************************
  *Summary: 替换字符串中所有的特定字符串（循环替换，比如"12212"中"12″都替换成"21"，结果为"22211"）
  *Parameters:
       in str 输入字符串
	      old_value 需要替换的字符串
		  new_value 被替换的字符串
       out no
  *Return : 替换后的字符串
***********************************************/
string& replaceAll(string &str,const string &old_value,const string &new_value);

/**********************************************
  *Summary: 替换字符串中所有的特定字符串（循环替换，比如"12212"中"12″都替换成"21"，结果为"21221"）
  *Parameters:
       in str 输入字符串
	      old_value 需要替换的字符串
		  new_value 被替换的字符串
       out no
  *Return : 替换后的字符串
***********************************************/
string& replaceAllDistinct(string &str,const string &old_value,const string &new_value);
#endif
