#include <iostream>
#include <cmath>

class Vector3 {
    public:
        double x,y,z;

        friend std::ostream& operator<< (  std::ostream& os, const Vector3& v);
        friend std::istream& operator>> ( std::istream& is,  Vector3& v);

        Vector3 operator+ (const Vector3 &V1 );
        Vector3 operator- (const Vector3& V1);
        bool operator== (const Vector3 &V1);
        Vector3 operator= (const Vector3 &V1);
        Vector3& operator++ ();
        Vector3& operator++(int);
        Vector3 operator*(int) const;
        Vector3 operator/(int) const;

        double vectors_lenght() const;
        
};


int main(){
    Vector3 v1;
    std::cin>>v1;
    
    double l = v1.vectors_lenght();

    Vector3 v = v1/5;
    
    return 0;
}

 Vector3 Vector3::operator+ (const Vector3 &V1){
    Vector3 v;
    v.x = V1.x + this->x;
    v.y = V1.y + this->y;
    v.z = V1.z + this->z;
    return v;
}

std::ostream& operator<< (  std::ostream& os, const Vector3& v){
     os <<"("<< v.x <<","<< v.y <<","<< v.z <<")"<<"\n";  
     return os;
}

std::istream& operator>> ( std::istream& is, Vector3& v){
    std::cout << " Enter x,y,z coordinates:: ";
    is >> v.x >> v.y >> v.z;
    return is;
}

Vector3 Vector3::operator- (const Vector3& V1){
    Vector3 v;
    v.x = this->x - V1.x;
    v.y = this->y - V1.y;
    v.z = this->z - V1.z;
    return v;
}

bool Vector3::operator== (const Vector3& V1){
    Vector3 v;
    if (V1.x==this->x && V1.y==this->y && V1.z==this->z)
        return true;
    else   
        return false;
}

Vector3 Vector3::operator= (const Vector3 &V1){
    Vector3 v;
    v.x=V1.x;
    v.y=V1.y;
    v.z=V1.z;
    return v;
}

Vector3& Vector3::operator++ (){
    x++;
    y++;
    z++;
    return *this;
}

Vector3& Vector3::operator++(int){
    Vector3 v =*this;
    ++*this;
    return *this; 

}

Vector3 Vector3::operator*(int n) const {
    Vector3 v;
    v.x=x*n;
    v.y=y*n;
    v.z=z*n;
    return v;
}


Vector3 Vector3::operator/(int n) const {
    Vector3 v;
    v.x=x/n;
    v.y=y/n;
    v.z=z/n;
    return v;
}

double Vector3::vectors_lenght() const {
    double n;
    n=sqrt(x*x+y*y+z*z);
    return n;
}
