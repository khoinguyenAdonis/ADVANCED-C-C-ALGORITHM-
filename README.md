<details> 
    <summary><h1>⭐ C programming language <h2></summary>

<details> 
    <summary><h2>struct and union </h3></summary>

### struct
Struct định nghĩa một kiểu dữ liệu mới, với hơn một thành phần trong chương trình, biến dạng struct bao gồm nhiều thành phần có thể thuộc nhiều kiểu dữ liệu khác nhau. Typedef Struct  khai báo/ định nghĩa một kiểu struct
vd 
th1: 
```c 
struct a {
    int b;
};
int main(void) {
     a c; // báo lỗi ở dòng này
	return 0;
}
```
th2:
```c
typedef struct a {
	int b;
} a; //định nghĩa struct a thành a

int main(void) {
a c; // không lỗi nữa
	        return 0;
}
```
Kích thước kiểu struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding). Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau.
### union
Union trong C là một kiểu dữ liệu đặc biệt có sẵn trong C cho phép lưu trữ các kiểu dữ liệu khác nhau trong cùng một vị trí bộ nhớ. Cấu trúc của Union là tất cả các thành phần của nó dùng chung một vùng nhớ có kích thước tương ứng với thành phần lớn nhất.
Do đó kích thước của union là kích thước lớn nhất của kiểu dữ liệu trong nó. Thay đổi nội dung 1 thành viên trong union sẽ dẫn đến thay đổi nội dung của thành viên khác.

</details>
<details>
    <summary><h2>Phân vùng bộ nhớ ram </h3></summary>

|Stack|
|:-|
|↓|
|↑|
|Heap|
|Bss|
|Data|
|Text|
    
***Stack*** Quyền truy cập read and write.
- Được sử dụng cấp phát cho biến local, input parameter của hàm,...
- Sẽ được giải phóng khi ra khỏi block code/hàm .
- Các biến tạo trong vùng nhớ này có thể tự động được thu hồi, nên ta không cần các kỹ thuật thu hồi bộ nhớ như khi ta cấp phát động trong heap.

***Head*** Quyền truy cập Read and write.
- Được sr dụng để cấp phát bộ nhớ động.
- Các biến trong bộ nhớ này phải được thu hồi thủ công bằng cách sử dụng các hàm free()  

***Bss*** Quyền truy cập read and write.
- Chứa các biến global hoặc static khởi tạo bằng không hoặc không khởi tạo.
- Được giải phóng khi kết thúc chương trinhf.

***Data*** Quyền truy cập read and write.
- Chứa các biến global hoặc static được khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình.

***Text*** Quyền truy cập read only.
- Chứa các biến khai báo hằng số.
- Chứa mã máy của chương trình đã được biên dịch.

</details>
<details>
    <summary><h2>Macro and Function </h3></summary>

### Macro
Chuyển thay thế macro bằng các văn bản code trong quá trình tiền xử lý. 
Khai báo:
```c
    #define MACRO text
    
    int main(){
        printf("MACRO");
    }
```
Tiền xử lý 
```c
    #define MACRO text
    
    int main(){
        printf("text"); // thay thế macro
    }
```
Nối chuổi:
```c
#define CREATE_VARIABLE(name)       \
int name##__kieuint;                \
double name##__kieudouble;
FUNC(hienthi,hello world\n);

int main(){
    CREATE_VARIABLE(test);
    return 0;
}
```
Tiền xử lý:
```c
    int main (){
        int test__kieuint;
        double test__kieudouble;
        return 0;
    }
```
### Function
Khi khởi tạo một Function chương trình sẽ cấp cho Function đó 1 địa chỉ cố định để khi dùng sẽ gọi đến địa chỉ đó. khi thực hiện xong các biến local, parameter function sẽ được thu hồi. Do đó sẽ tiết kiệm bộ nhớ. Macro sẽ chiếm nhiều bộ nhớ hơn do macro chỉ thay thế lại.
VD:
```c
    int addition(int value1, int value2)
{
	int sumary = value1 + value2;
	return sumary;
}

void introduce()
{
	cout << "Hello!" << endl;
	cout << "I'm a program" << endl;
}
```
</details>
<details>
    <summary><h2>Compiler </h3></summary>

