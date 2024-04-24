#include <iostream>
#include <cmath>

class Vector3 {
public:
    double x, y, z;

    Vector3() : x(0), y(0), z(0) {} 
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    friend std::istream& operator>>(std::istream& is, Vector3& v);

    Vector3 operator+(const Vector3& V1) const;
    Vector3 operator-(const Vector3& V1) const;
    Vector3 operator*(double n) const;
    Vector3 operator/(double n) const;

    bool operator==(const Vector3& V1) const;

    Vector3& operator=(const Vector3& V1);

    Vector3& operator++();  
    Vector3 operator++(int); 

    double vectors_length() const;
};

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector3& v) {
    is >> v.x >> v.y >> v.z;
    return is;
}

Vector3 Vector3::operator+(const Vector3& V1) const {
    return Vector3(x + V1.x, y + V1.y, z + V1.z);
}

Vector3 Vector3::operator-(const Vector3& V1) const {
    return Vector3(x - V1.x, y - V1.y, z - V1.z);
}

bool Vector3::operator==(const Vector3& V1) const {
    return (x == V1.x && y == V1.y && z == V1.z);
}

Vector3& Vector3::operator=(const Vector3& V1) {
    if (this != &V1) {
        x = V1.x;
        y = V1.y;
        z = V1.z;
    }
    return *this;
}

Vector3& Vector3::operator++() {
    ++x; ++y; ++z;
    return *this;
}

Vector3 Vector3::operator++(int) {
    Vector3 temp = *this;
    ++*this;
    return temp;
}

Vector3 Vector3::operator*(double n) const {
    return Vector3(x * n, y * n, z * n);
}

Vector3 Vector3::operator/(double n) const {
    if (n == 0) {
        throw std::runtime_error("Division by zero exception");
    }
    return Vector3(x / n, y / n, z / n);
}

double Vector3::vectors_length() const {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    Vector3 v1;
    std::cin >> v1;
    std::cout << "Vector: " << v1 << "\n";
    double length = v1.vectors_length();
    std::cout << "Length: " << length << "\n";
    Vector3 v2 = v1 / 5;
    std::cout << "Scaled vector: " << v2 << "\n";
    return 0;
}

