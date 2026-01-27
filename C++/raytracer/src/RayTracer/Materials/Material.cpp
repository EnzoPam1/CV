/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Material
*/

#include "Material.hpp"

namespace RayTracer {
    Material::Material(const Color& color) : color(color) {}

    const Color& Material::getColor() const {
        return color;
    }

    void Material::setColor(const Color& newColor) {
        color = newColor;
    }
}