### Compiler 
Là quá trình chuyển đổi ngôn ngữ viết thành ngôn ngữ bật thấp mà máy tinhs có thể hiểu và thực hiện được.
**Quá trình compiler bao gồm:**
- *Giai đoàn tiền xử lý (Pre-processor):* Nhận mã nguồn, Xóa bor các chú thích, chỉ thị tiền xử lý (bắt đầu bằng #) vd như #include cho phép ghép thêm tệp của mã nguồn cần biên dịch các #define cũng đuoc thay thế vào tạo ra file .i
    Cách xem file .i bằng  gcc: gcc -S -o filename.s filename.c
- *Giai đoạn dịch NNBC sang Asembly (Compiler):* Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý. Tạo file .s
    Cách xem file .s bằng gcc: gcc -S -o filename.s filename.c
- *Giai đoạn dịch asembly sang ngôn ngữ máy (Asember):* Dich chương trình => Sang mã máy 0 và 1.Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
    Cách xem file .obj bằng gcc: gcc -c filename.c -o filename.o
- *Giai đoạn linker:*Trong giai đoạn này mã máy của một chương trình .o dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích nhất. Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.

</details>
<details>
    <summary><h2>Kiểu dữ liệu </h3></summary>


- Biến số nguyên (**Integer Variables**): Lưu trữ giá trị số nguyên không có phần thập phân.
	`int age = 25;`
- Biến số thực (**Floating-point Variables**): Lưu trữ giá trị số thực có phần thập phân.
	`float pi = 3.14;`
- Biến dấu chấm động (**Floating-point Variables**): Lưu trữ giá trị số thực có độ chính xác cao hơn float.
    `double pi = 3.14159;`
- Biến dài (**Long Variables**): Lưu trữ giá trị số nguyên có phạm vi mở rộng so với int.
    `long population = 1000000;`
- Biến ngắn (**Short Variables**): Lưu trữ giá trị số nguyên có phạm vi nhỏ hơn so với int.
    `short temperature = -10;`
- Biến ký tự (**Character Variables**): Lưu trữ một ký tự.
	`char grade = 'A';`
- Biến chuỗi ký tự (**String Variables**): Lưu trữ một chuỗi các ký tự.
	`char name[] = "John";`
- Biến boolean (**Boolean Variables**): Lưu trữ giá trị đúng (1) hoặc sai (0).
	`int isTrue = 1;`
- Con trỏ (**Pointer Variables**): Lưu trữ địa chỉ của một biến hoặc vùng nhớ.
	`int* ptr = NULL;`
- Biến mảng (**Array Variables**): Lưu trữ nhiều giá trị trong một biến duy nhất.
	`int numbers[] = {1, 2, 3, 4, 5};`
- Biến kích thước (**Size Variables**): Lưu trữ giá trị kích thước của các đối tượng trong bộ nhớ.
    ```size_t length = 10;```
- Biến không đổi (**Constant Variables**): Lưu trữ giá trị không thay đổi trong suốt thời gian chương trình chạy.
    ```const int MAX_VALUE = 100;```
- Biến từ khóa (**Keyword Variables**): Lưu trữ giá trị trùng với các từ khóa được định nghĩa trong ngôn ngữ C.
    ```int int = 5;```
- Biến từ xa (**Extern Variables**):Khai báo một biến đã được định nghĩa trong một tệp tin khác.
    ```extern int globalVar;```
- Biến có phạm vi tĩnh (**Static Scope Variables**): Lưu trữ giá trị trong suốt vòng đời của biến và chỉ có thể truy cập trong phạm vi của một hàm hoặc tệp tin.
    ```static int count = 0;```
- Biến hệ thống (**System Variables**): Lưu trữ thông tin đối với chương trình chạy, như số lượng tham số dòng lệnh và danh sách tham số.
    ```int argc; char** argv;```
- Biến môi trường (**Environment Variables**): Lưu trữ thông tin môi trường hệ thống như đường dẫn, biến cấu hình, v.v.
    `char* path = getenv("PATH");`
- Biến vô kiểu (**Void Variables**): Lưu trữ một địa chỉ bất kỳ và có thể chuyển đổi thành bất kỳ kiểu con trỏ nào.
	`void* ptr;`
- Biến hằng số từ xa (**Extern Constant Variables**): Khai báo một hằng số đã được định nghĩa trong một tệp tin khác. 
    `extern const int MAX_VALUE;` 
- Biến gần (**Auto Variables**): Được sử dụng để chỉ ra rằng một biến cục bộ tự động sẽ được tạo ra.
 	`auto int x = 5;`
- Biến trình tự (**Sequence Variables**): Chỉ định rằng một biến thường được truy cập nhanh chóng và thường xuyên.
    `register int counter = 0;`
- Biến quyền (**Qualifier Variables**): Đánh dấu biến có thể thay đổi mà không cần thông báo và không nên tối ưu hóa.
   	`volatile int status;`
- Biến tĩnh (**Static Variables**): Lưu trữ giá trị trong suốt vòng đời của chương trình và giá trị được duy trì ngay cả khi hàm hoặc khối lệnh kết thúc.
	```static int count = 0;```
- Biến tĩnh cục bộ (**Local Static Variables**): Lưu trữ giá trị trong suốt vòng đời của biến, nhưng chỉ có thể truy cập trong phạm vi của một hàm.
    ```C
    void function() {
        static int count = 0;
        // ...
    }
    ```
- Biến toàn cục (**Global Variables**): Khai báo ngoài hàm. Lưu trữ giá trị có thể truy cập từ bất kỳ đâu trong chương trình.
	```int globalVar = 10;```
- Biến cục bộ (**Local Variables**): Khai báo trong hàm. Lưu trữ giá trị chỉ có thể truy cập trong phạm vi của một hàm hoặc khối lệnh.
	```C
	void function() {
    	int localVar = 5;
   		// ...
	} 
	```
- Biến tên (**Label Variables**): Đánh dấu một vị trí trong mã chương trình để nhảy đến khi sử dụng lệnh goto.
    ```C
    goto label;
    // ...
    label:
        // ...
    ```
- Biến tham chiếu (**Reference Variables**): Lưu trữ một tham chiếu đến một biến đã tồn tại, cho phép thay đổi giá trị của biến qua tham chiếu.
    ```C
    int x = 10;
    int& ref = x;
    ```
- Biến hàm (**Function Variables**): Lưu trữ địa chỉ của một hàm và cho phép gọi hàm thông qua con trỏ.
    ```C
    int (*func_ptr)(int, int);
    int sum(int a, int b) {
        return a + b;
    }
    func_ptr = sum;
    ```
- Biến cấu trúc (**Structure Variables**): Lưu trữ các thành phần có liên quan vào một biến.
    ```
    struct Person {
        char name[20];
        int age;
    };
    struct Person p1;
	```
- Biến cấu trúc mở rộng (**Extended Structure Variables**): Lưu trữ các thành phần có liên quan vào một biến và mở rộng chức năng của cấu trúc.
    ```C
    struct Person {
        char name[20];
        int age;
    } p1;
    ```
- Biến liên kết (**Union Variables**): Lưu trữ giá trị của một thành phần trong một thời điểm.
    ```
    union Data {
        int x;
        float y;
    };
    union Data data;
    ```
- Biến liệt kê (**Enumeration Variables**): Lưu trữ một trong các giá trị được xác định trước từ một tập hợp các giá trị có tên.
    ```
    enum Color {
        RED,
        GREEN,
        BLUE
    };
	enum Color c = BLUE;
- Biến kiểu định danh (**Typedef Variables**): Tạo ra một tên mới cho một kiểu dữ liệu đã tồn tại để sử dụng dễ dàng hơn.
    ```C
    typedef int Integer;
    Integer number = 42;
	```
- Biến kiểu dữ liệu do người dùng định nghĩa (**User-defined Data Type Variables**): Định nghĩa và sử dụng kiểu dữ liệu tùy chỉnh trong ngôn ngữ C.
	```C
	typedef struct {
    	char name[20];
    	int age;
	} Person;
	Person p1; 
	```
### Khác nhau của static cục bộ và static toàn cục:
- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
</details>
<details>
  <summary><h3>Pointer</h3></summary>
	
- Bộ nhớ RAM chứa rất nhiều ô nhớ, `mỗi ô nhớ có kích thước 1 byte`. Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu `CPU 32bit` thì có `2^32 địa chỉ` có thể đánh cho các ô nhớ trong RAM.
	| Ô nhớ | 0 | 1 | ... | 2^32-2 | 2^32-1 |
  	|:-------:|:--------:|:--------:|---|:----------:|:--------:|
  	| Địa chỉ |0x00000000|0x00000001|...|0x0=fffffffe|0xffffffff|
	| Giá trị |          |     5    |...|     's'    |          |
	|   Biến  |          |     x    |...|    char    |          |
- Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa `địa chỉ bộ nhớ` và `dữ liệu được lưu trong đó`.
- Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở `hệ cơ số 16`. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
- ***Con trỏ(pointer):***
	- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
	- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`
### Các loại con trỏ:
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2  

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8 
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
	```c
	int num = 10; 
	const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
	```
- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
	```c
	int num = 10;
	float f = 3.14;
	void *ptr;
	ptr = &num;
	printf("num = %d\n",(int*)ptr);
	ptr = &f;
	printf("f = %f\n",(float*)ptr);
	```
- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	int main() {
	
		int (*operation)(int, int) = add;
		int result = operation(5, 3);
		printf("Result: %d\n", result);

		operation = subtract;
		result = operation(5, 3);
		printf("Result: %d\n", result);

		return 0;
	}

	```
- ***Con trỏ vào hàm (Pointers to Functions):*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	void performOperation(int a, int b, int (*operation)(int, int)) {
		int result = operation(a, b);
		printf("Result: %d\n", result);
	}

	int main() {
		int a = 5, b = 3;

		performOperation(a, b, add);
		performOperation(a, b, subtract);

		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
	```c
	void greet() {
		printf("Hello, World!\n");
	}

	void performAction(void (*action)()) {
		action();
	}

	int main() {
		performAction(greet);

		return 0;
	}

	```
### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

</details>
<details>
  <summary><h3>Stdargt - Assert</h3></summary>

- **Stdargt:** 
- Cú pháp: `#include<stdarg.h`
- stdarg.h trong Thư viện C định nghĩa một kiểu biến va_list và 3 macro mà có thể được sử dụng để lấy các tham số trong một hàm khi không cần biết chính xác có bao nhiêu tham số đầu vào
- va_list: là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi.
- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên.
- va_arg: Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai
- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

Ví dụ:

```C
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;// đây là 1 kiểu dữ liệu ,để lưu 1 địa chỉ 
    va_start(args, count);//count để xác định  giá trị ban đầu 
	//trong trường hợp này là 4....

    int result = 0;
    for (int i = 0; i < count; i++) {
        result += va_arg(args, int);// ép kiểu dữ liệu 
    }	

    va_end(args);

    return result;
}

int main() {
    printf("Sum: %d\n", sum(4, 1, 2, 3, 4));// sum:10 , vì cout =4>> truyền vào 4 tham số
    return 0;
}

```



Ví dụ 2:

```C++
#include <stdio.h>
#include <stdarg.h>


typedef struct Data
{
    int x;
    double y;
} Data;

void display(int count, ...) {

    va_list args;

    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args,Data);
        printf("Data.x at %d is: %d\n", i,tmp.x);
        printf("Data.y at %d is: %f\n", i,tmp.y);
    }
   

    va_end(args);


}

int main() {


    display(3, (Data){2,5.0} , (Data){10,57.0}, (Data){29,36.0});
    return 0;
}

```
</details>

<details>
  <summary><h3>Từ khóa đặc biệt trong C </h3></summary>

- Biến cục bộ là biến tồn tại trong các hàm :Hàm main() , hàm con.Biến cục bộ sẽ được lưu vào vùng nhớ stack, thu hồi khi kết thúc hàm. 
- Biến toàn cục là các biến được khai báo ở bên ngoài tất cả các hàm , Biến toàn cục tồn tại cho tới khi chương trình kết thúc.


### Khác nhau của static cục bộ và static toàn cục:

**Biến static cục bộ:** 
- Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. 
- Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm
- Biến static sẽ lưu vào vùng nhớ Data/ Bss, được giải phóng khi kết thúc chương trình.

- Ví dụ:

```C
		#include <stdio.h>
		void printMessage() {
		static int count = 0;
		// Tăng giá trị biến mỗi lần hàm được gọi
		count++;
		printf("Count: %d\n", count);
		}

		int main() {
		// Gọi hàm có sử dụng biến static
		printMessage();//
		printMessage();

		return 0;
		}// KQ:Count: 1,Count: 2

```

**Biến static toàn cục:**  
- Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được.Nghĩa là `extern` không dùng được
- Ví dụ:globalStaticVar được khai báo là static và nằm trong file "File1.c". Do đó, bạn không thể trực tiếp truy cập nó từ file "File2.c", bằng extern int globalStaticVar; trong File2.c, chương trình sẽ không biên dịch được và thông báo lỗi.

**Biến Extern:**
- Trong C, khi 1 biến đi sau từ khóa “extern” có nghĩa:
- Từ khóa extern được sử dụng để khai báo một biến,hàm mà đã được định nghĩa bên ngoài chương trình hoặc tệp tin.
- Biến extern không tạo ra bộ nhớ mới cho biến , tiết kiệm dung lượng chương trình
- Biến được tham chiếu phải được khai báo toàn cục.
- Lưu ý: khi sử dụng extern, không được khai báo giá trị ban đầu cho biến


Ví dụ

- File 1 ta khai báo

```C
int GlobalVariable = 0; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}
```
- File 2, chúng ta extern biến đó để sử dụng

```C
extern int GlobalVariable; // implicit definition 
void SomeFunction(); // function prototype (declaration) 
int main() 
{ 
  GlobalVariable = 1; 
  SomeFunction(); 
  return 0; 
}; 
```




**Biến register:**
- Từ khóa register được dùng để khai báo các biến có tính chất như biến cục bộ nhưng mà nó được lưu trong thanh ghi của CPU. Do nó được lưu trong thanh ghi nên tốc độ xử lý sẽ nhanh hơn so với các biến được lưu trong Ram.
    `register int counter = 0;`
- Hạn chế dùng register vì thanh ghi có giới hạn (32 bit là 4 byte , 64 bit là 8 byte ) >> chỉ lưu những biến quan trọng , cần tính toán nhanh
- Giải thích :Nếu khai báo biến thông thường để tính toán không có từ khóa register , thực hiện một phép tính thì cần có 3 bước.
	- Ví dụ: `int a = 6.Ví dụ :a có địa chỉ là 0X01,  a=a+4`
	- B1:Lưu địa chỉ và giá trị của biến vào bộ nhớ RAM : `0X01=6;` 
	- B2:Sau đó chuyển từ Ram qua thanh ghi(register)
	- B3:Từ register chuyển qua ALU (Arithmetic Logic Unit) ,để tính toán.Sau khi tính toán xong thì lại chuyển ngược về register>> về RAM



**Biến volatile:** Thông báo cho trình biên dịch rằng giá trị của biến này không tối ưu , nếu tối ưu thì sẽ không đúng kết quả của người code.
- Sử dụng volatile với biến có giá trị thay đổi từ bên ngoài , liên tục và giống nhau.Nếu không có volatile, compiler sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị nên compiler có xu hướng loại bỏ để có thể tối ưu kích cỡ file code .
- Ví dụ:
```C
   	int main() {
    volatile int sensorValue;

    while (1) {
        // Đọc giá trị từ cảm biến (sensor)
        sensorValue = readSensor();

        // Xử lý giá trị cảm biến
        processSensorValue(sensorValue);
    }

    return 0;
}
```

</details>
 
<details>
  <summary><h3>Goto_setjmp</h3></summary>

**Goto:**
- goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.


Ví dụ

```C
#include <stdio.h>
int main() {    
	int i = 0;   // Đặt nhãn    start        
	if (i >= 5) {           
		goto end;  // Chuyển control đến nhãn "end"       
		}       
		printf("%d ", i);        
		i++;        
		goto start;  // Chuyển control đến nhãn "start"    		 
		end: // Nhãn "end"       
		printf("\n");
		return 0;
	}
```



**Setjmp.h:**
- `setjmp.h` là một thư viện trong ngôn ngữ lập trình C, chứa các hàm setjmp và longjmp được sử dụng để xử lý các tình huống ngoại lệ.
- Khi điều kiện là sai, chúng không dừng chương trình lại như assert, mà thay vào đó chúng tạo ra một cơ hội để nhảy đến một điểm nhảy trước đó đã được đánh dấu bởi setjmp
- `setjmp` sẽ lưu điểm đánh dấu chương trình ngoại lệ .
- `longjmp` được sử dụng để nhảy đến một điểm  đã được đánh dấu bởi setjmp.


Ví dụ

```C

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;//jmp_buf là kiểu dữ liệu trong thư viện Setjmp.h
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}


```

</details>

<details>
  <summary><h3>Bitmask </h3></summary>

**Khái niệm**:
- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ  trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ  
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ
- khi muốn Set 1 bit tại ví trí chỉ cần dịch bit 1 tới vị trí Cần SET và OR với iá trị hiện tại
- Khi muốn Clear bit tai vị tri chỉ cần dịch bit 1 tới vị trí cần Clear , đảo ngược hết bit đó  và AND với giá trị hiện tại
- Ví dụ:

```C
	uint8_t x = 0;/0X0000 0000
	// Muốn set tại vị tri 1 
	x = x | (1 << 1);//0x0000 0001
	x = x & ~(1 << 1);0x0000 0000



```

Ví dụ 1 

```C

#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm 5 tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

void removeFeatures(uint8_t *features, uint8_t unwantedFeatures) {
    *features &= ~unwantedFeatures;
}


int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    removeFeatures(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```




Ví dụ 2 
```C
#include <stdio.h>

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000


void enableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT &= ~LED;
}


int main() {
    unsigned int GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
    
    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }

    // Cập nhật trạng thái của GPIO_PORT tương ứng với hardware

    return 0;
}
```

</details>
</details>


<details>
  <summary><h1>⭐C++ programming language<h2></summary>

<details>
  <summary><h2>Class</h2></summary>
	
### Class là gì?
- Class là 1 kiểu dữ liệu do người dùng định nghĩa
- Biến trong class gọi là `PROPERTY`.
- Hàm trong class gọi là `METHOD`.
- Ví dụ:

```C++
class ClassName {
private:   
// Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp   
// Dữ liệu thành viên, hàm thành viên, ...
protected:    
// Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa
public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
	// Dữ liệu thành viên, hàm thành viên, ...
	// Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
	// ..
};

```
**Constructor**
-  Constructor  là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class,Nó được sử dụng để khởi tạo các thuộc tính của đối tượng..
-  Có hai loại chính:
	+ Default Constructor (Constructor mặc định): không có tham số .
	+ Parameterized Constructor (Constructor với tham số):   constructor được khởi tạo và có tham số truyền vào.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>

class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;

    // Parameterized Constructor
    HinhChuNhat(int dai = 5, int rong = 3) {
        chieuDai = dai;
        chieuRong = rong;
    }

    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
};

