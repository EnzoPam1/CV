/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include <cmath>

namespace RayTracer {
    Cone::Cone(const Math::Point3D& apex, const Math::Vector3D& axis, 
             double angle, double height, const Color& color)
        : apex(apex), axis(axis.normalize()), angle(angle * M_PI / 180.0), height(height), color(color) {}

    std::optional<HitRecord> Cone::hit(const Ray& ray, double t_min, double t_max) const {
        Math::Vector3D normalizedAxis = axis;
        
        // Cosinus carré de l'angle d'ouverture
        double cosAngle2 = std::cos(angle) * std::cos(angle);
        double tanAngle = std::tan(angle);
        
        // Vecteur de l'apex à l'origine du rayon
        Math::Vector3D co = ray.origin - apex;
        
        // Variables pour stocker le point d'intersection le plus proche
        double t = t_max;
        bool hitFound = false;
        bool hitBase = false; // Pour déterminer si l'intersection est avec la base
        
        // Teste l'intersection avec la surface conique
        // Coefficients pour l'équation quadratique
        double rayDotAxis = ray.direction.dot(normalizedAxis);
        double coDotAxis = co.dot(normalizedAxis);
        
        double a = std::pow(rayDotAxis, 2) - cosAngle2 * ray.direction.dot(ray.direction);
        double b = 2.0 * (rayDotAxis * coDotAxis - cosAngle2 * ray.direction.dot(co));
        double c = std::pow(coDotAxis, 2) - cosAngle2 * co.dot(co);
        
        // Résolution de l'équation quadratique
        double discriminant = b * b - 4 * a * c;
        
        if (std::abs(a) > 1e-6 && discriminant >= 0) {
            double sqrtd = std::sqrt(discriminant);
            double t0 = (-b - sqrtd) / (2.0 * a);
            double t1 = (-b + sqrtd) / (2.0 * a);
            
            // Vérifier les deux solutions potentielles
            if (t0 > t_min && t0 < t) {
                Math::Point3D hitPoint = ray.pointAt(t0);
                Math::Vector3D ap = hitPoint - apex;
                double heightProj = ap.dot(normalizedAxis);
                
                if (heightProj >= 0 && heightProj <= height) {
                    t = t0;
                    hitFound = true;
                    hitBase = false;
                }
            }
            
            if (t1 > t_min && t1 < t) {
                Math::Point3D hitPoint = ray.pointAt(t1);
                Math::Vector3D ap = hitPoint - apex;
                double heightProj = ap.dot(normalizedAxis);
                
                if (heightProj >= 0 && heightProj <= height) {
                    t = t1;
                    hitFound = true;
                    hitBase = false;
                }
            }
        }
        
        // Teste l'intersection avec la base circulaire
        // Position de la base (à 'height' le long de l'axe depuis l'apex)
        Math::Point3D baseCenter = apex + normalizedAxis * height;
        
        // Si le rayon n'est pas parallèle au plan de la base
        if (std::abs(rayDotAxis) > 1e-6) {
            // Distance le long du rayon jusqu'au plan de la base
            double t_base = (baseCenter - ray.origin).dot(normalizedAxis) / rayDotAxis;
            
            if (t_base > t_min && t_base < t) {
                // Point d'intersection avec le plan de la base
                Math::Point3D hitPoint = ray.pointAt(t_base);
                
                // Vérifier si le point est à l'intérieur du cercle de la base
                double radius = height * tanAngle; // Rayon de la base
                Math::Vector3D vbc = hitPoint - baseCenter;
                double distanceFromAxis = (vbc - normalizedAxis * vbc.dot(normalizedAxis)).length();
                
                if (distanceFromAxis <= radius) {
                    t = t_base;
                    hitFound = true;
                    hitBase = true;
                }
            }
        }
        
        if (!hitFound)
            return std::nullopt;
        
        // Calculer la normale et créer le record d'intersection
        Math::Point3D hitPoint = ray.pointAt(t);
        Math::Vector3D normal;
        
        if (hitBase) {
            // Normal de la base (opposée à l'axe du cône)
            normal = normalizedAxis;
        } else {
            // Normale de la surface conique
            Math::Vector3D ap = hitPoint - apex;
            normal = (ap - normalizedAxis * (ap.dot(normalizedAxis) / normalizedAxis.dot(normalizedAxis) 
                    * (1 + tanAngle * tanAngle))).normalize();
        }
        
        // Création de l'enregistrement d'intersection
        HitRecord record;
        record.t = t;
        record.point = hitPoint;
        record.normal = normal;
        record.color = color;
        
        return record;
    }

    void Cone::translate(const Math::Vector3D& translation) {
        apex += translation;
    }

