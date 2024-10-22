#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

void printUsage() {
    std::cout << "Использование: ./calculator [операция] [угол] [режим]\n";
    std::cout << "Операции: tan (тангенс), cot (котангенс)\n";
    std::cout << "Режимы: rad (радианы), deg (градусы)\n";
}

double calculateTangent(double angle, const std::string& mode) {
    if (mode == "deg") {
        angle = angle * M_PI / 180;  // Преобразуем градусы в радианы
    }
    return tan(angle);
}

double calculateCotangent(double angle, const std::string& mode) {
    if (mode == "deg") {
        angle = angle * M_PI / 180; // Преобразуем градусы в радианы
    }
    // Обработка случая, когда тангенс равен нулю
    double tanValue = tan(angle);
    if (tanValue == 0.0) {
        return std::numeric_limits<double>::infinity(); // Бесконечность
    }
    return 1.0 / tanValue;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    std::string operation = argv[1];
    double angle;
    try {
        angle = std::stod(argv[2]);
    } catch (const std::invalid_argument&) {
        std::cerr << "Ошибка: угол должен быть числом.\n";
        return 1;
    }

    std::string mode = argv[3];

    if (operation == "tan") {
        double result = calculateTangent(angle, mode);
        std::cout << "tan(" << angle << " " << mode << ") = " << result << std::endl;
    } else if (operation == "cot") {
        double result = calculateCotangent(angle, mode);
        std::cout << "cot(" << angle << " " << mode << ") = " << result << std::endl;
    } else {
        std::cerr << "Ошибка: неизвестная операция.\n";
        printUsage();
        return 1;
    }

    return 0;
}
