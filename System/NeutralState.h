#ifndef NEUTRALSTATE_H
#define NEUTRALSTATE_H

#include "SatisfactionState.h"
#include <string>

using namespace std;

class NeutralState : public SatisfactionState
{
public:
  // 45 <= satisfaction < 65
  void handle(Citizen *citizen) override;
  string getStateName() const override;
};
#endif