#ifndef CONFIGFILE_HPP_
#define CONFIGFILE_HPP_

#include <map>
#include <fstream>
#include <iostream>

class ConfigFile
{
private:
    std::ofstream out;
    std::ifstream in;
    std::map<std::string, std::string> config;
    
public:
    ConfigFile();
    
    std::map<std::string, std::string> GetConfig() { return config; }
    std::string GetValue(std::string key) { return config[key]; }
    void SetValue(std::string key, std::string val) { config.insert(std::pair<std::string, std::string>(key, val)); }
    
    int Read();
    int Write();
    
    ~ConfigFile();
};

#endif
