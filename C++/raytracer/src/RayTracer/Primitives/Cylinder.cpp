/*
** EPITECH PROJECT, 2025
** ultimetest
** File description:
** Cylinder
*/

#include "Cylinder.hpp"
#include <cmath>

namespace RayTracer {
    Cylinder::Cylinder(const Math::Point3D& center, const Math::Vector3D& axis, 
                     double radius, double height, const Color& color)
        : center(center), axis(axis.normalize()), radius(radius), height(height), color(color) {}

    std::optional<HitRecord> Cylinder::hit(const Ray& ray, double t_min, double t_max) const {
        // Vecteur de l'origine du rayon au centre du cylindre
        Math::Vector3D oc = ray.origin - center;
        
        // Calcule les projections pour l'équation du corps cylindrique
        double rayDotAxis = ray.direction.dot(axis);
        double ocDotAxis = oc.dot(axis);
        
        // Composantes perpendiculaires à l'axe
        Math::Vector3D rayPerp = ray.direction - axis * rayDotAxis;
        Math::Vector3D ocPerp = oc - axis * ocDotAxis;
        
        // Coefficients de l'équation quadratique pour le cylindre
        double a = rayPerp.dot(rayPerp);
        
        // Si le rayon est parallèle à l'axe, on ne peut intersecter que les bouchons
        bool parallelToAxis = (std::abs(a) < 1e-6);
        
        double t = t_max;         // Meilleur hit trouvé
        bool hitFound = false;    // Si une intersection valide a été trouvée
        
        // Intersection avec le corps du cylindre (si pas parallèle à l'axe)
        if (!parallelToAxis) {
            double b = 2.0 * ocPerp.dot(rayPerp);
            double c = ocPerp.dot(ocPerp) - radius * radius;
            
            double discriminant = b * b - 4 * a * c;
            
            if (discriminant >= 0) {
                double sqrtd = std::sqrt(discriminant);
                double t0 = (-b - sqrtd) / (2.0 * a);
                double t1 = (-b + sqrtd) / (2.0 * a);
                
                // Trouver la plus petite intersection valide
                if (t0 > t_min && t0 < t_max && t0 < t) {
                    // Calculer la position sur l'axe
                    double h = ocDotAxis + t0 * rayDotAxis;
                    if (h >= -height/2.0 && h <= height/2.0) {
                        t = t0;
                        hitFound = true;
                    }
                }
                
                if (t1 > t_min && t1 < t_max && t1 < t) {
                    // Calculer la position sur l'axe
                    double h = ocDotAxis + t1 * rayDotAxis;
                    if (h >= -height/2.0 && h <= height/2.0) {
                        t = t1;
                        hitFound = true;
                    }
                }
            }
        }
        
        // Intersection avec les bouchons circulaires (disques aux extrémités)
        if (std::abs(rayDotAxis) > 1e-6) {  // Si le rayon n'est pas perpendiculaire à l'axe
            // Bouchon inférieur (à -height/2)
            double t_bottom = (-height/2.0 - ocDotAxis) / rayDotAxis;
            if (t_bottom > t_min && t_bottom < t_max && t_bottom < t) {
                // Vérifier si le point est à l'intérieur du disque
                Math::Point3D hitPoint = ray.pointAt(t_bottom);
                Math::Vector3D hitToCenter = hitPoint - (center - axis * (height/2.0));
                double distFromAxis = (hitToCenter - axis * hitToCenter.dot(axis)).length();
                
                if (distFromAxis <= radius) {
                    t = t_bottom;
                    hitFound = true;
                }
            }
            
            // Bouchon supérieur (à +height/2)
            double t_top = (height/2.0 - ocDotAxis) / rayDotAxis;
            if (t_top > t_min && t_top < t_max && t_top < t) {
                // Vérifier si le point est à l'intérieur du disque
                Math::Point3D hitPoint = ray.pointAt(t_top);
                Math::Vector3D hitToCenter = hitPoint - (center + axis * (height/2.0));
                double distFromAxis = (hitToCenter - axis * hitToCenter.dot(axis)).length();
                
                if (distFromAxis <= radius) {
                    t = t_top;
                    hitFound = true;
                }
            }
        }
        
        if (!hitFound)
            return std::nullopt;
        
        // Calculer le point d'intersection et la normale
        Math::Point3D hitPoint = ray.pointAt(t);
        Math::Vector3D normal;
        
        // Déterminer où l'intersection s'est produite (corps ou bouchon)
        double h = (hitPoint - center).dot(axis);
        if (std::abs(h - height/2.0) < 1e-6) {
            // Bouchon supérieur
            normal = axis;
        } else if (std::abs(h + height/2.0) < 1e-6) {
            // Bouchon inférieur
            normal = axis * -1.0;
        } else {
            // Corps du cylindre
            Math::Point3D axisPoint = center + axis * h;
            normal = (hitPoint - axisPoint).normalize();
        }
        
        // Création de l'enregistrement d'intersection
        HitRecord record;
        record.t = t;
        record.point = hitPoint;
        record.normal = normal;
        record.color = color;
        
        return record;
    }

