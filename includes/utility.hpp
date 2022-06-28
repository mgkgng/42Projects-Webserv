#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdarg>
#include <map>

using std::string;
typedef const std::string const_string;

bool        end_with(const_string &str, const_string &end)
{
    return end.size() > str.size() ? false : (str.substr(str.size() - end.size()) == end);
}

// Should be called in server, with a cgi (map set in route/config) and uri
// If true call the execute_CGI
string      is_CGI(const std::map<string, string> &cgi, const_string &file)
{
    for (std::map<string, string>::const_iterator iter = cgi.begin(); iter != cgi.end(); iter++)
        if (end_with(file, iter->first))
            return iter->second;
    return NULL;
}

string     to_lower_string(string str)
{
    for (string::iterator it = str.begin(); it != str.end(); it++)
        *it = tolower(*it);
    return (str);
}

string     to_upper_string(string str)
{
    for (string::iterator it = str.begin(); it != str.end(); it++)
        *it = toupper(*it);
    return (str);
}

// http://www.cplusplus.com/articles/D9j2Nwbp/
template<typename T>
string to_string(const T &status_code)
{  
	std::ostringstream in_string;
	in_string << status_code;
	return (in_string.str());
}

string replace_all_occurrency(string s, const_string &to_replace, const_string &replace)
{
    size_t  current = 0;
    while (true)
    {
        size_t  found = s.find(to_replace, current);
        if (found == string::npos) break;
        s.replace(found, to_replace.size(), replace);
        current = found + replace.size();
    }
    return (s);
}

template<typename Elem, typename Type>
bool    is_found_in(Elem elem, size_t n, Type first ...)
{
        va_list         args;
        va_start(args, first);

        while (n--)
        {
            if (elem == first)
                va_end(args), return (true);
            first = va_arg(args, Type);
        }
        va_end(args);
        return (false);
}