# Builds a .zip file for loading with BMBF
& $PSScriptRoot/build.ps1

if ($?) {
    Compress-Archive -Path "./libs/arm64-v8a/libbetter-practice.so", "./libs/arm64-v8a/libbeatsaber-hook_1_0_12.so", "./bmbfmod.json" -DestinationPath "./better-practice_v0.1.0.zip" -Update
}
