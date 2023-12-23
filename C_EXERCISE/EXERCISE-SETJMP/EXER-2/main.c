#include <stdio.h>
#include <setjmp.h>



enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };
jmp_buf buf ;
int exception;
char* error_message;
#define THROW(x,y) \
error_message = y;\
longjmp(buf, FILE_ERROR)

#define TRY if(exception == NO_ERROR) 
#define CATCH(x) else if(exception == (x))
 
 void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    printf("networkOperation...\n");
    THROW(NETWORK_ERROR, "Lỗi networkOperation."); // Bổ sung chương trình
}

void calculateData() {
    printf("calculateData\n");
    THROW(CALCULATION_ERROR, "calculateData");// Bổ sung chương trình
}

int main(){
    exception = setjmp(buf);
    TRY{
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n", error_message);} // Bổ sung thêm nhiều CA
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);}
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_message);}
}