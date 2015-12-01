 #define _XOPEN_SOURCE       /* See feature_test_macros(7) */
       #include <unistd.h>
       #include <stdio.h>
       int main(){
       char *pwd,*salt;
       printf("enter your password and the salt");
       scanf("%s%s",&pwd,&salt);
       crypt(pwd, salt);
       }
