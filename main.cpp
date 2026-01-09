#include "analyzer.h"
#include <iostream>
#include <chrono>  // For timing

// This is a simple main program to test our trip analyzer
// It reads the SmallTrips.csv file and shows the top zones and busy slots

int main() {
    // Create a new trip analyzer object
    TripAnalyzer analyzer;
    
    // Start timing to see how fast our program is
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Read and process the CSV file
    std::cout << "Reading SmallTrips.csv..." << std::endl;
    analyzer.ingestFile("SmallTrips.csv");
    
    // Stop timing
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    
    // Show the top 10 zones by trip count
    std::cout << "\n=== Top 10 Zones ===" << std::endl;
    auto topZones = analyzer.topZones(10);
    for (size_t i = 0; i < topZones.size(); i++) {
        std::cout << (i + 1) << ". " << topZones[i].zone 
                  << " - " << topZones[i].count << " trips" << std::endl;
    }
    
    // Show the top 10 busy time slots
    std::cout << "\n=== Top 10 Busy Time Slots ===" << std::endl;
    auto topSlots = analyzer.topBusySlots(10);
    for (size_t i = 0; i < topSlots.size(); i++) {
        std::cout << (i + 1) << ". " << topSlots[i].zone 
                  << " at hour " << topSlots[i].hour 
                  << " - " << topSlots[i].count << " trips" << std::endl;
    }
    
    // Show how long it took to process everything
    std::cout << "\nProcessing time: " << duration.count() << " ms" << std::endl;
    
    return 0;
}

