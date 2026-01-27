/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include "../Utils/Color.hpp"

namespace RayTracer {
    class Material {
    private:
        Color color;

    public:
        Material() = default;
        Material(const Color& color);

        const Color& getColor() const;
        void setColor(const Color& newColor);
    };
}

#endif /* !MATERIAL_HPP_ */
