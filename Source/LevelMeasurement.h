// ==================================================================================
// Copyright (c) 2012 HiFi-LoFi
//
// This is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ==================================================================================

#ifndef _LEVELMEASUREMENT_H
#define _LEVELMEASUREMENT_H

#include "../JuceLibraryCode/JuceHeader.h"

#include <cstddef>


class LevelMeasurement
{
public:
  explicit LevelMeasurement(float decay = 0.9999f);  
  void process(size_t len, const float* data0);
  void process(size_t len, const float* data0, const float* data1);
  void updateLevel(size_t len, float maxLevel);
  float getLevel() const;  
  void reset();
  
private:
  juce::Atomic<float> _level;
  const float _decay;
};


#endif // Header guard