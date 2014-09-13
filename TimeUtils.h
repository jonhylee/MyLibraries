/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		TimeUtils.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-6
  *Description:		ʱ�䴦������
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-6
       Author:		zhiqli
       Modification:�����ļ�
***********************************************/

#ifndef __TIME_UTILS_HH__
#define __TIME_UTILS_HH__

#ifdef BOOST
 /*
    * GMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽת��UTCʱ��
    */
    time_t gmt_time_to_utc(const string &strgmt);

    /*
    * GMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽ��ȡ������ʱ����
    */
    bool gmt_time_to_ymdmhs(short &year,
        short &month,
        short &day,
        short &hours,
        short &minutes,
        short &seconds,
        const string &strgmt);

    /*
    * GMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽ��ȡ������ʱ����
    */
    bool gmt_time_to_ymdmhs(short &year,
        char &month,
        char &day,
        char &hours,
        char &minutes,
        char &seconds,
        const string &strgmt);

    /*
    * GMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽ��ȡ������ʱ����
    */
    bool gmt_time_to_ymdmhs(unsigned short &year,
        unsigned char &month,
        unsigned char &day,
        unsigned char &hours,
        unsigned char &minutes,
        unsigned char &seconds,
        const string &strgmt);

    /*
    * UTCתGMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽ
    */
    string &utc_time_to_gmt(string &strgmt,
        const time_t utc);

    /*
    * ȡ��ǰʱ��,GMT+8ʱ�䣬YYYY-MM-DD hh:mm:ss��ʽ
    */
    string &cur_gmt_time(string &strgmt);

    /*
    * ������ʱ����ת��Ϊutcʱ��
    */
    time_t ymdmhs_time_to_utc(const short year,
        const char month,
        const char day,
        const char hours,
        const char minutes,
        const char seconds);

#endif

#endif