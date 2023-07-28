#include <iostream>
#include <string>

struct Material {
    std::string name;
    double strength; // Some strength property value
    double density;  // Some density property value
    double cost;     // Some cost property value

    Material(std::string n, double s, double d, double c)
        : name(std::move(n)), strength(s), density(d), cost(c) {}
};

int main() {
    Material steel("Steel", 500, 7.8, 5);
    Material aluminum("Aluminum", 200, 2.7, 3);
    Material titanium("Titanium", 800, 4.5, 8);

    std::cout << "Material Selection Advisor\n";
    std::cout << "Please provide the required properties of the component:\n";

    double requiredStrength, requiredDensity, availableBudget;
    std::cout << "Required Strength (MPa): ";
    std::cin >> requiredStrength;
    
    std::cout << "Required Density (g/cm^3): ";
    std::cin >> requiredDensity;

    std::cout << "Available Budget ($): ";
    std::cin >> availableBudget;

    // Check all possible materials and determine which one suits the requirements best
    Material* bestMaterial = nullptr;
    double bestMaterialScore = 0.0;

    Material* materials[] = {&steel, &aluminum, &titanium};
    for (Material* material : materials) {
        // Some scoring function based on user requirements and material properties
        double materialScore = material->strength / requiredStrength +
                              material->density / requiredDensity +
                              availableBudget / material->cost;

        if (bestMaterial == nullptr || materialScore > bestMaterialScore) {
            bestMaterial = material;
            bestMaterialScore = materialScore;
        }
    }

    // Output the best material recommendation
    if (bestMaterial != nullptr) {
        std::cout << "\nBest Material Recommendation:\n";
        std::cout << "Material: " << bestMaterial->name << std::endl;
        std::cout << "Strength (MPa): " << bestMaterial->strength << std::endl;
        std::cout << "Density (g/cm^3): " << bestMaterial->density << std::endl;
        std::cout << "Cost ($): " << bestMaterial->cost << std::endl;
    } else {
        std::cout << "\nNo suitable material found based on the provided requirements.\n";
    }

    return 0;
}
