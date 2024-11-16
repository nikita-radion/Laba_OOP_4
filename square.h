#pragma once
#include "figure.h"
#include <cmath>

template<Scalar T>
class Square : public Figure<T> {
public:
    Square() : Figure<T>(4) {}
    
    std::unique_ptr<Figure<T>> clone() const override {
        auto new_square = std::make_unique<Square<T>>();
        for (size_t i = 0; i < 4; ++i) {
            new_square->vertices_[i] = std::make_unique<Point<T>>(
                this->vertices_[i]->x(),
                this->vertices_[i]->y()
            );
        }
        return new_square;
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
        T side = std::sqrt(
            std::pow(this->vertices_[1]->x() - this->vertices_[0]->x(), 2) +
            std::pow(this->vertices_[1]->y() - this->vertices_[0]->y(), 2)
        );
        return side * side;
    }
    
    friend std::istream& operator>>(std::istream& is, Square<T>& square) {
        for (size_t i = 0; i < 4; ++i) {
            T x, y;
            is >> x >> y;
            square.vertices_[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }
    
    std::string getName() const override {
        return "Квадрат";
    }
};