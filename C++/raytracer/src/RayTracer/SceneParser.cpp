/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SceneParser
*/

#include "SceneParser.hpp"
#include "Factories/PrimitiveFactory.hpp"
#include "Lights/AmbientLight.hpp"
#include "Lights/DirectionalLight.hpp"
#include <libconfig.h++>
#include <iostream>

namespace RayTracer {
    SceneParser::SceneParser() : config(std::make_unique<libconfig::Config>()) {}

    bool SceneParser::parseFile(const std::string& filename) {
        try {
            config->readFile(filename.c_str());
            
            // Parse chaque section du fichier de configuration
            parseCamera();
            parsePrimitives();
            parseLights();
            
            return true;
        }
        catch(const libconfig::FileIOException& ex) {
            std::cerr << "Error reading file: " << ex.what() << std::endl;
            return false;
        }
        catch(const libconfig::ParseException& ex) {
            std::cerr << "Parse error at " << ex.getFile() << ":" << ex.getLine()
                      << " - " << ex.getError() << std::endl;
            return false;
        }
        catch(const libconfig::SettingNotFoundException& ex) {
            std::cerr << "Setting not found: " << ex.getPath() << std::endl;
            return false;
        }
        catch(const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            return false;
        }
    }

    void SceneParser::parseCamera() {
        try {
            const libconfig::Setting& cameraSettings = config->lookup("camera");
            
            const libconfig::Setting& resolution = cameraSettings["resolution"];
            int width = resolution["width"];
            int height = resolution["height"];
            double aspectRatio = static_cast<double>(width) / height;
            
            const libconfig::Setting& position = cameraSettings["position"];
            double x = position["x"];
            double y = position["y"];
            double z = position["z"];
            
            double fov = 72.0; // Valeur par défaut
            if (cameraSettings.exists("fieldOfView")) {
                fov = cameraSettings["fieldOfView"];
            }
            
            // Création de la caméra
            Camera camera(Math::Point3D(x, y, z), fov, aspectRatio);
            
            scene.setCamera(camera);
        }
        catch(const libconfig::SettingNotFoundException& ex) {
            std::cerr << "Camera setting not found: " << ex.getPath() << std::endl;
            // Utilise une caméra par défaut
            scene.setCamera(Camera());
        }
    }

