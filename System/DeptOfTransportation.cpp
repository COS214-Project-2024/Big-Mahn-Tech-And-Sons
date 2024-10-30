#include "DeptOfTransportation.h"
#include "CityGrid.h"

DeptOfTransportation::DeptOfTransportation()
{
    
}

// DeptOfTransportation::~DeptOfTransportation()
// {

// }

int DeptOfTransportation::grid_num_rows()
{
    return this->cityGrid->getNumRows();
}

int DeptOfTransportation::grid_num_cols()
{
    return this->cityGrid->getNumCols();
}

// add the other ones in the header file
