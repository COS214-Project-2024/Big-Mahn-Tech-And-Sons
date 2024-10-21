
#ifndef HAPPYSTATE_H
#define HAPPYSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;


class HappyState: public SatisfactionState {
   public:
      void handle(Citizen* citizen) override;
      string getStateName() const override;


};
#endif // HAPPYSTATE_H