/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "../Interfaces/IPrimitive.hpp"

namespace RayTracer {
    class Plane : public IPrimitive {
    private:
        Math::Vector3D normal;  // Vecteur normal au plan
        double position;        // Position le long de l'axe normal
        Color color;
        char axis;              // 'X', 'Y', ou 'Z' pour simplifier

    public:
        Plane() = default;
        Plane(char axis, double position, const Color& color);
        Plane(const Math::Vector3D& normal, double position, const Color& color);

        // Implémentation de IPrimitive
        std::optional<HitRecord> hit(const Ray& ray, double t_min, double t_max) const override;
        void translate(const Math::Vector3D& translation) override;
        void rotateX(double angle) override;
        void rotateY(double angle) override;
        void rotateZ(double angle) override;
        void scale(const Math::Vector3D& scaleFactor) override;
    };
}

#endif /* !PLANE_HPP_ */
