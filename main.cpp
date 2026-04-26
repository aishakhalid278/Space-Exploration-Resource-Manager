#include <iostream>
#include "ResourceManager.h"

int main() {
    // 1. Demonstrating Overloaded Initializations
    SpaceResource empty; 
    SpaceResource helium3("Helium-3", 50.5, 0.95);
    SpaceResource lunarIce("Lunar Ice", 120.0, 0.80);
    SpaceResource processedIce(lunarIce, 0.99); // Processed version

    std::cout << "--- Mission Resource Inventory ---" << std::endl;
    std::cout << "Inventory 1: " << helium3 << std::endl;
    std::cout << "Inventory 2: " << lunarIce << std::endl;
    std::cout << "Inventory 3: " << processedIce << std::endl;
    std::cout << "----------------------------------" << std::endl << std::endl;

    // 2. Demonstrating Operator Overloading
    
    // Arithmetic + (Combining batches)
    SpaceResource extraHelium("Helium-3", 25.0, 0.95);
    SpaceResource totalHelium = helium3 + extraHelium;
    std::cout << "After Docking: Combined Helium-3 = " << totalHelium << std::endl;

    // Arithmetic * (Scaling for mission duration)
    double projectedNeeds = helium3 * 2.5;
    std::cout << "Projected Helium-3 needs for 2.5x mission duration: " << projectedNeeds << " MT" << std::endl;

    // Comparison < (Checking storage limits)
    if (helium3 < lunarIce) {
        std::cout << "Warning: Helium-3 levels are lower than Ice reserves." << std::endl;
    }

    return 0;
}
