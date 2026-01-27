/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include <limits>

namespace RayTracer {
    Scene::Scene() : backgroundColor(Color(0, 0, 0)) {}

    Scene::Scene(const Camera& camera, const Color& backgroundColor)
        : camera(camera), backgroundColor(backgroundColor) {}

    void Scene::addPrimitive(std::shared_ptr<IPrimitive> primitive) {
        primitives.push_back(primitive);
    }

    void Scene::addLight(std::shared_ptr<ILight> light) {
        lights.push_back(light);
    }

    const Camera& Scene::getCamera() const {
        return camera;
    }

    void Scene::setCamera(const Camera& newCamera) {
        camera = newCamera;
    }

    const Color& Scene::getBackgroundColor() const {
        return backgroundColor;
    }

    void Scene::setBackgroundColor(const Color& color) {
        backgroundColor = color;
    }

    Color Scene::trace(const Ray& ray) const {
        // Valeurs pour recherche de l'intersection la plus proche
        double closestT = std::numeric_limits<double>::infinity();
        std::optional<HitRecord> closestHit;
        
        // Parcours toutes les primitives pour trouver intersection la plus proche
        for (const auto& primitive : primitives) {
            auto hit = primitive->hit(ray, 0.001, closestT);
            if (hit.has_value() && hit->t < closestT) {
                closestT = hit->t;
                closestHit = hit;
            }
        }
        
        // Si intersection trouvée, calculer couleur
        if (closestHit.has_value()) {
            return shade(*closestHit);
        }
        
        // Sinon, retourner couleur de fond
        return backgroundColor;
    }

    Color Scene::shade(const HitRecord& record) const {
        Color finalColor(0, 0, 0);
        
        // Parcours toutes lumières pour calculer éclairage
        for (const auto& light : lights) {
            Color lightContribution = light->illuminate(
                record.point,
                record.normal,
                record.color,
                primitives
            );
            
            finalColor += lightContribution;
        }
        
        // Clamp pour s'assurer que les valeurs restent dans [0, 1]
        finalColor.clamp();
        
        return finalColor;
    }
}
