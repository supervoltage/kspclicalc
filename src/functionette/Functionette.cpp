#include "Functionette.hpp"

// constructors and destructors
Functionette::Functionette(std::string name, int min, int max, std::map<std::string, std::string> helper)
{}

// getters and setters
std::string Functionette::get_name() const
{}

void Functionette::set_name(std::string new_name)
{}

std::pair<int, int> Functionette::get_bounds() const
{}

void Functionette::get_bounds(int& min, int& max) const
{}

void Functionette::set_bounds(std::pair<int, int> new_bounds)
{}

void Functionette::set_bounds(int min, int max)
{}

std::map<std::string, std::string> Functionette::get_helper() const
{}

void Functionette::set_helper(std::map<std::string, std::string> new_helper)
{}

void Functionette::insert_helper_pair(std::pair<std::string, std::string> pair)
{}

void Functionette::insert_helper_pair(std::string name, std::string desc)
{}

std::string Functionette::operator[] (std::string searchterm) // obtain argument value from one specific argument name
{}

std::map<std::string, std::string> Functionette::get_args() const  // get all args; first is name, second is value
{}

void Functionette::store(std::string functionette)
{}
