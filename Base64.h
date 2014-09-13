/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		Base64.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-11
  *Description:		Base64���ܽ�����
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-11
       Author:		zhiqli
       Modification:�����ļ�
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
  *Summary: Base64����
  *Parameters:
       in encoded_string �����ַ���
       out no
  *Return : �����ַ���
***********************************************/
string base64_decode(string const& encoded_string);

/**********************************************
  *Summary: Base64����
  *Parameters:
       in encoded_string �������ַ���
		  in_len �������ַ�������
       out no
  *Return : ���ܺ��ַ���
***********************************************/
string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);

#endif