    void Cylinder::translate(const Math::Vector3D& translation) {
        center += translation;
    }

    void Cylinder::rotateX(double angle) {
        double radians = angle * M_PI / 180.0;
        
        // Rotation du centre
        double newY = center.Y * std::cos(radians) - center.Z * std::sin(radians);
        double newZ = center.Y * std::sin(radians) + center.Z * std::cos(radians);
        center.Y = newY;
        center.Z = newZ;
        
        // Rotation de l'axe
        double newAxisY = axis.Y * std::cos(radians) - axis.Z * std::sin(radians);
        double newAxisZ = axis.Y * std::sin(radians) + axis.Z * std::cos(radians);
        axis.Y = newAxisY;
        axis.Z = newAxisZ;
        axis = axis.normalize();
    }

    void Cylinder::rotateY(double angle) {
        double radians = angle * M_PI / 180.0;
        
        // Rotation du centre
        double newX = center.X * std::cos(radians) + center.Z * std::sin(radians);
        double newZ = -center.X * std::sin(radians) + center.Z * std::cos(radians);
        center.X = newX;
        center.Z = newZ;
        
        // Rotation de l'axe
        double newAxisX = axis.X * std::cos(radians) + axis.Z * std::sin(radians);
        double newAxisZ = -axis.X * std::sin(radians) + axis.Z * std::cos(radians);
        axis.X = newAxisX;
        axis.Z = newAxisZ;
        axis = axis.normalize();
    }

    void Cylinder::rotateZ(double angle) {
        double radians = angle * M_PI / 180.0;
        
        // Rotation du centre
        double newX = center.X * std::cos(radians) - center.Y * std::sin(radians);
        double newY = center.X * std::sin(radians) + center.Y * std::cos(radians);
        center.X = newX;
        center.Y = newY;
        
        // Rotation de l'axe
        double newAxisX = axis.X * std::cos(radians) - axis.Y * std::sin(radians);
        double newAxisY = axis.X * std::sin(radians) + axis.Y * std::cos(radians);
        axis.X = newAxisX;
        axis.Y = newAxisY;
        axis = axis.normalize();
    }

    void Cylinder::scale(const Math::Vector3D& scaleFactor) {
        // Calcul du facteur d'échelle perpendiculaire à l'axe
        double dotX = std::abs(axis.dot(Math::Vector3D(1, 0, 0)));
        double dotY = std::abs(axis.dot(Math::Vector3D(0, 1, 0)));
        double dotZ = std::abs(axis.dot(Math::Vector3D(0, 0, 1)));
        
        // Facteur d'échelle pour le rayon (perpendiculaire à l'axe)
        double radialScaleX = dotX * scaleFactor.X;
        double radialScaleY = dotY * scaleFactor.Y;
        double radialScaleZ = dotZ * scaleFactor.Z;
        double radialScale = std::sqrt(radialScaleX * radialScaleX + 
                                    radialScaleY * radialScaleY + 
                                    radialScaleZ * radialScaleZ);
        
        // Facteur d'échelle pour la hauteur (le long de l'axe)
        double axialScale = dotX * scaleFactor.X + 
                            dotY * scaleFactor.Y + 
                            dotZ * scaleFactor.Z;
        
        // Application des facteurs d'échelle
        radius *= radialScale;
        height *= axialScale;
    }
}
