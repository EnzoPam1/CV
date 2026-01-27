/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Math {
    Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

    double Vector3D::length() const {
        return std::sqrt(X * X + Y * Y + Z * Z);
    }

    double Vector3D::dot(const Vector3D& other) const {
        return X * other.X + Y * other.Y + Z * other.Z;
    }

    Vector3D Vector3D::normalize() const {
        double len = length();
        if (len <= 0.0)
            return Vector3D(0, 0, 0);
        return Vector3D(X / len, Y / len, Z / len);
    }

    Vector3D Vector3D::operator+(const Vector3D& other) const {
        return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
    }

    Vector3D Vector3D::operator-(const Vector3D& other) const {
        return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
    }

    Vector3D Vector3D::operator*(const Vector3D& other) const {
        return Vector3D(X * other.X, Y * other.Y, Z * other.Z);
    }

    Vector3D Vector3D::operator/(const Vector3D& other) const {
        return Vector3D(X / other.X, Y / other.Y, Z / other.Z);
    }

    Vector3D Vector3D::operator*(double scalar) const {
        return Vector3D(X * scalar, Y * scalar, Z * scalar);
    }

    Vector3D Vector3D::operator/(double scalar) const {
        return Vector3D(X / scalar, Y / scalar, Z / scalar);
    }

    Vector3D& Vector3D::operator+=(const Vector3D& other) {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator-=(const Vector3D& other) {
        X -= other.X;
        Y -= other.Y;
        Z -= other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator*=(const Vector3D& other) {
        X *= other.X;
        Y *= other.Y;
        Z *= other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator/=(const Vector3D& other) {
        X /= other.X;
        Y /= other.Y;
        Z /= other.Z;
        return *this;
    }

    Vector3D& Vector3D::operator*=(double scalar) {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    Vector3D& Vector3D::operator/=(double scalar) {
        X /= scalar;
        Y /= scalar;
        Z /= scalar;
        return *this;
    }
}