int main() {
    // Tạo đối tượng HinhChuNhat và sử dụng constructor với giá trị mặc định
    HinhChuNhat hinhCN1;

    // Tạo đối tượng HinhChuNhat và truyền giá trị khác cho constructor
    HinhChuNhat hinhCN2(7, 4);

    // Hiển thị diện tích của hình chữ nhật 1 và 2
    std::cout << "Dien tich hinh chieuDai1: " << hinhCN1.tinhDienTich() << std::endl;
    std::cout << "Dien tich hinh chieuDai2: " << hinhCN2.tinhDienTich() << std::endl;

    return 0;
}


```
</details>

**Destructor**
- DDestructor trong C++ là một method sẽ được tự động gọi khi đối tượng được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>

class HinhChuNhat {
public:
    double chieuDai;  
    double chieuRong;

    // Constructor
    HinhChuNhat() {
        chieuDai = 10;
        chieuRong = 9;
    }

    // Destructor
    ~HinhChuNhat() {
        std::cout << "Destructor" << '\n';
    }

    // Hàm tính diện tích   
    double tinhDienTich() {       
        return chieuDai * chieuRong; 
    }
};

int main() {
    HinhChuNhat hinh1;
    std::cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';

    return 0;
}

```
</details>

**Static keyword**
- Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
<details>
<summary>Ví dụ:</summary>

