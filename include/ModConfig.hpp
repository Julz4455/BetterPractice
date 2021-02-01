#pragma once
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(BetterPracticeConfig,
  
  DECLARE_VALUE(BetterPracticeEnabled, bool, "Enabled?", true);

  INIT_FUNCTION(
    INIT_VALUE(BetterPracticeEnabled);
  )

)
