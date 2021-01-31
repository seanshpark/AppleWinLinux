#pragma once

#include "frontends/libretro/joypadbase.h"

#include <vector>


class Analog : public JoypadBase
{
public:
  Analog();

  double getAxis(int i) const override;

private:
  std::vector<std::pair<unsigned, unsigned> > myAxisCodes;
};
