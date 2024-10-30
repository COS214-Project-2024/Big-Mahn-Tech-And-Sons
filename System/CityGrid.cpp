#include "CityGrid.h"

Cell::Cell(int row_value, int col_value, string cardinal_point)
{
    /*1*/ this->cell_col_value = col_value;
    /*2*/ this->cell_row_value = row_value;
    /*3*/ this->cardinal_direction = cardinal_point;
    /*4*/ this->detailed_attribute = "BLANK";
    /*5*/ this->attribute = '.';
    /*6*/ this->street_name = "-";
}

Cell::~Cell()
{
    //no memory management required here.
}

const char Cell::getAttribute()
{
    return attribute;
}

void Cell::updateDetailed_Attribute(string newDetailedAttribute)
{
    if(newDetailedAttribute!=detailed_attribute)
    {
        detailed_attribute = newDetailedAttribute;
    }
}

const string Cell::getDetailed_Atttribute()
{
    return detailed_attribute;
}

void Cell::changeAttribute(char newAttribute)
{
    if(newAttribute!=attribute)
    attribute = newAttribute;
}

const string Cell::getCardinal_direction()
{
    return cardinal_direction;
}

void Cell::updateStreetName(string streetName)
{
    if(street_name!=streetName)
    street_name = streetName;
}

const string Cell::getStreetName()
{
    if(attribute=='R')  //makes sure that it is a road.
    {
        return street_name;
    }
    return "-";
}

vector<vector<Cell>>* CityGrid::citygrid = nullptr;

CityGrid::CityGrid(int row_dimension, int col_dimension)
{
    this->grid_num_rows=row_dimension;
    this->grid_num_cols=col_dimension;
    citygrid = new vector<vector<Cell>>(row_dimension, vector<Cell>(col_dimension, Cell(0, 0, "-")));

    string cardinal_point;

    for(int i = 0; i < row_dimension; i++)
    {
        for(int j = 0; j < col_dimension; j++)
        {
            if(i<row_dimension/2){cardinal_point="N";}
            else{cardinal_point="S";}
            if(j<col_dimension/2){cardinal_point+="W";}
            else{cardinal_point+="E";}
            (*citygrid)[i][j] =  Cell(i, j, cardinal_point);
        }
    }
}

CityGrid::~CityGrid()
{
    if(citygrid!=nullptr)
    delete citygrid;
}

void CityGrid::printCityGrid()
{
    for(int i =0; i < grid_num_cols ;i++)
    {
        if(i==0)
        cout<<"  ";
        cout<<i<<" ";
        if(i==(grid_num_cols-1))
        cout<<endl;
    }
    for (int i = 0; i < grid_num_rows ;i++) {
        cout<<i<<" ";
        for (int j = 0; j < grid_num_cols; j++) {
            cout <<(*citygrid)[i][j].getAttribute()<<" ";
        } 
        cout << endl;
    }
}

void CityGrid::printCityCardinal()
{
    for(int i =0; i < grid_num_cols ;i++)
    {
        if(i==0)
        cout<<"  ";
        cout<<i<<"  ";
        if(i==(grid_num_cols-1))
        cout<<endl;
    }
    for (int i = 0; i < grid_num_rows ;i++) {
        cout<<i<<" ";
        for (int j = 0; j < grid_num_cols; j++) {
            cout <<(*citygrid)[i][j].getCardinal_direction()<<" ";
        } 
        cout << endl;
    }
}