```C++
#include <iostream>
#include <string>

class HinhChuNhat {
public:
    double chieuDai;
    double chieuRong;
    static int var;
};

int HinhChuNhat::var =0;
// Đây là cách đặt giá trị khởi tạo cho biến static var trong lớp HinhChuNhat(bắt buộc)
int main() {
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    std::cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    std::cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    std::cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    std::cout << "address of var: " << &hinh1.var << '\n'; 
    std::cout << "address of var: " << &hinh2.var << '\n'; 
    std::cout << "address of var: " << &hinh3.var << '\n'; 

    return 0;
}

```
</details>


 

<details>
<summary>Ví dụ:</summary>

```C++
class sinhvien {
	puplic:// phạm vi truy cập
	string ten;//PROPERTY
	int tuoi;
	int mssv;
	void display(){//METHOD
	cout<<"ten:"<<ten<<endl;
	cout<<"tuoi:"<<tuoi<<endl;
	cout<<"mssv:"<<mssv<<endl;

}
};

int main(){
	sinhvien sv1;
	sv1.ten ="hoang";//OBJECT thuộc class sinh viên
	sv1.tuoi=19;
	sv1.mssv =123123;
	sv1.display();// in ra 0.
	return 0;

}

```
- Class có thể khởi tạo giá trị ban đầu:
```C++
class sinhvien {
	puplic:// phạm vi truy cập
	sinhvien(string l_ten , int l_tuoi,string l_lop, int l_ngay){// gia tri ban đầu có tham số đầu vào
		static int  s_mssv;
		mssv=s_mssv;
		s_mssv ++;
		tuoi =l_tuoi;
		ten=l_ten;
		lop=l_lop;
		ngay =l_ngay;
	}
	string ten;//PROPERTY
	stactic int ngay; // static trong class phải khởi tạo giá trị ban đầu 
	int tuoi;
	int mssv;
	string lop;
	string ten;
	void display();//METHOD
	
	//director là 1 cơ chế tự động 
	~sinhvien(){
		count<<"Huy object co ten:"<<ten>>endl;
	}
};

int sinhvien::ngay;// khởi tạo gia trị ban đầu cho static

void sinhvien::display{
	cout<<"ten:"<<ten<<endl;
	cout<<"tuoi:"<<tuoi<<endl;
	cout<<"mssv:"<<mssv<<endl;
	cout<<"lop:"<<mssv<<endl;

}
void test1(){
	sinhvien sv1("thai",19,"CDEE"),sv2("tha",20,"fhsjd",14);//sv1 là OBJECT thuộc class sinhvien
	printf("dia chi sv1.mssv: %p\n",&(sv1.mssv));//khác địa chỉ
	printf("dia chi sv2.mssv: %p\n",&(sv2.mssv));//khác địa chỉ
	printf("--------------");
	printf("dia chi sv1.ngay: %p\n",&(sv1.ngay));//cung  địa chỉ
	printf("dia chi sv2.ngay: %p\n",&(sv2.ngay));//cung địa chỉ
	// Khi khởi tạo thì địa chỉ của nó tồn tại trong suốt chương trình nên member static này của các object sẽ đều có cùng 1 địa chỉ.
	sv1.display();
	sv2.display();	
}

int main(){
	test1();
	return 0;
	// sẽ in ra là ten,tuoi,mssv,lop,Huy object co ten thai
}
```
</details>


