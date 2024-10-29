#include "CityGrid.h"



Cell::Cell(int row_value, int col_value, string cardinal_point)
{
    this->cell_row_value = row_value;
    this->cell_col_value = col_value;
    this->attribute = '.';
    this->cardinal_direction = cardinal_point;
}

Cell::~Cell()
{
    //no memory management required here.
}

const char Cell::getAttribute()
{
    return attribute;
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

int Cell::getRow() const
{
return cell_row_value;
}

int Cell::getCols() const
{
    return cell_col_value;
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
    if(start_row<0 || start_col<0 || length<0){return false;}

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
                        (*citygrid)[i][start_col].updateStreetName(strname); //check string comparisons.
                        continue;
                    }
                    else
                    {
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
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
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
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
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
                        (*citygrid)[i][start_col].updateStreetName(strname);
                        continue;
                    }
                    else
                    {
                        (*citygrid)[start_row][i].changeAttribute('R');
                        (*citygrid)[start_row][i].updateStreetName(strname);
                    }
                }
            }
            break;
    }

    return true;

}

bool CityGrid::addBuilding(Building * building, int row, int col, int width, int height)
{
         // Ensure building fits within grid bounds
    if (row + height > grid_num_rows || col + width > grid_num_cols) return false;

    // Check for overlap with other buildings
    for (int r = row; r < row + height; ++r) {
        for (int c = col; c < col + width; ++c) {
            if ((*citygrid)[r][c].getAttribute() == 'B') return false;

        }
    }

     // Check if the area is clear
     for (int i = row; i < row + height && i < grid_num_rows; i++) {
        for (int j = col; j < col + width && j < grid_num_cols; j++) {
            if ((*citygrid)[i][j].getAttribute() != '.') {
                return false; // Space is occupied
            }
        }
    }

    // Place building in the specified area
    for (int r = row; r < row + height; ++r) {
        for (int c = col; c < col + width; ++c) {
            (*citygrid)[r][c].changeAttribute('B'); // Mark cells as building
        }
    }
    
   

      // Update building position
    building->setPosition(row, col);
    buildings.push_back(building);
    buildingMap[building->getName()] = building;
    
    return true;
}



bool CityGrid::removeBuilding( int row, int col, int width, int height)
{

}

Cell * CityGrid::findCell(Building * building)
{
      // Assuming each building has a specific row/col it starts at:
    int row = building->getRow();  // Hypothetical getter function in Building
    int col = building->getCol();  // Hypothetical getter function in Building
    
    if (row >= 0 && row < grid_num_rows && col >= 0 && col < grid_num_cols) {
        return &(*citygrid)[row][col];
    }
    return nullptr;
}





 std::vector<Cell> CityGrid::travel(const Cell& start, const Cell& destination)
 {
    std::vector<std::vector<bool>> visited(grid_num_rows, std::vector<bool>(grid_num_cols, false));
    std::queue<std::pair<Cell, std::vector<Cell>>> q;
    
    q.push({start, {start}});
    visited[start.getRow()][start.getCols()] = true;

    while (!q.empty()) {
        Cell current = q.front().first;
        std::vector<Cell> currentPath = q.front().second;
        q.pop();

        if (current.getRow() == destination.getRow() && 
            current.getCols() == destination.getCols()) {
            return currentPath;
        }

        for (const Cell& neighbor : getNeighbors(current)) {
            if (!visited[neighbor.getRow()][neighbor.getCols()]) {
                visited[neighbor.getRow()][neighbor.getCols()] = true;
                std::vector<Cell> newPath = currentPath;
                newPath.push_back(neighbor);
                q.push({neighbor, newPath});
            }
        }
    }
    return {};
 }


bool CityGrid::isValidRoad(int row, int col) {
  if (row < 0 || row >= grid_num_rows || col < 0 || col >= grid_num_cols) {
        return false;
    }
    return (*citygrid)[row][col].getAttribute() == 'R';
}



std::vector<Cell> CityGrid::getNeighbors(const Cell& cell)
{
     std::vector<Cell> neighbors;
    int row = cell.getRow();
    int col = cell.getCols();
    
    // Define possible moves (up, down, left, right)
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        
        if (isValidRoad(newRow, newCol)) {
            neighbors.push_back((*citygrid)[newRow][newCol]);
        }
    }
    
    return neighbors;   
}


bool CityGrid::removeRoad(int start_row, int start_col, int length, string direction)
{
    if(start_row<0 || start_col<0 || length<0){return false;}

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
                        (*citygrid)[i][start_col].updateStreetName("-");
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
                        (*citygrid)[i][start_col].updateStreetName("-");
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
            cout<<(*citygrid)[i][j].getStreetName()<<" "; 
        } 
        cout << endl;
    }
}

void CityGrid::printCityRoads()
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
            if((*citygrid)[i][j].getAttribute()=='R')
            {cout <<(*citygrid)[i][j].getAttribute()<<" ";}
            else{cout <<'.'<<" ";}
        } 
        cout << endl;
    }
}

int CityGrid::getNumRows()
{
    return this->grid_num_rows;
}

int CityGrid::getNumCols()
{
    return this->grid_num_cols;
}
