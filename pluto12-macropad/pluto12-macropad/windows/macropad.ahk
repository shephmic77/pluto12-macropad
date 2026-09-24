#Requires AutoHotkey v2.0
#SingleInstance Force

F13::OpenApp("Spotify", "https://open.spotify.com/")
F14::OpenApp("Discord", "https://discord.com/app")
F15::Run "https://krillion.io/"

OpenApp(name, fallback) {
    for folder in [A_Programs, A_ProgramsCommon] {
        Loop Files folder "\*" name "*.lnk", "R" {
            Run A_LoopFileFullPath
            return
        }
    }
    Run fallback
}
