#include "DeptOfTransportation.h"

DeptOfTransportation* DeptOfTransportation::instance = nullptr;

DeptOfTransportation::DeptOfTransportation()
{
    cityGrid = new CityGrid(10,10);
}

DeptOfTransportation::~DeptOfTransportation()
{
    delete cityGrid;
}

DeptOfTransportation* DeptOfTransportation::getInstance()
{
    if (!instance)
    {
        instance = new DeptOfTransportation();
    }
    return instance;
}

bool DeptOfTransportation::addRoad(int start_row, int start_col, int street_Length, string direction, string street_name)
{
    if(cityGrid->addRoad(start_row,start_col,street_Length,direction,street_name))
    {
        return true;
    }
    cout<<"Road not added ~ DeptTrans";
    return false;
}