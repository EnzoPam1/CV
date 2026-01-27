/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SceneParser
*/

#ifndef SCENEPARSER_HPP_
#define SCENEPARSER_HPP_

#include "Scene.hpp"
#include <string>
#include <memory>
#include <libconfig.h++>

namespace libconfig {
    class Config;
}

namespace RayTracer {
    class SceneParser {
    private:
        std::unique_ptr<libconfig::Config> config;
        Scene scene;

        void parsePrimitives();
        void parseLights();
        void parseCamera();

    public:
        SceneParser();
        
        bool parseFile(const std::string& filename);
        const Scene& getScene() const;
    };
}

#endif /* !SCENEPARSER_HPP_ */