</details>
<details>
  <summary><h2>namespace</h2></summary>

- Namespace:là từ khóa trong C++ được sử dụng để phân biệt các hàm, lớp, biến cùng tên trong các file khác nhau.
 tạo những vùng nhớ khác nhau ,mỗi namespace là 1 chương trình riêng ,với 2 namespace khác nhau có thể tạo các biến trùng tên. Nhưng trong 1 namespace không thể có 2 biến cùng tên

<details>
<summary>Ví dụ:</summary>

```C++
//fileB.hpp

#include <iostream>

using namespace std;

namespace fileB{
    void function(() { cout << “function in fileB running.” << endl; }
}
//fileC.hpp
#include <iostream>

using namespace std;

namespace fileC{
    void function(() { cout << “function in fileC running.” endl; }
}


# 

```
**Dùng using namespace tên, có thể rút gọn code**
- Ví dụ:
```C++
using namespace onga;
int main(){
	cout<<"con ong a: teo"<<teo<<endl;
	return 0;
	
}

// FILE MAIN.CPP
#include <iostream>
#incldue “fileB.hpp”
#include “fileC.hpp”

using namespace std;

int main() {
    fileB::function();
    fileC::function();
    
    return 0;
}





```
</details>

</details>
<details>

  <summary><h3>Hướng đối tượng </h3></summary>

### hướng đối tượng là gi?
- OOP là một phương pháp lập trình dưới dạng các "đối tượng," mỗi đối tượng có chứa dữ liệu và các phương thức để thao tác dữ liệu đó.
- Các khái niệm quan trọng trong OOP bao gồm:
	+ Class: để tạo ra các đối tượng , nó mô tả dữ liệu và phương thức của đối tượng đó
	+ Đối tượng (Object) : Một đối tượng cụ thể được tạo ra từ class, có 
**Phạm vi truy cập:**
- Public:Member nào trong Public thì object có thể trỏ trực tiếp được và nội tại trong class cũng sử dụng được .
- protected:Member trong protected thì Class con có thể trỏ tới được
- private: Chỉ có nội tại trong class mới sử dụng được.Lý do đặt PROPERTY trong private, để chắc chắn object không trỏ tới được.

**1/Encapsulation (Tính đóng gói):**
- Object không được phép truy cập PROPERTY từ phạm vi public
- PROPERTY nằm ở private hoặc protected.
- Để truy cập PROPERTY phải thông qua method.
- Lý do để bảo vệ dữ liệu của một đối tượng khỏi sự xâm phạm từ bên ngoài.

<details>
<summary>Ví dụ:</summary>

```C++
#include<iostream>
#include<string>
using namespace std;
class doituong{
	private:
	int tuoi;//PROPERTY
	string ten;

	public:
	void hienthi(){//hienthi() method
	    cout<<"ten: "<<ten<<endl;
		cout<<"tuoi: "<<tuoi<<endl;
	}
	void setten(int name){
		ten=name;
	}
	void settuoi(int old){
		tuoi=old;
	}
	int gettuoi(){
		return tuoi;

	}
	string getten(){
		return ten;

	}
	

}
int main(){
	doituong dt;//dt là object thuộc class doituong
	dt.hienthi();
	return 0;
 }
```
</details>

**2/Inheritance (Tính kế thừa ):**
- Một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.
Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trongC++.

**khi nào nên dùng/không dùng class kế thừa**
- Nên dùng: Khi một lớp B được miêu tả là "B là một A". Ví dụ: một lớp hình tròn có thể kế thừa từ một lớp hình học.
- Không nên:Mối quan hệ "has-a" (có một) diễn ra khi một lớp chứa một đối tượng của một lớp khác. ví dụ: danhsachSV chứa một đối tượng sinhvien, do đó chúng ta có thể nói danhsachSV "có" hoặc "bao gồm" danh sách các sinh viên.

<details>
<summary>Ví dụ:</summary>

