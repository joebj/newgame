/**
 * @file       test.cpp
 * @brief      
 * @author     Hanwei
 * @version    1.0.0
 */

/*********************************************************************
 *  Hanwei   04/19/11      Initial Version
 *********************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
///////////////////////
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <curl/curl.h>
///////////////////////
using namespace std;
static size_t WriteMemoryCallback(void *ptr,size_t size,size_t nmemb,void *data)
{
    int realsize = size * nmemb;
    string *vec = static_cast<string *>(data);
    const char * chPtr = static_cast<char*>(ptr);
    vec->insert(vec->end(),chPtr,chPtr+realsize);
    return realsize;
}
/**
 * @brief 
 */
int main ( int argc, char *argv[] )
{
    CURL *curl_handle;
    CURLcode res;
    string chunk;
    char *useragent ="Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)";
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
	res = curl_easy_setopt(curl_handle,CURLOPT_URL,"http://export.tudou.com/baidu/baidu_lastest_td.xml");
	res = curl_easy_setopt(curl_handle,CURLOPT_NOBODY,1L);
	res = curl_easy_setopt(curl_handle,CURLOPT_USERAGENT,useragent);
	res = curl_easy_setopt(curl_handle,CURLOPT_HEADERFUNCTION,WriteMemoryCallback);
	res = curl_easy_setopt(curl_handle,CURLOPT_WRITEHEADER,(void *)&chunk);
	res = curl_easy_perform(curl_handle);
	cout<<chunk<<endl;

	return EXIT_SUCCESS;
}				// ----------  end of function main  ----------

