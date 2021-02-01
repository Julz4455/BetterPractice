#pragma once
#include "UnityEngine/Sprite.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(BetterPracticeUI, BetterPracticeConfigViewController, HMUI::ViewController,

  DECLARE_INSTANCE_FIELD(bool, isEnabled);

  DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
  DECLARE_OVERRIDE_METHOD(void, DidDeactivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidDeactivate", 2), bool addedToHierarchy, bool screenSystemEnabling);

  REGISTER_FUNCTION(BetterPracticeConfigViewController,
    REGISTER_FIELD(isEnabled);

    REGISTER_METHOD(DidActivate);
    REGISTER_METHOD(DidDeactivate);
  )

)
