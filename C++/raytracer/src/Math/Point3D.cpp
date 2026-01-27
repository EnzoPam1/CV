/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace Math {
    Point3D::Point3D(double x, double y, double z) : X(x), Y(y), Z(z) {}

    Point3D Point3D::operator+(const Vector3D& vec) const {
        return Point3D(X + vec.X, Y + vec.Y, Z + vec.Z);
    }

    Point3D Point3D::operator-(const Vector3D& vec) const {
        return Point3D(X - vec.X, Y - vec.Y, Z - vec.Z);
    }

    Point3D& Point3D::operator+=(const Vector3D& vec) {
        X += vec.X;
        Y += vec.Y;
        Z += vec.Z;
        return *this;
    }

    Point3D& Point3D::operator-=(const Vector3D& vec) {
        X -= vec.X;
        Y -= vec.Y;
        Z -= vec.Z;
        return *this;
    }

    Vector3D Point3D::operator-(const Point3D& other) const {
        return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
    }

    double Point3D::distance(const Point3D& other) const {
        return ((*this) - other).length();
    }
}