bool CityGrid::addRoad(int start_row, int start_col, int length, string direction, string strname)
{
    if(start_row<0 || start_col<0 || length<0)
    {
        cout<<"Invalid dimensions";
        return false;}

    int end_row, end_col;

    enum Direction
    {
        up,down,left,right,none
    };
    Direction move=none;

    if(direction=="up"){move=up;}
    if(direction=="down"){move=down;}
    if(direction=="left"){move=left;}
    if(direction=="right"){move=right;}

    switch (move)
    {
        case up:
            end_col = start_col;
            end_row = start_row - length+1;
            break;

        case down:
            end_col = start_col;
            end_row = start_row + length-1;
            break;

        case left:
            end_row = start_row;
            end_col = start_col - length+1;
            break;

        case right:
            end_row = start_row;
            end_col = start_col + length-1;
            break;

        default:
            cout<<"No direction specified";
            return false;   // no direction specified
            break;
    }

    if(start_row > grid_num_rows-1){start_row=grid_num_rows-1;}
    if(end_row > grid_num_rows-1){end_row=grid_num_rows-1;}
    if(start_col > grid_num_cols-1){start_col=grid_num_cols-1;}
    if(end_col > grid_num_cols-1){end_col=grid_num_cols-1;}


    switch (move)
    {
        case up:
            for(int i=end_row; i<= start_row; i++)
            {
                if((*citygrid)[i][start_col].getAttribute()=='R' || (*citygrid)[i][start_col].getAttribute()=='.')
                {
                    if((*citygrid)[i][start_col].getAttribute()=='R')
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].updateStreetName(strname); //check string comparisons.
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].changeAttribute('R');
                        (*citygrid)[i][start_col].updateStreetName(strname);
                    }
                }
            }
            break;

        case down:
            for(int i=start_row; i<= end_row; i++)
            {
                if((*citygrid)[i][start_col].getAttribute()=='R' || (*citygrid)[i][start_col].getAttribute()=='.')
                {
                    if((*citygrid)[i][start_col].getAttribute()=='R')
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].changeAttribute('R');
                        (*citygrid)[i][start_col].updateStreetName(strname);
                    }
                }
            }
            break;

        case left:
            for(int i=end_col; i<= start_col; i++)
            {
                if((*citygrid)[start_row][i].getAttribute()=='R' || (*citygrid)[start_row][i].getAttribute()=='.')
                {
                    if((*citygrid)[start_row][i].getAttribute()=='R')
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[start_row][i].changeAttribute('R');
                        (*citygrid)[start_row][i].updateStreetName(strname);
                    }
                }
            }
            break;

        case right:
            for(int i=start_col; i<= end_col; i++)
            {
                if((*citygrid)[start_row][i].getAttribute()=='R' || (*citygrid)[start_row][i].getAttribute()=='.')
                {
                    if((*citygrid)[start_row][i].getAttribute()=='R')
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].updateDetailed_Attribute("ROAD");
                        (*citygrid)[start_row][i].changeAttribute('R');
                        (*citygrid)[start_row][i].updateStreetName(strname);
                    }
                }
            }
            break;
    }

    return true;

}

bool CityGrid::removeRoad(int start_row, int start_col, int length, string direction)
{
    if(start_row<0 || start_col<0 || length<0)
    {
        cout<<"Invalid dimensions";
        return false;}

    int end_row, end_col;

    enum Direction
    {
        up,down,left,right,none
    };
    Direction move=none;

    if(direction=="up"){move=up;}
    if(direction=="down"){move=down;}
    if(direction=="left"){move=left;}
    if(direction=="right"){move=right;}

    switch (move)
    {
        case up:
            end_col = start_col;
            end_row = start_row - length+1;
            break;

        case down:
            end_col = start_col;
            end_row = start_row + length-1;
            break;

        case left:
            end_row = start_row;
            end_col = start_col - length+1;
            break;

        case right:
            end_row = start_row;
            end_col = start_col + length-1;
            break;

        default:
            cout<<"No direction specified.";
            return false;   // no direction specified
            break;
    }

    if(start_row > grid_num_rows-1){start_row=grid_num_rows-1;}
    if(end_row > grid_num_rows-1){end_row=grid_num_rows-1;}
    if(start_col > grid_num_cols-1){start_col=grid_num_cols-1;}
    if(end_col > grid_num_cols-1){end_col=grid_num_cols-1;}


    switch (move)
    {
        case up:
            for(int i=end_row; i<= start_row; i++)
            {
                if((*citygrid)[i][start_col].getAttribute()=='R' || (*citygrid)[i][start_col].getAttribute()=='.')
                {
                    if((*citygrid)[i][start_col].getAttribute()=='.')
                    {
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].changeAttribute('.');
                        (*citygrid)[i][start_col].updateStreetName("-");
                        (*citygrid)[i][start_col].updateDetailed_Attribute("BLANK");
                    }
                }
            }
            break;

        case down:
            for(int i=start_row; i<= end_row; i++)
            {
                if((*citygrid)[i][start_col].getAttribute()=='R' || (*citygrid)[i][start_col].getAttribute()=='.')
                {
                    if((*citygrid)[i][start_col].getAttribute()=='.')
                    {
                        continue;
                    }
                    else
                    {
                        (*citygrid)[i][start_col].changeAttribute('.');
                        (*citygrid)[i][start_col].updateStreetName("-");
                        (*citygrid)[i][start_col].updateDetailed_Attribute("BLANK");
                    }
                }
            }
            break;

        case left:
            for(int i=end_col; i<= start_col; i++)
            {
                if((*citygrid)[start_row][i].getAttribute()=='R' || (*citygrid)[start_row][i].getAttribute()=='.')
                {
                    if((*citygrid)[start_row][i].getAttribute()=='.')
                    {
                        continue;
                    }
                    else
                    {
                        (*citygrid)[start_row][i].changeAttribute('.');
                        (*citygrid)[start_row][i].updateStreetName("-");
                        (*citygrid)[start_row][i].updateDetailed_Attribute("BLANK");
                    }
                }
            }
            break;

        case right:
            for(int i=start_col; i<= end_col; i++)
            {
                if((*citygrid)[start_row][i].getAttribute()=='R' || (*citygrid)[start_row][i].getAttribute()=='.')
                {
                    if((*citygrid)[start_row][i].getAttribute()=='.')
                    {
                        continue;
                    }
                    else
                    {
                        (*citygrid)[start_row][i].changeAttribute('.');
                        (*citygrid)[start_row][i].updateStreetName("-");
                        (*citygrid)[start_row][i].updateDetailed_Attribute("BLANK");
                    }
                }
            }
            break;
    }

    return true;
}

