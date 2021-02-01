#define RAPIDJSON_HAS_STDSTRING 1

#include "main.hpp"
#include "ModConfig.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine::UI;
using namespace UnityEngine;
using namespace QuestUI;
using namespace TMPro;
using namespace HMUI;

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo, LoggerOptions(false, false));
    return *logger;
}

DEFINE_CONFIG(BetterPracticeConfig);

auto cs2utf8(Il2CppString *t) {
    return to_utf8(csstrtostr(t));
}

MAKE_HOOK_OFFSETLESS(
    PracticeViewController_DidActivate, void,
    PracticeViewController *self, bool firstActivation,
    bool addedToHierarchy, bool screenSystemDisabling
) {
    PracticeViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemDisabling);

    if (getBetterPracticeConfig().BetterPracticeEnabled.GetValue()) {

        auto difficulty_text = self->levelBar->difficultyText;
        auto level = ((IPreviewBeatmapLevel *)self->level);
        auto bpm = level->get_beatsPerMinute() * (self->practiceSettings->songSpeedMul);
        auto difficulty = self->beatmapDifficulty.value;
        auto difficulty_str = "";

        switch(difficulty) {
        case 0: 
            difficulty_str = "Easy";
            break;
        case 1: 
            difficulty_str = "Normal";
            break;
        case 2: 
            difficulty_str = "Hard";
            break;
        case 3: 
            difficulty_str = "Expert";
            break;
        case 4: 
            difficulty_str = "Expert+";
            break;
        default: 
            difficulty_str = "Unknown";
            break;
        }

        // BPM to fixed (.00)
        std::stringstream bpm_fixed_stream;
        bpm_fixed_stream << std::fixed << std::setprecision(2) << bpm;
        std::string bpm_fixed = bpm_fixed_stream.str();

        difficulty_text->set_text(il2cpp_utils::createcsstr(
            (std::string)difficulty_str + "\n"
            "BPM: " + bpm_fixed + "\n" +
            "Duration: " + cs2utf8(self->songStartSlider->TextForValue(level->get_songDuration()))
        ));
    }
}

MAKE_HOOK_OFFSETLESS(
    PracticeViewController_HandleSpeedSliderValueDidChange, void,
    PracticeViewController *self,
    RangeValuesTextSlider *slider, float val
) {
    PracticeViewController_HandleSpeedSliderValueDidChange(self, slider, val);

    if (getBetterPracticeConfig().BetterPracticeEnabled.GetValue()) {

        auto difficulty_text = self->levelBar->difficultyText;
        auto level = ((IPreviewBeatmapLevel *)self->level);
        auto bpm = level->get_beatsPerMinute() * (self->practiceSettings->songSpeedMul);
        auto difficulty = self->beatmapDifficulty.value;
        auto difficulty_str = "";

        switch (difficulty) {
        case 0:
            difficulty_str = "Easy";
            break;
        case 1:
            difficulty_str = "Normal";
            break;
        case 2:
            difficulty_str = "Hard";
            break;
        case 3:
            difficulty_str = "Expert";
            break;
        case 4:
            difficulty_str = "Expert+";
            break;
        default:
            difficulty_str = "Unknown";
            break;
        }

        // BPM to fixed (.00)
        std::stringstream bpm_fixed_stream;
        bpm_fixed_stream << std::fixed << std::setprecision(2) << bpm;
        std::string bpm_fixed = bpm_fixed_stream.str();

        difficulty_text->set_text(il2cpp_utils::createcsstr(
            (std::string)difficulty_str + "\n"
            "BPM: " + bpm_fixed + "\n" +
            "Duration: " + cs2utf8(self->songStartSlider->TextForValue(level->get_songDuration()))
        ));
    }
}

MAKE_HOOK_OFFSETLESS(
    PracticeViewController_HandleSongStartSliderValueDidChange, void,
    PracticeViewController *self,
    RangeValuesTextSlider *slider, float val
) {
    PracticeViewController_HandleSongStartSliderValueDidChange(self, slider, val);

    if (getBetterPracticeConfig().BetterPracticeEnabled.GetValue()) {

        auto difficulty_text = self->levelBar->difficultyText;
        auto level = ((IPreviewBeatmapLevel *)self->level);
        auto bpm = level->get_beatsPerMinute() * (self->practiceSettings->songSpeedMul);
        auto difficulty = self->beatmapDifficulty.value;
        auto difficulty_str = "";

        switch (difficulty) {
        case 0:
            difficulty_str = "Easy";
            break;
        case 1:
            difficulty_str = "Normal";
            break;
        case 2:
            difficulty_str = "Hard";
            break;
        case 3:
            difficulty_str = "Expert";
            break;
        case 4:
            difficulty_str = "Expert+";
            break;
        default:
            difficulty_str = "Unknown";
            break;
        }

        // BPM to fixed (.00)
        std::stringstream bpm_fixed_stream;
        bpm_fixed_stream << std::fixed << std::setprecision(2) << bpm;
        std::string bpm_fixed = bpm_fixed_stream.str();

        difficulty_text->set_text(il2cpp_utils::createcsstr(
            (std::string)difficulty_str + "\n"
            "BPM: " + bpm_fixed + "\n" +
            "Duration: " + cs2utf8(self->songStartSlider->TextForValue(level->get_songDuration() - val))
        ));
    }
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = "better-practice";
    info.version = "0.1.0";
    modInfo = info;

    getBetterPracticeConfig().Init(modInfo);
    getLogger().info("Completed setup!");
}

void DidActivate(HMUI::ViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
    getLogger().info("DidActivate: %p, %d, %d, %d", self, firstActivation, addedToHierarchy, screenSystemEnabling);
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();
    QuestUI::Init();

    getLogger().info("Registering custom types...");

    custom_types::Register::RegisterTypes<
        BetterPracticeUI::BetterPracticeConfigViewController,
        BetterPracticeUI::BetterPracticeFlowCoordinator
        >();

    getLogger().info("Registering mod settings...");
    
    QuestUI::Register::RegisterModSettingsViewController(modInfo, DidActivate);
    QuestUI::Register::RegisterModSettingsFlowCoordinator<BetterPracticeUI::BetterPracticeFlowCoordinator*>(ModInfo { "BetterPractice", "0.1.0" });

    getLogger().info("Installing hooks...");

    INSTALL_HOOK_OFFSETLESS(
        getLogger(),
        PracticeViewController_DidActivate,
        il2cpp_utils::FindMethodUnsafe("", "PracticeViewController", "DidActivate", 3)
    );

    INSTALL_HOOK_OFFSETLESS(
        getLogger(),
        PracticeViewController_HandleSpeedSliderValueDidChange,
        il2cpp_utils::FindMethodUnsafe("", "PracticeViewController", "HandleSpeedSliderValueDidChange", 2)
    );

    INSTALL_HOOK_OFFSETLESS(
        getLogger(),
        PracticeViewController_HandleSongStartSliderValueDidChange,
        il2cpp_utils::FindMethodUnsafe("", "PracticeViewController", "HandleSongStartSliderValueDidChange", 2)
    );

    getLogger().info("Installed all hooks!");
}