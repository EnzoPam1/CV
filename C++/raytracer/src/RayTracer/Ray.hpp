/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "../Math/Point3D.hpp"
#include "../Math/Vector3D.hpp"

namespace RayTracer {
    class Ray {
    public:
        Math::Point3D origin;
        Math::Vector3D direction;

        Ray() = default;
        Ray(const Math::Point3D& origin, const Math::Vector3D& direction);

        // Calcule un point le long du rayon à la distance t
        Math::Point3D pointAt(double t) const;
    };
}

#endif /* !RAY_HPP_ */
