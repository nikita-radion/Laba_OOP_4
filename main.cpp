#include <iostream>
#include "array.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include <sstream>

int main() {
    std::cout << "\n=== Работа с Array<Figure<int>*> ===\n";
    Array<std::shared_ptr<Figure<int>>> figures;
    
    auto square = std::make_shared<Square<int>>();
    std::stringstream ss_square("0 0 2 0 2 2 0 2");
    ss_square >> *square;
    figures.push_back(square);
    
    auto rect = std::make_shared<Rectangle<int>>();
    std::stringstream ss_rect("0 0 3 0 3 2 0 2");
    ss_rect >> *rect;
    figures.push_back(rect);
    
    auto trap = std::make_shared<Trapezoid<int>>();
    std::stringstream ss_trap("0 0 4 0 3 2 1 2");
    ss_trap >> *trap;
    figures.push_back(trap);
    
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "\nФигура " << i + 1 << " (" << figures[i]->getName() << "):\n";
        std::cout << "Координаты: " << *figures[i];
        std::cout << "\nЦентр: " << figures[i]->getCenter();
        std::cout << "\nПлощадь: " << static_cast<double>(*figures[i]) << "\n";
    }
    
    double total_area = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total_area += static_cast<double>(*figures[i]);
    }
    std::cout << "\nОбщая площадь всех фигур: " << total_area << "\n";
    
    figures.remove(1);
    std::cout << "\nПосле удаления фигуры с индексом 1:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << figures[i]->getName() << " ";
    }
    std::cout << "\n";
    
    std::cout << "\n=== Работа с Array<Square<double>> ===\n";
    Array<Square<double>> squares;
    
    Square<double> sq1;
    std::stringstream ss_sq1("0 0 2 0 2 2 0 2");
    ss_sq1 >> sq1;
    squares.push_back(sq1);
    
    Square<double> sq2;
    std::stringstream ss_sq2("1 1 3 1 3 3 1 3");
    ss_sq2 >> sq2;
    squares.push_back(sq2);
    
    Square<double> sq3 = sq1;  
    squares.push_back(sq3);
    squares.push_back(std::move(sq2));  
    
    std::cout << "Количество квадратов: " << squares.size() << "\n";
    for (size_t i = 0; i < squares.size(); ++i) {
        std::cout << "Квадрат " << i + 1 << " площадь: " 
                  << static_cast<double>(squares[i]) << "\n";
    }
    
    return 0;
}