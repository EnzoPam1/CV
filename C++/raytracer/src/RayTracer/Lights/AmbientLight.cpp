/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

namespace RayTracer {
    AmbientLight::AmbientLight(double intensity, const Color& color) 
        : intensity(intensity), color(color) {}

    Color AmbientLight::illuminate(const Math::Point3D&, 
                                  const Math::Vector3D&, 
                                  const Color& objectColor,
                                  const std::vector<std::shared_ptr<IPrimitive>>&) const {
        // La lumière ambiante éclaire également toutes les surfaces, indépendamment de leur orientation
        return objectColor * color * intensity;
    }

    bool AmbientLight::isInShadow(const Math::Point3D&, 
                                const Math::Vector3D&,
                                const std::vector<std::shared_ptr<IPrimitive>>&) const {
        // La lumière ambiante n'est jamais bloquée
        return false;
    }
}
