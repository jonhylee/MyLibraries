

#include "TimeUtils.h"

#ifdef BOOST

#include <boost/date_time/posix_time/posix_time.hpp>

/*
* GMT+8时间，YYYY-MM-DD hh:mm:ss格式转成UTC时间
*/
time_t gmt_time_to_utc(const string &strgmt) 
{
	time_t utc = 0;

	try
	{
		boost::posix_time::ptime pt1(
			boost::gregorian::date(1970, 1, 1), 
			boost::posix_time::time_duration(8, 0, 0)); 

		boost::posix_time::ptime pt2(
			boost::posix_time::time_from_string(strgmt)); 

		boost::posix_time::time_duration td = pt2 - pt1; 

		utc = td.total_seconds();
	}
	catch (...)
	{
		utc = 0;
	}

	return utc;
}

/*
* GMT+8时间，YYYY-MM-DD hh:mm:ss格式获取年月日时分秒
*/
bool gmt_time_to_ymdmhs(short &year,
								   short &month,
								   short &day,
								   short &hours,
								   short &minutes,
								   short &seconds,
								   const string &strgmt) 
{
	try
	{
		boost::posix_time::ptime pt(
			boost::posix_time::time_from_string(strgmt)); 

		boost::gregorian::date dt = pt.date();
		boost::posix_time::time_duration td = pt.time_of_day();

		year = dt.year();
		month = dt.month();
		day = dt.day();

		hours = td.hours();
		minutes = td.minutes();
		seconds = td.seconds();
	}
	catch (...)
	{
		return false;
	}

	return true;
}

/*
* GMT+8时间，YYYY-MM-DD hh:mm:ss格式获取年月日时分秒
*/
bool gmt_time_to_ymdmhs(short &year,
								   char &month,
								   char &day,
								   char &hours,
								   char &minutes,
								   char &seconds,
								   const string &strgmt) 
{
	try
	{
		boost::posix_time::ptime pt(
			boost::posix_time::time_from_string(strgmt)); 

		boost::gregorian::date dt = pt.date();
		boost::posix_time::time_duration td = pt.time_of_day();

		year = dt.year();
		month = char(dt.month());
		day = char(dt.day());

		hours = char(td.hours());
		minutes = char(td.minutes());
		seconds = char(td.seconds());
	}
	catch (...)
	{
		return false;
	}

	return true;
}

bool gmt_time_to_ymdmhs(unsigned short &year,
								   unsigned char &month,
								   unsigned char &day,
								   unsigned char &hours,
								   unsigned char &minutes,
								   unsigned char &seconds,
								   const string &strgmt)
{
	try
	{
		boost::posix_time::ptime pt(
			boost::posix_time::time_from_string(strgmt)); 

		boost::gregorian::date dt = pt.date();
		boost::posix_time::time_duration td = pt.time_of_day();

		year = dt.year();
		month = (unsigned char)(dt.month());
		day = (unsigned char)(dt.day());

		hours = (unsigned char)(td.hours());
		minutes = (unsigned char)(td.minutes());
		seconds = (unsigned char)(td.seconds());
	}
	catch (...)
	{
		return false;
	}

	return true;
}

enum
{
	GMT8_SECONDS = 60 * 60 * 8
};

/*
* UTC转GMT+8时间，YYYY-MM-DD hh:mm:ss格式
*/
string &utc_time_to_gmt(string &strgmt,
								   const time_t utc) 
{
	boost::posix_time::ptime pt(
		boost::posix_time::from_time_t(utc + GMT8_SECONDS));

	strgmt = boost::posix_time::to_simple_string(pt);

	return strgmt;
}

/*
* 取当前时间,GMT+8时间，YYYY-MM-DD hh:mm:ss格式
*/
string &cur_gmt_time(string &strgmt) 
{
	return utc_time_to_gmt(strgmt, time(NULL));
}

/*
* 年月日时分秒转换为utc时间
*/
time_t ymdmhs_time_to_utc(const short year,
									 const char month,
									 const char day,
									 const char hours,
									 const char minutes,
									 const char seconds) 
{
	time_t utc = 0;

	try
	{
		boost::posix_time::ptime pt1(
			boost::gregorian::date(1970, 1, 1), 
			boost::posix_time::time_duration(8, 0, 0)); 

		boost::posix_time::ptime pt2(boost::gregorian::date(year, month, day), 
			boost::posix_time::time_duration(hours, minutes, seconds)); 

		boost::posix_time::time_duration td = pt2 - pt1; 

		utc = td.total_seconds();
	}
	catch (...)
	{
		utc = 0;
	}

	return utc;
}

#endif

