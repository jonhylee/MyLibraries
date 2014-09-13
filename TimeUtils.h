/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		TimeUtils.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-6
  *Description:		时间处理工具类
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-6
       Author:		zhiqli
       Modification:创建文件
***********************************************/

#ifndef __TIME_UTILS_HH__
#define __TIME_UTILS_HH__

#ifdef BOOST
 /*
    * GMT+8时间，YYYY-MM-DD hh:mm:ss格式转成UTC时间
    */
    time_t gmt_time_to_utc(const string &strgmt);

    /*
    * GMT+8时间，YYYY-MM-DD hh:mm:ss格式获取年月日时分秒
    */
    bool gmt_time_to_ymdmhs(short &year,
        short &month,
        short &day,
        short &hours,
        short &minutes,
        short &seconds,
        const string &strgmt);

    /*
    * GMT+8时间，YYYY-MM-DD hh:mm:ss格式获取年月日时分秒
    */
    bool gmt_time_to_ymdmhs(short &year,
        char &month,
        char &day,
        char &hours,
        char &minutes,
        char &seconds,
        const string &strgmt);

    /*
    * GMT+8时间，YYYY-MM-DD hh:mm:ss格式获取年月日时分秒
    */
    bool gmt_time_to_ymdmhs(unsigned short &year,
        unsigned char &month,
        unsigned char &day,
        unsigned char &hours,
        unsigned char &minutes,
        unsigned char &seconds,
        const string &strgmt);

    /*
    * UTC转GMT+8时间，YYYY-MM-DD hh:mm:ss格式
    */
    string &utc_time_to_gmt(string &strgmt,
        const time_t utc);

    /*
    * 取当前时间,GMT+8时间，YYYY-MM-DD hh:mm:ss格式
    */
    string &cur_gmt_time(string &strgmt);

    /*
    * 年月日时分秒转换为utc时间
    */
    time_t ymdmhs_time_to_utc(const short year,
        const char month,
        const char day,
        const char hours,
        const char minutes,
        const char seconds);

#endif

#endif