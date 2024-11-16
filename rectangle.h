#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle() : Figure<T>(4) {}
    
    std::unique_ptr<Figure<T>> clone() const override {
        auto new_rect = std::make_unique<Rectangle<T>>();
        for (const auto& vertex : this->vertices_) {
            new_rect->vertices_.push_back(std::make_unique<Point<T>>(
                vertex->x(), vertex->y()
            ));
        }
        return new_rect;
    }
    
    Point<T> getCenter() const override {
        T x_sum = 0, y_sum = 0;
        for (const auto& vertex : this->vertices_) {
            x_sum += vertex->x();
            y_sum += vertex->y();
        }
        return Point<T>(x_sum / 4, y_sum / 4);
    }
    
    double getArea() const override {
        T width = std::sqrt(
            std::pow(this->vertices_[1]->x() - this->vertices_[0]->x(), 2) +
            std::pow(this->vertices_[1]->y() - this->vertices_[0]->y(), 2)
        );
        T height = std::sqrt(
            std::pow(this->vertices_[2]->x() - this->vertices_[1]->x(), 2) +
            std::pow(this->vertices_[2]->y() - this->vertices_[1]->y(), 2)
        );
        return width * height;
    }
    
    friend std::istream& operator>>(std::istream& is, Rectangle<T>& rect) {
        for (size_t i = 0; i < 4; ++i) {
            T x, y;
            is >> x >> y;
            rect.vertices_[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }
    
    std::string getName() const override {
        return "Прямоугольник";
    }
};