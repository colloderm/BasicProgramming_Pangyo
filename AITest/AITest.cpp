#include <iostream>
#include <string>
#include <ctime>   // time() 사용을 위해 필요
#include <cstdlib> // rand(), srand() 사용을 위해 필요

using namespace std;

// --- 상위 클래스 및 캐릭터 설계 ---

// class Character {
// protected:
//     string Name;
//     int HP;
//     int MaxHP;
//     int AttackPower;
//
// public:
//     Character(string name, int hp, int atk) : Name(name), HP(hp), MaxHP(hp), AttackPower(atk) {}
//     virtual ~Character() = default;
//
//     string GetName() const { return Name; }
//     bool IsDead() const { return HP <= 0; }
//     int GetAttackPower() const { return AttackPower; }
//
//     virtual void TakeDamage(int damage) {
//         HP -= damage;
//         if (HP < 0) HP = 0;
//         cout << Name << "이(가) " << damage << "의 피해를 입었습니다. (남은 HP: " << HP << ")\n";
//     }
// };
//
// class Player : public Character {
// private:
//     int Level;
//     int EXP;
//     int MaxEXP;
//     int CriticalChance; // 강타 확률 (0~100)
//
// public:
//     Player(string name) : Character(name, 150, 20), Level(1), EXP(0), MaxEXP(100), CriticalChance(20) {}
//
//     // 강타 로직이 포함된 공격력 계산
//     int GetCalculatedDamage(bool& outIsCritical) {
//         int chance = rand() % 100; // 0~99 사이 난수
//         if (chance < CriticalChance) {
//             outIsCritical = true;
//             return AttackPower * 2; // 강타 시 2배 데미지
//         }
//         outIsCritical = false;
//         return AttackPower;
//     }
//
//     void GainEXP(int exp) {
//         EXP += exp;
//         cout << "\n[경험치 +" << exp << " 획득!]\n";
//         if (EXP >= MaxEXP) LevelUp();
//     }
//
//     void LevelUp() {
//         Level++;
//         EXP -= MaxEXP;
//         MaxEXP += 50;
//         MaxHP += 30;
//         HP = MaxHP;
//         AttackPower += 10;
//         cout << "▶▶ LEVEL UP! 현재 레벨: " << Level << " ◀◀\n";
//     }
//
//     void PrintStatus() {
//         cout << "\n[" << Name << " Status] LV:" << Level << " HP:" << HP << "/" << MaxHP << " ATK:" << AttackPower << " EXP:" << EXP << "/" << MaxEXP << "\n";
//     }
// };
//
// class Monster : public Character {
// private:
//     int DropEXP;
//
// public:
//     Monster(string name, int hp, int atk, int dropExp)
//         : Character(name, hp, atk), DropEXP(dropExp) {}
//
//     int GetDropEXP() const { return DropEXP; }
// };
//
// // --- 전투 및 생성 시스템 ---
//
// class Battle {
// public:
//     static void StartBattle(Player& player, Monster& monster) {
//         cout << "\n!!! " << monster.GetName() << "이(가) 나타났습니다 !!!\n";
//
//         while (!player.IsDead() && !monster.IsDead()) {
//             cout << "1. 공격 2. 도망 : ";
//             int choice;
//             cin >> choice;
//
//             if (choice == 1) {
//                 // 플레이어 공격 (강타 확률 체크)
//                 bool isCritical = false;
//                 int finalDamage = player.GetCalculatedDamage(isCritical);
//
//                 if (isCritical) cout << "★[CRITICAL HIT] 강력한 일격을 날립니다!★\n";
//                 else cout << "[" << player.GetName() << "의 일반 공격]\n";
//                 
//                 monster.TakeDamage(finalDamage);
//
//                 if (monster.IsDead()) {
//                     cout << "몬스터를 처치했습니다!\n";
//                     player.GainEXP(monster.GetDropEXP());
//                     return;
//                 }
//
//                 // 몬스터 공격
//                 cout << "\n[" << monster.GetName() << "의 반격]\n";
//                 player.TakeDamage(monster.GetAttackPower());
//
//                 if (player.IsDead()) return;
//             } 
//             else {
//                 cout << "전투에서 이탈합니다.\n";
//                 return;
//             }
//         }
//     }
// };
//
// // 몬스터 랜덤 생성을 위한 헬퍼 함수
// Monster* SpawnRandomMonster() {
//     int roll = rand() % 3; // 0, 1, 2
//     switch (roll) {
//         case 0: return new Monster("슬라임", 30, 5, 30);
//         case 1: return new Monster("오크", 80, 15, 70);
//         case 2: return new Monster("드래곤", 200, 40, 250);
//         default: return new Monster("고블린", 50, 10, 50);
//     }
// }

// 1. 부모 클래스
class Parent 
{
public:
    virtual ~Parent() {} // 다형성을 위한 가상 소멸자

    // 정적 바인딩 (컴파일 타임 결정)
    void NormalFunction() 
    {
        printf("Parent : 정적 바인딩 호출됨 (포인터 타입 기준)\n");
    }

    // 동적 바인딩 (런타임 결정)
    virtual void VirtualFunction() 
    {
        printf("Parent : 동적 바인딩 호출됨\n");
    }
};

// 2. 자식 클래스
class Child : public Parent 
{
public:
    ~Child() override {}

    // 부모의 일반 함수를 가림 (Hiding)
    void NormalFunction() 
    {
        printf("Child  : 정적 바인딩 호출됨\n");
    }

    // 부모의 가상 함수를 덮어씀 (Overriding)
    void VirtualFunction() override 
    {
        printf("Child  : 동적 바인딩 호출됨 (실제 객체 기준)\n");
    }
};

// --- 메인 루프 ---

int main() {
    // srand(static_cast<unsigned>(time(nullptr))); // 실행할 때마다 다른 랜덤값 설정
    //
    // Player hero("초보 용사");
    // cout << "RPG 게임에 접속했습니다.\n";
    //
    // while (true) {
    //     hero.PrintStatus();
    //     cout << "무엇을 하시겠습니까? (1. 탐험 2. 휴식 3. 종료) : ";
    //     int action;
    //     cin >> action;
    //
    //     if (action == 1) {
    //         Monster* enemy = SpawnRandomMonster(); // 랜덤 몬스터 생성
    //         Battle::StartBattle(hero, *enemy);
    //         delete enemy; // 동적 할당 메모리 해제 필수
    //
    //         if (hero.IsDead()) {
    //             cout << "당신은 쓰러졌습니다... GAME OVER\n";
    //             break;
    //         }
    //     }
    //     else if (action == 2) {
    //         cout << "마을에서 휴식하여 체력을 회복합니다.\n";
    //         // 간단한 회복 로직 추가 가능
    //     }
    //     else if (action == 3) {
    //         cout << "게임을 종료합니다.\n";
    //         break;
    //     }
    // }
    
    printf("--- 바인딩 테스트 시작 ---\n\n");

    // 3. 부모 포인터로 자식 객체를 가리킴 (다형성의 핵심)
    Parent* myPointer = new Child();

    // 4-1. 정적 바인딩 테스트 (일반 함수)
    // 컴파일러는 myPointer가 Parent* 타입이라는 것만 보고 Parent의 함수를 박아넣음.
    myPointer->NormalFunction();

    // 4-2. 동적 바인딩 테스트 (가상 함수)
    // 런타임에 myPointer가 가리키는 실제 메모리(Child)를 추적해서 Child의 함수를 실행함.
    myPointer->VirtualFunction();

    printf("\n--- 메모리 해제 ---\n");
    delete myPointer;

    return 0;
}