    void Cone::rotateX(double angleX) {
        double radians = angleX * M_PI / 180.0;
        
        // Rotation de l'apex
        double newY = apex.Y * std::cos(radians) - apex.Z * std::sin(radians);
        double newZ = apex.Y * std::sin(radians) + apex.Z * std::cos(radians);
        apex.Y = newY;
        apex.Z = newZ;
        
        // Rotation de l'axe
        double newAxisY = axis.Y * std::cos(radians) - axis.Z * std::sin(radians);
        double newAxisZ = axis.Y * std::sin(radians) + axis.Z * std::cos(radians);
        axis.Y = newAxisY;
        axis.Z = newAxisZ;
        axis = axis.normalize();
    }

    void Cone::rotateY(double angleY) {
        double radians = angleY * M_PI / 180.0;
        
        // Rotation de l'apex
        double newX = apex.X * std::cos(radians) + apex.Z * std::sin(radians);
        double newZ = -apex.X * std::sin(radians) + apex.Z * std::cos(radians);
        apex.X = newX;
        apex.Z = newZ;
        
        // Rotation de l'axe
        double newAxisX = axis.X * std::cos(radians) + axis.Z * std::sin(radians);
        double newAxisZ = -axis.X * std::sin(radians) + axis.Z * std::cos(radians);
        axis.X = newAxisX;
        axis.Z = newAxisZ;
        axis = axis.normalize();
    }

    void Cone::rotateZ(double angleZ) {
        double radians = angleZ * M_PI / 180.0;
        
        // Rotation de l'apex
        double newX = apex.X * std::cos(radians) - apex.Y * std::sin(radians);
        double newY = apex.X * std::sin(radians) + apex.Y * std::cos(radians);
        apex.X = newX;
        apex.Y = newY;
        
        // Rotation de l'axe
        double newAxisX = axis.X * std::cos(radians) - axis.Y * std::sin(radians);
        double newAxisY = axis.X * std::sin(radians) + axis.Y * std::cos(radians);
        axis.X = newAxisX;
        axis.Y = newAxisY;
        axis = axis.normalize();
    }

    void Cone::scale(const Math::Vector3D& scaleFactor) {
        // Le scaling affecte la hauteur et l'angle d'ouverture
        
        // Calcul du facteur d'échelle le long de l'axe (pour la hauteur)
        double axialScale = std::abs(scaleFactor.X * axis.X + 
                                scaleFactor.Y * axis.Y + 
                                scaleFactor.Z * axis.Z);
        
        // Calcul du facteur d'échelle moyen perpendiculaire à l'axe (pour l'angle)
        double avgPerpendicularScale = 0.0;
        
        if (std::abs(axis.X) < 1.0) {
            Math::Vector3D perpX = Math::Vector3D(1, 0, 0) - axis * axis.X;
            perpX = perpX.normalize();
            double scaleX = std::abs(perpX.X * scaleFactor.X + 
                                perpX.Y * scaleFactor.Y + 
                                perpX.Z * scaleFactor.Z);
            avgPerpendicularScale += scaleX;
        }
        
        if (std::abs(axis.Y) < 1.0) {
            Math::Vector3D perpY = Math::Vector3D(0, 1, 0) - axis * axis.Y;
            perpY = perpY.normalize();
            double scaleY = std::abs(perpY.X * scaleFactor.X + 
                                perpY.Y * scaleFactor.Y + 
                                perpY.Z * scaleFactor.Z);
            avgPerpendicularScale += scaleY;
        }
        
        if (std::abs(axis.Z) < 1.0) {
            Math::Vector3D perpZ = Math::Vector3D(0, 0, 1) - axis * axis.Z;
            perpZ = perpZ.normalize();
            double scaleZ = std::abs(perpZ.X * scaleFactor.X + 
                                perpZ.Y * scaleFactor.Y + 
                                perpZ.Z * scaleFactor.Z);
            avgPerpendicularScale += scaleZ;
        }
        
        // Calculer la moyenne (nombre de vecteurs perpendiculaires utilisés)
        int numPerp = (std::abs(axis.X) < 1.0) + (std::abs(axis.Y) < 1.0) + (std::abs(axis.Z) < 1.0);
        if (numPerp > 0) {
            avgPerpendicularScale /= numPerp;
        } else {
            avgPerpendicularScale = (scaleFactor.X + scaleFactor.Y + scaleFactor.Z) / 3.0;
        }
        
        // Application du facteur d'échelle à la hauteur
        height *= axialScale;
        
        // L'angle du cône reste inchangé car il est défini par le rapport entre la hauteur et le rayon
        // qui sont tous deux affectés proportionnellement par le scaling
    }
}
