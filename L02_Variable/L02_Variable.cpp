#include <cstdio>

int main(int argc, char* argv[])
{
    printf("== Variant ============\n");
    
    // 변수의 선언 ==> 자료형은 int(정수형) / 변수 이름이 A
    int A; // 선언만 하면 A는 쓰레기 값만 들어감 =>
    A = 1024; // 대입
    printf("A = %d\n", A);
    
    // 변수의 선언 + 정의(definition) ==> 값을 넣어서 변수를 초기화 시켜주는것
    int B = 100;
    B = 2222;
    B = -130;
    printf("B = %d\n", B);
    
    // 상수, 리터럴(literal)
    const int Val = 5; // 선언만 하면 컴파일 오류
    int const Val2 = 10;
    
    char C = 'A';
    
    char szString[] = "Hello"; // "Hello" 문자열 리터럴
    printf("szString = %s\n", szString);
    
    bool Boolean = true; // true(참): 1, false(거짓): 0
    
    return 0;
}
