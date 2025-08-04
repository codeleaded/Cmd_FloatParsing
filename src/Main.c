#include "/home/codeleaded/System/Static/Library/ConstParser.h"

unsigned long Dec_Of_Mant(unsigned long Mant,unsigned long length){
    const unsigned long target = length >> 2;
    const unsigned long start = U64_Pow10(target);
    unsigned long ret = start;
    
    for(int i = length - 1;i>=0;i--){
        if(Mant & (1UL << i)){
            const unsigned long add = start >> (length - i);
            ret += add;
        }
    }
    
    return ret << 1;
}
unsigned long Dec_Of_F64Mant(F64 n){//log2(10) = 3.321928095 = 10 / 3
    unsigned long bits = *(unsigned long*)&n;
    unsigned long bits_noep = bits & ~(0b111111111111UL << 52);// 1 + 11
    unsigned long bits_nwep = bits_noep | ((1023UL + 18UL * 10UL / 3UL) << 52);

    F64 newn = *(F64*)&bits_nwep;
    U64 Ipart = (U64)newn; 
    printf("D: %lf, I: %ld\n",newn,Ipart);
    return Ipart;
}

long Dec_Expo(unsigned long Expo){
    return (long)Expo - 1023;
}
unsigned long Expo_Dec(long Dec){
    return (unsigned long)((long)Dec + 1023);
}

char* F64_Get_Dc(F64 n){
    unsigned long bits = *(long*)&n;
    unsigned long bits_sign = (bits >> 63) & 0b1;
    unsigned long bits_expo = (bits >> 52) & 0b11111111111;
    unsigned long bits_mant = (bits & ~(0xFFFUL << 52));

    char buffer[128];
    memset(buffer,0,sizeof(buffer));

    printf("S: %lx, E: %lx, M: %lx\n",bits_sign,bits_expo,bits_mant);
    unsigned long dm = Dec_Of_Mant(bits_mant,52);
    printf("M: %lu\n",dm);

    return NULL;
}
char* F64_Get_Ex(F64 n){//log10(2) = 0.301029996 = 0.3
    unsigned long bits = *(unsigned long*)&n;
    unsigned long bits_sign = (bits >> 63) & 0b1;
    unsigned long bits_expo = (bits >> 52) & 0b11111111111;
    unsigned long bits_mant = (bits & ~(0xFFFUL << 52));

    char buffer[128];
    memset(buffer,0,sizeof(buffer));

    printf("S: %lx, E: %lx, M: %lx\n",bits_sign,bits_expo,bits_mant);
    
    unsigned long dm = Dec_Of_F64Mant(n);
    long ep = Dec_Expo(bits_expo);
    ep = ep * 3 / 10 + (ep<0 ? -1 : 0);
    
    printf("E: %ld, M: %lu\n",ep,dm);

    return NULL;
}

F64 F64_Parse_Dc(char* s){
    return 0.0;
}
F64 F64_Parse_Ex(char* s){
    return 0.0;
}
F64 F64_Parse(char* s){
    return 0.0;
}





int main(int argc, const char *argv[]){
    
    F64 d = 3.141592654e1;
    char* cstr = F64_Get_Ex(d);
    F64 p = F64_Parse_Ex(cstr);
    printf("S: %s, D: %lf, P: %lf\n",cstr,d,p);
    
    //I64 n = 0xFFFFFFFFFFFFFFFFL;
    //char* cstr = I64_Get_D(n);
    //I64 p = I64_Parse(cstr);
    //printf("S: %s, P: %ld, D: %ld, X: %lx, O: %lo\n",cstr,p,n,n,n);

    if(cstr) free(cstr);
    cstr = NULL;

    return 0;
}