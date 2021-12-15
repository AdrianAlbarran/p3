#pragma once
class Vector3D
{

private:

	float x;
    float y;
    float z;

public:
    //Constructores de la clase 
    inline Vector3D(float dx, float dy, float dz) :x(dx), y(dy), z(dz) {}
    inline Vector3D() :x(0), y(0), z(0) {}

    //Getters & Setters
    inline float getX() { return x; }
    inline float getY() { return y; }
    inline float getZ() { return z; }

    void set(Vector3D vector) {
        this->x = vector.x;
        this->y = vector.y;
        this->z = vector.z;
    }
    inline void setX(float x) { this->x = x; }
    inline void setY(float y) { this->y = y; }
    inline void setZ(float z) { this->z = z; }

    Vector3D Add(const Vector3D& vector) {
        Vector3D r;
        Vector3D aux = vector;

        r.x = this->x + aux.getX();
        r.y = this->y + aux.getY();
        r.z = this->z + aux.getZ();
        return r;
    }

    Vector3D Substract(const Vector3D& vector) {
        Vector3D r;
        Vector3D aux = vector;

        r.x = this->x - aux.getX();
        r.y = this->y - aux.getY();
        r.z = this->z - aux.getZ();
        return r;
    }

    Vector3D Product(const float& value) {
        Vector3D r;
        r.x = x * value;
        r.y = y * value;
        r.z = z * value;
        return r;
    }

    Vector3D Division(const float& value) {
        Vector3D r;
        r.x = x / value;
        r.y = y / value;
        r.z = z / value;
        return r;
    }

    float DotProduct(const Vector3D& v) {
        double d;
        d = x * v.x + y * v.y + z * v.z;
        return d;
    }

    Vector3D operator+ (const Vector3D& vector) {
        return this->Add(vector);
    }

    Vector3D operator- (const Vector3D& vector) {
        return this->Substract(vector);
    }

    Vector3D operator* (const float& value) {
        return this->Product(value);
    }

    Vector3D operator/ (const float& value) {
        return this->Division(value);
    }

    float operator* (const Vector3D& vector) {
        return this->DotProduct(vector);
    }
};