bool CityGrid::removeRoad(string streetName)
{
    bool status=false;
    for(int i=0; i<grid_num_rows; i++)
    {
        for(int j=0; j<grid_num_cols; j++)
        {
            if((*citygrid)[i][j].getStreetName()==streetName)
            {
                status=true;
                (*citygrid)[i][j].updateStreetName("-");
                (*citygrid)[i][j].changeAttribute('.');
                (*citygrid)[i][j].updateDetailed_Attribute("BLANK");
            }
        }
    }
    return status;
}

void CityGrid::printCityStreets()
{
    for (int i = 0; i < grid_num_rows ;i++)
    {
        cout<<i<<" ";
        for (int j = 0; j < grid_num_cols; j++)
        {
            if((*citygrid)[i][j].getAttribute()=='R')
            {
                cout<<(*citygrid)[i][j].getStreetName()<<" "; //prints streetName
            }
            else
            {
                cout<<(*citygrid)[i][j].getAttribute()<<" ";
            } 
        } 
        cout << endl;
    }
}

void CityGrid::printAll_DetailedAttributes()
{
    for (int i = 0; i < grid_num_rows ;i++)
    {
        cout<<i<<" ";
        for (int j = 0; j < grid_num_cols; j++)
        {
            cout<<(*citygrid)[i][j].getDetailed_Atttribute()<<" ";
        } 
        cout << endl;
    }
}

void CityGrid::printCityRoadNetwork()
{
    for(int i =0; i < grid_num_cols ;i++)
    {
        if(i==0)
        cout<<"  ";
        cout<<i<<" ";
        if(i==(grid_num_cols-1))
        cout<<endl;
    }

    for (int i = 0; i < grid_num_rows ;i++)
    {
        cout<<i<<" ";
        for (int j = 0; j < grid_num_cols; j++)
        {
            
            if((*citygrid)[i][j].getDetailed_Atttribute()=="ROAD")
            {
                cout<<(*citygrid)[i][j].getAttribute()<<" "; //prints roads
            }
            if((*citygrid)[i][j].getDetailed_Atttribute()=="BLANK")
            {
                cout <<(*citygrid)[i][j].getAttribute()<<" "; //prints  available space
            }
            if((*citygrid)[i][j].getDetailed_Atttribute()=="USED")
            {
                cout <<(*citygrid)[i][j].getAttribute()<<" "; //prints  available space
            }
        } 
        cout << endl;
    }
}

vector<pair<int,int>> CityGrid::errorPair()
{
    vector<pair<int,int>> errorVector;
    errorVector.push_back({-1,-1});
    errorVector.push_back({-1,-1});
    errorVector.push_back({-1,-1});
    errorVector.push_back({-1,-1});
    return errorVector;
}

bool CityGrid::isEmptySpace(int uplr, int uplc, int uprc, int dlr) {
    // Ensure bounds are within grid limits
    if (uplr < 0 || uplc < 0 || dlr >= grid_num_rows || uprc >= grid_num_cols)
    {
        cout<<"invalid dimensions.";
        return false; // Out of bounds, not valid space
    }

    // Check each cell within the specified rectangle
    for (int i = uplr; i <= dlr; i++) {
        for (int j = uplc; j <= uprc; j++) {  // <= uprc to include the last column
            if ((*citygrid)[i][j].getAttribute() != '.')
            {
                cout<<"No space to add building";
                return false; // Cell is not empty
            }
        }
    }
    return true; // All cells in the area are empty
}

