#include "CityGrid.h"
#include "Building.h"



// .......................... CELL ...............................//

Cell::Cell(int row_value, int col_value, string cardinal_point)
{
     this->cell_col_value = col_value;
     this->cell_row_value = row_value;
     this->cardinal_direction = cardinal_point;
     set_Detailed_Attribute("BLANK");
     set_Attribute('.');
     this->street_name = "-";
}

Cell::~Cell()
{
    //no memory management required here.
}

bool Cell::set_Attribute(char attri)
{
    if(attri=='C'){ this->attribute = 'C'; return true;}    // Commercial building
    if(attri=='H'){ this->attribute = 'H'; return true;}    // Residential building
    if(attri=='L'){ this->attribute = 'L'; return true;}    // Landmark building
    if(attri=='I'){ this->attribute = 'I'; return true;}    // Industrial buidling
    if(attri=='R'){ this->attribute = 'R'; return true;}    // Road
    if(attri=='.'){ this->attribute = '.'; return true;}    // Blank
    if(attri=='#'){ this->attribute = '#'; return true;}    // Used

    return false;
}

bool Cell::set_Detailed_Attribute(string detailed_Attri)
{
    if(detailed_Attri=="SCHOOL"){ this->detailed_attribute = "SCHOOL"; return true;}
    if(detailed_Attri=="OFFICE"){ this->detailed_attribute = "OFFICE"; return true;}
    if(detailed_Attri=="HOSPITAL"){ this->detailed_attribute = "HOSPITAL"; return true;}
    if(detailed_Attri=="SHOP"){ this->detailed_attribute = "SHOP"; return true;}
    
    if(detailed_Attri=="ESTATE"){ this->detailed_attribute = "ESTATE"; return true;}
    if(detailed_Attri=="APARTMENT"){ this->detailed_attribute = "APARTMENT"; return true;}
    if(detailed_Attri=="HOUSE"){ this->detailed_attribute = "HOUSE"; return true;}

    if(detailed_Attri=="MUSEUM"){ this->detailed_attribute = "MUSEUM"; return true;}
    if(detailed_Attri=="MONUMENT"){ this->detailed_attribute = "MONUMENT"; return true;}
    if(detailed_Attri=="PARK"){ this->detailed_attribute = "PARK"; return true;}

    if(detailed_Attri=="FACTORY"){ this->detailed_attribute = "FACTORY"; return true;}
    if(detailed_Attri=="AIRPORT"){ this->detailed_attribute = "AIRPORT"; return true;}
    if(detailed_Attri=="WAREHOUSE"){ this->detailed_attribute = "WAREHOUSE"; return true;}
    if(detailed_Attri=="TRAINSTATION"){ this->detailed_attribute = "TRAINSTATION"; return true;}

    if(detailed_Attri=="ROAD"){ this->detailed_attribute = "ROAD"; return true;}
    if(detailed_Attri=="BLANK"){ this->detailed_attribute = "BLANK"; return true;}
    if(detailed_Attri=="USED"){ this->detailed_attribute = "USED"; return true;}

    return false;
}

const char Cell::getAttribute()
{
    return attribute;
}

void Cell::updateDetailed_Attribute(string newDetailedAttribute)
{
    if(newDetailedAttribute!=detailed_attribute)
    {
        set_Detailed_Attribute(newDetailedAttribute);
    }
}

const string Cell::getDetailed_Atttribute()
{
    return detailed_attribute;
}

