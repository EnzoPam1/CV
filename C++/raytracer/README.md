How to add an element to our Raytracer project 

If you want to add a figure to our project (we'll take the sphere as an example), you need to : 
1. Create a sphere class that derives from the Raytracer namespace and accesses the Iprimitives class. 
2. In your sphere class, add what you need, e.g. x, y, z angles, etc... 
3. Next, you'll need to calculate coefficients, vectors and so on. 

If you want to add a light, you must : 
1. Go to the .cfg file you want. 
2. You'll probably notice that there's already a lights section, with x, y, z points inside for ambient and diffuse direction. 
3. To add a light, it's very simple, just go back to the lights section, which reads as follows: 

lights =  
{ 
ambient = 0.3; 
diffuse = 0.7; 

  directional =  
  ( 
    { 
    x = 1.0; 
    y = -1.0; 
    z = -1.0 
    } 
  ); 
}; 

Then modify the coordinates. 

Create a SceneFile.cfg: 

To create à scene you need to create every components of the scene with their characteristics, the camera, the primitives the light.. 
 following this pattern :  
 camera = -> name of the component 
 { 
   resolution = { width = 800; height = 600 }; -> characteristics of the component 
   position = { x = 0.0; y = 0.0; z = 0.0 }; 
   fieldOfView = 72.0; 
 }; 

How add à new element to the parser: 

First of all you will need to go in the file SceneParser.hpp and add you new prompt to the class if it's a new components that does not exist. Otherwise if it's à modification to an already existing component you can directly go into the SceneParser.hpp. 
 TO parse the cfg file we use the libconfig++ library. 
 the prompt will be something like that: 
 parseCOMPONENT() { 
         try { 
           const libconfig::Setting& ComponentSettings = config->lookup("COMPONENT"); 
               const libconfig::Setting& characteristic = ComponentSettings["characteristic"]; 
               int width = resolution["width"]; 
               int height = resolution["height"]; 
         }catch(const libconfig::SettingNotFoundException& ex) { 
             std::cerr << "Camera setting not found: " << ex.getPath() << std::endl; 
             // Use a default component (you to create the default parameters) 
             scene.setCOMPONENT(COMPONENT()); 
         } 
 } 
 If you need to parse more complexe thing you can refer to the libconfig++ manual. 
