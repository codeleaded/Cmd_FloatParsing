#include "/home/codeleaded/System/Static/Library/ConstParser.h"

int main(int argc, const char *argv[]){
    
    F64 d = -3.14159265358e1;

    char buffer1[128];
    memset(buffer1,0,sizeof(buffer1));
    F64_Print_Dc(d,buffer1,16);

    char buffer2[128];
    memset(buffer2,0,sizeof(buffer2));
    F64_Print_Ex(d,buffer2);

    F64 p1 = F64_Parse_Dc(buffer1);
    F64 p2 = F64_Parse_Ex(buffer2);
    printf("S: %s, S: %s, D: %lf, P: %lf, P: %lf\n",buffer1,buffer2,d,p1,p2);
    
    //I64 n = 0xFFFFFFFFFFFFFFFFL;
    //char* cstr = I64_Get_D(n);
    //I64 p = I64_Parse(cstr);
    //printf("S: %s, P: %ld, D: %ld, X: %lx, O: %lo\n",cstr,p,n,n,n);

    //if(cstr) free(cstr);
    //cstr = NULL;

    return 0;
}