```C++
using namespace std;

class doituong{

	protected:
	int namsinh;
	string ten;
	int tuoi;
	public:
	void nhapthongtin(string name,int old,int year){ 
	    	ten=name;
			tuoi=old;
			namsinh=year;
	}
	void hienthi(){//hienthi() method cha
	    	cout<<"ten: "<<ten<<endl;
			cout<<"tuoi: "<<tuoi<<endl;
			cout<<"namsinh: "<<namsinh<<endl;
	}

};

class sinhvien : public doituong{
    protected:
	int MSSV;
	public:
	void setMSSV(int mssv){
		MSSV=mssv;
	}
	void hienthi(){// là method con từ cha và sửa nó thì được gọi là override(ghi đè)
		cout<<"MSSV: "<<MSSV<<endl;
		cout<<"ten: "<<ten<<endl;
		cout<<"tuoi: "<<tuoi<<endl;
		cout<<"namsinh: "<<namsinh<<endl;
		

	}

};


class HS : public sinhvien{
    private:
	int HS;
	public:
	void setHS(int hs){
		HS=hs;
	}
	void hienthi();

};
//thằng HS sẽ kế thừa thằng gần nhất >> hienthi(), sẽ kế thừa hienthi() của sinhvien chứ không phải doituong
int main(void){
    doituong dt;
	sinhvien sv;
	dt.nhapthongtin("hung",24,1883);
	dt.hienthi();
	printf("-----------\n");
	sv.nhapthongtin("thai",25,1992);
	sv.hienthi();

    return 0;
}
//ten: hung
//tuoi: 24
//namsinh: 1883
-----------
//MSSV: 0
//ten: thai
//tuoi: 25
//namsinh: 1992

```
</details>

- Các kiểu kế thừa: public,private và protected .Thì private là không  dùng vì class con kế thừa private sẽ đưa tất cả property từ class cha vào private. Làm cho các class tiếp theo không thể truy cập vào được( private chỉ cho phép nội tại class trỏ tới)

<details>
<summary>Ví dụ:</summary>

```C++
class doituong{
	protected:
	int namsinh;
	string ten;
	int tuoi;
	public:
	void nhapthongtin(string name,int old,int year){ 
	    	ten=name;
			tuoi=old;
			namsinh=year;
	}

};

class sinhvien : private doituong{	
	// tất cả property  của doituong sẽ chuyển vào private của sinhvien
 

};

class hs : private sinhvien{
 // lỗi vì thằng private không kế thừa và sử dụng được từ class con
};

```

</details>

**3/Polymorphism (Tính đa hình):**
- Các method có thể trùng tên với nhau , nhưng phải khác các input parameter
<details>
<summary>Ví dụ:</summary>

```C++
using namespace std;

class toanhoc{

	protected:
	int namsinh;
	void tong(int a,int b ){ 
	    	printf("tong a+b :%d\n",a+b);
	}
	void hienthi(int a,int b ,int c){ 
		printf("tong a+b+c :%d\n",a+b+c);
	}
	int hienthi(int a,double b){ 		
		return a +(int)b;
	}
};

int main(void){
	toanhoc th;
	th.tong(7,4);
	th.tong(5,3,5);
	printf("tong:%d\n",th.tong(5,6.7));

}
```
</details>

**4/Abstraction (Tính trừu tượng ):**

- Ẩn đi các chi tiết của một đối tượng và hiển thị những gì cần thiết, để sử dụng đối tượng đó.

**Template trong C++ là gì?**
- Là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- gồm 2 loại template function và template class;
template funcion cho phép người sử dụng dùng cùng một func với nhiều kiểu dữ liệu khác nhau mà không phải khai báo nhiều phiên bản của cùng 1 func mà khác kiểu dữ liệu.
template classs giống như của func nhưng đuocwj sử dụng cho class. Cho phép ta viết 1 class mà sử dụng nhiều kiểu dư3x liệu khác nhau
vi dụ:
```c++
template <typename T>
class Student{
private:
T a;
public:
Student(T A) : a(A){};
};

int main(){
    Student<int> khoi(42); // a=42 kieu int
    Student<float> khoi(42,1); // a=42,1 kieu float
}

```
<details>
<summary>Ví dụ</summary>

```C++	
void hienthi(int a,int b ,int c){ 
		printf("tong a+b+c :%d\n",a+b+c);
}
int hienthi(int a,double b){ 		
		return a +(int)b;
}
//thay vì dài như vậy ta có thể dùng Template do C++ hỗ trợ
//Code viết lại:
template <typename test>
test tong(test a,test b){
	return test(a +b);
}
int main(void){
	tong("tong a va b: %d\n",tong(6,4));
	tong("tong a va b: %f\n",tong(6.5,4.4));
} 
```
</details>


**Virtual trong C++ là gì?**
- Được sử dụng để tạo hàm ảo. Hàm ảo cho phép lớp con ghi đè hàm của lớp cha  . 


<details>
<summary>Ví dụ</summary>

```C++

 #include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->speak();  // Output: Dog barks
    animal2->speak();  // Output: Cat meows

    delete animal1;
    delete animal2;

    return 0;
}


```
</details>


</details>
<details>
  <summary><h2>Standard template library </h2></summary>

## STL là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến

**Một số thành phần chính của STL:**
- Container:Một container là một cấu trúc dữ liệu chứa nhiều phần tử gồm:
	+ Vector
	+ List
	+ Map
	+ Array

- Iterator
- Algorithms
- Functor


**Vector trong C++ là gì?**

- vector là một mảng động, tức là có khả năng thay đổi kích thước  
- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.
- Một số method của vector:
1. at(): Truy cập vào phần tử của vector
2. size(): Trả về kích thước của vector
3. resize(): Thay đổi kích thước của vector
4. begin(): Địa chỉ của phần tử đầu tiên của vector
5. end(): Địa chỉ của phần tử cuối cùng của vector
6. push_back(): Thêm phần tử vào vị trí cuối của vector
<details>
<summary>Ví dụ </summary>

```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  
    vector <int> arr1 = {2,5,7,4,9};

    arr1.at(0) = 3;
    arr1.resize(7);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    
    arr1.push_back(10);

    cout << "-----------" << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1.at(i) << endl;
    }
    

    return 0;
}

```

</details>


**List là gì**

- List là một c  danh sách liên kết hai chiều.
- Dưới đây là một số đặc điểm quan trọng của list:
	+ Truy cập tuần tự
	+ Hiệu suất chèn và xóa: 
- Một số method của list:
	+ push_back():
	+ pop_back():
	+ insert(): Chèn một node vào list
	+ erase(): Xóa một node của list
	+ size(): Trả về kích thước của list
- Sử dụng vector khi:
	+ Cần truy cập ngẫu nhiên đến các phần tử.
    + Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	+ Dung lượng có thể biết trước hoặc thay đổi ít.
- Sử dụng list khi:
	+ Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	+ Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.

**Map**
- Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử của map

**Array**
- Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)
- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []

# Iterator
- Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.

# Algorithm
- Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. 
- Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 















