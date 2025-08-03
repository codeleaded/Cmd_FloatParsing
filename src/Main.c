#include "/home/codeleaded/System/Static/Library/ConstParser.h"

int main(int argc, const char *argv[]){
    
    Double d = 0.0;
    char* cstr = Double_Get(d,8);
    Double out = Double_Parse(cstr,1);

    


    printf("S: %s, D: %lf\n",cstr,out);

    return 0;
}