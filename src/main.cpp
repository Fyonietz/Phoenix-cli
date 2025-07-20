#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <windows.h>
#include <filesystem>

std::string style=" > ";

void ashes(){
    std::cout << "New Era Has Come..." << std::flush << std::endl;
}
void ignite(){
    std::cout <<style<< "Igniting..." << std::flush << std::endl;
    system("Phoenix.exe");
}
void talon(){
    std::cout <<style<< "Weaving Feather..." <<std::flush << std::endl;
      // Build sequence
    int result = 0;

    // Configure CMake
    result = system("cmake -S . -B build -G \"Ninja\" > nul 2>&1");
    if (result != 0) {
        std::cerr << "Failed: Cmake Configure\n";
        return;
    }else{
        std::cout<<style<<"Fanning The Embers..."<<std::endl;
    }

    // Build with CMake
    result = system("cmake --build build > nul 2>&1");
    if (result != 0) {
        std::cerr << "Failed: Cmake Build\n";
        return;
    }else{
        std::cout<<style<<"Binding Wings..."<<std::endl;
    }
    std::cout<<style<<"Phoenix Is Born..."<<std::endl;
    result = system("Phoenix.exe");  
    if (result != 0) {
        std::cerr << "Failed: Running Phoenix\n";
        return;
    }
        
    
}
void resurge(){
    std::cout << "Resurge..." <<std::flush << std::endl;
}
void aether(){
    std::cout << "Fly High..." <<std::flush << std::endl;
}



int main(int argc, char *argv[]) {
    std::unordered_map<std::string,void (*)()> command_lists={
      {"ashes",ashes},
      {"ignite",ignite},
      {"talon",talon},
      {"resurge",resurge},
      {"aether",aether}
    };

    if (argc > 1) {
        std::string input = argv[1];

        // Check if command exists in the map
        if (command_lists.find(input) != command_lists.end()) {
            command_lists[input](); // Call the corresponding function
        } else {
            std::cout << "Unknown command: " << input << std::endl;
        }
    } else {
        std::cout << "No command provided." << "DIR: " << std::filesystem::current_path() << std::endl;
    }

    return 0;
}
