#include "DeptTransportation.h"

DeptTransportation::DeptTransportation()
{
    
}

DeptTransportation::~DeptTransportation()
{

}

int DeptTransportation::grid_num_rows()
{
    return this->cityGrid->getNumRows();
}

int DeptTransportation::grid_num_cols()
{
    return this->cityGrid->getNumCols();
}

// add the other ones in the header file
