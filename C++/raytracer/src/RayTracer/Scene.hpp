/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "Interfaces/IPrimitive.hpp"
#include "Interfaces/ILight.hpp"
#include "Camera.hpp"
#include <vector>
#include <memory>

namespace RayTracer {
    class Scene {
    private:
        std::vector<std::shared_ptr<IPrimitive>> primitives;
        std::vector<std::shared_ptr<ILight>> lights;
        Camera camera;
        Color backgroundColor;

    public:
        Scene();
        Scene(const Camera& camera, const Color& backgroundColor);

        // Ajoute objets à la scène
        void addPrimitive(std::shared_ptr<IPrimitive> primitive);
        void addLight(std::shared_ptr<ILight> light);

        const Camera& getCamera() const;
        void setCamera(const Camera& newCamera);
        const Color& getBackgroundColor() const;
        void setBackgroundColor(const Color& color);

        // Trace rayon à travers scène et retourne couleur
        Color trace(const Ray& ray) const;

        // Détermine couleur finale d'un point avec éclairage
        Color shade(const HitRecord& record) const;
    };
}

#endif /* !SCENE_HPP_ */
