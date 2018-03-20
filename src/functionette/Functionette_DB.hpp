#ifndef FUNCTIONETTE_DB
#define FUNCTIONETTE_DB

#include <string>
#include <vector>

struct func_info
{
    std::string name;
    int min;
    int max;
};

class Functionette_DB
{
private:
    std::vector<func_info> m_db;
public:
    Functionette_DB();
    
    std::vector<func_info> get_db() const;
    void set_db(std::vector<func_info> db);
    
    void insert_info(func_info inf);
    void insert_info(std::string new_name, int new_min, int new_max);
};

#endif
