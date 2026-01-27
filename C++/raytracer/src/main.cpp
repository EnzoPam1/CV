/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** main
*/

#include "RayTracer/Scene.hpp"
#include "RayTracer/SceneParser.hpp"
#include "RayTracer/Utils/Color.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Vérification des arguments
    if (argc == 2 && std::string(argv[1]) == "--help") {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "SCENE_FILE: scene configuration" << std::endl;
        return 0;
    }
    
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        return 84;
    }
    
    // Parser la scène depuis le fichier
    RayTracer::SceneParser parser;
    if (!parser.parseFile(argv[1])) {
        std::cerr << "Error: Failed to parse scene file" << std::endl;
        return 84;
    }
    
    const RayTracer::Scene& scene = parser.getScene();
    const RayTracer::Camera& camera = scene.getCamera();
    
    // Déterminer la résolution de l'image
    int width = 800;   // Valeur par défaut
    int height = 600;  // Valeur par défaut
    
    // Générer l'image au format PPM
    std::cout << "P3" << std::endl;
    std::cout << width << " " << height << std::endl;
    std::cout << "255" << std::endl;
    
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            double u = static_cast<double>(i) / (width - 1);
            double v = static_cast<double>(j) / (height - 1);
            
            RayTracer::Ray ray = camera.ray(u, v);
            RayTracer::Color color = scene.trace(ray);
            
            RayTracer::write_color(std::cout, color);
        }
    }
    
    return 0;
}
