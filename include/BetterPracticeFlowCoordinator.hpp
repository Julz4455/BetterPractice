#pragma once
#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"

#include "BetterPracticeConfigViewController.hpp"

#include "custom-types/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(BetterPracticeUI, BetterPracticeFlowCoordinator, HMUI::FlowCoordinator,

  DECLARE_INSTANCE_FIELD(BetterPracticeUI::BetterPracticeConfigViewController*, BetterPracticeConfigViewController);

  DECLARE_METHOD(void, Awake);

  DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

  DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "BackButtonWasPressed", 1), HMUI::ViewController* topViewController);

  REGISTER_FUNCTION(BetterPracticeFlowCoordinator,

    REGISTER_FIELD(BetterPracticeConfigViewController);

    REGISTER_METHOD(Awake);
    REGISTER_METHOD(DidActivate);
    REGISTER_METHOD(BackButtonWasPressed);

  )

)
