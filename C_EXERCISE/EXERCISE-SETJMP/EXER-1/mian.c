#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception;
char *error_code;



#define THROW(x,y)  \
error_code = y; \
longjmp(buf,(x))             

#define CATCH(x) if(exception == (x))


double divide(int a, int b) {
   if (b == 0) {
       THROW(1, "Lỗi: Phép chia cho 0!"); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   if(b == 1){
     THROW(2, "Lỗi: b = 1 phep chia khong thay doi");
     }
   if(b > a ) {
    THROW(3, "Lỗi: b > a phep chia ket qua be hon 0");
    }
   return (double)a / b;
}


int main(){
    
    int a = 10;
    int b = 50;
    if ((exception = setjmp(buf)) == 0) divide(a,b);
    CATCH(1) {
       printf("%s\n", error_code);
    }
    CATCH(2) {
       printf("%s\n", error_code);
    }
    CATCH(3){
       printf("%s\n", error_code);
    }
    return 0;
}