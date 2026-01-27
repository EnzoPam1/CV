/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Rectangle3D.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Camera {
    private:
        Math::Point3D origin;    // Position de la caméra
        Rectangle3D screen;      // Écran virtuel
        double fieldOfView;      // Champ de vision en degrés

    public:
        Camera();
        Camera(const Math::Point3D& origin, double fieldOfView, double aspectRatio);

        // Génère rayon allant de la caméra vers un point de l'écran
        Ray ray(double u, double v) const;

        const Math::Point3D& getOrigin() const;
        void setOrigin(const Math::Point3D& newOrigin);
        void setFieldOfView(double fov, double aspectRatio);
    };
}

#endif /* !CAMERA_HPP_ */
