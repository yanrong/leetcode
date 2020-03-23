#include <iostream>  
#include <string>  
#include <algorithm>  
#include <fstream>
#include <cstring>  
using namespace std;  
const int MAX_LEN = 1000;  
int ia[MAX_LEN];  
  
string subF(string str1, string str2)  
{      
     int i,j;  
     string result;  
     memset(ia,0,sizeof(ia));     // 暂存乘法运算的结果  
  
     reverse(str1.begin(), str1.end());     // 倒置  
     reverse(str2.begin(), str2.end());  
  
     int point1, point2,point;               //     小数位数  
     point1 = str1.find('.');      
     point2 = str2.find('.');  
     if(point1 != string::npos)               // 如果为小数，则将小数点删除  
          str1.erase(str1.begin()+point1);  
     else  
          point1 = 0;  
     if(point2 != string::npos)  
          str2.erase(str2.begin()+point2);  
     else  
          point2 = 0;  
     point1 > point2 ? point = point1 : point = point2;     // point保存最大的小数位数  
  
     int len1 = str1.size();  
     int len2 = str2.size();  
      
     for(i = 0; i < len1; i++)               // 乘法运算  
          for(j = 0; j < len2; j++)  
               ia[i+j] += (str1[i]-'0')*(str2[j]-'0');  
  
     int len;     // 乘积的长度  
     for(i = 0; i < len1+len2; i++)          // 进位处理  
     {  
          if(ia[i] >= 10)  
          {  
               ia[i+1] += (ia[i]/10);  
               ia[i] %= 10;  
          }  
     }  
     if(ia[len1+len2-1] > 0)  
          len = len1+len2;  
     else  
          len = len1+len2-1;  
  
     for(i = len-1; i >= 0; i--)  
          result += char(ia[i]+'0');  
     if(point > 0)          // 插入小数点  
     {  
          result.insert(result.end()-point1-point2,'.');  
          for(i = result.size()-1; i >= 0; i--)     // 去除小数点后的后置0  
          {  
               if(result[i] == '0')  
                    result.erase(result.begin()+i);  
               else if(result[i] == '.')  
               {  
                   result.erase(result.begin()+i);  
                   break;  
               }  
               else  
                    break;  
          }  
          while( (*result.begin()) == '0' )     // 去除小数点前的前置0  
              result.erase(result.begin());  
     }  
     return result;  
}  
  
int main()  
{
     string str1;  
     int n;  
     while(cin >> str1 >> n)  
     {  
         string str2("1");  
         while(n--)  
         {  
           str2 = subF(str1, str2);  
         }  
          cout << str2 << endl;  
     }  
     return 0;  
}  