const char CityGrid::getAttribute_from_DetailedAttribute(string detailed_Attribute)
{
    if(detailed_Attribute=="SCHOOL" || detailed_Attribute=="OFFICE" || detailed_Attribute=="HOSPITAL" || detailed_Attribute=="SHOP")
    {
        return 'C';
    }
    if(detailed_Attribute=="ESTATE" || detailed_Attribute=="APARTMENT" || detailed_Attribute=="HOUSE")
    {
        return 'H';
    }
    if(detailed_Attribute=="MUSEUM" || detailed_Attribute=="MONUMENT" || detailed_Attribute=="PARK")
    {
        return 'L';
    }
    if(detailed_Attribute=="FACTORY" || detailed_Attribute=="AIRPORT" || detailed_Attribute=="WAREHOUSE" || detailed_Attribute=="TRAINSTATION")
    {
        return 'I';
    }
    if(detailed_Attribute=="ROADS")
    {
        return 'R';
    }
    if(detailed_Attribute=="USED")
    {
        return '#';
    }
    return '.';
}

bool CityGrid::placeBuilding(int uplr, int uplc, int uprc, int dlr, std::string detailed_attr) {
    // Boundary checks to ensure valid coordinates within the grid
    if (uplr < 0 || uplc < 0 || dlr >= grid_num_rows || uprc >= grid_num_cols) {
        cout<< "Error: Building placement is out of grid bounds.\n";
        return false;
    }

    // Place the building within the specified rectangular area
    for (int i = uplr; i <= dlr; i++) {
        for (int j = uplc; j <= uprc; j++) {
            (*citygrid)[i][j].updateDetailed_Attribute(detailed_attr);
            (*citygrid)[i][j].changeAttribute(getAttribute_from_DetailedAttribute(detailed_attr));
        }
    }
    return true;
}

// Function to check if any cell surrounding the building area is a road
bool CityGrid::isNextToRoad(int uplr, int uplc, int uprc, int dlr) {
    // Check each cell around the perimeter of the building area
    for (int i = uplr; i <= dlr; ++i) {
        // Check left and right edges
        if (uplc > 0 && (*citygrid)[i][uplc - 1].getAttribute() == 'R') return true;  // Left edge
        if (uprc < grid_num_cols - 1 && (*citygrid)[i][uprc + 1].getAttribute() == 'R') return true;  // Right edge
    }
    for (int j = uplc; j <= uprc; ++j) {
        // Check top and bottom edges
        if (uplr > 0 && (*citygrid)[uplr - 1][j].getAttribute() == 'R') return true;  // Top edge
        if (dlr < grid_num_rows - 1 && (*citygrid)[dlr + 1][j].getAttribute() == 'R') return true;  // Bottom edge
    }
    return false;  // No road found adjacent to the building area
}

// Modified addBuilding function to include road check
std::vector<std::pair<int, int>> CityGrid::addBuilding(int length, int width, std::string detailed_Attribute) {
    if (length < 0 || width < 0 || width > grid_num_cols || length > grid_num_rows)
    {
        cout<<"invalid dimensions";
        return errorPair();
    }

    for (int i = 0; i <= grid_num_rows - length; ++i) {
        for (int j = 0; j <= grid_num_cols - width; ++j) {
            int up_left_row = i;
            int up_left_col = j;
            int up_right_row = i;
            int up_right_col = j + width - 1;
            int down_left_row = i + length - 1;
            int down_left_col = j;
            int down_right_row = i + length - 1;
            int down_right_col = j + width - 1;

            // Check if the space is empty and adjacent to a road
            if (isEmptySpace(up_left_row, up_left_col, up_right_col, down_left_row) &&
                isNextToRoad(up_left_row, up_left_col, up_right_col, down_left_row))
                {
                
                // Place the building if it meets both conditions
                if(placeBuilding(up_left_row, up_left_col, up_right_col, down_left_row, detailed_Attribute))
                {
                    // Return the corner positions
                    return{
                    {up_left_row, up_left_col},
                    {up_right_row, up_right_col},
                    {down_left_row, down_left_col},
                    {down_right_row, down_right_col}};
                }
            }
        }
    }
    cout<<"Could not add buillding";
    return errorPair();  // No suitable location found
}


int CityGrid::getDistance(int,int,string)
{
    return -1;
}
//get distance from building a to building b
//add building