/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "../Interfaces/IPrimitive.hpp"

namespace RayTracer {
    class Cone : public IPrimitive {
    private:
        Math::Point3D apex;      // Sommet du cône
        Math::Vector3D axis;     // Direction de l'axe du cône (normalisée)
        double angle;            // Angle d'ouverture du cône en radians
        double height;           // Hauteur du cône
        Color color;

    public:
        // Constructeurs
        Cone() = default;
        Cone(const Math::Point3D& apex, const Math::Vector3D& axis, 
             double angle, double height, const Color& color);

        // Implémentation de IPrimitive
        std::optional<HitRecord> hit(const Ray& ray, double t_min, double t_max) const override;
        void translate(const Math::Vector3D& translation) override;
        void rotateX(double angle) override;
        void rotateY(double angle) override;
        void rotateZ(double angle) override;
        void scale(const Math::Vector3D& scaleFactor) override;
    };
}

#endif /* !CONE_HPP_ */
