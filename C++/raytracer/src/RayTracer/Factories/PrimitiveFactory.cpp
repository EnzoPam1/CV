/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PrimitiveFactory
*/
#include "PrimitiveFactory.hpp"
#include "../Primitives/Sphere.hpp"
#include "../Primitives/Plane.hpp"
#include "../Primitives/Cylinder.hpp"
#include "../Primitives/Cone.hpp"
#include <stdexcept>

namespace RayTracer {
    std::shared_ptr<IPrimitive> PrimitiveFactory::createPrimitive(const std::string& type,
                                                                 const std::vector<double>& params,
                                                                 const Color& color) {
        if (type == "sphere") {
            if (params.size() < 4)
                throw std::invalid_argument("Sphere requires at least 4 parameters: x, y, z, radius");
            
            return std::make_shared<Sphere>(
                Math::Point3D(params[0], params[1], params[2]),
                params[3],
                color
            );
        }
        else if (type == "plane") {
            if (params.size() < 2)
                throw std::invalid_argument("Plane requires at least 2 parameters: axis, position");
            
            char axis;
            if (params[0] == 0)
                axis = 'X';
            else if (params[0] == 1)
                axis = 'Y';
            else
                axis = 'Z';
            
            return std::make_shared<Plane>(
                axis,
                params[1],
                color
            );
        }
        else if (type == "cylinder") {
            if (params.size() < 8)
                throw std::invalid_argument("Cylinder requires at least 8 parameters: centerX, centerY, centerZ, axisX, axisY, axisZ, radius, height");
            
            return std::make_shared<Cylinder>(
                Math::Point3D(params[0], params[1], params[2]),
                Math::Vector3D(params[3], params[4], params[5]),
                params[6],
                params[7],
                color
            );
        }
        else if (type == "cone") {
            if (params.size() < 8)
                throw std::invalid_argument("Cone requires at least 8 parameters: apexX, apexY, apexZ, axisX, axisY, axisZ, angle, height");
            
            return std::make_shared<Cone>(
                Math::Point3D(params[0], params[1], params[2]),
                Math::Vector3D(params[3], params[4], params[5]),
                params[6],
                params[7],
                color
            );
        }
        else {
            throw std::invalid_argument("Unknown primitive type: " + type);
        }
    }
}