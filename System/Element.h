// Element.h
#pragma once

//#include "TaxManager.h"
class TaxManager;

/**
 * @class Element 
 * @brief Base class for elements that accept a visitor.
 */
class Element {
public:
    // virtual ~Element() {}
    
    /**
     * @brief Accepts a visitor.
     * 
     * @param visitor The visitor object.
     */
    virtual void accept(TaxManager* visitor) = 0;
};
