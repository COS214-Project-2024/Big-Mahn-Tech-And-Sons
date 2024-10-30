/** 
 * * @author u21824241_(add yours guys)
 */

#ifndef VISITHOUSING_H
#define VISITHOUSING_H


#include "TaxManager.h"
#include "Building.h"
class Budget;

/**
 * @class visitHousing
 * @brief ConcreteVisitor class for housing taxation.
 */

class visitHousing : public TaxManager 
{
        public:
            void visitBuilding(Building* building);
            void visitBudget(Budget* budget);
};

#endif // VISITHOUSING_H
