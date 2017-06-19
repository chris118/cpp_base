//
//  util.hpp
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <ctime>
#include <sys/timeb.h>  

#ifndef UTIL
#define UTIL

int API_TimeToString(string &strDateStr)
{
    //generate the name
    time_t timep;
    struct tm *p;
    time(&timep); /*当前time_t类型UTC时间*/
    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    p->tm_year = p->tm_year + 1900;
    p->tm_mon = p->tm_mon + 1;
    
    char chTmp[20];
    bzero(chTmp,sizeof(chTmp));
    snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d-%02d-%02d-%02d",
             p->tm_year, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    
    strDateStr = chTmp;
    return 0;
}

int API_TimeToString2(string &strDateStr)
{
    //generate the name
    time_t timep;
    struct tm *p;
    time(&timep); /*当前time_t类型UTC时间*/
    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    p->tm_year = p->tm_year + 1900;
    p->tm_mon = p->tm_mon + 1;
    
    char chTmp[20];
    bzero(chTmp,sizeof(chTmp));
    snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d",
             p->tm_year, p->tm_mon, p->tm_mday);
    
    strDateStr = chTmp;
    return 0;
}

string GenerateUUID(){
    uuid_t uu;
    uuid_generate( uu );
    
    char buf[64] = {0};
    snprintf(buf, sizeof(buf),
             "%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X",
             uu[0], uu[1], uu[2],
             uu[3], uu[4], uu[5],
             uu[6], uu[7], uu[8],
             uu[9], uu[10], uu[11],
             uu[12], uu[13], uu[14],uu[15]);
    
    return string(buf);
    
}

string MakeOutputFileName(string ext)
{
    string time_str;
    API_TimeToString(time_str);
    string name = time_str + ext;
    
    return name;
}

string MakeOutputFolderName()
{
    string time_str;
    API_TimeToString2(time_str);
    
    return time_str;
}

int randomInt(int scope)
{
    srand((unsigned)time(NULL)); //用于保证是随机数
    return rand()%scope;  //用rand产生随机数并设定范围
}

char* GetLocalTimeStamp()
{
    // // 基于当前系统的当前日期/时间
    // time_t now = time(0);
    
    // // 把 now 转换为字符串形式
    // char* dt = ctime(&now);
    
    // return dt;
    struct  tm      *ptm;  
    struct  timeb   stTimeb;  
    static  char    szTime[19];  

    ftime(&stTimeb);  
    ptm = localtime(&stTimeb.time);  
    sprintf(szTime, "%02d-%02d %02d:%02d:%02d.%03d",  
            ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);  
    szTime[18] = 0;  
    return szTime; 
}

std::string ltos(long l)  
{  
    ostringstream os;  
    os<<l;  
    std::string result;  
    istringstream is(os.str());  
    is>>result;  
    return result;  
  
} 

std::string get_timestamp_string(){
    std::time_t t = std::time(0);
    return ltos(t);
}

#endif
