/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		Base64.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-11
  *Description:		Base64加密解密类
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-11
       Author:		zhiqli
       Modification:创建文件
***********************************************/

#ifndef __BASE64_H__
#define __BASE64_H__

#include <stdio.h>
#include <string>

using namespace std;


static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

/**********************************************
  *Summary: Base64解密
  *Parameters:
       in encoded_string 加密字符串
       out no
  *Return : 解密字符串
***********************************************/
string base64_decode(string const& encoded_string);

/**********************************************
  *Summary: Base64加密
  *Parameters:
       in encoded_string 待加密字符串
		  in_len 待加密字符串长度
       out no
  *Return : 加密后字符串
***********************************************/
string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);

#endif
