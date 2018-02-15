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

void CLI::add_option(std::string short_name, std::string long_name, bool positional, bool repeatable)
{
    Option opt(short_name, long_name, positional, repeatable);
    m_opt_db.push_back(opt);
}

int CLI::parse()
{
    int parse_count(0);
    for (std::vector<std::string>::size_type i = 0; i < m_user_input.size(); ++i)
    {
        bool match = false;
        for (const auto& db_arg : m_opt_db)
        {
            if (m_user_input[i] == db_arg.get_short_name() || m_user_input[i] == db_arg.get_long_name())
            {
                std::pair<std::string, std::string> res;
                // prepare the result pair depending on whether the option is positional
                if (db_arg.is_positional() && (i+1) != m_user_input.size())
                {
                    //m_results[m_user_input[i]] = m_user_input[i+1];
                    res.first = m_user_input[i]; 
                    res.second= m_user_input[i+1];
                    match = true;
                    ++i;
                }
                else
                {
                    //m_results[m_user_input[i]] = "true";
                    res.first = m_user_input[i];
                    res.second= "true";
                    match = true;
                }
                
                // insert it into the results vector depending on whether the option is repeatable
                if (db_arg.is_repeatable())
                {
                    m_results.push_back(res);
                    ++parse_count;
                }
                else
                {
                    for (const auto& it : m_results)
                    {
                        // if this already exists in the results, skip it; otherwise, add it in
                        if (it.first == db_arg.get_short_name() || it.first == db_arg.get_long_name())
                            break;
                        else
                            m_results.push_back(res);
                    }
                }
                break;
            }
            else continue;
        }
        if (match == false)
            //std::cerr << "invalid argument: " << m_user_input[i] << "\n";
            throw std::invalid_argument(m_user_input[i].c_str());
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
