#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

char* int_ip_to_str(int ip)
{
    char* ret = new char [16];

    int num[4];
    int x = 255;
    for(int i=0; i<4; i++)
    {
        num[i] = ip&x;
        ip >>= 8;
    }
    snprintf(ret,16,"%d.%d.%d.%d",num[3],num[2],num[1],num[0]);

    return ret;
}

int int_ip_to_str_test()
{
    int ip_int = 167773121;
    char* ip_str = int_ip_to_str(ip_int);
    const char* expected_str = "10.0.3.193";
    assert(strcmp(ip_str, expected_str) == 0);
    delete ip_str;
    return 0;
}

int main()
{
   int_ip_to_str_test();
   return 0;
}