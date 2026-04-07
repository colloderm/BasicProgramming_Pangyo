#include <cstdio>

int main(int argc, char* argv[])
{
    printf("=== C++ 20 Console Application ===\n\n");
    
    // 1. 이중 for문 예시 - 구구단 출력
    printf("--- Double For Loop Example (Multiplication Table) ---\n");
    for (int i = 2; i <= 4; ++i) {
        for (int j = 1; j <= 5; ++j) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    
    // 2. do-while문 - 일단 최소 1번은 실행시킨 후 조건을 판별.
    printf("--- Do-While Loop Example ---\n");
    int count = 5;
    do {
        printf("Count: %d\n", count);
        count++;
    } while (count < 5);
    
    printf("\n=== Program End ===\n");
    
    return 0;
}
