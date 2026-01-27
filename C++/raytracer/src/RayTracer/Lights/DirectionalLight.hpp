/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "../Interfaces/ILight.hpp"

namespace RayTracer {
    class DirectionalLight : public ILight {
    private:
        Math::Vector3D direction;  // Direction de la lumière (normalisée)
        double intensity;
        Color color;
        bool castShadows;

    public:
        DirectionalLight() = default;
        DirectionalLight(const Math::Vector3D& direction, double intensity, 
                        const Color& color = Color(1, 1, 1), bool castShadows = true);

        // Implémentation de ILight
        Color illuminate(const Math::Point3D& point, 
                         const Math::Vector3D& normal, 
                         const Color& objectColor,
                         const std::vector<std::shared_ptr<IPrimitive>>& primitives) const override;
        
        bool isInShadow(const Math::Point3D& point, 
                    const Math::Vector3D& normal, // Paramètre ajouté
                    const std::vector<std::shared_ptr<IPrimitive>>& primitives) const override;
    };
}

#endif /* !DIRECTIONALLIGHT_HPP_ */
