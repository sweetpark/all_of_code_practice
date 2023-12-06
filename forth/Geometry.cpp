#include <iostream>

#define size_of_array 5

class Point{
    private:
        int pos_x;
        int pos_y;

    public:
        Point(int x, int y)
        {
            pos_x = x;
            pos_y = y;
        }

        int GetX(){
            return pos_x; 
        }
        int GetY(){
            return pos_y;
        }
};


class Geometry{
    private:
        Point* point_arr[5];
        int num_point;

    public:

        Geometry(){
            num_point=0;
        }

        void AddPoint(const Point &point){
            point_arr[num_point++]=new Point(point);
        }

        void PrintPoint(){
            for(int i =0; i<size_of_array; i++){
                std::cout<< point_arr[i]->GetX() << "," <<point_arr[i]->GetY() <<std::endl;
            }
        }



        int PrintMeetPoint(const Geometry &geometry){
            int cnt =0;
            for(int i=0; i<size_of_array; i++){
                for(int k=i+1; k<size_of_array; k++ ){
                    int a = geometry.point_arr[k]->GetX() - geometry.point_arr[i]->GetX();
                    int b = geometry.point_arr[k]->GetY() - geometry.point_arr[i]->GetY();
                    int c = -(geometry.point_arr[i]->GetX()*(geometry.point_arr[k]->GetX()-geometry.point_arr[i]->GetX()) + geometry.point_arr[i]->GetY()*(geometry.point_arr[k]->GetY()-geometry.point_arr[i]->GetY()));
                    for (int j=0; j<size_of_array; j++){
                        if (i != j && k != j){
                            for(int l =j+1; l<size_of_array; l++){
                                if (l != i && l != k){
                                    std::cout << "=======Meet Calc=======" <<std::endl;
                                    std::cout << "i: " << i << " k : " << k << " j : " << j <<" l : " << l <<std::endl;
                                    double result =(a*geometry.point_arr[j]->GetX()+b*geometry.point_arr[j]->GetY()+c)*(a*geometry.point_arr[l]->GetX()+b*geometry.point_arr[l]->GetY()+c);
                                    std::cout << "f(x) : " << a <<"x + " <<b << "y " << c << std::endl; 
                                    std::cout << "{f(x1,y1)*f(x2,y2)<=0 condition} result =  " << result << std::endl;
                                    std::cout << "=======Meet End ========" <<std::endl;
                                    std::cout << std::endl;
                                    if(result <= 0){
                                        cnt++;
                                        continue;
                                    }else{
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return cnt;
        }
};


int main(){
    
    Point point(1,2);
    Point point2(2,3);
    Point point3(3,5);
    Point point4(4,6);
    Point point5(0,0);

    Geometry test;

    test.AddPoint(point);
    test.AddPoint(point2);
    test.AddPoint(point3);
    test.AddPoint(point4);
    test.AddPoint(point5);
    

    test.PrintPoint();

    int meet_count=test.PrintMeetPoint(test);
    std::cout << "Meet count : " <<meet_count << std::endl;

    return 0;
}