/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../Interfaces/IPrimitive.hpp"

namespace RayTracer {
    class Sphere : public IPrimitive {
    private:
        Math::Point3D center;
        double radius;
        Color color;

    public:
        Sphere() = default;
        Sphere(const Math::Point3D& center, double radius, const Color& color);

        // Implémentation de IPrimitive
        std::optional<HitRecord> hit(const Ray& ray, double t_min, double t_max) const override;
        void translate(const Math::Vector3D& translation) override;
        void rotateX(double angle) override;
        void rotateY(double angle) override;
        void rotateZ(double angle) override;
        void scale(const Math::Vector3D& scaleFactor) override;
    };
}

#endif /* !SPHERE_HPP_ */
