/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
#define PRIMITIVEFACTORY_HPP_

#include "../Interfaces/IPrimitive.hpp"
#include "../Utils/Color.hpp"
#include <string>
#include <memory>
#include <vector>

namespace RayTracer {
    // Factory pattern pour la création de primitives
    class PrimitiveFactory {
    public:
        // Crée une primitive en fonction du type spécifié
        static std::shared_ptr<IPrimitive> createPrimitive(const std::string& type,
                                                          const std::vector<double>& params,
                                                          const Color& color);
    };
}

#endif /* !PRIMITIVEFACTORY_HPP_ */
