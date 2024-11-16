#include <gtest/gtest.h>
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include "../include/array.h"
#include <sstream>
#include <cmath>

TEST(SquareTest, CenterCalculation) {
    Square<double> square;
    std::stringstream ss("0 0 2 0 2 2 0 2");  
    ss >> square;
    
    auto center = square.getCenter();
    EXPECT_NEAR(center.x(), 1.0, 0.0001);
    EXPECT_NEAR(center.y(), 1.0, 0.0001);
}

TEST(SquareTest, AreaCalculation) {
    Square<double> square;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> square;
    
    double area = static_cast<double>(square);
    EXPECT_NEAR(area, 4.0, 0.0001);
}

TEST(SquareTest, Equality) {
    Square<double> s1, s2;
    std::stringstream ss1("0 0 2 0 2 2 0 2");
    std::stringstream ss2("0 0 2 0 2 2 0 2");
    ss1 >> s1;
    ss2 >> s2;
    
    EXPECT_TRUE(s1 == s2);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle<double> rectangle;
    std::stringstream ss("0 0 3 0 3 2 0 2");  
    ss >> rectangle;
    
    auto center = rectangle.getCenter();
    EXPECT_NEAR(center.x(), 1.5, 0.0001);
    EXPECT_NEAR(center.y(), 1.0, 0.0001);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle<double> rectangle;
    std::stringstream ss("0 0 3 0 3 2 0 2");
    ss >> rectangle;
    
    double area = static_cast<double>(rectangle);
    EXPECT_NEAR(area, 6.0, 0.0001);
}

TEST(RectangleTest, Equality) {
    Rectangle<double> r1, r2;
    std::stringstream ss1("0 0 3 0 3 2 0 2");
    std::stringstream ss2("0 0 3 0 3 2 0 2");
    ss1 >> r1;
    ss2 >> r2;
    
    EXPECT_TRUE(r1 == r2);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid<double> trapezoid;
    std::stringstream ss("0 0 4 0 3 2 1 2");
    ss >> trapezoid;
    
    auto center = trapezoid.getCenter();
    EXPECT_NEAR(center.x(), 2.0, 0.0001);
    EXPECT_NEAR(center.y(), 1.0, 0.0001);
}

TEST(ArrayTest, PushBackAndSize) {
    Array<std::shared_ptr<Figure<double>>> figures;
    auto square = std::make_shared<Square<double>>();
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> *square;
    
    figures.push_back(square);
    EXPECT_EQ(figures.size(), 1);
}

TEST(ArrayTest, RemoveElement) {
    Array<std::shared_ptr<Figure<double>>> figures;
    auto rect = std::make_shared<Rectangle<double>>();
    std::stringstream ss("0 0 3 0 3 2 0 2");
    ss >> *rect;
    
    figures.push_back(rect);
    figures.remove(0);
    EXPECT_EQ(figures.size(), 0);
}

TEST(OperationsTest, CopyAssignmentSquare) {
    Square<double> s1;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> s1;
    
    Square<double> s2;
    s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(OperationsTest, MoveAssignmentRectangle) {
    Rectangle<double> r1;
    std::stringstream ss("0 0 3 0 3 2 0 2");
    ss >> r1;
    
    Rectangle<double> r2;
    r2 = std::move(r1);
    
    Rectangle<double> expected;
    std::stringstream ss2("0 0 3 0 3 2 0 2");
    ss2 >> expected;
    EXPECT_TRUE(r2 == expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}