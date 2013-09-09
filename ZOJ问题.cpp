#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[1001];
    int len,cnt,flag1,flag2,flag3,i;
    while(~scanf("%s",s)){
        len=strlen(s);
        cnt=0;
        flag1=flag2=-1;
        flag3=0;
        for(i=0;i<len;i++){
            if(s[i]!='z'&&s[i]!='o'&&s[i]!='j'){
                flag3=1; //记录是否有非法字符； 
                break;                            
            }             
        }
        for(i=0;i<len;i++){
            if(s[i]=='z'){
                flag1=i;//z第一次出现； 
                break;        
            }              
        }
        for(i=len-1;i>=0;i--){
            if(s[i]=='j'){
                flag2=i;//j最后一次出现； 
                break;        
            }                 
        }
        if(flag1>flag2||flag1==-1||flag2==-1||flag3==1){
            printf("Wrong Answer\n");           
        } 
        else{
            for(i=flag1+1;i<flag2;i++){
                if(s[i]=='o'){
                    cnt++;        
                }//统计z、j中间o的个数                     
            }
            //printf("cnt=%d/n",cnt);
            if(cnt!=flag2-flag1-1||cnt==0){//判断z、j中间是否出现除o以外的字符；cnt=0是zoj中间没有出现o，不合法； 
                printf("Wrong Answer\n");                  
            }
            else{
                if(flag1*cnt==len-flag2-1){
                    printf("Accepted\n");                       
                }
                else{
                    printf("Wrong Answer\n");
                }
            }
        }               
    }
}
/*
 Problem Description
 对给定的字符串(只包含'z','o','j'三种字符),判断他是否能AC。
 
 是否AC的规则如下：
 1. zoj能AC；
 2. 若字符串形式为xzojx，则也能AC，其中x可以是N个'o' 或者为空；
 3. 若azbjc 能AC，则azbojac也能AC，其中a,b,c为N个'o'或者为空；
 
 
 Input
 输入包含多组测试用例，每行有一个只包含'z','o','j'三种字符的字符串，字符串长度小于等于1000；
 
 
 Output
 对于给定的字符串，如果能AC则请输出字符串“Accepted”，否则请输出“Wrong Answer”。
 
 
 Sample Input
 zoj
 ozojo
 ozoojoo
 oozoojoooo
 zooj
 ozojo
 oooozojo
 zojoooo
 
 
 Sample Output
 Accepted
 Accepted
 Accepted
 Accepted
 Accepted
 Accepted
 Wrong Answer
 Wrong Answer
*/