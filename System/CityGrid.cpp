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

