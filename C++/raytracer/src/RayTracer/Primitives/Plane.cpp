/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Plane
*/

#include "Plane.hpp"
#include <cmath>

namespace RayTracer {
    Plane::Plane(char axis, double position, const Color& color) 
        : position(position), color(color), axis(axis) {
        // Définir le vecteur normal en fonction de l'axe
        if (axis == 'X' || axis == 'x')
            normal = Math::Vector3D(1, 0, 0);
        else if (axis == 'Y' || axis == 'y')
            normal = Math::Vector3D(0, 1, 0);
        else // Z
            normal = Math::Vector3D(0, 0, 1);
    }

    Plane::Plane(const Math::Vector3D& normal, double position, const Color& color)
        : normal(normal.normalize()), position(position), color(color), axis('C') {} // 'C' pour custom

    std::optional<HitRecord> Plane::hit(const Ray& ray, double t_min, double t_max) const {
        // Vérification que le rayon n'est pas parallèle au plan
        double denom = normal.dot(ray.direction);
        if (std::abs(denom) < 1e-6)
            return std::nullopt;
        
        // Calcul du point d'intersection
        Math::Point3D p0;
        if (axis == 'X' || axis == 'x')
            p0 = Math::Point3D(position, 0, 0);
        else if (axis == 'Y' || axis == 'y')
            p0 = Math::Point3D(0, position, 0);
        else if (axis == 'Z' || axis == 'z')
            p0 = Math::Point3D(0, 0, position);
        else // Custom normal
            p0 = Math::Point3D(normal.X * position, normal.Y * position, normal.Z * position);
        
        double t = normal.dot(p0 - ray.origin) / denom;
        
        // Vérifier que t est dans l'intervalle [t_min, t_max]
        if (t < t_min || t > t_max)
            return std::nullopt;
        
        // Créer l'enregistrement d'intersection
        HitRecord record;
        record.t = t;
        record.point = ray.pointAt(t);
        record.normal = normal;
        // Assurer que la normale est orientée dans le sens opposé au rayon
        if (denom > 0)
            record.normal = record.normal * -1;
        record.color = color;
        
        return record;
    }

    void Plane::translate(const Math::Vector3D& translation) {
        // Pour un plan, nous ne déplaçons que sa position le long de sa normale
        position += normal.dot(translation);
    }

    void Plane::rotateX(double angle) {
        // Rotation du vecteur normal autour de l'axe X
        double radians = angle * M_PI / 180.0;
        double newY = normal.Y * std::cos(radians) - normal.Z * std::sin(radians);
        double newZ = normal.Y * std::sin(radians) + normal.Z * std::cos(radians);
        normal.Y = newY;
        normal.Z = newZ;
        normal = normal.normalize();
        // Le plan personnalisé après rotation
        axis = 'C';
    }

    void Plane::rotateY(double angle) {
        double radians = angle * M_PI / 180.0;
        double newX = normal.X * std::cos(radians) + normal.Z * std::sin(radians);
        double newZ = -normal.X * std::sin(radians) + normal.Z * std::cos(radians);
        normal.X = newX;
        normal.Z = newZ;
        normal = normal.normalize();
        axis = 'C';
    }

    void Plane::rotateZ(double angle) {
        double radians = angle * M_PI / 180.0;
        double newX = normal.X * std::cos(radians) - normal.Y * std::sin(radians);
        double newY = normal.X * std::sin(radians) + normal.Y * std::cos(radians);
        normal.X = newX;
        normal.Y = newY;
        normal = normal.normalize();
        axis = 'C';
    }

    void Plane::scale(const Math::Vector3D& scaleFactor) {
    // Un plan infini n'est pas affecté par la mise à l'échelle
    (void)scaleFactor;
    }
}
