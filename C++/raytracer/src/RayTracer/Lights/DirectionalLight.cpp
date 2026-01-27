/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"
#include "../Interfaces/IPrimitive.hpp"

namespace RayTracer {
    DirectionalLight::DirectionalLight(const Math::Vector3D& direction, double intensity, 
                                     const Color& color, bool castShadows)
        : direction(direction.normalize()), intensity(intensity), 
          color(color), castShadows(castShadows) {}

    Color DirectionalLight::illuminate(const Math::Point3D& point, 
                                      const Math::Vector3D& normal, 
                                      const Color& objectColor,
                                      const std::vector<std::shared_ptr<IPrimitive>>& primitives) const {
        // Vérifie si le point est dans l'ombre
        if (castShadows && isInShadow(point, normal, primitives)) {
            return Color(0, 0, 0); // Aucune contribution de lumière
        }
        
        // Calcul de l'illumination diffuse
        double dot = normal.dot(direction * -1.0); // Direction de la lumière inversée
        
        if (dot <= 0)
            return Color(0, 0, 0); // Surface non éclairée
        
        // Retourne la couleur éclairée avec la couleur de la lumière
        return objectColor * color * (intensity * dot);
    }

    bool DirectionalLight::isInShadow(const Math::Point3D& point, 
                                    const Math::Vector3D& normal,
                                    const std::vector<std::shared_ptr<IPrimitive>>& primitives) const {
        if (!castShadows)
            return false;
    
        // Direction de l'ombre (opposée à la direction de la lumière)
        Math::Vector3D shadowDir = direction * -1.0;
        // Utiliser une constante epsilon bien définie
        const double SHADOW_EPSILON = 0.005;
        // Direction de l'ombre (opposée à la direction de la lumière)
        Math::Point3D shadowOrigin = point + normal * SHADOW_EPSILON;
        
        // Rayon allant vers la direction de l'ombre
        Ray shadowRay(shadowOrigin, shadowDir);
        
        // Vérifier si le rayon d'ombre intersecte avec une primitive
        for (const auto& primitive : primitives) {
            auto hit = primitive->hit(shadowRay, 0.001, std::numeric_limits<double>::infinity());
            if (hit.has_value()) {
                return true; // Le point est dans l'ombre
            }
        }
        return false; // Le point n'est pas dans l'ombre
    }
}