void Cell::changeAttribute(char newAttribute)
{
    if(newAttribute!=attribute)
    {
        set_Attribute(newAttribute);
    }
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
//................................................................//




//........................... CITYGRID ...........................//

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
        cout<<setw(3.5)<<" ";
        if(i<10){cout<<"0"<<i<<" ";}
        else{cout<<i<<" ";}
        if(i==(grid_num_cols-1))
        cout<<endl;
    }
    for (int i = 0; i < grid_num_rows ;i++) {
        if(i<10)
        {cout<<"0"<<i<<" ";}
        else{cout<<i<<" ";}
        for (int j = 0; j < grid_num_cols; j++) {
            cout<<setw(2)<<(*citygrid)[i][j].getAttribute()<<" ";
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
    direction = toLower(direction);
    strname = toLower(strname);

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
        if(i<10){cout<<"0"<<i<<" ";}
        else{cout<<i<<" ";}
        for (int j = 0; j < grid_num_cols; j++)
        {
            if((*citygrid)[i][j].getAttribute()=='R')
            {
                cout<<(*citygrid)[i][j].getStreetName()<<" "; //prints streetName
            }
            else
            {

                cout<<setw(2)<<(*citygrid)[i][j].getAttribute()<<" ";
            } 
        } 
        cout << endl;
    }
}

