/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include <cmath>

namespace RayTracer {
    Camera::Camera() : origin(Math::Point3D(0, 0, 0)), fieldOfView(90.0) {
        // Configuration par défaut avec un écran à 1 unité devant la caméra
        double halfWidth = 1.0;
        double halfHeight = 1.0;
        
        Math::Point3D screenCenter(0, 0, -1);
        Math::Vector3D horizontalAxis(2 * halfWidth, 0, 0);
        Math::Vector3D verticalAxis(0, 2 * halfHeight, 0);
        
        screen = Rectangle3D(
            screenCenter - horizontalAxis * 0.5 - verticalAxis * 0.5,
            horizontalAxis,
            verticalAxis
        );
    }

    Camera::Camera(const Math::Point3D& origin, double fieldOfView, double aspectRatio)
        : origin(origin), fieldOfView(fieldOfView) {
        // Calcul de la hauteur de l'écran basé sur le champ de vision
        double theta = fieldOfView * M_PI / 180.0;
        double h = std::tan(theta / 2.0);
        double halfHeight = h;
        double halfWidth = aspectRatio * halfHeight;
        
        // L'écran est placé à 1 unité devant la caméra
        Math::Point3D screenCenter(0, 0, -1);
        Math::Vector3D horizontalAxis(2 * halfWidth, 0, 0);
        Math::Vector3D verticalAxis(0, 2 * halfHeight, 0);
        
        screen = Rectangle3D(
            screenCenter - horizontalAxis * 0.5 - verticalAxis * 0.5,
            horizontalAxis,
            verticalAxis
        );
    }

    Ray Camera::ray(double u, double v) const {
        // Génère rayon allant de l'origine vers un point de l'écran
        Math::Point3D target = screen.pointAt(u, v);
        return Ray(origin, (target - origin).normalize());
    }

    const Math::Point3D& Camera::getOrigin() const {
        return origin;
    }

    void Camera::setOrigin(const Math::Point3D& newOrigin) {
        origin = newOrigin;
    }

    void Camera::setFieldOfView(double fov, double aspectRatio) {
        fieldOfView = fov;
        
        // Recalcul de l'écran
        double theta = fieldOfView * M_PI / 180.0;
        double h = std::tan(theta / 2.0);
        double halfHeight = h;
        double halfWidth = aspectRatio * halfHeight;
        
        Math::Point3D screenCenter(0, 0, -1);
        Math::Vector3D horizontalAxis(2 * halfWidth, 0, 0);
        Math::Vector3D verticalAxis(0, 2 * halfHeight, 0);
        
        screen = Rectangle3D(
            screenCenter - horizontalAxis * 0.5 - verticalAxis * 0.5,
            horizontalAxis,
            verticalAxis
        );
    }
}
