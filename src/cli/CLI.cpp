#include "CLI.hpp"
#include <stdexcept>
#include <utility>
#include <algorithm>

std::vector<std::string> CLI::separate_opts(const std::vector<std::string>& vec)
{
    std::vector<std::string> out;
    for (const auto& it : vec)
    {
        if (it[0] != '-')
        {
            out.push_back(it);
            continue;
        }
        else if (it[0] == '-' && it[1] == '-')
        {
            out.push_back(it);
            continue;
        }             
        else
        {
            if (it.size() < 3)
            {
                out.push_back(it);
                continue;
            }
            else
            {
                for (std::string::size_type i = 1; i < it.size(); ++i)
                {
                    std::string out_it("-");
                    out_it += it[i];
                    out.push_back(out_it);
                }
            }
        }
    }
    return out;
}

CLI::CLI(int argc, char** argv, std::string prog_name, std::string prog_desc)
    : m_prog_name(prog_name), m_prog_desc(prog_desc)
{
    // extract the executable name
    m_exec_name = argv[0];
    // take the rest of the input and store it
    for (int i = 1; i < argc; ++i)
        m_user_input.push_back(argv[i]);
    // separate all arguments
    m_user_input = separate_opts(m_user_input);
}

void CLI::add_option(std::string name, std::string short_name, std::string long_name,
                     bool positional, bool repeatable)
{
    Option opt(name, short_name, long_name, positional, repeatable);
    m_opt_db.push_back(opt);
}

int CLI::parse()
{
    int parse_count(0);
    for (std::vector<std::string>::size_type i = 0; i < m_user_input.size(); ++i)
    {
        if (m_user_input[i][0] != "-")
            throw std::invalid_argument(m_user_input[i]);
        
        std::pair<std::string, std::string> res;
        for (const auto& db_opt : m_opt_db)
        {
            if(m_user_input[i] != db_opt)
                continue;
            if(db_arg.is_positional())
            {
                if((i+1) == m_user_input.size() || m_user_input[i+1][0] == "-")
                    throw std::invalid_argument (m_user_input[i] + " is positional but has no argument");
                res.first = m_user_input[i];
                res.second = m_user_input[i+1];
                ++i;
            }
            else
            {
                res.first = m_user_input[i];
                res.second = "true";
            }
            
            if(db_arg.is_repeatable())
            {
                m_results.push_back(res);
                ++parse_count;
                break;
            }
            else
            {
                for (const auto& it_res : m_results)
                {
                    if (it_res.first != res.first)
                    {
                        continue;
                    }
                    // more code required here
                }
                m_results.push_back(res);
                ++parse_count;
                break;
            }
        }
    }
    return parse_count;
}

std::vector<std::pair<std::string, std::string> > CLI::get_results() const
{
    return m_results;
}

std::string CLI::operator[] (const std::string& opt) const
{
    for (const auto& it : m_results)
    {
        if (it.first == opt) return it.second;
    }
    return std::string();
}
