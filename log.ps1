$timestamp = Get-Date -Format "MM-dd HH:mm:ss.fff"
adb logcat -T "$timestamp" main-modloader:W QuestHook[better-practice`|v0.1.0]:* AndroidRuntime:E *:S