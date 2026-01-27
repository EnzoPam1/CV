/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** AmbientLight
*/

#ifndef AMBIENTLIGHT_HPP_
#define AMBIENTLIGHT_HPP_

#include "../Interfaces/ILight.hpp"

namespace RayTracer {
    class AmbientLight : public ILight {
    private:
        double intensity;
        Color color;

    public:
        AmbientLight() = default;
        AmbientLight(double intensity, const Color& color = Color(1, 1, 1));

        // Implémentation de ILight
        Color illuminate(const Math::Point3D& point, 
                         const Math::Vector3D& normal, 
                         const Color& objectColor,
                         const std::vector<std::shared_ptr<IPrimitive>>& primitives) const override;
        
        bool isInShadow(const Math::Point3D& point, 
                    const Math::Vector3D& normal,
                    const std::vector<std::shared_ptr<IPrimitive>>& primitives) const override;
    };
}

#endif /* !AMBIENTLIGHT_HPP_ */
