/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"

namespace Math {
    class Point3D {
    public:
        double X;
        double Y;
        double Z;

        Point3D() = default;
        Point3D(double x, double y, double z);

        Point3D operator+(const Vector3D& vec) const;
        Point3D operator-(const Vector3D& vec) const;
        Point3D& operator+=(const Vector3D& vec);
        Point3D& operator-=(const Vector3D& vec);

        // Calcule un vecteur entre deux points
        Vector3D operator-(const Point3D& other) const;

        // Calcule la distance entre deux points
        double distance(const Point3D& other) const;
    };
}

#endif /* !POINT3D_HPP_ */
