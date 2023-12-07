#include <iostream>

class Marine{

    int hp;
    int coord_x, coord_y;
    //상수화 진행 (고정값)
    const int default_damage;
    bool is_dead;


    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);



        void show_status();
};

//생성자 (인자 x) , 생성자 선언 + 초기화
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

//생성자 (인자 o) 
Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status(){
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}


int main() {
    Marine marine1(2,3);
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    marine1.be_attacked(marine2.attack());

    marine1.show_status();
    marine2.show_status();
    
}