    void SceneParser::parsePrimitives() {
        try {
            const libconfig::Setting& primitivesSettings = config->lookup("primitives");
            
            // Parse les sphères
            if (primitivesSettings.exists("spheres")) {
                const libconfig::Setting& spheres = primitivesSettings["spheres"];
                int count = spheres.getLength();
                
                for (int i = 0; i < count; ++i) {
                    const libconfig::Setting& sphere = spheres[i];
                    
                    double x = sphere["x"];
                    double y = sphere["y"];
                    double z = sphere["z"];
                    double r = sphere["r"];
                    
                    const libconfig::Setting& colorSetting = sphere["color"];
                    int red = colorSetting["r"];
                    int green = colorSetting["g"];
                    int blue = colorSetting["b"];
                    
                    Color color(red / 255.0, green / 255.0, blue / 255.0);
                    
                    std::vector<double> params = {x, y, z, r};
                    auto primitive = PrimitiveFactory::createPrimitive("sphere", params, color);
                    
                    // Appliquer une mise à l'échelle si spécifiée
                    if (sphere.exists("scale")) {
                        const libconfig::Setting& scaleSettings = sphere["scale"];
                        double scaleX = scaleSettings.exists("x") ? double(scaleSettings["x"]) : 1.0;
                        double scaleY = scaleSettings.exists("y") ? double(scaleSettings["y"]) : 1.0;
                        double scaleZ = scaleSettings.exists("z") ? double(scaleSettings["z"]) : 1.0;
                        
                        primitive->scale(Math::Vector3D(scaleX, scaleY, scaleZ));
                    }
                    
                    scene.addPrimitive(primitive);
                }
            }
            
            // Parse les plans
            if (primitivesSettings.exists("planes")) {
                const libconfig::Setting& planes = primitivesSettings["planes"];
                int count = planes.getLength();
                
                for (int i = 0; i < count; ++i) {
                    const libconfig::Setting& plane = planes[i];
                    
                    std::string axisStr = plane["axis"];
                    double position = plane["position"];
                    
                    int axisValue;
                    if (axisStr == "X" || axisStr == "x")
                        axisValue = 0;
                    else if (axisStr == "Y" || axisStr == "y")
                        axisValue = 1;
                    else // Z
                        axisValue = 2;
                    
                    const libconfig::Setting& colorSetting = plane["color"];
                    int red = colorSetting["r"];
                    int green = colorSetting["g"];
                    int blue = colorSetting["b"];
                    
                    Color color(red / 255.0, green / 255.0, blue / 255.0);
                    
                    std::vector<double> params = {static_cast<double>(axisValue), position};
                    auto primitive = PrimitiveFactory::createPrimitive("plane", params, color);
                    
                    // Appliquer une mise à l'échelle si spécifiée
                    if (plane.exists("scale")) {
                        const libconfig::Setting& scaleSettings = plane["scale"];
                        double scaleX = scaleSettings.exists("x") ? double(scaleSettings["x"]) : 1.0;
                        double scaleY = scaleSettings.exists("y") ? double(scaleSettings["y"]) : 1.0;
                        double scaleZ = scaleSettings.exists("z") ? double(scaleSettings["z"]) : 1.0;
                        
                        primitive->scale(Math::Vector3D(scaleX, scaleY, scaleZ));
                    }
                    
                    scene.addPrimitive(primitive);
                }
            }
            
            // Parse les cylindres
            if (primitivesSettings.exists("cylinders")) {
                const libconfig::Setting& cylinders = primitivesSettings["cylinders"];
                int count = cylinders.getLength();
                
                for (int i = 0; i < count; ++i) {
                    const libconfig::Setting& cylinder = cylinders[i];
                    
                    const libconfig::Setting& center = cylinder["center"];
                    double cx = center["x"];
                    double cy = center["y"];
                    double cz = center["z"];
                    
                    const libconfig::Setting& axis = cylinder["axis"];
                    double ax = axis["x"];
                    double ay = axis["y"];
                    double az = axis["z"];
                    
                    double radius = cylinder["radius"];
                    double height = cylinder["height"];
                    
                    const libconfig::Setting& colorSetting = cylinder["color"];
                    int red = colorSetting["r"];
                    int green = colorSetting["g"];
                    int blue = colorSetting["b"];
                    
                    Color color(red / 255.0, green / 255.0, blue / 255.0);
                    
                    std::vector<double> params = {cx, cy, cz, ax, ay, az, radius, height};
                    auto primitive = PrimitiveFactory::createPrimitive("cylinder", params, color);
                    
                    // Appliquer une mise à l'échelle si spécifiée
                    if (cylinder.exists("scale")) {
                        const libconfig::Setting& scaleSettings = cylinder["scale"];
                        double scaleX = scaleSettings.exists("x") ? double(scaleSettings["x"]) : 1.0;
                        double scaleY = scaleSettings.exists("y") ? double(scaleSettings["y"]) : 1.0;
                        double scaleZ = scaleSettings.exists("z") ? double(scaleSettings["z"]) : 1.0;
                        
                        primitive->scale(Math::Vector3D(scaleX, scaleY, scaleZ));
                    }
                    
                    scene.addPrimitive(primitive);
                }
            }

            // Parse les cônes
            if (primitivesSettings.exists("cones")) {
                const libconfig::Setting& cones = primitivesSettings["cones"];
                int count = cones.getLength();
                
                for (int i = 0; i < count; ++i) {
                    const libconfig::Setting& cone = cones[i];
                    
                    const libconfig::Setting& apex = cone["apex"];
                    double ax = apex["x"];
                    double ay = apex["y"];
                    double az = apex["z"];
                    
                    const libconfig::Setting& axis = cone["axis"];
                    double ox = axis["x"];
                    double oy = axis["y"];
                    double oz = axis["z"];
                    
                    double angle = cone["angle"];
                    double height = cone["height"];
                    
                    const libconfig::Setting& colorSetting = cone["color"];
                    int red = colorSetting["r"];
                    int green = colorSetting["g"];
                    int blue = colorSetting["b"];
                    
                    Color color(red / 255.0, green / 255.0, blue / 255.0);
                    
                    std::vector<double> params = {ax, ay, az, ox, oy, oz, angle, height};
                    auto primitive = PrimitiveFactory::createPrimitive("cone", params, color);
                    
                    // Appliquer une mise à l'échelle si spécifiée
                    if (cone.exists("scale")) {
                        const libconfig::Setting& scaleSettings = cone["scale"];
                        double scaleX = scaleSettings.exists("x") ? double(scaleSettings["x"]) : 1.0;
                        double scaleY = scaleSettings.exists("y") ? double(scaleSettings["y"]) : 1.0;
                        double scaleZ = scaleSettings.exists("z") ? double(scaleSettings["z"]) : 1.0;
                        
                        primitive->scale(Math::Vector3D(scaleX, scaleY, scaleZ));
                    }
                    
                    scene.addPrimitive(primitive);
                }
            }
        }
        catch(const libconfig::SettingNotFoundException& ex) {
            std::cerr << "Primitives setting not found: " << ex.getPath() << std::endl;
        }
    }

