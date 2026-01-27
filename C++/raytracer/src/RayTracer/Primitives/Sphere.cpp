/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>

namespace RayTracer {
    Sphere::Sphere(const Math::Point3D& center, double radius, const Color& color)
        : center(center), radius(radius), color(color) {}

    std::optional<HitRecord> Sphere::hit(const Ray& ray, double t_min, double t_max) const {
        // Vecteur allant de l'origine du rayon au centre de la sphère
        Math::Vector3D oc = ray.origin - center;
        
        // Coefficients de l'équation quadratique
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - radius * radius;
        
        // Discriminant de l'équation quadratique
        double discriminant = b * b - 4 * a * c;
        
        // Si le discriminant est négatif, il n'y a pas d'intersection
        if (discriminant < 0)
            return std::nullopt;
        
        // Calcul des racines
        double sqrtd = std::sqrt(discriminant);
        double root = (-b - sqrtd) / (2.0 * a);
        
        // Vérification que la racine est dans l'intervalle [t_min, t_max]
        if (root < t_min || root > t_max) {
            root = (-b + sqrtd) / (2.0 * a);
            if (root < t_min || root > t_max)
                return std::nullopt;
        }
        
        // Création de l'enregistrement d'intersection
        HitRecord record;
        record.t = root;
        record.point = ray.pointAt(root);
        record.normal = (record.point - center) / radius; // Normalisation de la normale
        record.color = color;
        
        return record;
    }

    void Sphere::translate(const Math::Vector3D& translation) {
        center += translation;
    }

    void Sphere::rotateX(double angle) {
        // Rotation d'une sphère autour de son centre ne change pas sa forme,
        // donc nous n'avons besoin que de déplacer le centre
        double radians = angle * M_PI / 180.0;
        double newY = center.Y * std::cos(radians) - center.Z * std::sin(radians);
        double newZ = center.Y * std::sin(radians) + center.Z * std::cos(radians);
        center.Y = newY;
        center.Z = newZ;
    }

    void Sphere::rotateY(double angle) {
        double radians = angle * M_PI / 180.0;
        double newX = center.X * std::cos(radians) + center.Z * std::sin(radians);
        double newZ = -center.X * std::sin(radians) + center.Z * std::cos(radians);
        center.X = newX;
        center.Z = newZ;
    }

    void Sphere::rotateZ(double angle) {
        double radians = angle * M_PI / 180.0;
        double newX = center.X * std::cos(radians) - center.Y * std::sin(radians);
        double newY = center.X * std::sin(radians) + center.Y * std::cos(radians);
        center.X = newX;
        center.Y = newY;
    }

    void Sphere::scale(const Math::Vector3D& scaleFactor) {
    // Moyenne des facteurs d'échelle
    // car sphère ne peut pas être étirée différemment selon les axes
    double avgScale = (scaleFactor.X + scaleFactor.Y + scaleFactor.Z) / 3.0;
    radius *= avgScale;
    }
}
