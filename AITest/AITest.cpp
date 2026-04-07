#include <stdio.h>
#include "Player.h"

int main()
{
    // 1. 크기가 3인 정수형 배열 선언 및 초기화
    int arr[3] = {10, 20, 30};

    // 2. 포인터 변수에 배열의 시작 주소 할당
    // 배열의 이름(arr)은 첫 번째 원소의 주소(&arr[0])로 암시적 변환(Decay)됩니다.
    int* ptr = arr; 

    printf("[배열과 포인터 접근 원리 테스트]\n");
    printf("배열의 시작 주소(arr): %p\n", (void*)arr);
    printf("포인터가 가진 주소(ptr): %p\n\n", (void*)ptr);

    // 3. 반복문을 통한 배열 요소 순회
    for (int i = 0; i < 3; ++i)
    {
        printf("--- 인덱스 %d ---\n", i);
        
        // 방법 A: 대괄호(인덱스)를 사용한 일반적인 접근
        printf("배열 인덱스 접근 (arr[%d]) : %d\n", i, arr[i]);
        
        // 방법 B: 포인터에 오프셋(i)을 더한 뒤 역참조(*)하여 접근
        // ptr + 1은 단순히 숫자 1이 더해지는 것이 아니라, 자료형(int, 4바이트) 크기만큼 주소가 이동합니다.
        printf("포인터 연산 접근 (*(ptr + %d)) : %d\n\n", i, *(ptr + i));
    }
    
    printf("[구조체 선언 및 C++20 초기화 테스트]\n");

    // C++20 지정 초기화(Designated Initializers)
    // 멤버의 이름을 명시하여 어떤 값이 들어가는지 명확하게 보여줍니다.
    // 주의: 구조체에 선언된 순서대로 초기화해야 합니다.
    CharacterState player = {
        .ID = 1001,
        .Level = 15,
        .HP = 250.5f
    };

    // 점(.) 연산자를 통한 멤버 접근 및 출력
    printf("플레이어 ID : %d\n", player.ID);
    printf("현재 레벨   : %d\n", player.Level);
    // %.1f는 소수점 첫째 자리까지만 출력하라는 포맷 지정자입니다.
    printf("현재 체력   : %.1f\n", player.HP);

    return 0;
}
