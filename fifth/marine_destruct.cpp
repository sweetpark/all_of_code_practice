#include <iostream>
#include <string.h>

class Marine{

    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char *name;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, const char *marine_name);
        ~Marine();
        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);



        void show_status();
};

//생성자 (인자 x)
Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage =5;
    is_dead = false;
    name = NULL;
}

//생성자 (인자 o) 
Marine::Marine(int x, int y){
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;

}

Marine::Marine(int x, int y, const char *marine_name){
    name = new char[strlen(marine_name) +1];
    strcpy(name, marine_name);
    hp = 50;
    damage = 5;
    coord_x = x;
    coord_y = y;
}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status(){
    //  std::cout << " *** Marine : " << name <<" *** " << std::endl;
    printf("*** Marine : %s ***\n",name);
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
//소멸자 (소멸자는 인자를 가지지 않는다 - 인자를 받아서 무엇하나?)
Marine::~Marine(){
    printf("%s 의 소멸자 호출! \n",name);
    if(name != NULL){
        delete[] name;
    }
}

int main() {
    Marine* marines[100];
    marines[0] = new Marine(2,3, "Marine 1");
    marines[1] = new Marine(3,5, "Marine 2");
    marines[2] = new Marine(2,3);
    marines[3] = new Marine(3,5);

    marines[0]->show_status();
    marines[1]->show_status();
    marines[2]->show_status();
    marines[3]->show_status();
    

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}