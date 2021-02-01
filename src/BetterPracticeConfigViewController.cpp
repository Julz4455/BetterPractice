#include "BetterPracticeConfigViewController.hpp"

#include "UnityEngine/RectOffset.hpp"
#include "UnityEngine/RectTransform.hpp"
#include "UnityEngine/Vector2.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/UI/Image.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/Toggle_ToggleEvent.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
#include "UnityEngine/Events/UnityAction.hpp"
#include "UnityEngine/Events/UnityAction_1.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
#include "HMUI/ScrollView.hpp"
#include "HMUI/ModalView.hpp"
#include "HMUI/Touchable.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include <stdlib.h>

#include "bp_logger.hpp"
#include "ModConfig.hpp"

#include <sstream>
#include <string>

using namespace QuestUI;
using namespace UnityEngine;
using namespace UnityEngine::UI;
using namespace UnityEngine::Events;
using namespace HMUI;

DEFINE_CLASS(BetterPracticeUI::BetterPracticeConfigViewController);

void BetterPracticeUI::BetterPracticeConfigViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
  if(firstActivation) {
    get_gameObject()->AddComponent<Touchable*>();
    GameObject* container = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
    
    AddConfigValueToggle(container->get_transform(), getBetterPracticeConfig().BetterPracticeEnabled);
  }
}

void BetterPracticeUI::BetterPracticeConfigViewController::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {
  // Something goes here...
}
