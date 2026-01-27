/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "../Ray.hpp"
#include "../Utils/Color.hpp"
#include <memory>
#include <optional>

namespace RayTracer {
    struct HitRecord {
        double t;               // Distance le long du rayon
        Math::Point3D point;    // Point d'intersection
        Math::Vector3D normal;  // Normale au point d'intersection
        Color color;            // Couleur de la primitive
    };

    class IPrimitive {
    public:
        virtual ~IPrimitive() = default;

        // Vérifie si un rayon intersecte avec la primitive et retourne les informations d'intersection
        virtual std::optional<HitRecord> hit(const Ray& ray, double t_min, double t_max) const = 0;

        // Applique une translation à la primitive
        virtual void translate(const Math::Vector3D& translation) = 0;

        // Applique une rotation autour de l'axe X
        virtual void rotateX(double angle) = 0;

        // Applique une rotation autour de l'axe Y
        virtual void rotateY(double angle) = 0;

        // Applique une rotation autour de l'axe Z
        virtual void rotateZ(double angle) = 0;

        // Prend un vecteur 3D qui représente le facteur d'échelle dans chaque dimension (X, Y, Z)
        virtual void scale(const Math::Vector3D& scaleFactor) = 0;
    };

    using PrimitivePtr = std::shared_ptr<IPrimitive>;
}

#endif /* !IPRIMITIVE_HPP_ */
