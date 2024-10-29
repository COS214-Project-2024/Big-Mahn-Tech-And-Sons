#ifndef SADSTATE_H
#define SADSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;


class SadState: public SatisfactionState {
   public:
      // satisafcation < 45
      void handle(Citizen* citizen) override;
      string getStateName() const override;
};
#endif