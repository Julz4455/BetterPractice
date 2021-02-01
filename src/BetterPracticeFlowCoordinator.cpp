#include "BetterPracticeFlowCoordinator.hpp"

#include "System/Action.hpp"
#include "System/Action_1.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "bp_logger.hpp"

using namespace QuestUI;

DEFINE_CLASS(BetterPracticeUI::BetterPracticeFlowCoordinator);

void BetterPracticeUI::BetterPracticeFlowCoordinator::Awake() {
  if(!BetterPracticeConfigViewController)
    BetterPracticeConfigViewController = BeatSaberUI::CreateViewController<BetterPracticeUI::BetterPracticeConfigViewController*>();
}

void BetterPracticeUI::BetterPracticeFlowCoordinator::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
  if(firstActivation) {
    SetTitle(il2cpp_utils::createcsstr("BetterPractice"), HMUI::ViewController::AnimationType::In);
    showBackButton = true;
    ProvideInitialViewControllers(BetterPracticeConfigViewController, nullptr, nullptr, nullptr, nullptr);
  }
}

void BetterPracticeUI::BetterPracticeFlowCoordinator::BackButtonWasPressed(HMUI::ViewController *topViewController) {
  this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}
