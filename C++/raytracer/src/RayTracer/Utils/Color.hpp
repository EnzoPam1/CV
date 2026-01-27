/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <iostream>

namespace RayTracer {
    class Color {
    public:
        double R;
        double G;
        double B;

        Color() = default;
        Color(double r, double g, double b);

        Color operator+(const Color& other) const;
        Color operator*(double scalar) const;
        Color operator*(const Color& other) const;
        Color& operator+=(const Color& other);
        Color& operator*=(double scalar);
        Color& operator*=(const Color& other);

        // Conversion en entiers pour PPM (0-255)
        int getRed() const;
        int getGreen() const;
        int getBlue() const;

        // Clamp les valeurs entre 0 et 1
        void clamp();
    };

    // Fonction globale pour écrire une couleur dans un stream
    void write_color(std::ostream& out, const Color& color);
}

#endif /* !COLOR_HPP_ */
