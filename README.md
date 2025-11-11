[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/R-2vi5zq)
# Decorator 패턴 실습: 게임 캐릭터 장비 시스템

## 개요
Decorator 패턴을 활용하여 게임 캐릭터가 다양한 장비를 동적으로 착용하고, 스탯(공격력, 스피드, 방어력)이 변경되는 시스템을 구현하세요.

## 요구사항
- Decorator 패턴을 사용하여 캐릭터에 장비를 동적으로 추가할 수 있어야 합니다.
- 각 캐릭터는 공격력(Attack), 스피드(Speed), 방어력(Defense) 세 가지 스탯을 가집니다.
- 장비는 해당 스탯을 변경합니다.

## 구현할 클래스
- Character (추상 클래스)
- Knight, Wizard, Archer (구체 캐릭터 클래스)
- EquipmentDecorator (데코레이터 클래스) 
- Armor, Boots, Staff, Sword, Bow (구체 데코레이터 클래스)

## 아래 클래스 다이어그램을 참고하여 Class 구현
```
+----------------------+
|    <<abstract>>      |
|      Character       | 
|----------------------|
| + description        |
|----------------------|
| + getDescription()   |
| + getAttack()        |
| + getSpeed()         |
| + getDefense()       |
+----------------------+
           ▲
           |
           +---------------------------+----------------------------+--------------------------+
           |                           |                            |                          |
+----------------------+    +----------------------+    +----------------------+    +----------------------+
|     EquipDecorator   |    |       Knight         |    |       Wizard         |    |       Archer         |
+----------------------+    +----------------------+    +----------------------+    +----------------------+
| + charactor          |    | + getAttack()        |    | + getAttack()        |    | + getAttack()        |
| ---------------------|    | + getSpeed()         |    | + getSpeed()         |    | + getSpeed()         |
|                      |    | + getDefense()       |    | + getDefense()       |    | + getDefense()       |
+----------------------+    +----------------------+    +----------------------+    +----------------------+
           ▲
           | 
           +-----------------------+----------------------+-------------------------+---------------------+
           |                       |                      |                         |                     |
+-------------------+   +-------------------+   +-------------------+   +-------------------+   +-------------------+
|       Armor       |   |       Boots       |   |       Staff       |   |       Sword       |   |        Bow        |
|-------------------|   |-------------------|   |-------------------|   |-------------------|   |-------------------|
| + getDescription()|   | + getDescription()|   | + getDescription()|   | + getDescription()|   | + getDescription()|
| + getAttack()     |   | + getAttack()     |   | + getAttack()     |   | + getAttack()     |   | + getAttack()     |
| + getSpeed()      |   | + getSpeed()      |   | + getSpeed()      |   | + getSpeed()      |   | + getSpeed()      |
| + getDefense()    |   | + getDefense()    |   | + getDefense()    |   | + getDefense()    |   | + getDefense()    |
+-------------------+   +-------------------+   +-------------------+   +-------------------+   +-------------------+

```

## 각 캐릭터 기본 스탯
- Knight: 공격력 70, 스피드 40, 방어력 80
- Wizard: 공격력 50, 스피드 50, 방어력 30
- Archer: 공격력 60, 스피드 70, 방어력 40

## 장비 효과
- Armor: 방어력 +30, 스피드 -5
- Boots: 스피드 +15
- Staff: 공격력 +20 (마법사 착용시 +60)
- Bow: 공격력 +25 (궁수 착용시 +65)
- Sword: 공격력 +30 (기사 착용시 +70)


## 실행 방법
1. C++로 클래스를 구현합니다.
2. 캐릭터 객체를 생성하고, 장비 데코레이터로 감쌉니다.
3. 최종 설명과 스탯을 출력합니다.

예시 코드:
```cpp
Character* knight = new Knight();
knight = new Armor(knight);
knight = new Boots(knight);
knight = new Sword(knight);
cout << knight->getDescription() << endl;  // Print Knight, Armor, Boots, Sword
cout << knight->getAttack() << endl;       // Print 100
cout << knight->getSpeed() << endl;        // Print 50
cout << knight->getDefense() << endl;      // Print 110
```

## 생각해보기
- 장비 해제 기능을 추가하려면 어떻게 해야 할까요?



### 예상 출력
```
-------------------------------------------------------------
Knight, Armor, Boots, Sword | Attack: 100 | Speed: 50 | Defense: 110
Knight, Armor, Bow | Attack: 95 | Speed: 35 | Defense: 110
Knight, Boots, Staff | Attack: 90 | Speed: 55 | Defense: 80
-------------------------------------------------------------
Wizard, Armor, Boots, Sword | Attack: 80 | Speed: 60 | Defense: 60
Wizard, Armor, Bow | Attack: 75 | Speed: 45 | Defense: 60
Wizard, Boots, Staff | Attack: 70 | Speed: 65 | Defense: 30
-------------------------------------------------------------
Archer, Armor, Boots, Sword | Attack: 90 | Speed: 80 | Defense: 70
Archer, Armor, Bow | Attack: 85 | Speed: 65 | Defense: 70
Archer, Boots, Staff | Attack: 80 | Speed: 85 | Defense: 40
-------------------------------------------------------------
```

## 테스트 방법

모든 함수 구현 후, 아래 명령어를 통해 테스트를 실행하세요:

### Windows 사용자
```
.\test8.bat
```

### MacOS/Linux 사용자
```bash
/bin/bash test8.sh
```
