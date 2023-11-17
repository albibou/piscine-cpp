#include <iostream>
#include <fstream>
#include <string>

#define USAGE "Use as ./sed_is_for_losers filename to_find to_replace"
#define FILE_ERROR "Can't open filename"
#define CFILE_ERROR "Can't open new file"
#define STRING_EMPTY "to_find/to_replace/both is empty"
#define ERROR_READING "error reading file"

std::string    ft_look_to_replace(std::string to_find, std::string to_replace, std::string buffer){

    int buffsize = buffer.size();
    int findsize = to_find.size();
    std::string tmp;
    const size_t found = buffer.find(to_find);

    if (found != std::string::npos)
        return (tmp = buffer.substr(0, found) + to_replace + buffer.substr((found + findsize), buffsize));
    return(buffer);
}

int main(int argc, char **argv)
{
    std::string     filename = argv[1];
    std::string     to_find = argv[2];
    std::string     to_replace = argv[3];
    std::string     new_name = filename + ".replace";
    std::ifstream   originfs(argv[1]);
    std::ofstream   copyfs;

    if (argc != 4)
        return ((std::cout << USAGE << std::endl), 1);
    if (!to_find.size() || !to_replace.size())
        return ((std::cout << STRING_EMPTY << std::endl), 1);
    if (!originfs.is_open())
        return ((std::cout << FILE_ERROR << std::endl), originfs.close(), 1);
    copyfs.open(new_name.c_str(), std::fstream::out);
    if (!copyfs.is_open())
        return ((std::cout << CFILE_ERROR << std::endl), originfs.close(), 1);
    while (originfs.good())
    {
        std::string buffer;
        if (!getline(originfs, buffer))
            return (0);
        copyfs << ft_look_to_replace(to_find, to_replace, buffer) << std::endl;
    }
    return (0);
}
