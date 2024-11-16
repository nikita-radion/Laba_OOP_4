#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid() : Figure<T>(4) {}
    
    std::unique_ptr<Figure<T>> clone() const override {
        auto new_trapezoid = std::make_unique<Trapezoid<T>>();
        for (const auto& vertex : this->vertices_) {
            new_trapezoid->vertices_.push_back(
                std::make_unique<Point<T>>(vertex->x(), vertex->y())
            );
        }
        return new_trapezoid;
    }
    
    Point<T> getCenter() const override {
        T x_sum = 0;
        T y_sum = 0;
        for (const auto& vertex : this->vertices_) {
            x_sum += vertex->x();
            y_sum += vertex->y();
        }
        return Point<T>(x_sum / 4, y_sum / 4);
    }
    
    double getArea() const override {
        T a = std::abs(this->vertices_[1]->x() - this->vertices_[0]->x());
        T b = std::abs(this->vertices_[2]->x() - this->vertices_[3]->x());
        T h = std::abs(this->vertices_[2]->y() - this->vertices_[0]->y());
        return (a + b) * h / 2.0;
    }
    
    friend std::istream& operator>>(std::istream& is, Trapezoid<T>& trapezoid) {
        trapezoid.vertices_.clear();
        for (size_t i = 0; i < 4; ++i) {
            T x, y;
            is >> x >> y;
            trapezoid.vertices_.push_back(std::make_unique<Point<T>>(x, y));
        }
        return is;
    }
    
    std::string getName() const override {
        return "Трапеция";
    }
};