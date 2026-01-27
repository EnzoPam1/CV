/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Color
*/

#include "Color.hpp"
#include <algorithm>

namespace RayTracer {
    Color::Color(double r, double g, double b) : R(r), G(g), B(b) {}

    Color Color::operator+(const Color& other) const {
        return Color(R + other.R, G + other.G, B + other.B);
    }

    Color Color::operator*(double scalar) const {
        return Color(R * scalar, G * scalar, B * scalar);
    }

    Color Color::operator*(const Color& other) const {
        return Color(R * other.R, G * other.G, B * other.B);
    }

    Color& Color::operator+=(const Color& other) {
        R += other.R;
        G += other.G;
        B += other.B;
        return *this;
    }

    Color& Color::operator*=(double scalar) {
        R *= scalar;
        G *= scalar;
        B *= scalar;
        return *this;
    }

    Color& Color::operator*=(const Color& other) {
        R *= other.R;
        G *= other.G;
        B *= other.B;
        return *this;
    }

    int Color::getRed() const {
        return static_cast<int>(255.999 * std::clamp(R, 0.0, 1.0));
    }

    int Color::getGreen() const {
        return static_cast<int>(255.999 * std::clamp(G, 0.0, 1.0));
    }

    int Color::getBlue() const {
        return static_cast<int>(255.999 * std::clamp(B, 0.0, 1.0));
    }

    void Color::clamp() {
        R = std::clamp(R, 0.0, 1.0);
        G = std::clamp(G, 0.0, 1.0);
        B = std::clamp(B, 0.0, 1.0);
    }

    void write_color(std::ostream& out, const Color& color) {
        out << color.getRed() << ' '
            << color.getGreen() << ' '
            << color.getBlue() << '\n';
    }
}