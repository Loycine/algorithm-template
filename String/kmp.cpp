#include <string>
#include <iostream>

using namespace std;

/*
KMP: Find pattern p in String s.
When not the same, find string匹配位置前the longest后缀 和 pattern的前缀对齐。
abcabcdabcabcabcf
abcabcf

abcabcdabcabcabcf
   abcabcf

abcabcdabcabcabcf
      abcabcf

abcabcdabcabcabcf
       abcabcf

abcabcdabcabcabcf
          abcabcf
*/

const int maxn = 20;
int next_array[maxn];

/*
-1
abcabcfabcabca
 000123
*/


//这里的str是被包含的较短字符串，length是这个字符串的长度。
void make_next_array(const char* str, int* next_array, int len)
{
    next_array[0] = -1;
    int k;
    for(int q=1; q<len; q++)
    {
        k = next_array[q-1];
        while(k > -1 && str[q-1] != str[k])
        {
            k = next_array[k];
        }
        if(k == -1)
        {
            next_array[q] = 0;
        }
        else if(str[q-1] == str[k])
        {
            next_array[q] = k+1; 
        }
        else
        {
            next_array[q] = 0;
        }
    }
}

int kmp_find(string s, string p)
{
    int n = s.size();
    int m = p.size();
    int i = 0;
    int j = 0;

    while(true)
    {
        if(j == m)
        {
            return i-m;
        }
        if(i >= n)
        {
            return -1;
        }
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else if(s[i] != p[j])
        {
            j = next_array[j];
            if(j == -1)
            {
                ++j;
                ++i;
            }
        }

    }
}
int main()
{
    string p = "abcabcf";
    make_next_array(p.c_str(), next_array, p.size());
    for(int i=0; i<p.size(); i++)
    {
        cout << next_array[i] << " ";
    }
    cout << "\n";

    string s = "abcabcdabcabcabcf";
   
    cout << kmp_find(s, p) << "\n";

}

