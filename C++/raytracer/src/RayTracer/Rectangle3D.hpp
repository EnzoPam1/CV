/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "../Math/Point3D.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {
    class Rectangle3D {
    public:
        Math::Point3D origin;       // Coin bas-gauche
        Math::Vector3D bottom_side; // Vecteur vers le coin bas-droit
        Math::Vector3D left_side;   // Vecteur vers le coin haut-gauche

        Rectangle3D() = default;
        Rectangle3D(const Math::Point3D& origin, 
                    const Math::Vector3D& bottom_side,
                    const Math::Vector3D& left_side);

        // Calcule un point sur le rectangle à partir des coordonnées (u, v)
        // où u et v sont dans l'intervalle [0, 1]
        Math::Point3D pointAt(double u, double v) const;
    };
}

#endif /* !RECTANGLE3D_HPP_ */
