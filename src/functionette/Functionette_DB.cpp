#include "Functionette_DB.hpp"
#include <stdexcept>

Functionette_DB::Functionette_DB()
{}

std::vector<func_info> Functionette_DB::get_db() const
{
    return m_db;
}
void Functionette_DB::set_db(std::vector<func_info> db)
{
    m_db = db;
}

void Functionette_DB::insert_info(func_info inf)
{
    if (inf.min < 0 || inf.max < 0)
        throw std::invalid_argument("min and max values cannot be negative");
    m_db.push_back(inf);
}

void Functionette_DB::insert_info(std::string new_name, int new_min, int new_max)
{    
    insert_info(func_info{new_name, new_min, new_max});
}

bool Functionette_DB::search(std::string name, int argc)
{
    for (const auto& it: m_db)
    {
        if (name == it.name)
        {
            if (argc >= it.min && argc <= it.max)
                return true;
            else
                return false;
        }
        else
            continue;
    }
    return false;
}

bool Functionette_DB::search(Functionette fn)
{
    return search(fn.get_name(), fn.get_argc());
}
