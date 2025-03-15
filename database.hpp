#pragma once

#include<iostream>
#include<string.h>

class WaterDataset
{
    public:
    WaterDataset(){}
    WaterDataset(const std::string &filename){loadData(filename);}
    void loadData(const std::string &filename);
};