<details>
<summary>Ví dụ quan trọng</summary>

```C++
#include <iostream>
#include <string>
#include <vector>

#define in 0
#define intb 1
#define add 2
#define del 3
#define fix 4
#define rs 5
#define out 6


 

using namespace std;

class sinhvien {
protected:
    string tensv;
    int tuoisv;
    int idsv;
    float diemtoansv;
    float diemlysv;
    float diemhoasv;
    float diemtrungbinhsv;

public:
    sinhvien() : tuoisv(0), idsv(0), diemtoansv(0.0), diemlysv(0.0), diemhoasv(0.0), diemtrungbinhsv(0.0) {}

    sinhvien(string name, int old, int id, float diemtoan, float diemly, float diemhoa)
        : tensv(name), tuoisv(old), idsv(id), diemtoansv(diemtoan), diemlysv(diemly), diemhoasv(diemhoa) {}

    void nhapthongtinsv() {
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, tensv);

        cout << "Nhap tuoi sinh vien: ";
        cin >> tuoisv;

        do {
        cout << "Nhap diem toan sinh vien (0>>10): ";
        cin >> diemtoansv;
        } while (diemtoansv < 0 || diemtoansv >10 );
        
       

        do {
            cout << "Nhap diem ly sinh vien (0>>10): ";
            cin >> diemlysv;
        } while (diemlysv < 0 || diemlysv > 10);

        do {
            cout << "Nhap diem hoa sinh vien (0>>10): ";
            cin >> diemhoasv;
        } while (diemhoasv < 0 || diemhoasv > 10);
    }

    float diemtrungbinh() {
        diemtrungbinhsv = (diemtoansv + diemlysv + diemhoasv) / 3;
        return diemtrungbinhsv;
    }

    string layXepLoai()  {
        float dtb = diemtrungbinh();
        if (dtb > 8) {
            return "Gioi";
        } else if (dtb >= 6.5 && dtb < 8) {
            return "Kha";
        } else {
            return "TB";
        }
    }

    string layThongTin()  {
        return "Ten: " + tensv + "\nTuoi: " + to_string(tuoisv) + "\nID: " + to_string(idsv) +
               "\nDiem Toan: " + to_string(diemtoansv) + "\nDiem Ly: " + to_string(diemlysv) +
               "\nDiem Hoa: " + to_string(diemhoasv) + "\nDiem Trung Binh: " + to_string(diemtrungbinhsv) +
               "\nXep loai: " + layXepLoai();
    }

    int layIdSV()  {
        return idsv;
    }
    void setIdSV(int newId) {
        idsv = newId;
    }
 
};

class danhsachSV {
private:
    vector<sinhvien> danhsachsinhvien;
    static int maxId ;
    

public:
   
    void xoasv(int id) {
        int n = danhsachsinhvien.size();
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (danhsachsinhvien[i].layIdSV() == id) {
                found = true;
                // Xóa sinh viên tại vị trí i
                danhsachsinhvien.erase(danhsachsinhvien.begin() + i);
                cout << "Da xoa sinh vien co ID " << id << endl;

            break;  
            }   
        }  
        if (!found) {
        cout << "Khong tim thay sinh vien co ID " << id << endl;   
        }

    }

    void suaThongTinSV(int id) {
        int n = danhsachsinhvien.size();
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (danhsachsinhvien[i].layIdSV() == id) {
                found = true;
                cout << "Nhap thong tin moi cho sinh vien:\n";
                sinhvien svMoi;
                svMoi.nhapthongtinsv();
                svMoi.diemtrungbinh();
                danhsachsinhvien[i] = svMoi;
                cout << "Da cap nhat thong tin cho sinh vien co ID " << id << endl;

                break;  
            }
        }

        if (!found) {
            cout << "Khong tim thay sinh vien co ID " << id << endl;
        }
    }


    void sapXepTheoDiemTB() {
        int n = danhsachsinhvien.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                 
                if (danhsachsinhvien[j].diemtrungbinh() > danhsachsinhvien[j + 1].diemtrungbinh()) {                  
                    sinhvien temp = danhsachsinhvien[j];
                    danhsachsinhvien[j] = danhsachsinhvien[j + 1];
                    danhsachsinhvien[j + 1] = temp;
                }
            }
        }
    }

    void inThongTinDanhSach() const {
        for (auto sv : danhsachsinhvien) {
            cout << sv.layThongTin() << endl;
            cout << "-------------" << endl;
        }
    }

    void nhapThemSV() {
        sinhvien sv;
        maxId++;
        sv.setIdSV(maxId);
        sv.nhapthongtinsv();
        sv.diemtrungbinh();
        danhsachsinhvien.push_back(sv);
    }
    
    void reset(){
        danhsachsinhvien.clear();


    }
};

int danhsachSV::maxId = 0;

int main() {
    danhsachSV dssv;
    int nhapkey;
    int i_id;
    
    int soluongsv;

    do {
        cout << "Nhap so luong sinh vien (khong duoc am): ";
        cin >> soluongsv;
    } while (soluongsv < 0);

    for (int i = 0; i < soluongsv; i++) {
        dssv.nhapThemSV();
    }
    do {
        cout << "Vui long lam theo huong dan: "<< endl;
        cout << "Nhap 0:In ra danh sach sinh vien "<< endl;
        cout << "Nhap 1:In ra danh sach sinh vien theo diem TB"<< endl;
        cout << "Nhap 2:them sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 3:xoa sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 4:sua sinh vien va in ra theo diem TB"<< endl;
        cout << "Nhap 5:reset chuong trinh"<< endl;
        cout << "Nhap 6:thoat chuong trinh"<< endl;
    
    
        cin >> nhapkey;
        switch (nhapkey)
        {
        case  in:
            cout << "Danh sach sinh vien:"<< endl;;
            dssv.inThongTinDanhSach();
            break;

        case  intb:
            dssv.sapXepTheoDiemTB();
            cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh:"<< endl;;
            dssv.inThongTinDanhSach();
            break;

        case add:
            dssv.nhapThemSV(); 
            dssv.inThongTinDanhSach();  
            break;

        case del:
            cout << "vui long nhap id sinh vien can xoa:"<< endl;;
            cin >> i_id;
            dssv.xoasv(i_id);
            dssv.inThongTinDanhSach();  
            break;

        case fix:
            cout << "vui long nhap id sinh vien can sua:"<< endl;;
            cin >> i_id;
            dssv.suaThongTinSV(i_id); 
            dssv.inThongTinDanhSach();  
            break;
        case rs:
            cout << "reset tat ca du lieu" << endl;
            dssv.reset();
            break;
        case out:
            cout << "Thoat chuong trinh" << endl;
            break;
        
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai"<< endl;
            break;
        }
    }
    while (nhapkey!=6);
 
    return 0;

}


```
</details>

