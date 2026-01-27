/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <cmath>

namespace Math {
    class Vector3D {
    public:
        double X;
        double Y;
        double Z;

        Vector3D() = default;
        Vector3D(double x, double y, double z);

        double length() const;
        double dot(const Vector3D& other) const;
        Vector3D normalize() const;

        Vector3D operator+(const Vector3D& other) const;
        Vector3D operator-(const Vector3D& other) const;
        Vector3D operator*(const Vector3D& other) const;
        Vector3D operator/(const Vector3D& other) const;
        Vector3D operator*(double scalar) const;
        Vector3D operator/(double scalar) const;
        Vector3D& operator+=(const Vector3D& other);
        Vector3D& operator-=(const Vector3D& other);
        Vector3D& operator*=(const Vector3D& other);
        Vector3D& operator/=(const Vector3D& other);
        Vector3D& operator*=(double scalar);
        Vector3D& operator/=(double scalar);
    };
}

#endif /* !VECTOR3D_HPP_ */
