/**
 * * @author u21824241_(add yours guys)
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include "Element.h"
class TaxManager;

/**
 * @class Element
 * @brief Base class for elements that accept a visitor.
 */
class Element
{
public:
    // virtual ~Element() {}

    /**
     * @brief Accepts a visitor.
     *
     * @param visitor The visitor object.
     */
    virtual void accept(TaxManager *visitor) = 0;
};

#endif