void CityGrid::printCityRoadNetwork()
{
    for(int i =0; i < grid_num_cols ;i++)
    {
        if(i==0)
        cout<<setw(3.5)<<" ";
        if(i<10){cout<<"0"<<i<<" ";}
        else{cout<<i<<" ";}
        if(i==(grid_num_cols-1))
        cout<<endl;
    }

    for (int i = 0; i < grid_num_rows ;i++)
    {
        if(i<10)
        {cout<<"0"<<i<<" ";}
        else{cout<<i<<" ";}
        for (int j = 0; j < grid_num_cols; j++)
        {
            
            if((*citygrid)[i][j].getDetailed_Atttribute()=="ROAD")
            {
                cout<<setw(2)<<(*citygrid)[i][j].getAttribute()<<" "; //prints roads
            }
            else if((*citygrid)[i][j].getDetailed_Atttribute()=="BLANK")
            {
                cout<<setw(2)<<(*citygrid)[i][j].getAttribute()<<" "; //prints  available space
            }
            else
            {
                cout<<setw(2)<<"#"<<" "; //prints  available space
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
               // cout<<"No space to add building";
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

std::vector<std::pair<int, int>> CityGrid::addBuilding(int length, int width, Building* building){

    string detailed_Attribute = toUpper(building->getType());
    if (length < 0 || width < 0 || width > grid_num_cols || length > grid_num_rows)
    {
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
                    cout<<"is it adding correct co-ords";
                    cout<<"("<<up_left_row<<","<<up_left_col<<")\n";
                    cout<<"("<<up_right_row<<","<<up_right_col<<")\n";
                    cout<<"("<<down_left_row<<","<<down_left_col<<")\n";
                    cout<<"("<<down_right_row<<","<<down_right_col<<")\n";
                    std::vector<std::pair<int, int>> coord = {
                    {up_left_row, up_left_col},         //up left corner
                    {up_right_row, up_right_col},       //up right corner
                    {down_left_row, down_left_col},     //down left corner
                    {down_right_row, down_right_col}};  //down right corner
                    building->setCoordinates(coord);
                    return coord;
                }
            }
        }
    }
    cout<<"Could not add buillding" << building->getName() << " " << building->getType() << endl; 
    return errorPair();  // No suitable location found
}

bool CityGrid::removeBuilding(vector<pair<int,int>> buildiing)
{
    if(buildiing!=errorPair())
    {
        int uplr = buildiing[0].first;
        int dlr = buildiing[2].first;
        int uplc = buildiing[0].second;
        int uprc = buildiing[1].second;

        for (int i = uplr; i <= dlr; i++)
        {
            for (int j = uplc; j<= uprc; j++)
            {
                (*citygrid)[i][j].changeAttribute('.');
                (*citygrid)[i][j].updateDetailed_Attribute("BLANK");
            }
        }
        return true;
    }
    return false;
}

string CityGrid::toUpper(string word)
{
    for(int i=0; i<word.length(); i++)
    {
        word[i]=toupper(word[i]);
    }
    return word;
}

string CityGrid::toLower(string word)
{
    for(int i=0; i<word.length(); i++)
    {
        word[i]=tolower(word[i]);
    }
    return word;
}

vector<std::pair<int, int>> CityGrid::getAdjacentRoadCells(int uplr, int uplc, int uprc, int dlr) {
    
    vector<pair<int, int>> roadCells;

    // Check each cell around the perimeter of the building area for a road
    for (int i = uplr; i <= dlr; ++i) {
        // Check left and right edges
        if (uplc > 0 && (*citygrid)[i][uplc - 1].getAttribute() == 'R') 
            roadCells.push_back({i, uplc - 1});  // Left edge
        if (uprc < grid_num_cols - 1 && (*citygrid)[i][uprc + 1].getAttribute() == 'R') 
            roadCells.push_back({i, uprc + 1});  // Right edge
    }
    for (int j = uplc; j <= uprc; ++j) {
        // Check top and bottom edges
        if (uplr > 0 && (*citygrid)[uplr - 1][j].getAttribute() == 'R') 
            roadCells.push_back({uplr - 1, j});  // Top edge
        if (dlr < grid_num_rows - 1 && (*citygrid)[dlr + 1][j].getAttribute() == 'R') 
            roadCells.push_back({dlr + 1, j});  // Bottom edge
    }
    return roadCells;  // Returns coordinates of all adjacent road cells
}

int CityGrid::getDistance(Building* citizen_current_building, Building* citizen_destination_building)
{
    vector<pair<int,int>> curr_building = citizen_current_building->getGridCoordinates();
    vector<pair<int,int>> dest_building = citizen_destination_building->getGridCoordinates();
    if(isNextToRoad(curr_building[0].first,curr_building[0].second,curr_building[1].second,curr_building[2].first)&&
       isNextToRoad(dest_building[0].first,dest_building[0].second,dest_building[1].second,dest_building[2].first))
       {
            // Get road-adjacent cells for each building
    std::vector<std::pair<int, int>> currRoadCells = getAdjacentRoadCells(
        citizen_current_building->getGridCoordinates()[0].first, 
        citizen_current_building->getGridCoordinates()[0].second, 
        citizen_current_building->getGridCoordinates()[1].second, 
        citizen_current_building->getGridCoordinates()[2].first);

    std::vector<std::pair<int, int>> destRoadCells = getAdjacentRoadCells(
        citizen_destination_building->getGridCoordinates()[0].first, 
        citizen_destination_building->getGridCoordinates()[0].second, 
        citizen_destination_building->getGridCoordinates()[1].second, 
        citizen_destination_building->getGridCoordinates()[2].first);

    // Early exit if no road cells adjacent to either building
    if (currRoadCells.empty() || destRoadCells.empty()) {
        return -1;
    }

    // Breadth-First Search (BFS) to find the shortest path between road cells
    std::queue<std::pair<int, int>> q;
    std::unordered_map<int, int> distances;  // flattened key -> distance

    // Helper function to flatten the coordinates
    auto flatten = [this](int x, int y) {
        return x * grid_num_cols + y;
    };

    // Initialize BFS with the current building’s road-adjacent cells
    for (const auto& cell : currRoadCells) {
        q.push(cell);
        distances[flatten(cell.first, cell.second)] = 0;
    }

    // Perform BFS to find the shortest path to any destination road cell
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Check if we reached a road cell adjacent to the destination building
        int flattened_dest_key;
        for (const auto& destCell : destRoadCells) {
            flattened_dest_key = flatten(destCell.first, destCell.second);
            if (flatten(x, y) == flattened_dest_key) {
                return distances[flatten(x, y)];  // Return the distance to the destination
            }
        }

        // Explore neighbors on the road grid
        for (const auto& [dx, dy] : std::vector<std::pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int nx = x + dx, ny = y + dy;
            int flattened_key = flatten(nx, ny);

            if (nx >= 0 && nx < grid_num_rows && ny >= 0 && ny < grid_num_cols && 
                (*citygrid)[nx][ny].getAttribute() == 'R' && distances.find(flattened_key) == distances.end()) {
                
                q.push({nx, ny});
                distances[flattened_key] = distances[flatten(x, y)] + 1;
            }
        }
    }

    // If no path found, return -1
    return -1;
       }
}

//get distance from building a to building b