    void SceneParser::parseLights() {
        try {
            const libconfig::Setting& lightsSettings = config->lookup("lights");
            
            // Parse la lumière ambiante
            if (lightsSettings.exists("ambient")) {
                double ambient = lightsSettings["ambient"];
                
                // Couleur de la lumière ambiante (blanc par défaut)
                Color ambientColor(1, 1, 1);
                
                if (lightsSettings.exists("ambientColor")) {
                    const libconfig::Setting& colorSetting = lightsSettings["ambientColor"];
                    int red = colorSetting["r"];
                    int green = colorSetting["g"];
                    int blue = colorSetting["b"];
                    ambientColor = Color(red / 255.0, green / 255.0, blue / 255.0);
                }
                
                auto ambientLight = std::make_shared<AmbientLight>(ambient, ambientColor);
                scene.addLight(ambientLight);
            }
            
            // Parse la lumière diffuse (directionnelle)
            if (lightsSettings.exists("diffuse")) {
                double diffuse = lightsSettings["diffuse"];
                
                // Parse les lumières directionnelles
                if (lightsSettings.exists("directional")) {
                    const libconfig::Setting& directionals = lightsSettings["directional"];
                    int count = directionals.getLength();
                    
                    for (int i = 0; i < count; ++i) {
                        const libconfig::Setting& dir = directionals[i];
                        
                        // Direction par défaut (vers le bas)
                        Math::Vector3D direction(0, -1, 0);
                        
                        // Si direction est spécifiée
                        if (dir.exists("x") && dir.exists("y") && dir.exists("z")) {
                            double x = dir["x"];
                            double y = dir["y"];
                            double z = dir["z"];
                            direction = Math::Vector3D(x, y, z).normalize();
                        }
                        
                        // Couleur de la lumière directionnelle (blanc par défaut)
                        Color lightColor(1, 1, 1);
                        
                        if (dir.exists("color")) {
                            const libconfig::Setting& colorSetting = dir["color"];
                            int red = colorSetting["r"];
                            int green = colorSetting["g"];
                            int blue = colorSetting["b"];
                            lightColor = Color(red / 255.0, green / 255.0, blue / 255.0);
                        }
                        
                        auto directionalLight = std::make_shared<DirectionalLight>(
                            direction, diffuse, lightColor, true);
                        scene.addLight(directionalLight);
                    }
                }
            }
        }
        catch(const libconfig::SettingNotFoundException& ex) {
            std::cerr << "Lights setting not found: " << ex.getPath() << std::endl;
            
            // Ajoute lumières par défaut
            auto ambientLight = std::make_shared<AmbientLight>(0.2, Color(1, 1, 1));
            scene.addLight(ambientLight);
            
            auto directionalLight = std::make_shared<DirectionalLight>(
                Math::Vector3D(0, -1, -1).normalize(), 0.8, Color(1, 1, 1), true);
            scene.addLight(directionalLight);
        }
    }

    const Scene& SceneParser::getScene() const {
        return scene;
    }
}
