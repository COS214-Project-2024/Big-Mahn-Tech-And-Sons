#ifndef NUETRALSTATE_H
#define NUETRALSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;


class NuetralState: public SatisfactionState {
   public:
      void handle(Citizen* citizen) override;
      string getStateName() const override;
};
#endif