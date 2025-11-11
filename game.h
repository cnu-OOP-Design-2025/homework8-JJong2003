#pragma

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Character {
protected:
    string description;
public:
    virtual std::string getDescription() const { return description; };
    virtual int getAttack() const = 0;
    virtual int getSpeed() const = 0;
    virtual int getDefense() const = 0;
    virtual ~Character() {}
};

class Knight : public Character {
public:
    Knight() { description = "Knight"; }
    int getAttack() const override {return 70;}
    int getSpeed() const override {return 40;}
    int getDefense() const override {return 80;}
};

class Wizard : public Character {
public:
    Wizard() { description = "Wizard"; }
    int getAttack() const override {return 50;}
    int getSpeed() const override {return 50;}
    int getDefense() const override {return 30;}
};

class Archer : public Character {
public:
    Archer() { description = "Archer"; }
    int getAttack() const override {return 60;}
    int getSpeed() const override {return 70;}
    int getDefense() const override {return 40;}
};

class equip_testmentDecorator : public Character {
protected:
    Character* character;
public:
    equip_testmentDecorator(Character* c) : character(c) {}
    virtual ~equip_testmentDecorator() { delete character; }
};

// 방어력+30, 스피드-5
class Armor : public equip_testmentDecorator {
public:
    Armor(Character* c) : equip_testmentDecorator(c) {}
    string getDescription() const override {return character->getDescription() + ", Armor";}; 
    int getAttack() const override {return character->getAttack();}
    int getSpeed() const override {return character->getSpeed() -5;}
    int getDefense() const override {return character->getDefense() +30;}
};

// 스피드 +15
class Boots : public equip_testmentDecorator {
public:
    Boots(Character* c) : equip_testmentDecorator(c) {}
    string getDescription() const override {return character->getDescription() + ", Boots";}
    int getAttack() const override {return character->getAttack();}
    int getSpeed() const override {return character->getSpeed() +15;}
    int getDefense() const override {return character->getDefense();}
};

// 공격력 +20 (마법사 착용시 +60)
class Staff : public equip_testmentDecorator {
public:
    Staff(Character* c) : equip_testmentDecorator(c) {}
    string getDescription() const override {return character->getDescription() + ", Staff";}
    int getAttack() const override {
        return (character->getDescription().compare("Wizard") == 0 ? character->getAttack() + 60 : character->getAttack() + 20);
    }
    int getSpeed() const override {return character->getSpeed();}
    int getDefense() const override {return character->getDefense();}
};

// 공격력 +30 (기사 착용시 +70)
class Sword : public equip_testmentDecorator {
public:
    Sword(Character* c) : equip_testmentDecorator(c) {}
    string getDescription() const override {return character->getDescription() + ", Sword";}
    int getAttack() const override {
        // Knight *kn = dynamic_cast<Knight *> (character); // 이게 왜 자꾸 nulltpr로 나올까?  ->  이 앞전에 사용된 장비를 고려해야 됨  -> ptr의 chain
        // if (kn != nullptr)
        //     return character->getAttack() + 70;
        
        // // 반복문으로 데코레이터를 벗긴다
        // Character *baseCharacter = this->character;
    
        // while (auto* deco = dynamic_cast<equip_testmentDecorator *>(baseCharacter)) {
        //     baseCharacter = deco->character;    // protected라 안된다..
        // }

        return character->getAttack() + 30;
    }
    int getSpeed() const override {return character->getSpeed();}
    int getDefense() const override {return character->getDefense();}
};

// 공격력 +25 (궁수 착용시 +65)
class Bow : public equip_testmentDecorator {
public:
    Bow(Character* c) : equip_testmentDecorator(c) { }
    string getDescription() const override {return character->getDescription() + ", Bow";}
    int getAttack() const override {
        return (character->getDescription().compare("Archer") == 0 ? character->getAttack() + 65 : character->getAttack() + 25);
    }
    int getSpeed() const override {return character->getSpeed();}
    int getDefense() const override {return character->getDefense();}
};
