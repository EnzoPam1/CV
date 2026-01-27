/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_

#include "../Utils/Color.hpp"
#include "../Ray.hpp"
#include <memory>
#include <vector>

namespace RayTracer {
    class IPrimitive;

    class ILight {
    public:
        virtual ~ILight() = default;

        // Calcule la contribution de la lumière à un point donné
        virtual Color illuminate(const Math::Point3D& point, 
                                 const Math::Vector3D& normal, 
                                 const Color& objectColor,
                                 const std::vector<std::shared_ptr<IPrimitive>>& primitives) const = 0;

        // Vérifie si un point est dans l'ombre par rapport à cette lumière
        virtual bool isInShadow(const Math::Point3D& point, 
                            const Math::Vector3D& normal, // Paramètre ajouté
                            const std::vector<std::shared_ptr<IPrimitive>>& primitives) const = 0;
    };

    using LightPtr = std::shared_ptr<ILight>;
}

#endif /* !ILIGHT_HPP_ */
