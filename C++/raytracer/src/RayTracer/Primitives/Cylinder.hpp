/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "../Interfaces/IPrimitive.hpp"

namespace RayTracer {
    class Cylinder : public IPrimitive {
    private:
        Math::Point3D center;    // Centre du cylindre (milieu de l'axe)
        Math::Vector3D axis;     // Direction de l'axe du cylindre (normalisée)
        double radius;           // Rayon du cylindre
        double height;           // Hauteur du cylindre
        Color color;

    public:
        Cylinder() = default;
        Cylinder(const Math::Point3D& center, const Math::Vector3D& axis, 
                 double radius, double height, const Color& color);

        // Implémentation de IPrimitive
        std::optional<HitRecord> hit(const Ray& ray, double t_min, double t_max) const override;
        void translate(const Math::Vector3D& translation) override;
        void rotateX(double angle) override;
        void rotateY(double angle) override;
        void rotateZ(double angle) override;
        void scale(const Math::Vector3D& scaleFactor) override;
    };
}

#endif /* !CYLINDER_HPP_ */