<details>
  <summary><h2>Smart pointer</h2></summary>

## SmartPointer là gì
 là một cơ chế quản lý bộ nhớ tự động giúp hạn chế rủi ro của lỗi liên quan đến quản lý bộ nhớ giúp người lập trình tránh được việc quản lý bộ nhớ
### unique Pointer 
 là một loại của smart pointer trong 1 thời điêmr thì 1 OBJ chỉ có thể đuocwj trỏ bởi 1 unique_pointer
### share Pointer
 cũng là 1 loại smart pointer thì nó có thể nhiều con trỏ cùng trỏ đến 1 obj hay arry . nó cũng cung cấp 1 method để đếm được có baop nhiêu con share pointer đang trỏ đến obj hay array. nó sửi dụng bộ đếm tham chiếu để theo dỗi đối tượng 
### Weak pointer
 là một cơ chế giữ tham chiếu đến đồi tượng được quản lý bởi shared-ptr. nó cung cấp cách để theo dỗi đối tượng 1 cách an toàn mà không tăng thêm bộ đếm tham chiếu shared-pointer. Nó k trực tiếp truy cập đến đối tượng
 weak_ptr có một phương thức là lock(), mà trả về một shared_ptr. Nếu shared_ptr mà weak_ptr theo dõi vẫn tồn tại, lock() sẽ trả về một shared_ptr hợp lệ có thể sử dụng để truy cập đối tượng. Ngược lại, nếu shared_ptr đã bị giải phóng, lock() sẽ trả về một shared_ptr rỗng.

</details>
<details>
  <summary><h2>Can Protoco</h2></summary>

![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/64e8f67e-1e2f-46b8-a6d5-9e2274c391bc)
![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/8d2eb925-5a75-4f3b-94f8-40b9854c9fc7)

### độ ưu tiên khi truyền dữ liệu

mỗi Can đều có 1 id do lập trình viên quy định (tự cài đặt)
![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/5771e2d1-8f00-4ead-acb6-bfcb5b75baf7)
vd 
0100001001
0101110000

khi truyền địa chỉ id do truyền đi bit nào can module sẽ nhận lại đúng mức đó với đó do 2 dây tx và rx đều nối vào can high và can low khi có sự sai lệch giữa các bit truyền đi và nhận vào thì can nào có bit ở id bằng 0 sẽ được ưu tiên hơn từ biết có trọng số cao đến thâp buộc can có bit cao ở địa chỉ id vào chế độ chờ nhận đây là cách mà can phân biệt ai sẽ truyền ai nhận cùng thời điểm. 

![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/7bfd6264-4afd-4182-b606-cdf1296a4ae0)

### cách truyền bit 0 và 1 
![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/7eee81b1-5d96-46d1-8479-092600502e5b)

![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/a225c622-8bcd-421b-b6d1-9508dea2a231)
</details>

<details>
  <summary><h2>AUTOSAR Classic </h2></summary>
Autosar Classic là một kiến trúc phần mềm tiêu chuẩn dành cho các hệ thống điều khiển trong xe hơi. Nó bao gồm một bộ các tiêu chuẩn, khung làm việc và các hướng dẫn được phát triển bởi một liên minh các nhà sản xuất ô tô và nhà cung cấp linh kiện ô tô (như Daimler, BMW, Ford, General Motors, Bosch, Continental, và nhiều hãng khác).

Autosar Classic được thiết kế để cung cấp một cơ sở phần mềm chuẩn cho việc phát triển phần mềm điều khiển xe hơi. Nó giúp giảm thiểu sự phụ thuộc vào nhà cung cấp, tăng tính tương thích và tái sử dụng mã, và tạo điều kiện cho việc phát triển các tính năng phức tạp trong các hệ thống điều khiển xe hơi.

### overview
![image](https://github.com/khoinguyenAdonis/Embedded_Interview_T10/assets/143527982/592d761f-422c-4fe5-8729-40ebab36b83d)

- Mirocontroler : là những chip vd stm32 ... nạp chương trình viết bằng thanh ghi 
- MCAL : nơi viết các function để điều khiển mirocontroler cung cấp API cho các layer phía trên sử dụng mà không cần phải quan tâm đến phần cứng
- ECU Abstractuion layer: nơi chứa những tính năng cụ thể đuocwj viết bằng các API cung cấp từ MCAL mà không cần quan tâm đến hạ tầng dưới 
- Service layer : cung cấp các dịch vụ và chức năng cần thiết cho việc chạy ứng dụng trên các thiết bị nhúng. Hạ tầng RTE đóng vai trò quan trọng trong việc quản lý việc thực thi các mô-đun phần mềm và quản lý tài nguyên hệ thống. 
    Quản lý vòng đời của ứng dụng: Hạ tầng RTE theo dõi và điều khiển vòng đời của các ứng dụng và mô-đun phần mềm, bao gồm việc khởi tạo, chạy, và dừng lại.

    Quản lý tài nguyên hệ thống: Hạ tầng RTE quản lý các tài nguyên hệ thống như bộ nhớ, cổng giao tiếp, và tài nguyên phần cứng khác, đảm bảo rằng chúng được sử dụng hiệu quả và đúng cách bởi các ứng dụng.

    Quản lý thời gian thực: Hạ tầng RTE hỗ trợ quản lý thời gian thực cho các ứng dụng, bao gồm việc lập lịch, định thời, và xử lý sự kiện trong các khoảng thời gian cố định.

    Giao tiếp giữa các mô-đun phần mềm: Hạ tầng RTE cung cấp các cơ chế để ứng dụng và mô-đun phần mềm có thể giao tiếp và trao đổi dữ liệu với nhau một cách an toàn và đáng tin cậy.

    Quản lý lỗi và xử lý ngoại lệ: Hạ tầng RTE có khả năng xử lý lỗi và ngoại lệ xảy ra trong quá trình thực thi ứng dụng, đảm bảo tính ổn định và tin cậy của hệ thống.
- Application layer : Nó thực hiện các chức năng liên quan đến ứng dụng cụ thể mà người dùng cuối sử dụng để tương tác với mạng hoặc hệ thống. thông qua RTE gọi xuống các api dưới mcal r xuống mirocontroler 

BSW  là gòm các MCAL, compliex driver, service layer, ECU Abstraction  
</details>
</details>